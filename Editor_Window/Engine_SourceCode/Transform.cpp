#include "Transform.h"

namespace t
{
	Transform::Transform() 
		:Component(enums::eComponentType::Transform), 
		mPosition(0.0f, 0.0f),
		mScale(Vector2::One),
		mRotation(0.0f),
		mParent(nullptr),
		mOffset(Vector2::Zero)
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
	void Transform::Start()
	{
	}
	void Transform::Update()
	{
		if ( mParent )
			mPosition = mOffset + mParent->GetPosition();
	}
	void Transform::LateUpdate()
	{
	}
	void Transform::Render(HDC hdc)
	{
	}
}