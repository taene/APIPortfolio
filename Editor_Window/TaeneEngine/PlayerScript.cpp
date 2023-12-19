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

namespace t
{
	PlayerScript::PlayerScript()
		: mState(PlayerScript::eState::Idle)
		, player(nullptr) , head(nullptr) , body(nullptr) , headAni(nullptr) 
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

		Rigidbody* rb = GetOwner()->GetComponent<Rigidbody>();

		if ( Input::GetKeyPressed(eKeyCode::W) )
		{
			//pos.y -= mStatus.speed * Time::DeltaTime();
			rb->AddForce(Vector2::Up * mStatus.speed);
		}
		if ( Input::GetKeyPressed(eKeyCode::A) )
		{
			//pos.x -= mStatus.speed * Time::DeltaTime();
			rb->AddForce(Vector2::Left * mStatus.speed);
		}
		if ( Input::GetKeyPressed(eKeyCode::S) )
		{
			//pos.y += mStatus.speed * Time::DeltaTime();
			rb->AddForce(Vector2::Down * mStatus.speed);
		}
		if ( Input::GetKeyPressed(eKeyCode::D) )
		{
			//pos.x += mStatus.speed * Time::DeltaTime();
			rb->AddForce(Vector2::Right * mStatus.speed);
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
			|| Input::GetKeyUp(eKeyCode::Down) || Input::GetKeyUp(eKeyCode::Right) /*!isUp && !isLeft && !isDown && !isRight*/ )	//공격안함
		{
			isAttack = false;
			mState = PlayerScript::eState::Idle;
		}
	}

	void PlayerScript::shootBullet(Vector2 dir)
	{
		//머리방향 ㄴㄴ 총알은 총알이 알아서 움직이게 플레이어 개입 ㄴㄴ
		GameObject* bullet = nullptr;
		//Bullet
		if ( dir == Vector2::Up )
		{
			bullet = object::Instantiate<GameObject>(enums::eLayerType::Bullet , playerTr->GetPosition() + Vector2(5.0f , -40.0f));
			//bullets.push_back(bullet);
		}
		if ( dir == Vector2::Left )
		{
			bullet = object::Instantiate<GameObject>(enums::eLayerType::Bullet , playerTr->GetPosition() + Vector2(-60.0f , 10.0f));
			//bullets.push_back(bullet);
		}
		if ( dir == Vector2::Down )
		{
			bullet = object::Instantiate<GameObject>(enums::eLayerType::Bullet , playerTr->GetPosition() + Vector2(5.0f , 50.0f));
			//bullets.push_back(bullet);
		}
		if ( dir == Vector2::Right )
		{
			bullet = object::Instantiate<GameObject>(enums::eLayerType::Bullet , playerTr->GetPosition() + Vector2(70.0f , 10.0f));
			//bullets.push_back(bullet);
		}
		SpriteRenderer* bulletSr = bullet->AddComponent<SpriteRenderer>();
		BulletScript* bulletScript = bullet->AddComponent<BulletScript>();
		bulletScript->SetPlayer(player);
		bulletScript->SetDirection(dir);
		
		graphics::Texture* bulletT = Resources::Find<graphics::Texture>(L"Bullet");
		bulletSr->SetTexture(bulletT);
		bulletSr->SetSize(bulletSr->GetTextureSize() * 1.5f);
		Transform* bulletTr = bullet->GetComponent<Transform>();
		CircleCollider2D* bulletCollider = bullet->AddComponent<CircleCollider2D>();
		bulletCollider->SetSize(Vector2(0.3f , 0.3f));
		bulletCollider->SetOffset(Vector2(10.0f , 10.0f));
	}

	void PlayerScript::setBomb()
	{
		Transform* bodyTr = body->GetComponent<Transform>();
		GameObject* bomb = object::Instantiate<GameObject>(enums::eLayerType::InteractObject , bodyTr->GetPosition() + Vector2(30.0f , 30.0f));
		//SpriteRenderer* bombSr = bomb->AddComponent<SpriteRenderer>();
		Animator* bombAni = bomb->AddComponent<Animator>();
		graphics::Texture* bombPulseT = Resources::Find<graphics::Texture>(L"BombPulse");
		graphics::Texture* bombExplosionT = Resources::Find<graphics::Texture>(L"BombExplosion");
		bombAni->CreateAnimation(L"BombPulse" , bombPulseT , Vector2(0.0f , 0.0f) , Vector2(96.0f , 96.0f) , Vector2::Zero , 59 , 0.01f);
		bombAni->CreateAnimation(L"BombExplosion" , bombExplosionT , Vector2(0.0f , 0.0f) , Vector2(96.0f , 96.0f) , Vector2::Zero , 13 , 0.01f);
		
		//CircleCollider2D* bombCollider = bomb->AddComponent<CircleCollider2D>();
		//bombCollider->SetSize();
		//bombCollider->SetOffset();

		bombAni->PlayAnimation(L"BombPulse" , false);
		//위 애니메이션이 끝난 후 아래 애니메이션 실행
		float time = 0.0f;
		while ( time < 500.0f )
		{
			time += Time::DeltaTime();
			if ( bombAni->IsComplete() )
			{
				bombAni->PlayAnimation(L"BombExplosion" , false);
				time = 0.0f;
				break;
			}
			//time = 0.0f;
		}

		//BombExplosion 애니메이션이 다 끝나면 delete bomb
		while ( time < 500.0f )
		{
			time += Time::DeltaTime();
			if ( bombAni->IsComplete() )
			{
				delete bomb;
				bomb = nullptr;
				time = 0.0f;
				break;
			}
		}

		if ( Input::GetKeyUp(eKeyCode::E))
		{
			mState = PlayerScript::eState::Idle;
		}
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