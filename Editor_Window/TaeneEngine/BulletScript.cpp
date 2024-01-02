#include "BulletScript.h"
#include "PlayerScript.h"
#include "tTime.h"
#include "tObject.h"
#include "tRigidbody.h"

namespace t
{
	BulletScript::BulletScript()
		:mPlayer(nullptr)
		, mBullet(nullptr)
		, bType(BulletType::basic)
		, mTime(0.0f)
		, shootDir(Vector2::Zero)
		, mStatus()
		, bulletActiveTime(0.0f) , atkSpeed(0.0f) , bulletSpeed(0.0f) , atk(0.0f)
	{}
	BulletScript::~BulletScript()
	{}
	void BulletScript::Init()
	{
		bulletActiveTime = mStatus.bulletActiveTime;
		atkSpeed = mStatus.atkSpeed;
		bulletSpeed = mStatus.bulletSpeed;
		atk = mStatus.atk;
	}
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
		if ( mTime > bulletActiveTime )
		{
			//object::Destory(GetOwner());
			mBullet->GetComponent<Transform>()->SetPosition(Vector2(mPlayer->GetComponent<Transform>()->GetPosition()));
			mBullet->SetActive(false);
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
	void BulletScript::BulletInit()
	{
		switch ( bType )
		{
		case t::BulletScript::BulletType::basic:
			bulletActiveTime = mStatus.bulletActiveTime;
			atkSpeed = mStatus.atkSpeed;
			bulletSpeed = mStatus.bulletSpeed;
			atk = mStatus.atk;


			break;
		default:
			break;
		}

		//switch ( bType )
		//{
		//case 0:
		//	speed = 150;
		//	damage = 5;
		//	//prefabId = 0;
		//	count = 0;
		//	bulletSpeed = 0f;
		//	cloneCount = 0;
		//	Batch();

		//	break;
		//case 1:
		//	speed = 150;
		//	damage = 5;
		//	//  prefabId = 1;
		//	bulletSpeed = 0f;
		//	cloneCount = 0;
		//	// Filp();
		//	break;
		//case 2:
		//	speed = 0.3f;
		//	damage = 5;
		//	//  prefabId = 2;
		//	count = 2;
		//	bulletSpeed = 5f;
		//	cloneCount = 0;
		//	break;
		//case 3:
		//	speed = 1.5f;
		//	damage = 5;
		//	//   prefabId = 3;
		//	count = 0;
		//	bulletSpeed = 15f;
		//	cloneCount = 4;
		//	break;
		//case 4:
		//	speed = 1.5f;
		//	damage = 5;
		//	//  prefabId = 4;
		//	count = 0;
		//	bulletSpeed = 3f;
		//	cloneCount = 0;
		//	break;
		//case 5:
		//	speed = 1.5f;
		//	damage = 5;
		//	//  prefabId = 4;
		//	count = 3;
		//	bulletSpeed = 0f;
		//	cloneCount = 0;
		//	break;
		//case 6:
		//	speed = 1.5f;
		//	damage = 5;
		//	//  prefabId = 4;
		//	count = 5;
		//	bulletSpeed = 3f;
		//	cloneCount = 0;
		//	break;
		//default:

		//	break;
		//}
	}
	void BulletScript::shoot()
	{
		Transform* tr = mBullet->GetComponent<Transform>();
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