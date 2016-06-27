#pragma once
#include "System.h"

#include "GraphicTexture.h"
#include "RenderTarget.h"

namespace Tetra
{
	// 전방 선언 (리소스)
	class Texture;

	//===
	// 윈도우 창에 그래픽을 띄우기 위한 추상클래스
	class GraphicSystem : public System
	{
	protected:
		HWND hWnd;

		PROTECTED_GETTER(RenderTarget *, presentRenderTarget, RenderTarget);

		PROTECTED_SETTER(Color3, clearColor, ClearColor);

	protected:
		GraphicSystem(HWND hWnd);

	public:
		enum GraphicSystemSelection { DX9, DX11 };
		static GraphicSystem *Create(HWND hWnd, GraphicSystemSelection selection);
		virtual ~GraphicSystem();

		//===
		// 화면 관리 함수
		virtual void ClearScreen() = 0;
		virtual void Present() = 0;

		//===
		// 수학
		virtual void SetTransform(Matrix &mat) = 0;

		//===
		// 텍스쳐 관리
		virtual GraphicTexture *CreateGraphicTexture(std::string filePath) = 0;
		virtual void DrawGraphicTexture(GraphicTexture *graphicTexture, Matrix &matrix) = 0;
		virtual void DrawTexture(Texture *graphicTexture, Matrix &matrix) = 0;

		//===
		// 렌더타겟 관리
		virtual RenderTarget *CreateRenderTarget(int width, int height) = 0;
		virtual void SetRenderTarget(RenderTarget *rt) = 0;

		//===
		// 초기화 및 관리
		virtual void Init() override = 0;
		virtual void LoopStart() override = 0;
		virtual void LoopEnd() override = 0;
		virtual void Release() override = 0;
	};
}