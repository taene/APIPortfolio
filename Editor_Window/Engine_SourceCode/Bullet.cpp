#include "pch.h"
#include "Bullet.h"
#include "tTime.h"

namespace t
{
	Bullet::Bullet() :bX(0.0f), bY(0.0f), pX1(0.0f), pY1(0.0f), pX2(0.0f), pY2(0.0f)
	{
	}

	Bullet::~Bullet()
	{
	}

	void Bullet::Update()
	{
		const float speed = 600.0f;
		bY -= speed * Time::DeltaTime();
	}

	void Bullet::Render(HDC hdc)
	{
		HBRUSH greenBrush = CreateSolidBrush(RGB(0, 255, 0));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, greenBrush);

		HPEN greenPen = CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, greenPen);
		SelectObject(hdc, oldPen);

		Ellipse(hdc, 40.0f + pX1 + bX, 40.0f + pY1 + bY, pX2 + bX - 40.0f, pY2 + bY - 40.0f);

		SelectObject(hdc, oldBrush);
		DeleteObject(greenBrush);
		DeleteObject(greenPen);
	}
}