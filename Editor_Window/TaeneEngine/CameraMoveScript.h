#pragma once
#include "..\\Engine_SourceCode\\Script.h"

namespace t
{
	class CameraMoveScript :public Script
	{
	public:
		CameraMoveScript();
		~CameraMoveScript();

		void Init() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;


	private:

	};
}