#pragma once
#include "..\\Engine_SourceCode\\Script.h"

namespace t
{
	class PlayerScript :public Script
	{
	public:
		enum class eState
		{
			Idle,
			Walk,
			Sleep,
			GiveWater,
			Attack,
		};

		PlayerScript();
		~PlayerScript();

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	public:
		//�̺�Ʈ�Լ�

	private:
		//�����Լ�
		void idle();
		void move();
		void giveWater();

	private:
		eState mState;
		class Animator* mAnimator;

		//void (*StartEvent)();
		//void (*CompleteEvent)();
		//void (*EndEvent)();
	};
}