#include "Enemy.h"

namespace t
{
	Enemy::Enemy()
	{}
	Enemy::~Enemy()
	{}
	void Enemy::Init()
	{
		GameObject::Init();
	}
	void Enemy::Start()
	{
		GameObject::Start();
	}
	void Enemy::Update()
	{
		GameObject::Update();
	}
	void Enemy::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Enemy::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}