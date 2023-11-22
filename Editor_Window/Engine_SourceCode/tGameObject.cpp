#include "tGameObject.h"
#include "tInput.h"
#include "tTime.h"
#include "Transform.h"

namespace t
{
	GameObject::GameObject()
	{
		initTransform();
	}

	GameObject::~GameObject()
	{
		for (Component* i : mComponents)
		{
			delete i;
			i = nullptr;
		}
	}

	void GameObject::Init()
	{
		for (Component* i : mComponents)
		{
			i->Init();
		}
	}

	void GameObject::Update()
	{
		for (Component* i : mComponents)
		{
			i->Update();
		}

		//const float speed = 100.0f;
		//if (Input::GetKeyPressed(eKeyCode::A) || Input::GetKeyPressed(eKeyCode::Left))
		//{
		//	mX -= speed * Time::DeltaTime();
		//}
		//if (Input::GetKeyPressed(eKeyCode::D) || Input::GetKeyPressed(eKeyCode::Right))
		//{
		//	mX += speed * Time::DeltaTime();
		//}
		//if (Input::GetKeyPressed(eKeyCode::W) || Input::GetKeyPressed(eKeyCode::Up))
		//{
		//	mY -= speed * Time::DeltaTime();
		//}
		//if (Input::GetKeyPressed(eKeyCode::S) || Input::GetKeyPressed(eKeyCode::Down))
		//{
		//	mY += speed * Time::DeltaTime();
		//}
		//if (Input::GetKeyDown(eKeyCode::SpaceBar))
		//{
		//	//// ÃÑ¾Ë ½î±â
		//	//bullet = new Bullet();
		//	//bullet->GetPlayerPosition(100 + mX, 100 + mY, 200 + mX, 200 + mY);
		//	//bullets.push_back(bullet);
		//}
	}

	void GameObject::LateUpdate()
	{
		for (Component* i : mComponents)
		{
			i->LateUpdate();
		}
	}

	void GameObject::Render(HDC hdc)
	{
		for (Component* i : mComponents)
		{
			i->Render(hdc);
		}
	}
	void GameObject::initTransform()
	{
		AddComponent<Transform>();
	}
}