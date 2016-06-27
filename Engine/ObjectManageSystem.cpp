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
		if (returnSystem == nullptr) Error::Throw<SystemError>("오브젝트 관리 객체 생성에 실패하였습니다.");

		return returnSystem;
	}

	//===
	// 오브젝트 추가
	void ObjectManageSystem::AddObject(Object *object)
	{
		objectList.push_back(object);
	}

	//===
	// 오브젝트 받아오기
	Object *ObjectManageSystem::GetObject(std::string objectName)
	{
		for (auto object : objectList)
		{
			if (object->GetName() == objectName)
			{
				return object;
			}
		}

		Error::Throw<ObjectError>(objectName + " 오브젝트를 찾을 수 없습니다.");
		return nullptr;
	}

	Object *ObjectManageSystem::GetObject(int index)
	{
		auto objectIter = objectList.begin();
		std::advance(objectIter, index);

		return (*objectIter);
	}

	//===
	// 관리
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