#pragma once
#include "..\\Engine_SourceCode\\Scene.h"
#include "Tile.h"

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

		void Save();
		void Load();

	private:
		void renderGrid(HDC hdc);
		void createTileObject();

	private:
		std::vector<Tile*> mTiles;
    };
}

LRESULT CALLBACK WndTileProc(HWND hWnd , UINT message , WPARAM wParam , LPARAM lParam);