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
		Player* pl = new Player();
		Transform* tr = pl->AddComponent<Transform>();
		tr->SetPos(100, 650);
		tr->SetName(L"TR");

		SpriteRenderer* sr = pl->AddComponent<SpriteRenderer>();
		sr->SetName(L"SR");

		AddGameObject(pl);
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
}