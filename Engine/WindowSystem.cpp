#include "WindowSystem.h"

// MainSystem�� �޾ƿ��� ����
#include "../Execute/MainSystem.h"

namespace Tetra
{
	WindowSystem::WindowSystem(std::string windowTitle, int width, int height)
		: windowTitle(windowTitle), width(width), height(height)
	{
		hInstance = NULL;
		hWnd = NULL;

		ZeroMemory(&msg, sizeof(MSG));
	}


	WindowSystem::~WindowSystem()
	{
	}

	WindowSystem *WindowSystem::Create(std::string windowTitle, int width, int height, bool isShow)
	{
		WindowSystem *returnSystem = new WindowSystem(windowTitle, width, height);
		if (returnSystem == nullptr) Error::Throw<SystemError>("������ ��ü ������ �����Ͽ����ϴ�.");

		returnSystem->Init();
		if (returnSystem->GetHWND() == NULL)
		{
			SAFE_RELEASE(returnSystem);
			Error::Throw<SystemError>("������ �ڵ� ������ �����Ͽ����ϴ�.");
		}

		if (isShow)
			ShowWindow(returnSystem->GetHWND(), SW_SHOWDEFAULT);
		UpdateWindow(returnSystem->GetHWND());

		return returnSystem;
	}

	void WindowSystem::Init()
	{
		// �⺻���� ������ ����
		WNDCLASSEX wc =
		{
			sizeof(WNDCLASSEX), CS_CLASSDC, WindowSystem::MsgProc, 0L, 0L,
			GetModuleHandle(NULL), NULL, LoadCursor(NULL, IDC_ARROW), NULL, NULL,
			"WindowSystem", NULL
		};
		RegisterClassEx(&wc);
		hInstance = wc.hInstance;

		// �����츦 �߽ɿ� ������ �ش�.
		int screenResolutionX = GetSystemMetrics(SM_CXSCREEN);
		int screenResolutionY = GetSystemMetrics(SM_CYSCREEN);

		int windowX = (screenResolutionX / 2) - (width / 2);
		int windowY = (screenResolutionY / 2) - (height / 2);

		hWnd = CreateWindow("WindowSystem", windowTitle.c_str(),
			WS_OVERLAPPEDWINDOW, windowX, windowY, width, height,
			NULL, NULL, wc.hInstance, NULL);
	}

	void WindowSystem::LoopStart()
	{
		if (msg.message == WM_QUIT)
		{
			MainSystem::GetInstance()->EndLoop();
		}
	}

	void WindowSystem::LoopEnd()
	{
		// ������ ���������� �޽��� �˻縦 �Ѵ�.
		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	void WindowSystem::Release()
	{
		UnregisterClass("WindowSystem", hInstance);
	}

	// �޽��� ���ν���
	LRESULT WINAPI WindowSystem::MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		PAINTSTRUCT ps;
		HDC hdc;

		switch (msg)
		{
		case WM_PAINT:
			hdc = BeginPaint(hWnd, &ps);
			EndPaint(hWnd, &ps);
			break;

		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;

		default:
			return DefWindowProc(hWnd, msg, wParam, lParam);
		}

		return 0;
	}
}