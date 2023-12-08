#pragma once
#include "..\\Engine_SourceCode\\Script.h"
#include "Player.h"
#include "tAnimator.h"

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
			Damaged ,
		};

		PlayerScript();
		~PlayerScript();

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetPlayer(Player* pl) { player = pl; }

	public:
		//이벤트함수

	private:
		//로직함수
		void idle();
		void move();
		void attack();
		void onDamaged();

	private:
		eState mState;

		Player* player;
		GameObject* head;
		GameObject* body;

		//void (*StartEvent)();
		//void (*CompleteEvent)();
		//void (*EndEvent)();
	};
}