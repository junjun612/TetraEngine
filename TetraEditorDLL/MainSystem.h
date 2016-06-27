#pragma once
#include "../Engine/SystemManager.h"
#include "../Engine/TimerSystem.h"
#include "../Engine/WindowSystem.h"
#include "../Engine/GraphicSystem.h"
#include "../Engine/ResourceManageSystem.h"
#include "../Engine/ObjectManageSystem.h"

#include "../Engine/Texture.h"

#include "../Engine/Transform.h"
#include "../Engine/SpriteRenderer.h"

static const int WINDOW_WIDTH = 800;
static const int WINDOW_HEIGHT = 600;
static const std::string PROJECT_NAME = "TestProject";

//===
// ������ ��ü ������ �����ϴ� �ý��� Ŭ����
class MainSystem : public Singleton<MainSystem>
{
private:
	GETTER(Tetra::SystemManager *, systemManager, SystemManager);
	bool isLoop;

public:
	Tetra::RenderTarget *renderTarget;

protected:
	MainSystem();

public:
	static MainSystem *Create();
	~MainSystem();

	void Init();
	void Loop();
	void Release();

	void EndLoop() { isLoop = false; }

	void ImportXML();
};

// ������ ��ü ������ �����ϴ� �ý��� Ŭ����
#define MAIN_SYS MainSystem::GetInstance()

// ������ â�� ����, �޽����� �����ϴ� Ŭ����
#define WND_SYS MAIN_SYS->GetSystemManager()->GetSystem<Tetra::WindowSystem>()

// ������ â�� �׷����� ���� ���� �߻�Ŭ����
#define GRP_SYS MAIN_SYS->GetSystemManager()->GetSystem<Tetra::GraphicSystem>()
#include "../Engine/DX9GraphicSystem.h"
#define DX9_SYS static_cast<DX9GraphicSystem>(GRP_SYS)

// ���ҽ��� ���õ� ��ü�� �����ϴ� Ŭ����
#define RES_SYS MAIN_SYS->GetSystemManager()->GetSystem<Tetra::ResourceManageSystem>()

// ������Ʈ�� ���õ� ��ü�� �����ϴ� Ŭ����
#define OBJ_SYS MAIN_SYS->GetSystemManager()->GetSystem<Tetra::ObjectManageSystem>()