#include "tGameObject.h"
#include "tInput.h"
#include "tTime.h"
#include "Transform.h"

namespace t::object
{
	void Destory(GameObject* gameObject)
	{
		if ( gameObject != nullptr )
			gameObject->death();
	}
}

namespace t
{
	GameObject::GameObject()
		:mState(eState::Active), 
		mLayerType(eLayerType::None)
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

	void GameObject::Start()
	{
		for ( Component* i : mComponents )
		{
			if ( i == nullptr )
				continue;

			i->Start();
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

