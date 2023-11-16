#pragma once
#include "tEntity.h"
#include "Component.h"

namespace t
{
	struct Pos
	{
		int mX;
		int mY;
	};

	class Transform : public Component
	{
	public:
		Transform();
		~Transform();

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetPos(int x, int y) { mX = x; mY = y; }
		float GetX() { return mX; }
		float GetY() { return mY; }

	private:
		float mX;
		float mY;
	};
}