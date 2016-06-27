#pragma once
#include <string>
#include <memory>

/*
// ���� ��� ��
	class SystemError : public Error
	{
		public:
			SystemError(std::string content) : Error(content)  {}
	
			void Catch() override
			{
			std::cout << "�ý��� ���� : " << content << std::endl;
			}
	};
*/

namespace Tetra
{
	//===
	// try ~catch ������ ����� �� �ִ� ���� Ŭ����
	class Error
	{
	protected:
		std::string content;

		Error(std::string content);

	public:
		virtual ~Error();

		// ������ ������.
		template <typename ErrorType>
		static void Throw(std::string content)
		{
			throw (new ErrorType(content));
		}

		// �������� �ʰ� Catch �� �Ѵ�.
		template <typename ErrorType>
		static void JustCatch(std::string content)
		{
			Error * err = new ErrorType(content);
			err->Catch();
			delete err;
		}

		// ������ �߻����� �� ó���� �Լ�
		virtual void Catch();
	};
}