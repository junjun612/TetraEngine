#include "ComponentManager.h"

#include "Object.h"


namespace Tetra
{
	ComponentManager::ComponentManager()
	{
	}


	ComponentManager::~ComponentManager()
	{
	}

	ComponentManager *ComponentManager::Create()
	{
		ComponentManager *returnSystem = new ComponentManager();
		if (returnSystem == nullptr) Error::Throw<ObjectError>("������Ʈ ���� ������Ʈ �Ŵ��� ��ü ������ �����Ͽ����ϴ�.");

		return returnSystem;
	}

	//===
	// ����
	void ComponentManager::Init()
	{
		for (auto component : componentList)
		{
			component->Init();
		}
	}


	void ComponentManager::LoopStart()
	{
		for (auto component : componentList)
		{
			component->LoopStart();
		}
	}

	void ComponentManager::LoopEnd()
	{
		for (auto component = componentList.rbegin(); component != componentList.rend(); component++)
		{
			(*component)->LoopEnd();
		}
	}

	void ComponentManager::Release()
	{
		for (auto component : componentList)
		{
			SAFE_RELEASE_DELETE(component);
		}
	}
}