#pragma once
#include "..\\Engine_SourceCode\\Scene.h"

namespace t
{
    class ToolScene :public Scene
    {
	public:
		ToolScene();
		~ToolScene();

		void Init() override;
		void Start() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit()  override;

	private:
		class TilemapRenderer* tmr;
    };

}