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
		if (returnSystem == nullptr) Error::Throw<SystemError>("���ҽ� ���� ��ü ������ �����Ͽ����ϴ�.");

		return returnSystem;
	}

	//===
	// ���ҽ� �߰�
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
	// ���ҽ� �޾ƿ���
	Resource *ResourceManageSystem::GetResource(std::string fileName)
	{
		for (auto resource : resourceList)
		{
			if (resource->GetFileName() == fileName)
			{
				return resource;
			}
		}

		Error::Throw<ResourceError>(fileName + " ���ҽ��� ã�� �� �����ϴ�.");
		return nullptr;
	}
	Resource *ResourceManageSystem::GetResource(int index)
	{
		auto resourceIter = resourceList.begin();
		std::advance(resourceIter, index);

		return (*resourceIter);
	}

	//===
	// �ʱ�ȭ �� ����
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