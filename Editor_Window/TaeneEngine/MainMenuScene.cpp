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
		//배경
		bg = object::Instantiate<GameObject>
			(enums::eLayerType::BackGround1, Vector2(0, 0));
		SpriteRenderer* bgSr = bg->AddComponent<SpriteRenderer>();
		graphics::Texture* tBg = Resources::Find<graphics::Texture>(L"MMS_BG");
		bgSr->SetTexture(tBg);
		bgSr->SetSize(Vector2(1600.f, 900.0f));

		//로고
		logo = object::Instantiate<GameObject>
			(enums::eLayerType::BackGround2, Vector2(380.0f, 25.0f));
		SpriteRenderer* lgSr = logo->AddComponent<SpriteRenderer>();
		graphics::Texture* lgT = Resources::Find<graphics::Texture>(L"MMS_Title");
		lgSr->SetTexture(lgT);
		lgSr->SetSize(Vector2(lgSr->GetTextureSize().x * 0.7f, lgSr->GetTextureSize().y * 0.7f));


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