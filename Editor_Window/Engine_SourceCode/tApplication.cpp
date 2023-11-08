#include "tApplication.h"

namespace t
{
	Application::Application() :_hwnd(nullptr), _hdc(nullptr)
	{

	}
	Application::~Application()
	{
	}

	void Application::Init(HWND hwnd)
	{
		_hwnd = hwnd;
		_hdc = GetDC(hwnd);
		_player.SetPosition(0, 0);
		_monster.SetPosition(0, 0);
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		_player.Update();
		_monster.Update();
	}

	void Application::LateUpdate()
	{
	}

	void Application::Render()
	{
		_player.Render(_hdc);
		_monster.Render(_hdc);
	}

}
