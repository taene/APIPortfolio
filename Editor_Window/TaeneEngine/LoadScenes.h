#pragma once
#include "..\\Engine_SourceCode\SceneManager.h"
//���� ���� �߰��ϱ�, main���� �߰�
#include "PlayScene.h"
#include "..\\Engine_SourceCode\SceneManager.h"

//#ifdef DEBUG
//#pragma comment(lib, "..\\TaeneEngine\\x64\\Debug\\TaeneEngine.lib")
//#endif // DEBUG

namespace t
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		//SceneManager::CreateScene<PlayScene>(L"PlayScene");
		//SceneManager::CreateScene<PlayScene>(L"PlayScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}