#include "SceneManager.h"

namespace t
{
    std::map<std::wstring, Scene*> SceneManager::mScene = {};
    Scene* SceneManager::mActiveScene = nullptr;

    void SceneManager::Init()
    {
    }
    void SceneManager::Update()
    {
        mActiveScene->Update();
    }
    void SceneManager::LateUpdate()
    {
        mActiveScene->LateUpdate();
    }
    void SceneManager::Render(HDC hdc)
    {
        mActiveScene->Render(hdc);
    }
}