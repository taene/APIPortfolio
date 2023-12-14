#include "tInput.h"
#include "tObject.h"
#include "tApplication.h"
#include "tResources.h"
#include "tTexture.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "Player.h"

//Scene
#include "SceneManager.h"
#include "MainMenuScene.h"
#include "InGameScene.h"

//Camera
#include "Camera.h"
#include "Renderer.h"
#include "CameraMoveScript.h"

extern t::Application application;

namespace t
{
	MainMenuScene::MainMenuScene()
		:button1(nullptr) , button2(nullptr)
	{}
	MainMenuScene::~MainMenuScene()
	{}
	void MainMenuScene::Init()
	{
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None , Vector2::Zero);
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;
		camera->AddComponent<CameraMoveScript>();

		GameObject* bg = object::Instantiate<GameObject>
			(enums::eLayerType::BackGround1 , Vector2(0 , 0));
		SpriteRenderer* bgSr = bg->AddComponent<SpriteRenderer>();
		graphics::Texture* bgT = Resources::Find<graphics::Texture>(L"MMS_Bg");
		bgSr->SetTexture(bgT);
		bgSr->SetSize(Vector2(bgSr->GetTextureSize().x * 3.0f , bgSr->GetTextureSize().y * 3.0f));

		GameObject* newRunMenu = object::Instantiate<GameObject>
			(enums::eLayerType::BackGround2 , Vector2(550.0f , 250.0f));
		SpriteRenderer* newRunMenuSr = newRunMenu->AddComponent<SpriteRenderer>();
		graphics::Texture* newRunMenuT = Resources::Find<graphics::Texture>(L"MMS_NewRunMenu");
		newRunMenuSr->SetTexture(newRunMenuT);
		newRunMenuSr->SetSize(Vector2(bgSr->GetTextureSize().x * 0.7f , bgSr->GetTextureSize().y * 0.7f));

		GameObject* outMenu = object::Instantiate<GameObject>
			(enums::eLayerType::BackGround2 , Vector2(550.0f , 400.0f));
		SpriteRenderer* outMenuSr = outMenu->AddComponent<SpriteRenderer>();
		graphics::Texture* outMenuT = Resources::Find<graphics::Texture>(L"MMS_OutMenu");
		outMenuSr->SetTexture(outMenuT);
		outMenuSr->SetSize(Vector2(bgSr->GetTextureSize().x * 0.5f , bgSr->GetTextureSize().y * 0.5f));

		button1 = object::Instantiate<GameObject>
			(enums::eLayerType::BackGround2 , Vector2(480.0f , 330.0f));
		SpriteRenderer* button1Sr = button1->AddComponent<SpriteRenderer>();
		graphics::Texture* button1T = Resources::Find<graphics::Texture>(L"MMS_Button");
		button1Sr->SetTexture(button1T);
		button1Sr->SetSize(Vector2(button1Sr->GetTextureSize().x * 3.0f , button1Sr->GetTextureSize().y * 3.0f));
		button1->SetActive(true);

		button2 = object::Instantiate<GameObject>
			(enums::eLayerType::BackGround2 , Vector2(500.0f , 430.0f));
		SpriteRenderer* button2Sr = button2->AddComponent<SpriteRenderer>();
		graphics::Texture* button2T = Resources::Find<graphics::Texture>(L"MMS_Button");
		button2Sr->SetTexture(button2T);
		button2Sr->SetSize(Vector2(button2Sr->GetTextureSize().x * 3.0f , button2Sr->GetTextureSize().y * 3.0f));
		button2->SetActive(false);

		Scene::Init();
	}
	void MainMenuScene::Start()
	{
		Scene::Start();
	}
	void MainMenuScene::Update()
	{
		Scene::Update();
	}
	void MainMenuScene::LateUpdate()
	{
		Scene::LateUpdate();
		switchScene();
	}
	void MainMenuScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		/*wchar_t str[50] = L"MainMenu Scene";
		TextOut(hdc, 0, 0, str, 14);*/
	}
	void MainMenuScene::OnEnter()
	{}
	void MainMenuScene::OnExit()
	{}
	void MainMenuScene::switchScene()
	{
		if ( Input::GetKeyDown(eKeyCode::Down) || Input::GetKeyDown(eKeyCode::Up) )
		{
			if ( button1->IsActive() && button2->IsPaused() )
			{
				button1->SetActive(false);
				button2->SetActive(true);
			}
			else if ( button1->IsPaused() && button2->IsActive() )
			{
				button1->SetActive(true);
				button2->SetActive(false);
			}
		}

		if ( ( Input::GetKeyDown(eKeyCode::Enter) || Input::GetKeyDown(eKeyCode::SpaceBar) )
			&& button1->IsActive() && button2->IsPaused() )
		{
			SceneManager::LoadScene(L"InGameScene");
		}
		else if ( ( Input::GetKeyDown(eKeyCode::Enter) || Input::GetKeyDown(eKeyCode::SpaceBar) )
			&& button2->IsActive() && button1->IsPaused() )
		{
			DestroyWindow(application.GetHwnd());
		}
	}
}