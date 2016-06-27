#include "MainSystem.h"

MainSystem::MainSystem()
{
	systemManager = nullptr;
	isLoop = true;
}


MainSystem::~MainSystem()
{
}

MainSystem *MainSystem::Create()
{
	MainSystem *returnSystem = new MainSystem();
	if (returnSystem == nullptr) Tetra::Error::Throw<Tetra::SystemError>("메인 시스템 객체 생성 실패");

	return returnSystem;
}

void MainSystem::Init()
{
	try
	{
		systemManager = new Tetra::SystemManager();
		systemManager->AddSystem(Tetra::TimerSystem::Create());
		systemManager->AddSystem(Tetra::WindowSystem::Create(PROJECT_NAME, WINDOW_WIDTH, WINDOW_HEIGHT, false));
		systemManager->AddSystem(Tetra::GraphicSystem::Create(systemManager->GetSystem<Tetra::WindowSystem>()->GetHWND(), Tetra::GraphicSystem::GraphicSystemSelection::DX9));
		systemManager->AddSystem(Tetra::ResourceManageSystem::Create());
		systemManager->AddSystem(Tetra::ObjectManageSystem::Create());

		RES_SYS->AddResource(Tetra::Texture::Create("bg", "../Content/bg.jpg"));

		OBJ_SYS->Init();


		ImportXML();
	}
	catch (Tetra::Error *err)
	{
		err->Catch();
		SAFE_DELETE(err);
	}
}

void MainSystem::Loop()
{
	try
	{
		systemManager->LoopStart();

		systemManager->LoopEnd();
	}
	catch (Tetra::Error *err)
	{
		err->Catch();
		SAFE_DELETE(err);
	}
}

void MainSystem::Release()
{
	try
	{
		SAFE_RELEASE_DELETE(systemManager);
		this->DestroyInstance();
	}
	catch (Tetra::Error *err)
	{
		err->Catch();
		SAFE_DELETE(err);
	}
}

void MainSystem::ImportXML()
{
	// Project Setting
	GRP_SYS->SetClearColor(Color3(0, 0, 1));
	// Get Resource
	RES_SYS;
}