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
		srand(time(NULL));
		mState = rand() % 8;
		float speed = 0.02f;

		switch (mState)
		{
		case 0:	//ÁÂ
			if (350 + mX >= 0)
			{
				mX -= speed;
			}
			break;
		case 1:	//¿ì
			if (400 + mX <= 1600)
			{
				mX += speed;
			}
			break;
		case 2:	//»ó
			if (350 + mY >= 0)
			{
				mY -= speed;
			}
			break;
		case 3:	//ÇÏ
			if (400 + mY <= 900)
			{
				mY += speed;
			}
			break;
		case 4:	//ÁÂ»ó
			if (350 + mX >= 0 && 350 + mY >= 0)
			{
				mX -= speed;
				mY -= speed;
			}
			break;
		case 5:	//ÁÂÇÏ
			if (350 + mX >= 0 && 400 + mY <= 900)
			{
				mX -= speed;
				mY += speed;
			}
			break;
		case 6:	//¿ì»ó
			if (400 + mX <= 1600 && 350 + mY >= 0)
			{
				mX += speed;
				mY -= speed;
			}
			break;
		case 7:	//¿ìÇÏ
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
		Ellipse(hdc, 350.0f + mX, 350.0f + mY, 400.0f + mX, 400.0f + mY);

		SelectObject(hdc, oldBrush);
		DeleteObject(redBrush);
	}
}
