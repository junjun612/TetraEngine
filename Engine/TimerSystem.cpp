#include "TimerSystem.h"


namespace Tetra
{
	TimerSystem::TimerSystem()
	{
	}


	TimerSystem::~TimerSystem()
	{
	}

	TimerSystem *TimerSystem::Create()
	{
		// 생성, 에러 검출
		TimerSystem *returnSystem = new TimerSystem();
		if (returnSystem == nullptr)
			Error::Throw<SystemError>("타이머 객체 생성에 실패하였습니다.");

		// 초기화, 에러 검출
		returnSystem->Init();

		return returnSystem;
	}

	void TimerSystem::Init()
	{
		QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
	}

	void TimerSystem::LoopStart()
	{
		QueryPerformanceCounter((LARGE_INTEGER *)&beginTime);
	}

	void TimerSystem::LoopEnd()
	{
		static int fps = 0;
		static int second = 0;
		if (second != GetTickCount() / 1000)
		{
			second = GetTickCount() / 1000;

			char fpsStr[32];
			sprintf_s(fpsStr, "fps : %d \nDT : %.2f", fps, deltaTime);
			OutputDebugStringA(fpsStr);
			OutputDebugStringA("\n");

			fps = 0;
		}
		fps++;

		QueryPerformanceCounter((LARGE_INTEGER *)&endtime);
		__int64 elapsed = endtime - beginTime;

		// 100만(elapsed) = 1(초)
		// 60프레임 기준 DT가 1일 경우  elapsed = (1000000 / 60.0f);
		deltaTime = (FLOAT)(elapsed * 1000000 / frequency) / (1000000);
	}

	void TimerSystem::Release()
	{
	}
}