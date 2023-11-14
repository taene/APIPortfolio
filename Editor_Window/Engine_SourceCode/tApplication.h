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
		
	private:
		void clearRenderTargert();
		void copyRenderTargert(HDC source, HDC dest);
		void createBuffer(UINT width, UINT height);

	private:
		HWND _hwnd;
		HDC _hdc;
		
		HDC _backHdc;
		HBITMAP _backBuffer;

		UINT winWidth;
		UINT winHeight;

		Monster _monster;
	};
}
