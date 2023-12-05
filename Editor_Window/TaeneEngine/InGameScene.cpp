#include "tInput.h"
#include "tObject.h"
#include "tResources.h"
#include "tTexture.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "Camera.h"
#include "Renderer.h"
#include "Player.h"
//#include "tAnimator.h"

//Scene
#include "SceneManager.h"
#include "MainMenuScene.h"
#include "InGameScene.h"

//Script
#include "PlayerScript.h"
#include "CameraMoveScript.h"

namespace t
{
	InGameScene::InGameScene()
	{
	}
	InGameScene::~InGameScene()
	{
	}
	void InGameScene::Init()
	{
		//Camera
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None);
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;
		camera->AddComponent<CameraMoveScript>();

		//배경
		GameObject* bg1 = object::Instantiate<GameObject>
			(enums::eLayerType::BackGround1, Vector2::Zero);
		SpriteRenderer* bg1Sr = bg1->AddComponent<SpriteRenderer>();
		graphics::Texture* bg1T = Resources::Find<graphics::Texture>(L"IGS_BG1");
		bg1Sr->SetTexture(bg1T);
		bg1Sr->SetSize(bg1Sr->GetTextureSize() * 3.0f);
		//cameraComp->SetTarget(bg1);

		//Player* player = object::Instantiate<Player>(enums::eLayerType::Player , Vector2::Zero);

		//GameObject* bg2 = object::Instantiate<GameObject>
		//	(enums::eLayerType::BackGround1, Vector2(500, 0));
		//SpriteRenderer* bg2Sr = bg2->AddComponent<SpriteRenderer>();
		//graphics::Texture* bg2T = Resources::Find<graphics::Texture>(L"IGS_BG2");
		//bg2Sr->SetTexture(bg2T);
		//bg2Sr->SetSize(bg2Sr->GetTextureSize());



		Scene::Init();
	}
	void InGameScene::Update()
	{
		Scene::Update();
	}
	void InGameScene::LateUpdate()
	{
		/*if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"MainMenuScene");
		}*/

		Scene::LateUpdate();
	}
	void InGameScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}
	void InGameScene::OnEnter()
	{
	}
	void InGameScene::OnExit()
	{
	}
}