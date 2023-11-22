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
	MainMenuScene::MainMenuScene():bg(nullptr),logo(nullptr)
	{
	}
	MainMenuScene::~MainMenuScene()
	{
	}
	void MainMenuScene::Init()
	{
		bg = object::Instantiate<GameObject>
			(enums::eLayerType::BackGround1, Vector2(0, 0));
		SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
		sr->ImageLoad(L"C:\\GithubProjects\\APIPortfolio\\Assets\\Hollow Knight sprites 1.4.3.2 (Voidheart edition)\\Menu\\controller_prompt_bg.png");
		sr->SetSize(Vector2(1600.0f, 900.0f));	//main의 window창 크기와 동일함


		logo = object::Instantiate<GameObject>
			(enums::eLayerType::BackGround2, Vector2(300.0f, 25.0f));
		SpriteRenderer* sr1 = logo->AddComponent<SpriteRenderer>();
		sr1->ImageLoad(L"C:\\GithubProjects\\APIPortfolio\\Assets\\Hollow Knight sprites 1.4.3.2 (Voidheart edition)\\Backend\\title.png");
		sr1->SetSize(Vector2(sr1->GetSize().x * 0.8f, sr1->GetSize().y * 0.8f));
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