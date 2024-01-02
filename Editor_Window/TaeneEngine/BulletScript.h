#pragma once
#include "Script.h"
#include "Player.h"
#include "Bullet.h"

namespace t
{
	class BulletScript : public Script
	{
	public:
		enum class BulletType
		{
			basic ,

		};

		BulletScript();
		~BulletScript();

		void Init() override;
		void Start() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnCollisionEnter(Collider* other) override;
		void OnCollisionStay(Collider* other) override;
		void OnCollisionExit(Collider* other) override;

		void SetPlayerInScript(Player* player) { mPlayer = player; }
		void SetBulletInScript(Bullet* bullet) { mBullet = bullet; }
		void SetDirection(Vector2 dir) { shootDir = dir; }

	public:
		void BulletInit();

	private:
		void shoot();

	private:
		Player* mPlayer;
		Bullet* mBullet;
		Vector2 shootDir;
		Player::Status mStatus;
		BulletType bType;


		float mTime;

		//총알 기본정보
		float bulletActiveTime;
		float atkSpeed;
		float bulletSpeed;
		float atk;
	};

}