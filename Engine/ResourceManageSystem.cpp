#include "ResourceManageSystem.h"


namespace Tetra
{
	ResourceManageSystem::ResourceManageSystem()
	{
		resourceCount = 0;
	}


	ResourceManageSystem::~ResourceManageSystem()
	{
	}

	ResourceManageSystem *ResourceManageSystem::Create()
	{
		ResourceManageSystem *returnSystem = new ResourceManageSystem();
		if (returnSystem == nullptr) Error::Throw<SystemError>("리소스 관리 객체 생성에 실패하였습니다.");

		return returnSystem;
	}

	//===
	// 리소스 추가
	void ResourceManageSystem::AddResource(Resource *resource)
	{
		resourceList.push_back(resource);

		resourceCount++;
	}

	void ResourceManageSystem::AddResource(std::string xmlPath)
	{
		/*
		tinyxml2::XMLDocument document;
		document.LoadFile(resourceFilePath.c_str());
		tinyxml2::XMLNode *rootNode = document.FirstChild();

		tinyxml2::XMLElement *resourceElement = rootNode->FirstChildElement();
		while (resourceElement != NULL)
		{
		std::string typeName = resourceElement->Value();
		std::string filePath = resourceElement->GetText();

		for each(auto resource in resourceTypeList)
		{
		if (resource->GetResourceType() == typeName)
		{
		this->AddResource(resource->CreateSameType(filePath));
		break;
		}
		}
		resourceElement = resourceElement->NextSiblingElement();
		}
		*/
	}

	//===
	// 리소스 받아오기
	Resource *ResourceManageSystem::GetResource(std::string fileName)
	{
		for (auto resource : resourceList)
		{
			if (resource->GetFileName() == fileName)
			{
				return resource;
			}
		}

		Error::Throw<ResourceError>(fileName + " 리소스를 찾을 수 없습니다.");
		return nullptr;
	}
	Resource *ResourceManageSystem::GetResource(int index)
	{
		auto resourceIter = resourceList.begin();
		std::advance(resourceIter, index);

		return (*resourceIter);
	}

	//===
	// 초기화 및 관리
	void ResourceManageSystem::Init()
	{

	}
	void ResourceManageSystem::LoopStart()
	{
	}

	void ResourceManageSystem::LoopEnd()
	{
	}

	void ResourceManageSystem::Release()
	{
		for (auto resource : resourceList)
		{
			SAFE_RELEASE_DELETE(resource);
		}

	}
}