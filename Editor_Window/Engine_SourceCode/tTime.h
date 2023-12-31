#pragma once
#include "pch.h"

namespace t
{
	class Time
	{
	public:
		static void Init();
		static void Update();
		static void Render(HDC hdc);

		__forceinline static float DeltaTime() { return deltaTimeValue; }

	private:
		static LARGE_INTEGER cpuFrequency;
		static LARGE_INTEGER prevFrequency;
		static LARGE_INTEGER currentFrequency;
		static float deltaTimeValue;
	};

}

