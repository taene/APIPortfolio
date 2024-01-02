#include "PlayerScript.h"
#include "tInput.h"
#include "tTime.h"
#include "tObject.h"
#include "tGameObject.h"
#include "Transform.h"
#include "tAnimator.h"
#include "tRigidbody.h"
#include "SpriteRenderer.h"
#include "tResources.h"
#include "tCircleCollider2D.h"
#include "BulletScript.h"
#include "BulletPoolManager.h"
#include "Bullet.h"

namespace t
{
	PlayerScript::PlayerScript()
		: mState(PlayerScript::eState::Idle)
		, player(nullptr) , head(nullptr) , body(nullptr) , headAni(nullptr) , bomb(nullptr)
		, bodyAni(nullptr) , playerTr(nullptr)
		, mStatus()
		, isMove(false) , isAttack(false)
		, isUp(false) , isDown(false) , isLeft(false) , isRight(false)
	{}
	PlayerScript::~PlayerScript()
	{}
	void PlayerScript::Init()
	{}
	void PlayerScript::Start()
	{
		head = player->GetPlayerHead();
		body = player->GetPlayerBody();
		headAni = head->GetComponent<Animator>();
		bodyAni = body->GetComponent<Animator>();
		playerTr = player->GetComponent<Transform>();
	}
	void PlayerScript::Update()
	{
		switch ( mState )
		{
		case t::PlayerScript::eState::Idle:
			idle();
			break;
		case t::PlayerScript::eState::Move:
			move();
			break;
		case t::PlayerScript::eState::Attack:
			attack();
			break;
		case t::PlayerScript::eState::GetItem:
			
			break;
		case t::PlayerScript::eState::Bomb:
			setBomb();
			break;
		case t::PlayerScript::eState::Damaged:
			onDamaged();
			break;
		default:
			break;
		}
	}
	void PlayerScript::LateUpdate()
	{}
	void PlayerScript::Render(HDC hdc)
	{}
	void PlayerScript::OnCollisionEnter(Collider* other)
	{
		if ( other->GetOwner()->GetLayerType() == eLayerType::Enemy
			/*|| other->GetOwner()->GetLayerType() == eLayerType::InteractObject*/ )
		{
			mState = PlayerScript::eState::Damaged;
		}
	}
	void PlayerScript::OnCollisionStay(Collider* other)
	{}
	void PlayerScript::OnCollisionExit(Collider* other)
	{}
	void PlayerScript::DeleteBomb(GameObject* bomb)
	{
		delete bomb;
		bomb = nullptr;
	}
	void PlayerScript::idle()
	{
		headAni->PlayAnimation(L"PlayerHeadIdle" , false);
		bodyAni->PlayAnimation(L"PlayerBodyIdle" , false);

		if ( Input::GetKeyPressed(eKeyCode::W) )
		{
			headAni->PlayAnimation(L"PlayerHeadIdleUp" , false);
			bodyAni->PlayAnimation(L"PlayerBodyMoveUpDown");
			mState = PlayerScript::eState::Move;
		}
		if ( Input::GetKeyPressed(eKeyCode::A) )
		{
			headAni->PlayAnimation(L"PlayerHeadIdleLeft" , false);
			bodyAni->PlayAnimation(L"PlayerBodyMoveLeft");
			mState = PlayerScript::eState::Move;
		}
		if ( Input::GetKeyPressed(eKeyCode::S) )
		{
			headAni->PlayAnimation(L"PlayerHeadIdle" , false);
			bodyAni->PlayAnimation(L"PlayerBodyMoveUpDown");
			mState = PlayerScript::eState::Move;
		}
		if ( Input::GetKeyPressed(eKeyCode::D) )
		{
			headAni->PlayAnimation(L"PlayerHeadIdleRight" , false);
			bodyAni->PlayAnimation(L"PlayerBodyMoveRight");
			mState = PlayerScript::eState::Move;
		}

		if ( Input::GetKeyPressed(eKeyCode::Up) )
		{
			isAttack = true;
			headAni->PlayAnimation(L"PlayerHeadMoveUp");
			mState = PlayerScript::eState::Attack;
		}
		if ( Input::GetKeyPressed(eKeyCode::Left) )
		{
			isAttack = true;
			headAni->PlayAnimation(L"PlayerHeadMoveLeft");
			mState = PlayerScript::eState::Attack;
		}
		if ( Input::GetKeyPressed(eKeyCode::Down) )
		{
			isAttack = true;
			headAni->PlayAnimation(L"PlayerHeadMoveDown");
			mState = PlayerScript::eState::Attack;
		}
		if ( Input::GetKeyPressed(eKeyCode::Right) )
		{
			isAttack = true;
			headAni->PlayAnimation(L"PlayerHeadMoveRight");
			mState = PlayerScript::eState::Attack;
		}

		if ( Input::GetKeyDown(eKeyCode::E) )
		{
			mState = PlayerScript::eState::Bomb;
		}

	}

