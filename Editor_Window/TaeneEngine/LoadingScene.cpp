#include "LoadingScene.h"
#include "Player.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "tInput.h"
#include "MainMenuScene.h"
#include "SceneManager.h"
#include "tObject.h"
#include "tTexture.h"
#include "tResources.h"

namespace t
{
	LoadingScene::LoadingScene() :bg(nullptr)
	{
	}

	LoadingScene::~LoadingScene()
	{
	}

	void LoadingScene::Init()
	{
		bg = object::Instantiate<GameObject>
			(enums::eLayerType::BackGround1, Vector2(0, 0));
		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();

		graphics::Texture* bg = Resources::Find<graphics::Texture>(L"LS_BG");
		sr->SetTexture(bg);
		sr->SetSize(Vector2(1600.f,900.0f));
		
		//sr->SetSize(Vector2(1600.0f, 900.0f));	//main의 window창 크기와 동일함
		

		//게임 오브젝트 생성후에 레이어와 게임오브젝트들의 init함수를 호출
		Scene::Init();
	}

	void LoadingScene::Update()
	{
		Scene::Update();
	}

	void LoadingScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"MainMenuScene");
		}
	}

	void LoadingScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}

	void LoadingScene::OnEnter()
	{
	}

	void LoadingScene::OnExit()
	{
	}

}
