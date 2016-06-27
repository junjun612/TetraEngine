#pragma once
#include "Core.h"
#include "Windows.h"

namespace Tetra
{
	//===
	// 시스템 에러 처리
	class SystemError : public Error
	{
	public:
		SystemError(std::string content) : Error(content) {}

		void Catch() override
		{
			std::string errorMessage = "시스템 문제가 발생했습니다. \n에러 내용 : " + content;
			MessageBox(NULL, errorMessage.c_str(), "시스템 에러", MB_OK);
		}
	};

	//===
	// 프로그램의 기본 동작을 위한 시스템 인터페이스
	class System
	{
	protected:
		System();

	public:
		virtual ~System();

		// 구현 해야 하는 함수들
		virtual void Init() = 0;
		virtual void LoopStart() = 0;
		virtual void LoopEnd() = 0;
		virtual void Release() = 0;
	};
}