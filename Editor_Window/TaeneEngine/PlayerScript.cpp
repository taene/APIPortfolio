#include "PlayerScript.h"
#include "tInput.h"
#include "Transform.h"
#include "tTime.h"
#include "tGameObject.h"
#include "tAnimator.h"
#include "tObject.h"
#include "tResources.h"
#include "SpriteRenderer.h"
#include "tCircleCollider2D.h"
#include "BulletScript.h"

namespace t
{
	PlayerScript::PlayerScript()
		: mState(PlayerScript::eState::Idle)
		, player(nullptr) , head(nullptr) , body(nullptr) , headAni(nullptr) , bodyAni(nullptr) , playerTr(nullptr)
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
			|| other->GetOwner()->GetLayerType() == eLayerType::InteractObject )
		{
			mState = PlayerScript::eState::Damaged;
		}
	}
	void PlayerScript::OnCollisionStay(Collider* other)
	{}
	void PlayerScript::OnCollisionExit(Collider* other)
	{}
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
		shootBullet();

		if ( Input::GetKeyUp(eKeyCode::Up) || Input::GetKeyUp(eKeyCode::Left)
			|| Input::GetKeyUp(eKeyCode::Down) || Input::GetKeyUp(eKeyCode::Right) /*!isUp && !isLeft && !isDown && !isRight*/ )	//공격안함
		{
			isAttack = false;
			mState = PlayerScript::eState::Idle;
		}
	}

	void PlayerScript::shootBullet()
	{
		//Bullet
		//미리 많이 만들어놓고 사용할것인지 만들고 지우고 할것인지 고민좀해보자
		GameObject* bullet = object::Instantiate<GameObject>(enums::eLayerType::Bullet , playerTr->GetPosition() + Vector2(100.0f , 5.0f));
		SpriteRenderer* bulletSr = bullet->AddComponent<SpriteRenderer>();
		bullet->AddComponent<BulletScript>();
		graphics::Texture* bulletT = Resources::Find<graphics::Texture>(L"Bullet");
		bulletSr->SetTexture(bulletT);
		bulletSr->SetSize(bulletSr->GetTextureSize() * 1.5f);
		Transform* bulletTr = bullet->GetComponent<Transform>();
		CircleCollider2D* bulletCollider = bullet->AddComponent<CircleCollider2D>();
		bulletCollider->SetSize(Vector2(0.3f , 0.3f));
		bulletCollider->SetOffset(Vector2(10.0f , 10.0f));
		bullet->SetActive(false);

		//쏜방향쪽으로 (4방향) 눈물발사
	}

	void PlayerScript::setBomb()
	{
		if ( Input::GetKeyDown(eKeyCode::E) )
		{
			GameObject* bomb = object::Instantiate<GameObject>(enums::eLayerType::InteractObject , playerTr->GetPosition());
			//SpriteRenderer* bombSr = bomb->AddComponent<SpriteRenderer>();
			graphics::Texture* bombPulseT = Resources::Find<graphics::Texture>(L"BombPulse");
			Animator* bombAni = bomb->AddComponent<Animator>();
			bombAni->CreateAnimation(L"BombPulse" , bombPulseT , Vector2(0.0f , 0.0f) , Vector2(722.0f , 583.0f) ,
			Vector2::Zero , 59 , 0.5f);

			//bombPulse 끝나고 애니메이션 재생할 폭발 애니메이션
			graphics::Texture* bombExplosionT = Resources::Find<graphics::Texture>(L"BombExplosion");
			//bombAni->CreateAnimation(L"BombExplosion" , bombExplosionT , Vector2(0.0f , 0.0f) , Vector2(722.0f , 583.0f) ,Vector2::Zero , 59 , 0.5f); 작업중-리소스 32비트임

			bombAni->PlayAnimation(L"BombPulse" , false);
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