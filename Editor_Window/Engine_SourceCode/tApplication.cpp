#include "tApplication.h"
#include "tInput.h"
#include "tTime.h"
#include "SceneManager.h"
#include "tResources.h"

namespace t
{
	Application::Application() 
		:mHwnd(nullptr), mHdc(nullptr), 
		winWidth(0), winHeight(0), 
		mBackBuffer(NULL), mBackHdc(NULL)
	{

	}
	Application::~Application()
	{
	}

	void Application::Init(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);
		winWidth = width;
		winHeight = height;
		createBuffer(width, height);

		//_monster.SetPosition(0, 0);
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
		//_monster.Update();

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
		SceneManager::LateUpdate();
	}

	void Application::Render()
	{
		clearRenderTargert();

		Time::Render(mBackHdc);
		SceneManager::Render(mBackHdc);
		//_monster.Render(_backHdc);

		copyRenderTargert(mBackHdc, mHdc);

		/*if (!bullets.empty())
		{
			for (auto i : bullets)
			{
				i->Render(_backHdc);
			}
		}*/
	}

	void Application::Release()
	{
		SceneManager::Release();
		Resources::Release();
	}

	void Application::clearRenderTargert()
	{
		//������۸� - dc(��ȭ��)�� �ΰ��Ἥ �׸��� �ٲٰ� �׸��� �ٲٴ� �˰���
		//clear
		Rectangle(mBackHdc, -1, -1, winWidth + 1, winHeight + 1);
	}

	void Application::copyRenderTargert(HDC source, HDC dest)
	{
		//����ۿ� �ִ°��� ���� ���ۿ� �����ؼ� �׸���
		BitBlt(dest, 0, 0, winWidth, winHeight, source, 0, 0, SRCCOPY);
	}
	void Application::createBuffer(UINT width, UINT height)
	{
		// ������ �ػ󵵿� �´� ��ȭ��(�����) ����
		mBackBuffer = CreateCompatibleBitmap(mHdc, width, height);
		// ��ü�����ʰ� ���� backHdc�� �ϳ� �� �Ἥ �޸𸮸� �� ���� ������ ���̴� ���
		// + ����۸� ����ų DC ����
		mBackHdc = CreateCompatibleDC(mHdc);
		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBuffer);
		DeleteObject(oldBitmap);
	}
}