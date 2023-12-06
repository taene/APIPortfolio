#pragma once
#include "..\\Engine_SourceCode\\tGameObject.h"

namespace t
{
	class Player :public GameObject
	{
	public:
		void Init() override;
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