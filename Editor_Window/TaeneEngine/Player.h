#pragma once
#include "..\\Engine_SourceCode\\tGameObject.h"

namespace t
{
	class Player :public GameObject
	{
	public:
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
				bulletSpeed(200.0f) ,
				atk(3.5f) ,
				luck(0.0f) ,
				knockBack(0.5f)
			{}
		};

		void Init() override;
		void Start() override;
		void Update() override;
		void LateUpdate()override;
		void Render(HDC hdc) override;

	public:
		void SetPlayerHeadBody(GameObject* head , GameObject* body) { mHead = head; mBody = body; }
		GameObject* GetPlayerHead() { return mHead; }
		GameObject* GetPlayerBody() { return mBody; }

	private:

	private:
		GameObject* mHead;
		GameObject* mBody;
	};
}