#pragma once
#include <string>
#include <memory>

/*
// 실제 사용 예
	class SystemError : public Error
	{
		public:
			SystemError(std::string content) : Error(content)  {}
	
			void Catch() override
			{
			std::cout << "시스템 에러 : " << content << std::endl;
			}
	};
*/

namespace Tetra
{
	//===
	// try ~catch 문에서 사용할 수 있는 에러 클래스
	class Error
	{
	protected:
		std::string content;

		Error(std::string content);

	public:
		virtual ~Error();

		// 에러를 던진다.
		template <typename ErrorType>
		static void Throw(std::string content)
		{
			throw (new ErrorType(content));
		}

		// 종료하지 않고 Catch 만 한다.
		template <typename ErrorType>
		static void JustCatch(std::string content)
		{
			Error * err = new ErrorType(content);
			err->Catch();
			delete err;
		}

		// 에러가 발생했을 때 처리할 함수
		virtual void Catch();
	};
}