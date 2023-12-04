#pragma once
#include "..\\Engine_SourceCode\\SceneManager.h"
//만든 씬들 추가하기, main에도 추가
#include "PlayScene.h"
#include "LoadingScene.h"
#include "MainMenuScene.h"
#include "InGameScene.h"

//#ifdef DEBUG
//#pragma comment(lib, "..\\TaeneEngine\\x64\\Debug\\TaeneEngine.lib")
//#endif // DEBUG

namespace t
{
	void LoadScenes()
	{
		//SceneManager::CreateScene<PlayScene>(L"PlayScene");
		SceneManager::CreateScene<LoadingScene>(L"LoadingScene");
		/*SceneManager::CreateScene<MainMenuScene>(L"MainMenuScene");
		SceneManager::CreateScene<InGameScene>(L"InGameScene");*/
		//SceneManager::CreateScene<MainMenuScene>(L"MainMenuScene");
		//SceneManager::CreateScene<MainMenuScene>(L"MainMenuScene");
		//SceneManager::CreateScene<MainMenuScene>(L"MainMenuScene");
		//SceneManager::CreateScene<MainMenuScene>(L"MainMenuScene");

		SceneManager::LoadScene(L"LoadingScene");
	}
}