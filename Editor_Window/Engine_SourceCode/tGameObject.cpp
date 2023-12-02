#include "tGameObject.h"
#include "tInput.h"
#include "tTime.h"
#include "Transform.h"

namespace t
{
	GameObject::GameObject()
	{
		mComponents.resize((UINT)enums::eComponentType::End);
		initTransform();
	}

	GameObject::~GameObject()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			delete comp;
			comp = nullptr;
		}
	}

	void GameObject::Init()
	{
		for (Component* i : mComponents)
		{
			if (i == nullptr)
				continue;

			i->Init();
		}
	}

	void GameObject::Update()
	{
		for (Component* i : mComponents)
		{
			if (i == nullptr)
				continue;

			i->Update();
		}
	}

	void GameObject::LateUpdate()
	{
		for (Component* i : mComponents)
		{
			if (i == nullptr)
				continue;

			i->LateUpdate();
		}
	}

	void GameObject::Render(HDC hdc)
	{
		for (Component* i : mComponents)
		{
			if (i == nullptr)
				continue;

			i->Render(hdc);
		}
	}
	void GameObject::initTransform()
	{
		AddComponent<Transform>();
	}
}