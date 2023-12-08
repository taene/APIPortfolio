#include "tInput.h"
#include "tObject.h"
#include "tResources.h"
#include "tTexture.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "Camera.h"
#include "Renderer.h"
#include "Player.h"
#include "tAnimator.h"

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

		//BackGround
		/*GameObject* bg1 = object::Instantiate<GameObject>
			(enums::eLayerType::BackGround1, Vector2::Zero);
		SpriteRenderer* bg1Sr = bg1->AddComponent<SpriteRenderer>();
		graphics::Texture* bg1T = Resources::Find<graphics::Texture>(L"IGS_BG1");
		bg1Sr->SetTexture(bg1T);
		bg1Sr->SetSize(bg1Sr->GetTextureSize() * 3.0f);*/
		//cameraComp->SetTarget(bg1);

		//Player Head GameObject
		GameObject* head = object::Instantiate<GameObject>(enums::eLayerType::PlayerHead , Vector2::Zero);
		graphics::Texture* headT = Resources::Find<graphics::Texture>(L"Player_HeadDown");
		Transform* headTr = head->GetComponent<Transform>();
		headTr->SetScale(Vector2(3.0f , 3.0f));

		//Player Body GameObject
		GameObject* body = object::Instantiate<GameObject>(enums::eLayerType::PlayerBody , Vector2(0.0f , 65.0f));
		graphics::Texture* bodyT = Resources::Find<graphics::Texture>(L"Player_MoveBodyUpDown");
		Transform* bodyTr = body->GetComponent<Transform>();
		bodyTr->SetScale(Vector2(3.0f , 3.0f));

		//Player 
		Player* player = object::Instantiate<Player>(Vector2(100.0f , 100.0f));
		player->AddComponent<PlayerScript>();
		Transform* playerTr = player->GetComponent<Transform>();
		player->SetPlayerHeadBody(head , body);
		headTr->SetParent(playerTr);
		bodyTr->SetParent(playerTr);

		//Player Head Animation
		Animator* headAni = head->AddComponent<Animator>();
		headAni->CreateAnimation(L"PlayerHeadIdle" , headT, Vector2(0.0f , 0.0f) , Vector2(32.0f , 32.0f) ,
			Vector2(headTr->GetPosition().x / 2.0f , headTr->GetPosition().y / 2.0f) , 1 , 0.0f);
		headAni->CreateAnimation(L"PlayerHeadMoveDown" , headT, Vector2(0.0f , 0.0f) , Vector2(32.0f , 32.0f) ,
			Vector2(headTr->GetPosition().x / 2.0f , headTr->GetPosition().y / 2.0f) , 4 , 0.5f);
		graphics::Texture* headUpT = Resources::Find<graphics::Texture>(L"Player_HeadUp");
		headAni->CreateAnimation(L"PlayerHeadMoveUp" , headUpT , Vector2(0.0f , 0.0f) , Vector2(32.0f , 32.0f) ,
			Vector2(headTr->GetPosition().x / 2.0f , headTr->GetPosition().y / 2.0f) , 4 , 0.5f);
		graphics::Texture* headLeftT = Resources::Find<graphics::Texture>(L"Player_HeadLeft");
		headAni->CreateAnimation(L"PlayerHeadMoveLeft" , headLeftT , Vector2(0.0f , 0.0f) , Vector2(32.0f , 32.0f) ,
			Vector2(headTr->GetPosition().x / 2.0f , headTr->GetPosition().y / 2.0f) , 4 , 0.5f);
		graphics::Texture* headRightT = Resources::Find<graphics::Texture>(L"Player_HeadRight");
		headAni->CreateAnimation(L"PlayerHeadMoveRight" , headRightT , Vector2(0.0f , 0.0f) , Vector2(32.0f , 32.0f) ,
			Vector2(headTr->GetPosition().x / 2.0f , headTr->GetPosition().y / 2.0f) , 4 , 0.5f);

		//Player Body Animation
		Animator* bodyAni = body->AddComponent<Animator>();
		bodyAni->CreateAnimation(L"PlayerBodyIdle" , bodyT, Vector2(0.0f , 0.0f) , Vector2(32.0f , 32.0f) ,
			Vector2(bodyTr->GetPosition().x / 2.0f , bodyTr->GetPosition().y / 2.0f) , 1 , 0.0f);
		bodyAni->CreateAnimation(L"PlayerBodyMoveUpDown" , bodyT , Vector2(0.0f , 0.0f) , Vector2(32.0f , 32.0f) ,
			Vector2(bodyTr->GetPosition().x / 2.0f , bodyTr->GetPosition().y / 2.0f) , 20 , 0.5f);
		graphics::Texture* bodyLeftT = Resources::Find<graphics::Texture>(L"Player_MoveBodyLeft");
		headAni->CreateAnimation(L"PlayerBodyMoveLeft" , bodyLeftT , Vector2(0.0f , 0.0f) , Vector2(32.0f , 32.0f) ,
			Vector2(headTr->GetPosition().x / 2.0f , headTr->GetPosition().y / 2.0f) , 20 , 0.5f);
		graphics::Texture* bodyRightT = Resources::Find<graphics::Texture>(L"Player_MoveBodyRight");
		headAni->CreateAnimation(L"PlayerBodyMoveRight" , bodyRightT , Vector2(0.0f , 0.0f) , Vector2(32.0f , 32.0f) ,
			Vector2(headTr->GetPosition().x / 2.0f , headTr->GetPosition().y / 2.0f) , 20 , 0.5f);

		/*headAni->PlayAnimation(L"PlayerHeadIdle" , false);
		bodyAni->PlayAnimation(L"PlayerBodyIdle" , false);*/

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