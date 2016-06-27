#pragma once
#include "System.h"

namespace Tetra
{
	//=== 
	// QueryPerformanceFrequency�� ����Ͽ�
	// FPS �� �����ϰ�, deltaTIme�� ����� �ִ� Ŭ����
	class TimerSystem : public System
	{
	private:
		__int64 frequency;
		__int64 beginTime;
		__int64 endtime;

		// DeltaTime
		GETTER(float, deltaTime, DeltaTime);
		GETTERSETTER(float, speed, Speed);

	protected:
		TimerSystem();

	public:
		static TimerSystem *Create();
		~TimerSystem();

		void Init() override;
		void LoopStart() override;
		void LoopEnd() override;
		void Release() override;
	};

}