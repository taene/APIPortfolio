#include "MainMenuScene.h"
#include "Player.h"
#include "Transform.h"
#include "SpriteRenderer.h"

namespace t
{
	MainMenuScene::MainMenuScene()
	{
	}
	MainMenuScene::~MainMenuScene()
	{
	}
	void MainMenuScene::Init()
	{
		Player* bg = new Player();
		Transform* tr = bg->AddComponent<Transform>();
		tr->SetPos(Vector2(0, 0));
		tr->SetName(L"TR");

		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		sr->SetName(L"SR");
		sr->ImageLoad(L"C:\\GithubProjects\\APIPortfolio\\Assets\\Texture2D\\vheart_title.png");

		AddGameObject(bg);
	}
	void MainMenuScene::Update()
	{
		Scene::Update();
	}
	void MainMenuScene::LateUpdate()
	{
		Scene::LateUpdate();
	}
	void MainMenuScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
}