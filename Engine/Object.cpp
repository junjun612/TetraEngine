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
		if (returnObject == nullptr) Error::Throw<ObjectError>(objectName + " 오브젝트 객체 생성 실패");

		returnObject->Init();

		return returnObject;
	}

	//===
	// 컴포넌트 관리 함수
	void Object::Init()
	{
		if (componentManager == nullptr)
			Error::Throw<ObjectError>(name + " 오브젝트의 컴포넌트 매니저 생성 실패");
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