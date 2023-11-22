#include "LoadingScene.h"
#include "Player.h"
#include "Transform.h"
#include "SpriteRenderer.h"

namespace t
{
	LoadingScene::LoadingScene()
	{
	}

	LoadingScene::~LoadingScene()
	{
	}

	void LoadingScene::Init()
	{
		Player* bg = new Player();
		Transform* tr = bg->AddComponent<Transform>();
		tr->SetPosition(Vector2(0, 0));
		tr->SetName(L"TR");

		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		sr->SetName(L"SR");
		sr->ImageLoad(L"C:\\GithubProjects\\APIPortfolio\\Assets\\Hollow Knight sprites 1.4.3.2 (Voidheart edition)\\Menu\\vheart_title.png");

		AddGameObject(bg, enums::eLayerType::BackGround);
	}

	void LoadingScene::Update()
	{
		Scene::Update();
	}

	void LoadingScene::LateUpdate()
	{
		Scene::LateUpdate();
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
