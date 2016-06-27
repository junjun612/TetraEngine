#include "ObjectManageSystem.h"


namespace Tetra
{
	ObjectManageSystem::ObjectManageSystem()
	{
		objectCount = 0;
	}


	ObjectManageSystem::~ObjectManageSystem()
	{
	}


	ObjectManageSystem *ObjectManageSystem::Create()
	{
		ObjectManageSystem *returnSystem = new ObjectManageSystem();
		if (returnSystem == nullptr) Error::Throw<SystemError>("������Ʈ ���� ��ü ������ �����Ͽ����ϴ�.");

		return returnSystem;
	}

	//===
	// ������Ʈ �߰�
	void ObjectManageSystem::AddObject(Object *object)
	{
		objectList.push_back(object);
	}

	//===
	// ������Ʈ �޾ƿ���
	Object *ObjectManageSystem::GetObject(std::string objectName)
	{
		for (auto object : objectList)
		{
			if (object->GetName() == objectName)
			{
				return object;
			}
		}

		Error::Throw<ObjectError>(objectName + " ������Ʈ�� ã�� �� �����ϴ�.");
		return nullptr;
	}

	Object *ObjectManageSystem::GetObject(int index)
	{
		auto objectIter = objectList.begin();
		std::advance(objectIter, index);

		return (*objectIter);
	}

	//===
	// ����
	void ObjectManageSystem::Init()
	{
		for (auto object : objectList)
		{
			object->Init();
		}
	}


	void ObjectManageSystem::LoopStart()
	{
		objectCount = objectList.size();

		for (auto object : objectList)
		{
			object->LoopStart();
		}
	}

	void ObjectManageSystem::LoopEnd()
	{
		for (auto object = objectList.rbegin(); object != objectList.rend(); object++)
		{
			(*object)->LoopEnd();
		}
	}

	void ObjectManageSystem::Release()
	{
		for (auto object : objectList)
		{
			SAFE_RELEASE_DELETE(object);
		}
	}
}