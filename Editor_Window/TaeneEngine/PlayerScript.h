#pragma once
#include "..\\Engine_SourceCode\\Script.h"
#include "Player.h"
#include "tAnimator.h"
#include "Transform.h"

namespace t
{
	class PlayerScript :public Script
	{
	public:
		enum class eState
		{
			Idle ,
			Move ,
			Attack ,
			GetItem ,
			Bomb ,
			Damaged ,
		};

		PlayerScript();
		~PlayerScript();

		void Init() override;
		void Start() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnCollisionEnter(Collider* other) override;
		void OnCollisionStay(Collider* other) override;
		void OnCollisionExit(Collider* other) override;

		void SetPlayer(Player* pl) { player = pl; }

	public:
		//이벤트함수
		void DeleteBomb(GameObject* bomb);

	private:
		//로직함수
		void idle();
		void move();
		void attack();
		void shootBullet(Vector2 dir);
		void setBomb();
		void setExplosion();
		void onDamaged();


	private:
		bool isMove;
		bool isAttack;

		bool isUp;
		bool isDown;
		bool isLeft;
		bool isRight;

	private:
		eState mState;
		Player::Status mStatus;

		Player* player;
		GameObject* head;
		GameObject* body;
		GameObject* bomb;

		Animator* headAni;
		Animator* bodyAni;
		Transform* playerTr;

		//void (*StartEvent)();
		//void (*CompleteEvent)();
		//void (*EndEvent)();

	};
}