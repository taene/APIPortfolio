#include "PlayerScript.h"
#include "tInput.h"
#include "Transform.h"
#include "tTime.h"
#include "tGameObject.h"
#include "tAnimator.h"
#include "tObject.h"
#include "tResources.h"

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
		int a = rand() % 2;
		if ( a == 1 )
		{
			other->GetOwner()->GetComponent<Transform>()->SetPosition(Vector2(400.0f , 500.0f));
		}
		else
		{
			other->GetOwner()->GetComponent<Transform>()->SetPosition(Vector2(200.0f , 500.0f));
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

		if ( !isMove )
		{
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

		if ( Input::GetKeyUp(eKeyCode::Up) || Input::GetKeyUp(eKeyCode::Left)
			|| Input::GetKeyUp(eKeyCode::Down) || Input::GetKeyUp(eKeyCode::Right) /*!isUp && !isLeft && !isDown && !isRight*/ )	//공격안함
		{
			isAttack = false;
			mState = PlayerScript::eState::Idle;
		}
	}

	void PlayerScript::onDamaged()
	{}

}