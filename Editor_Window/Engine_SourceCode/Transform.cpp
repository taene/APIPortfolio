#include "Transform.h"

namespace t
{
	Transform::Transform() 
		:Component(enums::eComponentType::Transform), 
		mPosition(0.0f, 0.0f),
		mScale(Vector2::One),
		mRotation(0.0f),
		mParent(nullptr)
	{
	}
	Transform::~Transform()
	{
	}
	void Transform::Init()
	{
		if ( mParent )
			SetParent(mParent);
	}
	void Transform::Update()
	{
		
	}
	void Transform::LateUpdate()
	{
	}
	void Transform::Render(HDC hdc)
	{
	}
}