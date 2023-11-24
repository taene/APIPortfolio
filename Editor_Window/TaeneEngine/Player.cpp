#include "Player.h"
#include "tInput.h"
#include "Transform.h"
#include "tTime.h"

namespace t
{
	void Player::Init()
	{
		GameObject::Init();
	}

	void Player::Update()
	{
		GameObject::Update();
	}

	void Player::LateUpdate()
	{
		GameObject::LateUpdate();
	}

	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}
