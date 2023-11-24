#pragma once
#include "..\\Engine_SourceCode\\Script.h"

namespace t
{
	class PlayerScript :public Script
	{
	public:
		PlayerScript();
		~PlayerScript();

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void Move();

	private:

	};
}