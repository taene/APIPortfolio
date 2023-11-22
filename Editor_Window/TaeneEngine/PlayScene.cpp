#include "PlayScene.h"
#include "Player.h"
#include "Transform.h"
#include "SpriteRenderer.h"

namespace t
{
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}
	void PlayScene::Init()
	{
		/*bg = new Player();
		Transform* tr = bg->AddComponent<Transform>();
		tr->SetPosition(Vector2(0, 0));

		tr->SetName(L"TR");

		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		sr->SetName(L"SR");
		sr->ImageLoad(L"C:\\GithubProjects\\APIPortfolio\\Assets\\Texture2D\\vheart_title.png");

		AddGameObject(bg, enums::eLayerType::BackGround);*/
	}
	void PlayScene::Update()
	{
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
	void PlayScene::OnEnter()
	{
	}
	void PlayScene::OnExit()
	{
		/*Transform* tr = bg->AddComponent<Transform>();
		tr->SetPosition(Vector2(0, 0));*/
	}
}