#include "SystemManager.h"

namespace Tetra
{
	SystemManager::SystemManager()
	{
	}


	SystemManager::~SystemManager()
	{
	}

	// 시스템 추가
	void SystemManager::AddSystem(System *system)
	{
		systemList.push_back(system);
	}

	//===
	// 전체 시스템 관리
	void SystemManager::LoopStart()
	{
		for (auto system : systemList)
		{
			system->LoopStart();
		}
	}

	void SystemManager::LoopEnd()
	{
		for (auto systemIter = systemList.rbegin(); systemIter != systemList.rend(); systemIter++)
		{
			(*systemIter)->LoopEnd();
		}
	}

	void SystemManager::Release()
	{
		for (auto system : systemList)
		{
			SAFE_RELEASE_DELETE(system);
		}
	}
}