#include "Object.h"


namespace Tetra
{
	Object::Object(std::string objectName)
	{
		name = objectName;
		componentManager = ComponentManager::Create();
	}


	Object::~Object()
	{
	}

	Object *Object::Create(std::string objectName)
	{
		Object *returnObject = nullptr;
		returnObject = new Object(objectName);
		if (returnObject == nullptr) Error::Throw<ObjectError>(objectName + " ������Ʈ ��ü ���� ����");

		returnObject->Init();

		return returnObject;
	}

	//===
	// ������Ʈ ���� �Լ�
	void Object::Init()
	{
		if (componentManager == nullptr)
			Error::Throw<ObjectError>(name + " ������Ʈ�� ������Ʈ �Ŵ��� ���� ����");
	}

	void Object::LoopStart()
	{
		componentManager->LoopStart();
	}

	void Object::LoopEnd()
	{
		componentManager->LoopEnd();
	}

	void Object::Release()
	{
		SAFE_RELEASE_DELETE(componentManager);
	}
}