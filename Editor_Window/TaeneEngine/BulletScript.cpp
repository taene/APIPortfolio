#include "BulletScript.h"
#include "PlayerScript.h"
#include "tTime.h"
#include "tObject.h"

namespace t
{
	BulletScript::BulletScript()
		:mPlayer(nullptr)
		, mTime(0.0f)
		, shootDir(Vector2::Zero)
		, mStatus()
		//, bullets{}
	{}
	BulletScript::~BulletScript()
	{}
	void BulletScript::Init()
	{}
	void BulletScript::Start()
	{
		if ( mPlayer )
		{
			PlayerScript* playerScript = mPlayer->GetComponent<PlayerScript>();
		}
	}
	void BulletScript::Update()
	{
		mTime += Time::DeltaTime();
		if ( mTime > 3.0f )
		{
			//object::Destory(GetOwner());
			GetOwner()->GetComponent<Transform>()->SetPosition(Vector2(mPlayer->GetComponent<Transform>()->GetPosition()));
			GetOwner()->SetActive(false);
			mTime = 0.0f;
		}

		shoot();
	}
	void BulletScript::LateUpdate()
	{}
	void BulletScript::Render(HDC hdc)
	{}
	void BulletScript::OnCollisionEnter(Collider * other)
	{}
	void BulletScript::OnCollisionStay(Collider * other)
	{}
	void BulletScript::OnCollisionExit(Collider * other)
	{}
	void BulletScript::shoot()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		
		if ( shootDir == Vector2::Up )
		{
			pos.y -= mStatus.bulletSpeed * Time::DeltaTime();
		}
		if ( shootDir == Vector2::Left )
		{
			pos.x -= mStatus.bulletSpeed * Time::DeltaTime();
		}
		if ( shootDir == Vector2::Down )
		{
			pos.y += mStatus.bulletSpeed * Time::DeltaTime();
		}
		if ( shootDir == Vector2::Right )
		{
			pos.x += mStatus.bulletSpeed * Time::DeltaTime();
		}

		tr->SetPosition(pos);
	}
}