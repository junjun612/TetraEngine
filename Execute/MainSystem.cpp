#include "MainSystem.h"

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const std::string PROJECT_NAME = "TestProject";

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
	if (returnSystem == nullptr) Error::Throw<SystemError>("메인 시스템 객체 생성 실패");

	return returnSystem;
}

int MainSystem::StartSystem()
{
	try
	{
		//===
		// 시스템
		// 시스템 구조 초기화
		systemManager = new SystemManager();
		systemManager->AddSystem(TimerSystem::Create()); 
		systemManager->AddSystem(WindowSystem::Create(PROJECT_NAME, WINDOW_WIDTH, WINDOW_HEIGHT));
		systemManager->AddSystem(GraphicSystem::Create(systemManager->GetSystem<WindowSystem>()->GetHWND(), GraphicSystem::GraphicSystemSelection::DX9));
		systemManager->AddSystem(ResourceManageSystem::Create());
		systemManager->AddSystem(ObjectManageSystem::Create());

		// TODO: XML 받아오기
		ImportXML();

		//===
		// 리소스
		// 리소스 등록
		RES_SYS->AddResource(Tetra::Texture::Create("bg", "../Content/bg.jpg"));

		//===
		// 오브젝트
		// 오브젝트 등록 방법 1
		OBJ_SYS->AddObject(Object::Create("Object1"));

		// 오브젝트 등록 방법 2
		Object *object2 = Object::Create("Object2");
		OBJ_SYS->AddObject(object2);

		// 오브젝트 초기화
		OBJ_SYS->Init();

		//===
		// 컴포넌트 값 설정
		OBJ_SYS->GetObject("Object1")->AddComponent<Transform>();
		OBJ_SYS->GetObject("Object1")->AddComponent<SpriteRenderer>();
			OBJ_SYS->GetObject("Object1")->GetComponent<SpriteRenderer>()->SetSourceTexture(RES_SYS->GetResource<Texture>("bg"));

		object2->AddComponent<Transform>();
			object2->GetComponent<Transform>()->position = Vector3(200, 300, 0);
		object2->AddComponent<SpriteRenderer>();
		object2->GetComponent<SpriteRenderer>()->SetSourceTexture(RES_SYS->GetResource<Texture>("bg"));

		while (isLoop)
		{
			systemManager->LoopStart();

			systemManager->LoopEnd();
		}
	}
	catch (Error *err)
	{
		err->Catch();
		SAFE_DELETE(err);
	}

	SAFE_RELEASE_DELETE(systemManager);
	this->DestroyInstance();
	return 0;
}

void MainSystem::ImportXML()
{
	// Project Setting
	GRP_SYS->SetClearColor(Color3(0, 0, 1));

	// Get Resource
	RES_SYS;
}