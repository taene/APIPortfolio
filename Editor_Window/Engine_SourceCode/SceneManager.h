#pragma once
#include "Scene.h"

namespace t
{
	class SceneManager
	{
	public:
		template <typename T>
		static Scene* CreateScene(const std::wstring& name)
		{
			T* scene = new T();
			scene->SetName(name);
			mActiveScene = scene;
			scene->Init();

			mScene.insert(std::make_pair(name, scene));

			return scene;
		}

		static Scene* LoadScene(const std::wstring& name)
		{
			mActiveScene->OnExit();

			std::map<std::wstring, Scene*>::iterator it
				= mScene.find(name);

			if (it == mScene.end())
				return nullptr;

			mActiveScene = it->second;
			mActiveScene->OnEnter();

			return it->second;
		}

		static Scene* GetActiveScene() { return mActiveScene; }

		static void Init();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);
		static void Release();


	private:
		static std::map<std::wstring, Scene*> mScene;
		static Scene* mActiveScene;	//���� ��
	};
}