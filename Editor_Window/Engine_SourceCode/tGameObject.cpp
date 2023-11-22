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