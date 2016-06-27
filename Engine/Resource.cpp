#include "Resource.h"


namespace Tetra
{
	Resource::Resource(std::string fileName, std::string filePath)
	{
		this->fileName = fileName;
		this->filePath = filePath;
	}


	Resource::~Resource()
	{
	}
}