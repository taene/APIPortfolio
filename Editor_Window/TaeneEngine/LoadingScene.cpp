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
		//배경
		bg = object::Instantiate<GameObject>
			(enums::eLayerType::BackGround1 , Vector2::Zero);
		graphics::Texture* bgT = Resources::Find<graphics::Texture>(L"LS_StartMenu");
		Animator* bgAni = bg->AddComponent<Animator>();
		Transform* bgTr = bg->GetComponent<Transform>();
		bgTr->SetScale(Vector2(3.0f , 3.0f));
		bgAni->CreateAnimation(L"StartMenu" , bgT
			, Vector2(0.0f , 0.0f) , Vector2(480.0f , 272.0f) ,
			Vector2(bgTr->GetPosition().x / 2.0f , bgTr->GetPosition().y / 2.0f) , 40 , 0.05f);
		bgAni->PlayAnimation(L"StartMenu");

		////로고
		//logo1 = object::Instantiate<GameObject>
		//	(enums::eLayerType::BackGround1, Vector2(612.5f, 150.f));

		//SpriteRenderer* lg1Sr = logo1->AddComponent<SpriteRenderer>();
		//graphics::Texture* lg1T = Resources::Find<graphics::Texture>(L"LS_Logo1");
		//lg1Sr->SetTexture(lg1T);
		//lg1Sr->SetSize(lg1Sr->GetTextureSize() * 1.5f);

		//logo2 = object::Instantiate<GameObject>
		//	(enums::eLayerType::BackGround1, Vector2(150.0f, 700.0f));

		//SpriteRenderer* lg2Sr = logo2->AddComponent<SpriteRenderer>();
		//graphics::Texture* lg2T = Resources::Find<graphics::Texture>(L"LS_Logo2");
		//lg2Sr->SetTexture(lg2T);
		//lg2Sr->SetSize(lg2Sr->GetTextureSize());
		

		//게임 오브젝트 생성후에 레이어와 게임오브젝트들의 init함수를 호출
		Scene::Init();
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
