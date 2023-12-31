#include "Camera.h"
#include "tGameObject.h"
#include "Transform.h"
#include "tApplication.h"

extern t::Application application;

namespace t
{
	Camera::Camera() 
		:Component(enums::eComponentType::Camera),
		mDistance(Vector2::Zero), mResolution(Vector2::Zero),
		mLookPosition(Vector2::Zero), mTarget(nullptr)
	{
	}
	Camera::~Camera()
	{
	}
	void Camera::Init()
	{
		mResolution.x = application.GetWidth();
		mResolution.y = application.GetHeight();
	}
	void Camera::Start()
	{}
	void Camera::Update()
	{
		if (mTarget)
		{
			Transform* tr = mTarget->GetComponent<Transform>();
			mLookPosition = tr->GetPosition();
		}
		else
		{
			Transform* cameraTr = GetOwner()->GetComponent<Transform>();
			mLookPosition = cameraTr->GetPosition();
		}
		mDistance = mLookPosition - (mResolution / 2.0f);

	}
	void Camera::LateUpdate()
	{
	}
	void Camera::Render(HDC hdc)
	{
	}
}