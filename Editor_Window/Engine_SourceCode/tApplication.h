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

		void Init(HWND hwnd);
		void Run();
		void Update();
		void LateUpdate();
		void Render();

	private:
		HWND _hwnd;
		HDC _hdc;
		GameObject _player;
		Monster _monster;
	};
}
