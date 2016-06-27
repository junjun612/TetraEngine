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
		if (returnSystem == nullptr) Error::Throw<ObjectError>("오브젝트 내의 컴포넌트 매니저 객체 생성에 실패하였습니다.");

		return returnSystem;
	}

	//===
	// 관리
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