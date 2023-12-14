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

		struct Status
		{
			int hp;
			int	coin;
			int	bomb;
			int	key;
			float speed;
			float range;
			float atkSpeed;
			float bulletSpeed;
			float atk;
			float luck;

			float knockBack;
			
			Status()
				:hp(6) ,
				coin(0) ,
				bomb(1) ,
				key(0) ,
				speed(200.0f) ,
				range(23.75f) ,
				atkSpeed(10.0f) ,
				bulletSpeed(1.0f) ,
				atk(3.5f) ,
				luck(0.0f),
				knockBack(0.5f)
			{
			}
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

	private:
		//로직함수
		void idle();
		void move();
		void attack();
		void shootBullet();
		void setBomb();
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
		Status mStatus;

		Player* player;
		GameObject* head;
		GameObject* body;

		Animator* headAni;
		Animator* bodyAni;
		Transform* playerTr;

		//void (*StartEvent)();
		//void (*CompleteEvent)();
		//void (*EndEvent)();

	};
}