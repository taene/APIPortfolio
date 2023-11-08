#pragma once
#include "pch.h"

class Monster
{
public:
	Monster();
	~Monster();

	void Init();
	void Update();
	void LateUpdate();
	void Render(HDC hdc);

	void SetPosition(float x, float y)
	{
		mX = x;
		mY = y;
	}

private:
	float mX;
	float mY;
	int mState;
};