#include "tTime.h"

namespace t
{
	LARGE_INTEGER Time::cpuFrequency = {};
	LARGE_INTEGER Time::prevFrequency = {};
	LARGE_INTEGER Time::currentFrequency = {};
	float Time::deltaTimeValue = 0.0f;

	void Time::Init()
	{
		//cpu 고유 진동수
		QueryPerformanceFrequency(&cpuFrequency);

		//프로그램이 시작했을 때 현재 진동수
		QueryPerformanceCounter(&prevFrequency);
	}

	void Time::Update()
	{
		QueryPerformanceCounter(&currentFrequency);

		float differenceFrequency = static_cast<float> (currentFrequency.QuadPart - prevFrequency.QuadPart);
		deltaTimeValue = differenceFrequency / static_cast<float> (cpuFrequency.QuadPart);
		prevFrequency.QuadPart = currentFrequency.QuadPart;
	}
	void Time::Render(HDC hdc)
	{
		static float time = 0.0f;
		time += deltaTimeValue;
		float fps = 1.0f / deltaTimeValue;

		/*wchar_t str[50] = L"";
		swprintf_s(str, 50, L"Time : %d", (int)fps);
		int len = wcsnlen_s(str, 50);

		TextOut(hdc, 0, 0, str, len);*/
	}
}