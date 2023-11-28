#include "tInput.h"
#include "tObject.h"
#include "tResources.h"
#include "tTexture.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "Player.h"

//Scene
#include "SceneManager.h"
#include "MainMenuScene.h"
#include "InGameScene.h"

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
		GameObject* bg = object::Instantiate<GameObject>
			(enums::eLayerType::BackGround1, Vector2(0, 0));
		SpriteRenderer* bgSr = bg->AddComponent<SpriteRenderer>();
		graphics::Texture* tBg = Resources::Find<graphics::Texture>(L"MMS_BG");
		bgSr->SetTexture(tBg);
		bgSr->SetSize(Vector2(bgSr->GetTextureSize().x, bgSr->GetTextureSize().y));

		GameObject* bgObj1 = object::Instantiate<GameObject>
			(enums::eLayerType::BackGround2, Vector2(-150.0f, -50.0f));
		SpriteRenderer* bgObj1Sr = bgObj1->AddComponent<SpriteRenderer>();
		graphics::Texture* bgObj1T = Resources::Find<graphics::Texture>(L"MMS_bg1");
		bgObj1Sr->SetTexture(bgObj1T);
		bgObj1Sr->SetSize(Vector2(bgObj1Sr->GetTextureSize().x * 0.8f, bgObj1Sr->GetTextureSize().y * 0.8f));

		GameObject* bgObj2 = object::Instantiate<GameObject>
			(enums::eLayerType::BackGround2, Vector2(400.0f, 25.0f));
		SpriteRenderer* bgObj2Sr = bgObj2->AddComponent<SpriteRenderer>();
		graphics::Texture* bgObj2T = Resources::Find<graphics::Texture>(L"MMS_bg2");
		bgObj2Sr->SetTexture(bgObj2T);
		bgObj2Sr->SetSize(Vector2(bgObj2Sr->GetTextureSize().x * 0.8f, bgObj2Sr->GetTextureSize().y * 0.8f));

		GameObject* bgObj3 = object::Instantiate<GameObject>
			(enums::eLayerType::BackGround2, Vector2(1200.0f, -25.0f));
		SpriteRenderer* bgObj3Sr = bgObj3->AddComponent<SpriteRenderer>();
		graphics::Texture* bgObj3T = Resources::Find<graphics::Texture>(L"MMS_bg3");
		bgObj3Sr->SetTexture(bgObj3T);
		bgObj3Sr->SetSize(Vector2(bgObj3Sr->GetTextureSize().x * 0.8f, bgObj3Sr->GetTextureSize().y * 0.8f));

		GameObject* bgObj4 = object::Instantiate<GameObject>
			(enums::eLayerType::BackGround2, Vector2(300.0f, 400.0f));
		SpriteRenderer* bgObj4Sr = bgObj4->AddComponent<SpriteRenderer>();
		graphics::Texture* bgObj4T = Resources::Find<graphics::Texture>(L"MMS_bg4");
		bgObj4Sr->SetTexture(bgObj4T);
		bgObj4Sr->SetSize(Vector2(bgObj4Sr->GetTextureSize().x * 0.8f, bgObj4Sr->GetTextureSize().y * 0.8f));

		GameObject* bgObj5 = object::Instantiate<GameObject>
			(enums::eLayerType::BackGround2, Vector2(500.0f, 580.0f));
		SpriteRenderer* bgObj5Sr = bgObj5->AddComponent<SpriteRenderer>();
		graphics::Texture* bgObj5T = Resources::Find<graphics::Texture>(L"MMS_bg5");
		bgObj5Sr->SetTexture(bgObj5T);
		bgObj5Sr->SetSize(Vector2(bgObj5Sr->GetTextureSize().x * 0.8f, bgObj5Sr->GetTextureSize().y * 0.8f));

		GameObject* bgObj6 = object::Instantiate<GameObject>
			(enums::eLayerType::BackGround2, Vector2(1200.0f, 600.0f));
		SpriteRenderer* bgObj6Sr = bgObj6->AddComponent<SpriteRenderer>();
		graphics::Texture* bgObj6T = Resources::Find<graphics::Texture>(L"MMS_bg6");
		bgObj6Sr->SetTexture(bgObj6T);
		bgObj6Sr->SetSize(Vector2(bgObj6Sr->GetTextureSize().x * 0.8f, bgObj6Sr->GetTextureSize().y * 0.8f));

		GameObject* bgObj7 = object::Instantiate<GameObject>
			(enums::eLayerType::BackGround2, Vector2(1400.0f, 300.0f));
		SpriteRenderer* bgObj7Sr = bgObj7->AddComponent<SpriteRenderer>();
		graphics::Texture* bgObj7T = Resources::Find<graphics::Texture>(L"MMS_bg7");
		bgObj7Sr->SetTexture(bgObj7T);
		bgObj7Sr->SetSize(Vector2(bgObj7Sr->GetTextureSize().x * 0.8f, bgObj7Sr->GetTextureSize().y * 0.8f));

		GameObject* bgObj8 = object::Instantiate<GameObject>
			(enums::eLayerType::BackGround2, Vector2(730.0f, 380.0f));
		SpriteRenderer* bgObj8Sr = bgObj8->AddComponent<SpriteRenderer>();
		graphics::Texture* bgObj8T = Resources::Find<graphics::Texture>(L"MMS_bg8");
		bgObj8Sr->SetTexture(bgObj8T);
		bgObj8Sr->SetSize(Vector2(bgObj8Sr->GetTextureSize().x * 0.8f, bgObj8Sr->GetTextureSize().y * 0.8f));


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