#include "Player.h"
#include "tInput.h"
#include "Transform.h"
#include "tTime.h"
#include "tObject.h"
#include "tTexture.h"
#include "tResources.h"
#include "tAnimator.h"
#include "SpriteRenderer.h"

namespace t
{
	void Player::Init()
	{
		GameObject::Init();

		mHead->Init();
		mBody->Init();
	}

	void Player::Start()
	{
		GameObject::Start();

		mHead->Start();
		mBody->Start();
	}

	void Player::Update()
	{
		GameObject::Update();

		mHead->Update();
		mBody->Update();
	}

	void Player::LateUpdate()
	{
		GameObject::LateUpdate();

		mHead->LateUpdate();
		mBody->LateUpdate();
	}

	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);

		mHead->Render(hdc);
		mBody->Render(hdc);
	}
}
