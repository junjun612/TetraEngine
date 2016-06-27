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
		// 자식 클래스에서 override 하면
		// 사용 가능
	}
}