	void PlayerScript::move()
	{
		isMove = true;

		Vector2 pos = playerTr->GetPosition();

		//Rigidbody* rb = GetOwner()->GetComponent<Rigidbody>();

		if ( Input::GetKeyPressed(eKeyCode::W) )
		{
			pos.y -= mStatus.speed * Time::DeltaTime();
			//rb->AddForce(Vector2::Up * mStatus.speed);
		}
		if ( Input::GetKeyPressed(eKeyCode::A) )
		{
			pos.x -= mStatus.speed * Time::DeltaTime();
			//rb->AddForce(Vector2::Left * mStatus.speed);
		}
		if ( Input::GetKeyPressed(eKeyCode::S) )
		{
			pos.y += mStatus.speed * Time::DeltaTime();
			//rb->AddForce(Vector2::Down * mStatus.speed);
		}
		if ( Input::GetKeyPressed(eKeyCode::D) )
		{
			pos.x += mStatus.speed * Time::DeltaTime();
			//rb->AddForce(Vector2::Right * mStatus.speed);
		}

		playerTr->SetPosition(pos);

		if ( Input::GetKeyPressed(eKeyCode::Up) )
		{
			isAttack = true;
			isUp = true;
			headAni->PlayAnimation(L"PlayerHeadMoveUp");
			mState = PlayerScript::eState::Attack;
		}
		if ( Input::GetKeyPressed(eKeyCode::Left) )
		{
			isAttack = true;
			isLeft = true;
			headAni->PlayAnimation(L"PlayerHeadMoveLeft");
			mState = PlayerScript::eState::Attack;
		}
		if ( Input::GetKeyPressed(eKeyCode::Down) )
		{
			isAttack = true;
			isDown = true;
			headAni->PlayAnimation(L"PlayerHeadMoveDown");
			mState = PlayerScript::eState::Attack;
		}
		if ( Input::GetKeyPressed(eKeyCode::Right) )
		{
			isAttack = true;
			isRight = true;
			headAni->PlayAnimation(L"PlayerHeadMoveRight");
			mState = PlayerScript::eState::Attack;
		}

		if ( Input::GetKeyDown(eKeyCode::E) )
		{
			mState = PlayerScript::eState::Bomb;
		}

		if ( Input::GetKeyUp(eKeyCode::D) || Input::GetKeyUp(eKeyCode::A)
			|| Input::GetKeyUp(eKeyCode::W) || Input::GetKeyUp(eKeyCode::S) )
		{
			isMove = false;
			mState = PlayerScript::eState::Idle;
		}
	}

	void PlayerScript::attack()
	{
		isAttack = true;

		Vector2 pos = playerTr->GetPosition();

		if ( Input::GetKeyPressed(eKeyCode::W) )
		{
			pos.y -= mStatus.speed * Time::DeltaTime();
		}
		if ( Input::GetKeyPressed(eKeyCode::A) )
		{
			pos.x -= mStatus.speed * Time::DeltaTime();
		}
		if ( Input::GetKeyPressed(eKeyCode::S) )
		{
			pos.y += mStatus.speed * Time::DeltaTime();
		}
		if ( Input::GetKeyPressed(eKeyCode::D) )
		{
			pos.x += mStatus.speed * Time::DeltaTime();
		}

		playerTr->SetPosition(pos);

		//attack 로직
		if ( Input::GetKeyPressed(eKeyCode::Up) )
		{
			shootBullet(Vector2::Up);
		}
		if ( Input::GetKeyPressed(eKeyCode::Left) )
		{
			shootBullet(Vector2::Left);
		}
		if ( Input::GetKeyPressed(eKeyCode::Down) )
		{
			shootBullet(Vector2::Down);
		}
		if ( Input::GetKeyPressed(eKeyCode::Right) )
		{
			shootBullet(Vector2::Right);
		}
		

		if ( Input::GetKeyUp(eKeyCode::Up) || Input::GetKeyUp(eKeyCode::Left)
			|| Input::GetKeyUp(eKeyCode::Down) || Input::GetKeyUp(eKeyCode::Right) )
		{
			isAttack = false;
			mState = PlayerScript::eState::Idle;
		}
	}

