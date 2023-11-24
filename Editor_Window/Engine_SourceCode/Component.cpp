#include "Component.h"

namespace t
{
	Component::Component(enums::eComponentType type)
		:mOwner(nullptr), mType(type)
	{
	}

	Component::~Component()
	{
	}

	void Component::Init()
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
