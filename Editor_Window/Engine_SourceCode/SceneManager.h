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
			scene->Init();

			mScene.insert(std::make_pair(name, scene));

			return scene;
		}

		static Scene* LoadScene(const std::wstring& name)
		{
			std::map<std::wstring, Scene*>::iterator it
				= mScene.find(name);

			if (it == mScene.end())
				return nullptr;

			mActiveScene = it->second;
			return it->second;
		}

		static void Init();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);


	private:
		static std::map<std::wstring, Scene*> mScene;
		static Scene* mActiveScene;	//ÇöÀç ¾À
	};
}