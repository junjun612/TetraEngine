#pragma once
#include "Core.h"
#include "Windows.h"

namespace Tetra
{
	//===
	// �ý��� ���� ó��
	class SystemError : public Error
	{
	public:
		SystemError(std::string content) : Error(content) {}

		void Catch() override
		{
			std::string errorMessage = "�ý��� ������ �߻��߽��ϴ�. \n���� ���� : " + content;
			MessageBox(NULL, errorMessage.c_str(), "�ý��� ����", MB_OK);
		}
	};

	//===
	// ���α׷��� �⺻ ������ ���� �ý��� �������̽�
	class System
	{
	protected:
		System();

	public:
		virtual ~System();

		// ���� �ؾ� �ϴ� �Լ���
		virtual void Init() = 0;
		virtual void LoopStart() = 0;
		virtual void LoopEnd() = 0;
		virtual void Release() = 0;
	};
}