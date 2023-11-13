#pragma once
#include "pch.h"
#include "Bullet.h"

namespace t
{
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void SetPosition(float x, float y)
		{
			mX = x;
			mY = y;
		}
		std::vector<Bullet*> &GetBullets()
		{
			for (auto& i : bullets)
			{
				i;
			}
			return bullets;
		}

	private:
		float mX;
		float mY;
		Bullet* bullet;
		std::vector<Bullet*> bullets;
	};
}