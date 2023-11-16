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

	private:

	};
}