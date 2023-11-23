#pragma once
#include "tGameObject.h"
#include "Monster.h"

namespace t
{
	class Application
	{
	public:
		Application();
		~Application();

		void Init(HWND hwnd, UINT width, UINT height);
		void Run();
		void Update();
		void LateUpdate();
		void Render();

		HDC GetHdc() { return mHdc; }
		
	private:
		void clearRenderTargert();
		void copyRenderTargert(HDC source, HDC dest);
		void createBuffer(UINT width, UINT height);

	private:
		HWND mHwnd;
		HDC mHdc;
		
		HDC mBackHdc;
		HBITMAP mBackBuffer;

		UINT winWidth;
		UINT winHeight;

		Monster mMonster;
	};
}
