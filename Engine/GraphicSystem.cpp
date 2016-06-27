#include "GraphicSystem.h"

#include "DX9GraphicSystem.h"

namespace Tetra
{
	GraphicSystem::GraphicSystem(HWND hWnd)
	{
		this->hWnd = hWnd;

		clearColor = Color3(0, 0, 0);
	}


	GraphicSystem::~GraphicSystem()
	{
	}

	// 유저에 맞는 그래픽시스템을 생성해준다.
	GraphicSystem *GraphicSystem::Create(HWND hWnd, GraphicSystemSelection selection)
	{
		GraphicSystem *returnSystem = nullptr;

		switch (selection)
		{
		default:
			Error::Throw<SystemError>("선택하신 그래픽 시스템을 찾을 수 없습니다.");
			break;

		case DX9:
			returnSystem = DX9GraphicSystem::Create(hWnd);
			break;
		}

		return returnSystem;
	}
}