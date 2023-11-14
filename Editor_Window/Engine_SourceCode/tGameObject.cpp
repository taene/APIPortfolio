#include "tGameObject.h"
#include "tInput.h"
#include "tTime.h"

namespace t
{
	GameObject::GameObject() 
		:mX(0.0f), mY(0.0f)
	{
	}

	GameObject::~GameObject()
	{
	}

	void GameObject::Update()
	{
		const float speed = 100.0f;
		if (Input::GetKeyPressed(eKeyCode::A) || Input::GetKeyPressed(eKeyCode::Left))
		{
			mX -= speed * Time::DeltaTime();
		}
		if (Input::GetKeyPressed(eKeyCode::D) || Input::GetKeyPressed(eKeyCode::Right))
		{
			mX += speed * Time::DeltaTime();
		}
		if (Input::GetKeyPressed(eKeyCode::W) || Input::GetKeyPressed(eKeyCode::Up))
		{
			mY -= speed * Time::DeltaTime();
		}
		if (Input::GetKeyPressed(eKeyCode::S) || Input::GetKeyPressed(eKeyCode::Down))
		{
			mY += speed * Time::DeltaTime();
		}
		if (Input::GetKeyDown(eKeyCode::SpaceBar))
		{
			//// �Ѿ� ���
			//bullet = new Bullet();
			//bullet->GetPlayerPosition(100 + mX, 100 + mY, 200 + mX, 200 + mY);
			//bullets.push_back(bullet);
		}
	}

	void GameObject::LateUpdate()
	{
	}

	void GameObject::Render(HDC hdc)
	{
		HBRUSH blueBrush = CreateSolidBrush(RGB(rand()%255, rand() % 255, rand() % 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(rand() % 255, rand() % 255, rand() % 255));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);
		SelectObject(hdc, oldPen);

		Rectangle(hdc, mX, mY, 100.0f + mX, 100.0f + mY);

		SelectObject(hdc, oldBrush);
		DeleteObject(blueBrush);
		DeleteObject(redPen);
	}
}