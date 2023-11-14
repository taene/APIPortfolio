#include "tApplication.h"
#include "tInput.h"
#include "tTime.h"
#include "SceneManager.h"

namespace t
{
	Application::Application() 
		:_hwnd(nullptr), _hdc(nullptr), 
		winWidth(0), winHeight(0), 
		_backBuffer(NULL), _backHdc(NULL)
	{

	}
	Application::~Application()
	{
	}

	void Application::Init(HWND hwnd, UINT width, UINT height)
	{
		_hwnd = hwnd;
		_hdc = GetDC(hwnd);
		winWidth = width;
		winHeight = height;
		createBuffer(width, height);

		_monster.SetPosition(0, 0);
		SceneManager::Init();
		Time::Init();
		Input::Init();
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		Input::Update();
		Time::Update();
		SceneManager::Update();
		_monster.Update();

		/*bullets = _player.GetBullets();
		if (!bullets.empty())
		{
			for (auto i : bullets)
			{
				i->Update();
			}
		}*/

		//if (!bullets.empty())
		//{
		//	for (auto iter = bullets.begin(); iter != bullets.end();)
		//	{
		//		Bullet* i = *iter;
		//		if (i->GetBulletPositionX() <= 50 || i->GetBulletPositionX() >= 1550
		//			|| i->GetBulletPositionY() <= 50 || i->GetBulletPositionY() >= 850)
		//		{
		//			//일정범위 넘어가거나 몬스터에 닿으면 bullet 할당 해제, 객체 삭제
		//			iter = bullets.erase(iter);
		//			delete i;

		//		}
		//		else
		//		{
		//			iter++;
		//		}
		//	}
		//}
	}

	void Application::LateUpdate()
	{
	}

	void Application::Render()
	{
		clearRenderTargert();

		Time::Render(_backHdc);
		SceneManager::Render(_backHdc);
		_monster.Render(_backHdc);

		copyRenderTargert(_backHdc, _hdc);

		/*if (!bullets.empty())
		{
			for (auto i : bullets)
			{
				i->Render(_backHdc);
			}
		}*/
	}

	void Application::clearRenderTargert()
	{
		//더블버퍼링 - dc(도화지)를 두개써서 그리고 바꾸고 그리고 바꾸는 알고리즘
		//clear
		Rectangle(_backHdc, -1, -1, winWidth + 1, winHeight + 1);
	}

	void Application::copyRenderTargert(HDC source, HDC dest)
	{
		//백버퍼에 있는것을 원본 버퍼에 복사해서 그린다
		BitBlt(dest, 0, 0, winWidth, winHeight, source, 0, 0, SRCCOPY);
	}
	void Application::createBuffer(UINT width, UINT height)
	{
		// 윈도우 해상도에 맞는 도화지(백버퍼) 생성
		_backBuffer = CreateCompatibleBitmap(_hdc, width, height);
		// 교체하지않고 덮는 backHdc를 하나 더 써서 메모리를 더 쓰고 연산을 줄이는 방식
		// + 백버퍼를 가르킬 DC 생성
		_backHdc = CreateCompatibleDC(_hdc);
		HBITMAP oldBitmap = (HBITMAP)SelectObject(_backHdc, _backBuffer);
		DeleteObject(oldBitmap);
	}
}