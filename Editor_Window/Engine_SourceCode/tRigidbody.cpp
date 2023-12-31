#include "tRigidbody.h"
#include "tTime.h"
#include "Transform.h"
#include "tGameObject.h"

namespace t
{
	Rigidbody::Rigidbody()
		: Component(enums::eComponentType::Rigidbody)
		, mbGround(false) , useGravity(false)
		, mMass(1.0f)
		, mFriction(10.0f)
		, mForce(Vector2::Zero)
		, mVelocity(Vector2::Zero)
		, mLimitedVelocity(Vector2(200.0f , 200.0f))
		, mGravity(Vector2(0.0f , 800.0f))
		, mAccelation(Vector2::Zero)
	{

	}

	Rigidbody::~Rigidbody()
	{}

	void Rigidbody::Init()
	{}

	void Rigidbody::Update()
	{
		// f(힘) = m(질량) x a(가속도)
		// a = f / m;
		mAccelation = mForce / mMass;

		// 속도에 가속도를 더한다.
		mVelocity += mAccelation * Time::DeltaTime();

		if ( useGravity )
		{
			if ( mbGround )
			{
				//땅 위에 있을 때
				Vector2 gravity = mGravity;
				gravity.normalize();

				float dot = Vector2::Dot(mVelocity , gravity);
				mVelocity -= gravity * dot;
			}
			else
			{
				//공중에 있을 때
				mVelocity += mGravity * Time::DeltaTime();
			}

			//최대 속도 제한
			Vector2 gravity = mGravity;
			gravity.normalize();
			float dot = Vector2::Dot(mVelocity , gravity);
			mVelocity -= gravity * dot;
			gravity = gravity * dot;

			//좌우 속도 추출
			Vector2 sideVelocity = mVelocity - gravity;
			if ( mLimitedVelocity.y < gravity.length() )
			{
				gravity.normalize();
				gravity *= mLimitedVelocity.y;
			}
			if ( mLimitedVelocity.x < sideVelocity.length() )
			{
				sideVelocity.normalize();
				sideVelocity *= mLimitedVelocity.x;
			}
			mVelocity = gravity + sideVelocity;
		}

		// 마찰력

		// 마찰력에 의한 반대방향으로의 가속도
		if ( !( mVelocity == Vector2::Zero ) )
		{
			//속도에 반대방향으로 마찰력 작용
			Vector2 friction = -mVelocity;
			friction = friction.normalize() * mFriction * mMass * Time::DeltaTime();

			// 마찰력으로 인한 속도 감소량이 현재 속도보다 큰 경우
			if ( mVelocity.length() <= friction.length() )
			{
				// 멈춰
				mVelocity = Vector2::Zero;
			}
			else
			{
				mVelocity += friction;
			}
		}

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		pos = pos + mVelocity * Time::DeltaTime();
		tr->SetPosition(pos);

		mForce.clear();
	}

	void Rigidbody::LateUpdate()
	{}

	void Rigidbody::Render(HDC hdc)
	{}

}