#include "tInput.h"
#include "tObject.h"
#include "tResources.h"
#include "Renderer.h"

//Component
#include "tTexture.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "Camera.h"
#include "tAnimator.h"
#include "tRigidbody.h"

//Tile
#include "TilemapRenderer.h"
#include "Tile.h"

//Collider
#include "tBoxCollider2D.h"
#include "tCircleCollider2D.h"
#include "tCollisionManager.h"

//Scene
#include "SceneManager.h"
#include "MainMenuScene.h"
#include "InGameScene.h"

//Contents
#include "Player.h"
#include "Enemy.h"

//Script
#include "CameraMoveScript.h"
#include "PlayerScript.h"
#include "BulletScript.h"
#include "EnemyScript.h"


//PoolManager
#include "BulletPoolManager.h"


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
		//mapTileFileSaveLoad();

		//Camera
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None);
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;
		camera->AddComponent<CameraMoveScript>();

		//BackGround
		GameObject* bg1 = object::Instantiate<GameObject>
			(enums::eLayerType::BackGround1 , Vector2(0.0f , -5.0f));
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
		//player->AddComponent<Rigidbody>();
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
		//std::vector<GameObject*> bullets = {};
		//bullets.resize(100);
		//1) 100개 만들어놓고 setfalse하고 setTrue로 하면서 사용하다가 2) setfalse인 총알이 배열에 없으면 또만들기?

		for ( int i = 0; i < 1000; i++ )
		{
			Bullet* bullet = BulletPoolManager::SetBullet();
			bullet->SetPlayerHead(head);
			SpriteRenderer* bulletSr = bullet->AddComponent<SpriteRenderer>();
			BulletScript* bulletScript = bullet->AddComponent<BulletScript>();
			Rigidbody* bulletRb = bullet->AddComponent<Rigidbody>();
			bulletScript->SetPlayerInScript(player);
			bulletScript->SetBulletInScript(bullet);
			//bulletScript->SetDirection(dir);

			graphics::Texture* bulletT = Resources::Find<graphics::Texture>(L"Bullet");
			bulletSr->SetTexture(bulletT);
			bulletSr->SetSize(bulletSr->GetTextureSize() * 1.5f);
			Transform* bulletTr = bullet->GetComponent<Transform>();

			CircleCollider2D* bulletCollider = bullet->AddComponent<CircleCollider2D>();
			bulletCollider->SetSize(Vector2(0.3f , 0.3f));
			bulletCollider->SetOffset(Vector2(10.0f , 10.0f));

			bullet->SetActive(false);
		}
		
		//Enemy
		Enemy* enemy = object::Instantiate<Enemy>(enums::eLayerType::Player , Vector2(400.0f , 200.0f));
		enemy->AddComponent<EnemyScript>()->SetTarget(player);
		CircleCollider2D* enemyCollider = enemy->AddComponent<CircleCollider2D>();
		enemyCollider->SetSize(Vector2(0.3f , 0.3f));
		//enemyCollider->SetOffset(Vector2(-20.0f , -15.0f));
		//bomb Animation


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
		CollisionManager::CollisionLayerCheck(eLayerType::Player , eLayerType::Bullet , true);
		CollisionManager::CollisionLayerCheck(eLayerType::Player , eLayerType::Enemy , true);
		CollisionManager::CollisionLayerCheck(eLayerType::Player , eLayerType::InteractObject , true);
		CollisionManager::CollisionLayerCheck(eLayerType::Enemy , eLayerType::InteractObject , true);
		CollisionManager::CollisionLayerCheck(eLayerType::Enemy , eLayerType::Bullet , true);
	}
	void InGameScene::OnExit()
	{
	}
	void InGameScene::mapTileFileSaveLoad()
	{
		FILE* pFile = nullptr;
		_wfopen_s(&pFile , L"..\\Resources\\Test" , L"rb");

		while ( true )
		{
			int idxX = 0;
			int idxY = 0;

			int posX = 0;
			int posY = 0;


			if ( fread(&idxX , sizeof(int) , 1 , pFile) == NULL )
				break;
			if ( fread(&idxY , sizeof(int) , 1 , pFile) == NULL )
				break;
			if ( fread(&posX , sizeof(int) , 1 , pFile) == NULL )
				break;
			if ( fread(&posY , sizeof(int) , 1 , pFile) == NULL )
				break;

			Tile* tile = object::Instantiate<Tile>(eLayerType::MapTile , Vector2(posX , posY));
			TilemapRenderer* tmr = tile->AddComponent<TilemapRenderer>();
			tmr->SetTexture(Resources::Find<graphics::Texture>(L"basementTile"));
			tmr->SetIndex(Vector2(idxX , idxY));
		}

		fclose(pFile);
	}
}