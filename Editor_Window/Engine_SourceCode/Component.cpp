#include "Component.h"

namespace t
{
	Component::Component(eComponentType type)
		:mOwner(nullptr), mType(type)
	{
	}

	Component::~Component()
	{
	}

	void Component::Init()
	{
	}

	void Component::Start()
	{
	}

	void Component::Update()
	{
	}

	void Component::LateUpdate()
	{
	}

	void Component::Render(HDC hdc)
	{
	}

}
