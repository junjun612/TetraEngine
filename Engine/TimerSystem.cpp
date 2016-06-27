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
		// ����, ���� ����
		TimerSystem *returnSystem = new TimerSystem();
		if (returnSystem == nullptr)
			Error::Throw<SystemError>("Ÿ�̸� ��ü ������ �����Ͽ����ϴ�.");

		// �ʱ�ȭ, ���� ����
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

		// 100��(elapsed) = 1(��)
		// 60������ ���� DT�� 1�� ���  elapsed = (1000000 / 60.0f);
		deltaTime = (FLOAT)(elapsed * 1000000 / frequency) / (1000000);
	}

	void TimerSystem::Release()
	{
	}
}