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

	// ������ �´� �׷��Ƚý����� �������ش�.
	GraphicSystem *GraphicSystem::Create(HWND hWnd, GraphicSystemSelection selection)
	{
		GraphicSystem *returnSystem = nullptr;

		switch (selection)
		{
		default:
			Error::Throw<SystemError>("�����Ͻ� �׷��� �ý����� ã�� �� �����ϴ�.");
			break;

		case DX9:
			returnSystem = DX9GraphicSystem::Create(hWnd);
			break;
		}

		return returnSystem;
	}
}