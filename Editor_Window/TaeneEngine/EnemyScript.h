#pragma once
#include "Script.h"
#include "Transform.h"
#include "Player.h"

namespace t
{
    class EnemyScript : public Script
    {
	public:
		EnemyScript();
		~EnemyScript();

		void Init() override;
		void Start() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnCollisionEnter(Collider* other) override;
		void OnCollisionStay(Collider* other) override;
		void OnCollisionExit(Collider* other) override;

		void SetTarget(Player* pl) { targetTr = pl->GetComponent<Transform>(); }

	private:
		void jump();
		void follow();

	private:
		bool isDead;
		Transform* targetTr;	//따라갈 플레이어 위치
		Transform* enemyTr; //본인 위치

		float health; // 몬스터 현재 체력
		float maxHealth; // 몬스터 최대 체력
		float speed; // 몬스터 이동속도
		float damage; // 몬스터 데미지
    };

}