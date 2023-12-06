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
		, mAnimator(nullptr)
		, player(nullptr), head(nullptr),body(nullptr)
	{
	}
	PlayerScript::~PlayerScript()
	{
	}
	void PlayerScript::Init()
	{
		head = player->GetPlayerHead();
		body = player->GetPlayerBody();
	}
	void PlayerScript::Update()
	{
		if (mAnimator == nullptr)
		{
			
			mAnimator = GetOwner()->GetComponent<Animator>();
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
			damaged();
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
		
	}
	void PlayerScript::move()
	{
		Transform* tr = player->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (Input::GetKeyPressed(eKeyCode::D))
		{
			pos.x += 100.0f * Time::DeltaTime();
		}
		if (Input::GetKeyPressed(eKeyCode::A))
		{
			pos.x -= 100.0f * Time::DeltaTime();
		}
		if (Input::GetKeyPressed(eKeyCode::W))
		{
			pos.y -= 100.0f * Time::DeltaTime();
		}
		if (Input::GetKeyPressed(eKeyCode::S))
		{
			pos.y += 100.0f * Time::DeltaTime();
		}
		tr->SetPosition(pos);


		if (Input::GetKeyUp(eKeyCode::D) || Input::GetKeyUp(eKeyCode::A)
			|| Input::GetKeyUp(eKeyCode::W) || Input::GetKeyUp(eKeyCode::S))
		{
			mState = PlayerScript::eState::Idle;
			mAnimator->PlayAnimation(L"Idle", false);
		}
	}

	void PlayerScript::attack()
	{}

	void PlayerScript::damaged()
	{}
}