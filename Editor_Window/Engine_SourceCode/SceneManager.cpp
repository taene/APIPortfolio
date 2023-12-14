#include "SceneManager.h"
#include "tDontDestroyOnLoad.h"

namespace t
{
    std::map<std::wstring, Scene*> SceneManager::mScene = {};
    Scene* SceneManager::mActiveScene = nullptr;
    Scene* SceneManager::mDontDestroyOnLoad = nullptr;

    Scene* SceneManager::LoadScene(const std::wstring& name)
    {
        if ( mActiveScene )
            mActiveScene->OnExit();

        std::map<std::wstring , Scene*>::iterator it
            = mScene.find(name);

        if ( it == mScene.end() )
            return nullptr;

        mActiveScene = it->second;

        if ( mActiveScene )
            mActiveScene->OnEnter();

        return it->second;
    }

    void SceneManager::Init()
    {
        mDontDestroyOnLoad = CreateScene<DontDestroyOnLoad>(L"DontDestroyOnLoad");
    }
    void SceneManager::Start()
    {
        mActiveScene->Start();
        mDontDestroyOnLoad->Start();
    }
    void SceneManager::Update()
    {
        mActiveScene->Update();
        mDontDestroyOnLoad->Update();
    }
    void SceneManager::LateUpdate()
    {
        mActiveScene->LateUpdate();
        mDontDestroyOnLoad->LateUpdate();
    }
    void SceneManager::Render(HDC hdc)
    {
        mActiveScene->Render(hdc);
        mDontDestroyOnLoad->Render(hdc);
    }
    void SceneManager::Destroy()
    {
        mActiveScene->Destroy();
        mDontDestroyOnLoad->Destroy();
    }
    void SceneManager::Release()
    {
        for (auto& it : mScene)
        {
            delete it.second;
            it.second = nullptr;
        }
    }
}