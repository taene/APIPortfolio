#include "MainMenuScene.h"
#include "Player.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "tInput.h"
#include "InGameScene.h"
#include "SceneManager.h"
#include "tObject.h"
#include "tTexture.h"
#include "tResources.h"

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
		graphics::Texture* tBg = Resources::Find<graphics::Texture>(L"MMS_BG");
		sr->SetTexture(tBg);
		sr->SetSize(Vector2(1600.f, 900.0f));


		logo = object::Instantiate<GameObject>
			(enums::eLayerType::BackGround2, Vector2(380.0f, 25.0f));
		SpriteRenderer* sr1 = logo->AddComponent<SpriteRenderer>();
		graphics::Texture* tLg = Resources::Find<graphics::Texture>(L"MMS_Title");
		sr1->SetTexture(tLg);
		sr1->SetSize(Vector2(sr1->GetTextureSize().x * 0.7f, sr1->GetTextureSize().y * 0.7f));


		Scene::Init();
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