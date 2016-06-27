#pragma once
#include "System.h"
#include "Windows.h"

namespace Tetra
{
	//===
	// 윈도우 창을 띄우고, 메시지를 관리하는 클래스
	class WindowSystem : public System
	{
	private:
		HINSTANCE hInstance;
		GETTER(HWND, hWnd, HWND);
		MSG msg;

		static LRESULT WINAPI MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

	protected:
		std::string windowTitle;
		int width, height;

	protected:
		WindowSystem(std::string windowTitle, int width, int height);

	public:
		static WindowSystem *Create(std::string windowTitle, int width, int height, bool isShow = true);
		virtual ~WindowSystem();

		//===
		// 초기화 및 관리
		void Init() override;
		void LoopStart() override;
		void LoopEnd() override;
		void Release() override;
	};
}