#include "WindowSystem.h"

// MainSystem을 받아오기 위함
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
		if (returnSystem == nullptr) Error::Throw<SystemError>("윈도우 객체 생성에 실패하였습니다.");

		returnSystem->Init();
		if (returnSystem->GetHWND() == NULL)
		{
			SAFE_RELEASE(returnSystem);
			Error::Throw<SystemError>("윈도우 핸들 생성에 실패하였습니다.");
		}

		if (isShow)
			ShowWindow(returnSystem->GetHWND(), SW_SHOWDEFAULT);
		UpdateWindow(returnSystem->GetHWND());

		return returnSystem;
	}

	void WindowSystem::Init()
	{
		// 기본적인 윈도우 생성
		WNDCLASSEX wc =
		{
			sizeof(WNDCLASSEX), CS_CLASSDC, WindowSystem::MsgProc, 0L, 0L,
			GetModuleHandle(NULL), NULL, LoadCursor(NULL, IDC_ARROW), NULL, NULL,
			"WindowSystem", NULL
		};
		RegisterClassEx(&wc);
		hInstance = wc.hInstance;

		// 윈도우를 중심에 설정해 준다.
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
		// 루프의 마지막에서 메시지 검사를 한다.
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

	// 메시지 프로시져
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