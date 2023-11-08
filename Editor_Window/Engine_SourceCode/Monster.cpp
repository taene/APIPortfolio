#include "Monster.h"

Monster::Monster() :mX(0.0f), mY(0.0f), mState(0)
{
}
Monster::~Monster()
{
}

void Monster::Update()
{
	srand(time(0));
	mState = rand() % 4;
	float speed = 0.02f;

	switch (mState)
	{
	case 0:
		if (350 + mX >= 0)
		{
			mX -= speed;
		}
		break;
	case 1:
		if (400 + mX <= 1600)
		{
			mX += speed;
		}
		break;
	case 2:
		if (350 + mY >= 0)
		{
			mY -= speed;
		}
		break;
	case 3:
		if (400 + mY <= 900)
		{
			mY += speed;
		}
		break;

	default:
		break;
	}
}

void Monster::LateUpdate()
{
}

void Monster::Render(HDC hdc)
{
	HBRUSH redBrush = CreateSolidBrush(RGB(255, 0, 0));
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, redBrush);
	Ellipse(hdc, 350 + mX, 350 + mY, 400 + mX, 400 + mY);

	SelectObject(hdc, oldBrush);
	DeleteObject(redBrush);
}