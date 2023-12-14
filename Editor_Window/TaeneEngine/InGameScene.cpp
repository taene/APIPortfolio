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

//Collider
#include "tBoxCollider2D.h"
#include "tCircleCollider2D.h"
#include "tCollisionManager.h"

//Scene
#include "SceneManager.h"
#include "MainMenuScene.h"
#include "InGameScene.h"

//Script
#include "CameraMoveScript.h"
#include "PlayerScript.h"
#include "BulletScript.h"

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
		CollisionManager::CollisionLayerCheck(eLayerType::Player , eLayerType::Bullet , true);

		//Camera
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None);
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;
		camera->AddComponent<CameraMoveScript>();

		//BackGround
		GameObject* bg1 = object::Instantiate<GameObject>
			(enums::eLayerType::BackGround1, Vector2::Zero);
		SpriteRenderer* bg1Sr = bg1->AddComponent<SpriteRenderer>();
		graphics::Texture* bg1T = Resources::Find<graphics::Texture>(L"IGS_BG1");
		bg1Sr->SetTexture(bg1T);
		bg1Sr->SetSize(bg1Sr->GetTextureSize() * 3.0f);
		//cameraComp->SetTarget(bg1);

		//Player Head GameObject
		GameObject* head = object::Instantiate<GameObject>(enums::eLayerType::PlayerHead , Vector2::Zero);
		graphics::Texture* headT = Resources::Find<graphics::Texture>(L"Player_HeadDown");
		Transform* headTr = head->GetComponent<Transform>();
		headTr->SetScale(Vector2(3.0f , 3.0f));

		//Player Body GameObject
		GameObject* body = object::Instantiate<GameObject>(enums::eLayerType::PlayerBody , Vector2(0.0f , 30.0f));
		graphics::Texture* bodyT = Resources::Find<graphics::Texture>(L"Player_MoveBodyUpDown");
		Transform* bodyTr = body->GetComponent<Transform>();
		bodyTr->SetScale(Vector2(3.0f , 3.0f));

		//Player 
		Player* player = object::Instantiate<Player>(enums::eLayerType::Player, Vector2(200.0f , 200.0f));
		player->AddComponent<PlayerScript>()->SetPlayer(player);
		Transform* playerTr = player->GetComponent<Transform>();
		player->SetPlayerHeadBody(head , body);
		headTr->SetParent(playerTr);
		bodyTr->SetParent(playerTr);
		BoxCollider2D* playerCollider = player->AddComponent<BoxCollider2D>();
		//playerCollider->SetSize(Vector2(0.3f , 0.3f));
		playerCollider->SetOffset(Vector2(-20.0f , -15.0f));

		//object::DontDestroyOnLoad(player);
		//object::DontDestroyOnLoad(head);
		//object::DontDestroyOnLoad(body);

		//Player Head Animation
		Animator* headAni = head->AddComponent<Animator>();
		headAni->CreateAnimation(L"PlayerHeadIdle" , headT, Vector2(0.0f , 0.0f) , Vector2(32.0f , 32.0f) ,
			Vector2::Zero , 1 , 0.0f);
		headAni->CreateAnimation(L"PlayerHeadMoveDown" , headT, Vector2(0.0f , 0.0f) , Vector2(32.0f , 32.0f) ,
			Vector2::Zero , 4 , 0.15f);
		graphics::Texture* headUpT = Resources::Find<graphics::Texture>(L"Player_HeadUp");
		headAni->CreateAnimation(L"PlayerHeadIdleUp" , headUpT , Vector2(0.0f , 0.0f) , Vector2(32.0f , 32.0f) ,
			Vector2::Zero , 1 , 0.0f);
		headAni->CreateAnimation(L"PlayerHeadMoveUp" , headUpT , Vector2(0.0f , 0.0f) , Vector2(32.0f , 32.0f) ,
			Vector2::Zero , 4 , 0.15f);
		graphics::Texture* headLeftT = Resources::Find<graphics::Texture>(L"Player_HeadLeft");
		headAni->CreateAnimation(L"PlayerHeadIdleLeft" , headLeftT , Vector2(0.0f , 0.0f) , Vector2(32.0f , 32.0f) ,
			Vector2::Zero , 1 , 0.0f);
		headAni->CreateAnimation(L"PlayerHeadMoveLeft" , headLeftT , Vector2(0.0f , 0.0f) , Vector2(32.0f , 32.0f) ,
			Vector2::Zero , 4 , 0.15f);
		graphics::Texture* headRightT = Resources::Find<graphics::Texture>(L"Player_HeadRight");
		headAni->CreateAnimation(L"PlayerHeadIdleRight" , headRightT , Vector2(0.0f , 0.0f) , Vector2(32.0f , 32.0f) ,
			Vector2::Zero , 1 , 0.0f);
		headAni->CreateAnimation(L"PlayerHeadMoveRight" , headRightT , Vector2(0.0f , 0.0f) , Vector2(32.0f , 32.0f) ,
			Vector2::Zero , 4 , 0.15f);

		//Player Body Animation
		Animator* bodyAni = body->AddComponent<Animator>();
		bodyAni->CreateAnimation(L"PlayerBodyIdle" , bodyT, Vector2(0.0f , 0.0f) , Vector2(32.0f , 32.0f) ,
			Vector2::Zero , 1 , 0.0f);
		bodyAni->CreateAnimation(L"PlayerBodyMoveUpDown" , bodyT , Vector2(0.0f , 0.0f) , Vector2(32.0f , 32.0f) ,
			Vector2::Zero , 20 , 0.1f);
		graphics::Texture* bodyLeftT = Resources::Find<graphics::Texture>(L"Player_MoveBodyLeft");
		bodyAni->CreateAnimation(L"PlayerBodyMoveLeft" , bodyLeftT , Vector2(0.0f , 0.0f) , Vector2(32.0f , 32.0f) ,
			Vector2::Zero , 20 , 0.1f);
		graphics::Texture* bodyRightT = Resources::Find<graphics::Texture>(L"Player_MoveBodyRight");
		bodyAni->CreateAnimation(L"PlayerBodyMoveRight" , bodyRightT , Vector2(0.0f , 0.0f) , Vector2(32.0f , 32.0f) ,
			Vector2::Zero , 20 , 0.1f);

		//Bullet
		GameObject* bullet = object::Instantiate<GameObject>(enums::eLayerType::Bullet , Vector2(100.0f , 5.0f));
		SpriteRenderer* bulletSr = bullet->AddComponent<SpriteRenderer>();
		bullet->AddComponent<BulletScript>();
		graphics::Texture* bulletT = Resources::Find<graphics::Texture>(L"Bullet");
		bulletSr->SetTexture(bulletT);
		bulletSr->SetSize(bulletSr->GetTextureSize() * 1.5f);
		Transform* bulletTr = bullet->GetComponent<Transform>();

		CircleCollider2D* bulletCollider = bullet->AddComponent<CircleCollider2D>();
		//bulletCollider->SetSize(Vector2(0.3f , 0.3f));
		bulletCollider->SetOffset(Vector2(10.0f , 10.0f));
		//bulletTr->SetScale(Vector2(3.0f , 3.0f));
		//bulletTr->SetParent(playerTr);

		Scene::Init();
	}
	void InGameScene::Start()
	{
		Scene::Start();
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