#include "LoadingScene.h"
#include "Player.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "tInput.h"
#include "MainMenuScene.h"
#include "SceneManager.h"
#include "tObject.h"
#include "tTexture.h"
#include "tResources.h"
#include "tAnimator.h"

//camera
#include "Camera.h"
#include "Renderer.h"
#include "CameraMoveScript.h"

namespace t
{
	LoadingScene::LoadingScene() :bg(nullptr)
	{
	}

	LoadingScene::~LoadingScene()
	{
	}

	void LoadingScene::Init()
	{
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None , Vector2::Zero);
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;
		camera->AddComponent<CameraMoveScript>();

		//배경
		bg = object::Instantiate<GameObject>(enums::eLayerType::BackGround1 , Vector2(240.0f,135.0f));
		graphics::Texture* bgT = Resources::Find<graphics::Texture>(L"LS_StartMenu");
		Animator* bgAni = bg->AddComponent<Animator>();
		Transform* bgTr = bg->GetComponent<Transform>();
		bgTr->SetScale(Vector2(3.0f , 3.0f));
		bgAni->CreateAnimation(L"StartMenu" , bgT
			, Vector2(0.0f , 0.0f) , Vector2(480.0f , 272.0f) ,
			Vector2::Zero , 40 , 0.05f);
		bgAni->PlayAnimation(L"StartMenu");


		//게임 오브젝트 생성후에 레이어와 게임오브젝트들의 init함수를 호출
		Scene::Init();
	}

	void LoadingScene::Start()
	{
		Scene::Start();
	}

	void LoadingScene::Update()
	{
		Scene::Update();
	}

	void LoadingScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input::GetKeyDown(eKeyCode::SpaceBar)|| Input::GetKeyDown(eKeyCode::Enter) )
		{
			SceneManager::LoadScene(L"MainMenuScene");
		}
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
