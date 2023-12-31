#include "Bullet.h"

namespace t
{
	Bullet::Bullet()
	{}
	Bullet::~Bullet()
	{}
	void Bullet::Init()
	{
		GameObject::Init();
	}
	void Bullet::Start()
	{
		GameObject::Start();
	}
	void Bullet::Update()
	{
		GameObject::Update();
	}
	void Bullet::LateUpdate()
	{
		GameObject::LateUpdate();
	}
	void Bullet::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}