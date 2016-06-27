#pragma once
#include "System.h"

namespace Tetra
{
	//===
	// 모든 시스템을 관리하는 매니저 클래스
	class SystemManager
	{
	private:
		std::list <System *> systemList;

	public:
		SystemManager();
		~SystemManager();

		// 시스템 추가
		void AddSystem(System *system);

		// 시스템 찾기
		template <typename SystemType>
		SystemType *GetSystem()
		{
			for (auto system : systemList)
			{
				// dynamic_cast 가 가능한 경우 ( 자료형이 같거나 그의 부모클래스일 때 )
				if (dynamic_cast<SystemType *>(system))
				{
					// 템플릿 타입과 인자변수의 타입이 같을 경우 반환해 준다.
					return dynamic_cast<SystemType *>(system);
				}
			}

			// typeid 로 에러 출력
			Error::JustCatch<SystemError>("시스템 " + GetTypeName<SystemType>() + " 을(를) 찾을 수 없습니다.");
			return nullptr;
		}

		//===
		// 전체 시스템 관리
		void LoopStart();
		void LoopEnd();
		void Release();
	};
}