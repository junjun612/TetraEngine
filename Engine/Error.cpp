#include "Error.h"


namespace Tetra
{
	Error::Error(std::string content)
	{
		this->content = content;
	}

	Error::~Error()
	{
	}


	void Error::Catch()
	{
		// �ڽ� Ŭ�������� override �ϸ�
		// ��� ����
	}
}