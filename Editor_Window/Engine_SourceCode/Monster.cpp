#include "Monster.h"

namespace t
{
	Monster::Monster() :mX(0.0f), mY(0.0f), mState(0)
	{
	}
	Monster::~Monster()
	{
	}

	void Monster::Init()
	{
	}

	void Monster::Update()
	{
		srand(time(0));
		mState = rand() % 8;
		float speed = 0.02f;

		switch (mState)
		{
		case 0:	//좌
			if (350 + mX >= 0)
			{
				mX -= speed;
			}
			break;
		case 1:	//우
			if (400 + mX <= 1600)
			{
				mX += speed;
			}
			break;
		case 2:	//상
			if (350 + mY >= 0)
			{
				mY -= speed;
			}
			break;
		case 3:	//하
			if (400 + mY <= 900)
			{
				mY += speed;
			}
			break;
		case 4:	//좌상
			if (350 + mX >= 0 && 350 + mY >= 0)
			{
				mX -= speed;
				mY -= speed;
			}
			break;
		case 5:	//좌하
			if (350 + mX >= 0 && 400 + mY <= 900)
			{
				mX -= speed;
				mY += speed;
			}
			break;
		case 6:	//우상
			if (400 + mX <= 1600 && 350 + mY >= 0)
			{
				mX += speed;
				mY -= speed;
			}
			break;
		case 7:	//우하
			if (400 + mX <= 1600 && 400 + mY <= 900)
			{
				mX += speed;
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
}
