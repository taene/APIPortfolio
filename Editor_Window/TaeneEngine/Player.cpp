#include "Player.h"

namespace t
{
	void Player::Init()
	{
		GameObject::Init();
	}

	void Player::Update()
	{
		GameObject::Update();
		//const float speed = 100.0f;
		//if (Input::GetKeyPressed(eKeyCode::A) || Input::GetKeyPressed(eKeyCode::Left))
		//{
		//	mX -= speed * Time::DeltaTime();
		//}
		//if (Input::GetKeyPressed(eKeyCode::D) || Input::GetKeyPressed(eKeyCode::Right))
		//{
		//	mX += speed * Time::DeltaTime();
		//}
		//if (Input::GetKeyPressed(eKeyCode::W) || Input::GetKeyPressed(eKeyCode::Up))
		//{
		//	mY -= speed * Time::DeltaTime();
		//}
		//if (Input::GetKeyPressed(eKeyCode::S) || Input::GetKeyPressed(eKeyCode::Down))
		//{
		//	mY += speed * Time::DeltaTime();
		//}
		//if (Input::GetKeyDown(eKeyCode::SpaceBar))
		//{
		//	//// �Ѿ� ���
		//	//bullet = new Bullet();
		//	//bullet->GetPlayerPosition(100 + mX, 100 + mY, 200 + mX, 200 + mY);
		//	//bullets.push_back(bullet);
		//}
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