	void PlayerScript::shootBullet(Vector2 dir)
	{
		//Bullet
		if ( dir == Vector2::Up )
		{
			Bullet* bullet = BulletPoolManager::GetBullet();
			bullet->GetComponent<Transform>()->SetPosition(playerTr->GetPosition() + Vector2(5.0f , -40.0f));
			bullet->GetComponent<BulletScript>()->SetDirection(dir);
			//bullet = object::Instantiate<GameObject>(enums::eLayerType::Bullet , playerTr->GetPosition() + Vector2(5.0f , -40.0f));
		}
		if ( dir == Vector2::Left )
		{
			Bullet* bullet = BulletPoolManager::GetBullet();
			bullet->GetComponent<Transform>()->SetPosition(playerTr->GetPosition() + Vector2(-60.0f , 10.0f));
			bullet->GetComponent<BulletScript>()->SetDirection(dir);
			//bullet = object::Instantiate<GameObject>(enums::eLayerType::Bullet , playerTr->GetPosition() + Vector2(-60.0f , 10.0f));
		}
		if ( dir == Vector2::Down )
		{
			Bullet* bullet = BulletPoolManager::GetBullet();
			bullet->GetComponent<Transform>()->SetPosition(playerTr->GetPosition() + Vector2(5.0f , 50.0f));
			bullet->GetComponent<BulletScript>()->SetDirection(dir);
			//bullet = object::Instantiate<GameObject>(enums::eLayerType::Bullet , playerTr->GetPosition() + Vector2(5.0f , 50.0f));
		}
		if ( dir == Vector2::Right )
		{
			Bullet* bullet = BulletPoolManager::GetBullet();
			bullet->GetComponent<Transform>()->SetPosition(playerTr->GetPosition() + Vector2(70.0f , 10.0f));
			bullet->GetComponent<BulletScript>()->SetDirection(dir);
			//bullet = object::Instantiate<GameObject>(enums::eLayerType::Bullet , playerTr->GetPosition() + Vector2(70.0f , 10.0f));
		}
	}

	void PlayerScript::setBomb()
	{
		Transform* bodyTr = body->GetComponent<Transform>();
		bomb = object::Instantiate<GameObject>(enums::eLayerType::InteractObject , bodyTr->GetPosition() + Vector2(30.0f , 30.0f));
		Transform* bombTr = bomb->GetComponent<Transform>();
		Animator* bombAni = bomb->AddComponent<Animator>();
		graphics::Texture* bombPulseT = Resources::Find<graphics::Texture>(L"BombPulse");
		bombAni->CreateAnimation(L"BombPulse" , bombPulseT , Vector2(0.0f , 0.0f) , Vector2(96.0f , 96.0f) , Vector2::Zero , 59 , 0.01f);
		CircleCollider2D* bombCollider = bomb->AddComponent<CircleCollider2D>();
		bombCollider->SetSize(Vector2(0.5f , 0.5f));
		bombCollider->SetOffset(Vector2(-21.0f , -10.0f));

		bombAni->GetCompleteEvent(L"BombPulse") = std::bind(&PlayerScript::setExplosion , this);

		bombAni->PlayAnimation(L"BombPulse" , false);

		//BombExplosion 애니메이션이 다 끝나면 delete bomb 후 bombExplosion 게임오브젝트를 만드는 이벤트함수를 걸어서
		//bombExplosion 애니메이션 실행하고 콜라이더도 따로 설정
		

		if ( Input::GetKeyUp(eKeyCode::E))
		{
			mState = PlayerScript::eState::Idle;
		}
	}

	void PlayerScript::setExplosion()
	{
		Transform* bombTr = bomb->GetComponent<Transform>();
		GameObject* bombExplosion = object::Instantiate<GameObject>(enums::eLayerType::Effect , bombTr->GetPosition());
		Animator* bombExplosionAni = bombExplosion->AddComponent<Animator>();
		graphics::Texture* bombExplosionT = Resources::Find<graphics::Texture>(L"BombExplosion");
		bombExplosionAni->CreateAnimation(L"BombExplosion" , bombExplosionT , Vector2(0.0f , 0.0f) , Vector2(96.0f , 96.0f) , Vector2::Zero , 13 , 0.01f);
		CircleCollider2D* bombExplosionCollider = bombExplosion->AddComponent<CircleCollider2D>();
		bombExplosionCollider->SetSize(Vector2(1.0f , 1.0f));
		bombExplosionCollider->SetOffset(Vector2(-21.0f , -10.0f));

		bombExplosionAni->PlayAnimation(L"BombExplosion");
	}

	void PlayerScript::onDamaged()
	{
		//데미지 받을때 애니메이션
		//headAni->PlayAnimation(L"PlayerHeadDamaged" , false);
		//bodyAni->PlayAnimation(L"PlayerBodyDamaged" , false);

		int a = 0;

		Vector2 pos = playerTr->GetPosition();



	}

}