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
// ������ ��ü ������ �����ϴ� �ý��� Ŭ����
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

// ������ ��ü ������ �����ϴ� �ý��� Ŭ����
#define MAIN_SYS MainSystem::GetInstance()

// ������ â�� ����, �޽����� �����ϴ� Ŭ����
#define WND_SYS MAIN_SYS->GetSystemManager()->GetSystem<WindowSystem>()

// ������ â�� �׷����� ���� ���� �߻�Ŭ����
#define GRP_SYS MAIN_SYS->GetSystemManager()->GetSystem<GraphicSystem>()
	#include "../Engine/DX9GraphicSystem.h"
	#define DX9_SYS static_cast<DX9GraphicSystem>(GRP_SYS)

// ���ҽ��� ���õ� ��ü�� �����ϴ� Ŭ����
#define RES_SYS MAIN_SYS->GetSystemManager()->GetSystem<ResourceManageSystem>()

// ������Ʈ�� ���õ� ��ü�� �����ϴ� Ŭ����
#define OBJ_SYS MAIN_SYS->GetSystemManager()->GetSystem<ObjectManageSystem>()