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
		, player(nullptr), head(nullptr),body(nullptr)
	{
	}
	PlayerScript::~PlayerScript()
	{
	}
	void PlayerScript::Init()
	{
	}
	void PlayerScript::Update()
	{
		if ( head == nullptr && body == nullptr )
		{
			head = player->GetPlayerHead();
			body = player->GetPlayerBody();
		}

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
	{
	}
	void PlayerScript::Render(HDC hdc)
	{
	}
	void PlayerScript::idle()
	{
		Animator* headAni = head->GetComponent<Animator>();
		Animator* bodyAni = body->GetComponent<Animator>();

		headAni->PlayAnimation(L"PlayerHeadIdle" , false);
		bodyAni->PlayAnimation(L"PlayerBodyIdle" , false);

		if ( Input::GetKeyPressed(eKeyCode::W) || Input::GetKeyPressed(eKeyCode::A)
			|| Input::GetKeyPressed(eKeyCode::S) || Input::GetKeyPressed(eKeyCode::D) )
		{
			mState = eState::Move;
			move();
		}

		if ( Input::GetKeyPressed(eKeyCode::Up)|| Input::GetKeyPressed(eKeyCode::Left)
			|| Input::GetKeyPressed(eKeyCode::Down) || Input::GetKeyPressed(eKeyCode::Right) )
		{
			mState = eState::Attack;
			attack();
		}
		
	}

	void PlayerScript::move()
	{
		Transform* tr = player->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		Animator* headAni = head->GetComponent<Animator>();
		Animator* bodyAni = body->GetComponent<Animator>();

		if ( Input::GetKeyPressed(eKeyCode::W) )
		{
			pos.y -= 100.0f * Time::DeltaTime();
			bodyAni->PlayAnimation(L"PlayerBodyMoveUpDown");
		}
		if ( Input::GetKeyPressed(eKeyCode::A) )
		{
			pos.x -= 100.0f * Time::DeltaTime();
			bodyAni->PlayAnimation(L"PlayerBodyMoveLeft");
		}
		if ( Input::GetKeyPressed(eKeyCode::S) )
		{
			pos.y += 100.0f * Time::DeltaTime();
			bodyAni->PlayAnimation(L"PlayerBodyMoveUpDown");
		}
		if ( Input::GetKeyPressed(eKeyCode::D) )
		{
			pos.x += 100.0f * Time::DeltaTime();
			bodyAni->PlayAnimation(L"PlayerBodyMoveRight");
		}
		
		tr->SetPosition(pos);

		if (Input::GetKeyUp(eKeyCode::D) || Input::GetKeyUp(eKeyCode::A)
			|| Input::GetKeyUp(eKeyCode::W) || Input::GetKeyUp(eKeyCode::S))
		{
			mState = PlayerScript::eState::Idle;
			headAni->PlayAnimation(L"PlayerHeadIdle", false);
			bodyAni->PlayAnimation(L"PlayerBodyIdle", false);
		}
	}

	void PlayerScript::attack()
	{
		Transform* tr = player->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		Animator* headAni = head->GetComponent<Animator>();
		Animator* bodyAni = body->GetComponent<Animator>();

		if ( Input::GetKeyPressed(eKeyCode::Up) )
		{
			headAni->PlayAnimation(L"PlayerHeadMoveUp");
		}
		if ( Input::GetKeyPressed(eKeyCode::Left) )
		{
			headAni->PlayAnimation(L"PlayerHeadMoveLeft");
		}
		if ( Input::GetKeyPressed(eKeyCode::Down) )
		{
			headAni->PlayAnimation(L"PlayerHeadMoveDown");
		}
		if ( Input::GetKeyPressed(eKeyCode::Right) )
		{
			headAni->PlayAnimation(L"PlayerHeadMoveRight");
		}

		if ( Input::GetKeyPressed(eKeyCode::Up) || Input::GetKeyPressed(eKeyCode::Left)
			|| Input::GetKeyPressed(eKeyCode::Down) || Input::GetKeyPressed(eKeyCode::Right) )
		{
			mState = PlayerScript::eState::Idle;
			headAni->PlayAnimation(L"PlayerHeadIdle" , false);
			bodyAni->PlayAnimation(L"PlayerBodyIdle" , false);
		}
	}

	void PlayerScript::onDamaged()
	{
	}
}