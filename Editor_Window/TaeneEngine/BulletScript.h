#pragma once
#include "Script.h"
#include "Player.h"

namespace t
{
	class BulletScript : public Script
	{
	public:
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

		void SetPlayer(Player* player) { mPlayer = player; }

	private:
		void shoot();

	private:
		Player* mPlayer;
		Vector2 shootDir;
		Player::Status mStatus;
		//int dir;

		//const std::vector<GameObject*> bullets;

		float mTime;
	};

}