#pragma once
// Manager
#include "../Engine/SystemManager.h"
	#include "../Engine/TimerSystem.h"
	#include "../Engine/WindowSystem.h"
	#include "../Engine/GraphicSystem.h"
	#include "../Engine/ResourceManageSystem.h"
	#include "../Engine/ObjectManageSystem.h"

// Resource
#include "../Engine/Texture.h"

// Component
#include "../Engine/Transform.h"
#include "../Engine/SpriteRenderer.h"

using namespace Tetra;

//===
// 게임의 전체 루프를 관리하는 시스템 클래스
class MainSystem : public Singleton<MainSystem>
{
private:
	GETTER(SystemManager *, systemManager, SystemManager);

	bool isLoop;

protected:
	MainSystem();

public:
	static MainSystem *Create();
	~MainSystem();

	int StartSystem();
	void EndLoop() { isLoop = false; }

	void ImportXML();
};

// 게임의 전체 루프를 관리하는 시스템 클래스
#define MAIN_SYS MainSystem::GetInstance()

// 윈도우 창을 띄우고, 메시지를 관리하는 클래스
#define WND_SYS MAIN_SYS->GetSystemManager()->GetSystem<WindowSystem>()

// 윈도우 창에 그래픽을 띄우기 위한 추상클래스
#define GRP_SYS MAIN_SYS->GetSystemManager()->GetSystem<GraphicSystem>()
	#include "../Engine/DX9GraphicSystem.h"
	#define DX9_SYS static_cast<DX9GraphicSystem>(GRP_SYS)

// 리소스에 괸련된 전체를 관리하는 클래스
#define RES_SYS MAIN_SYS->GetSystemManager()->GetSystem<ResourceManageSystem>()

// 오브젝트에 괸련된 전체를 관리하는 클래스
#define OBJ_SYS MAIN_SYS->GetSystemManager()->GetSystem<ObjectManageSystem>()