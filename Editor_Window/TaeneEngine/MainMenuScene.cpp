#include "MainMenuScene.h"
#include "Player.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "tInput.h"
#include "InGameScene.h"
#include "SceneManager.h"
#include "tObject.h"

namespace t
{
	MainMenuScene::MainMenuScene():bg(nullptr)
	{
	}
	MainMenuScene::~MainMenuScene()
	{
	}
	void MainMenuScene::Init()
	{
		/*bg = new Player();
		Transform* tr = bg->AddComponent<Transform>();
		tr->SetPosition(Vector2(0, 0));
		tr->SetName(L"TR");
		
		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		sr->SetName(L"SR");
		sr->ImageLoad(L"C:\\GithubProjects\\APIPortfolio\\Assets\\Hollow Knight sprites 1.4.3.2 (Voidheart edition)\\Menu\\controller_prompt_bg.png");

		AddGameObject(bg, enums::eLayerType::BackGround);*/
		bg = object::Instantiate<Player>
			(enums::eLayerType::BackGround, Vector2(0,0));
		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		sr->ImageLoad(L"C:\\GithubProjects\\APIPortfolio\\Assets\\Hollow Knight sprites 1.4.3.2 (Voidheart edition)\\Menu\\controller_prompt_bg.png");
	}
	void MainMenuScene::Update()
	{
		Scene::Update();
	}
	void MainMenuScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"InGameScene");
		}
	}
	void MainMenuScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		wchar_t str[50] = L"MainMenu Scene";
		TextOut(hdc, 0, 0, str, 14);
	}
	void MainMenuScene::OnEnter()
	{
	}
	void MainMenuScene::OnExit()
	{
	}
}