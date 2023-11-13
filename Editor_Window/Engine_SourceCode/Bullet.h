#pragma once

namespace t
{
	class Bullet
	{
	public:
		Bullet();
		~Bullet();

		void Update();
		void Render(HDC hdc);
		void GetPlayerPosition(float x1, float y1, float x2, float y2)
		{
			pX1 = x1;
			pY1 = y1;
			pX2 = x2;
			pY2 = y2;
		}
		float GetBulletPositionX() { return (pX1 + pX2 + 2 * bX) / 2; }
		float GetBulletPositionY() { return (pY1 + pY2 + 2 * bY) / 2; }

	private:
		float bX, bY;
		float pX1, pY1, pX2, pY2;
	};
}
