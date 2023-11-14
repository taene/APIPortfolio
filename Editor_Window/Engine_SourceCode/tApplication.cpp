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
		//			//�������� �Ѿ�ų� ���Ϳ� ������ bullet �Ҵ� ����, ��ü ����
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
		//������۸� - dc(��ȭ��)�� �ΰ��Ἥ �׸��� �ٲٰ� �׸��� �ٲٴ� �˰���
		//clear
		Rectangle(_backHdc, -1, -1, winWidth + 1, winHeight + 1);
	}

	void Application::copyRenderTargert(HDC source, HDC dest)
	{
		//����ۿ� �ִ°��� ���� ���ۿ� �����ؼ� �׸���
		BitBlt(dest, 0, 0, winWidth, winHeight, source, 0, 0, SRCCOPY);
	}
	void Application::createBuffer(UINT width, UINT height)
	{
		// ������ �ػ󵵿� �´� ��ȭ��(�����) ����
		_backBuffer = CreateCompatibleBitmap(_hdc, width, height);
		// ��ü�����ʰ� ���� backHdc�� �ϳ� �� �Ἥ �޸𸮸� �� ���� ������ ���̴� ���
		// + ����۸� ����ų DC ����
		_backHdc = CreateCompatibleDC(_hdc);
		HBITMAP oldBitmap = (HBITMAP)SelectObject(_backHdc, _backBuffer);
		DeleteObject(oldBitmap);
	}
}