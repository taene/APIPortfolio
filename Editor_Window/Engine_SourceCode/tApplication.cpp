#include "tApplication.h"
#include "tInput.h"
#include "tTime.h"

namespace t
{
	Application::Application() :_hwnd(nullptr), _hdc(nullptr), winWidth(0), winHeight(0), _backBuffer(NULL), _backHdc(NULL)
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

		_player.SetPosition(0, 0);
		_monster.SetPosition(0, 0);

		// ������ �ػ󵵿� �´� ��ȭ��(�����) ����
		_backBuffer = CreateCompatibleBitmap(_hdc, width, height);
		// ��ü�����ʰ� ���� backHdc�� �ϳ� �� �Ἥ �޸𸮸� �� ���� ������ ���̴� ���
		// + ����۸� ����ų DC ����
		_backHdc = CreateCompatibleDC(_hdc);
		HBITMAP oldBitmap = (HBITMAP)SelectObject(_backHdc, _backBuffer);
		DeleteObject(oldBitmap);

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
		_player.Update();
		_monster.Update();

		bullets = _player.GetBullets();
		if (!bullets.empty())
		{
			for (auto i : bullets)
			{
				i->Update();
			}
		}

		// �Ҵ� ������ ��� �ؾ��ϳ���?

		/*for (auto i : bullets)
		{
			if (i->GetBulletPositionX() <= 50 || i->GetBulletPositionX() >= 1550
				|| i->GetBulletPositionY() <= 50 || i->GetBulletPositionY() >= 850)
			{
				delete i;
			}
		}*/

		//for (int i = 0; i < bullets.size(); i++)
		//{
		//	if (bullets[i]->GetBulletPositionX() <= 50 || bullets[i]->GetBulletPositionX() >= 1550
		//		|| bullets[i]->GetBulletPositionY() <= 50 || bullets[i]->GetBulletPositionY() >= 850)
		//	{
		//		//delete bullets[i];
		//		bullets.erase(bullets.begin() + i);
		//	}
		//}

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
		//������۸� - dc(��ȭ��)�� �ΰ��Ἥ �׸��� �ٲٰ� �׸��� �ٲٴ� �˰���
		Rectangle(_backHdc, 0, 0, winWidth, winHeight);

		Time::Render(_backHdc);
		_player.Render(_backHdc);
		_monster.Render(_backHdc);

		if (!bullets.empty())
		{
			for (auto i : bullets)
			{
				i->Render(_backHdc);
			}
		}

		//����ۿ� �ִ°��� ���� ���ۿ� �����ؼ� �׸���
		BitBlt(_hdc, 0, 0, winWidth, winHeight, _backHdc, 0, 0, SRCCOPY);
	}
}