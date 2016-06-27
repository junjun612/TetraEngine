#pragma once
#include "System.h"

#include "GraphicTexture.h"
#include "RenderTarget.h"

namespace Tetra
{
	// ���� ���� (���ҽ�)
	class Texture;

	//===
	// ������ â�� �׷����� ���� ���� �߻�Ŭ����
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
		// ȭ�� ���� �Լ�
		virtual void ClearScreen() = 0;
		virtual void Present() = 0;

		//===
		// ����
		virtual void SetTransform(Matrix &mat) = 0;

		//===
		// �ؽ��� ����
		virtual GraphicTexture *CreateGraphicTexture(std::string filePath) = 0;
		virtual void DrawGraphicTexture(GraphicTexture *graphicTexture, Matrix &matrix) = 0;
		virtual void DrawTexture(Texture *graphicTexture, Matrix &matrix) = 0;

		//===
		// ����Ÿ�� ����
		virtual RenderTarget *CreateRenderTarget(int width, int height) = 0;
		virtual void SetRenderTarget(RenderTarget *rt) = 0;

		//===
		// �ʱ�ȭ �� ����
		virtual void Init() override = 0;
		virtual void LoopStart() override = 0;
		virtual void LoopEnd() override = 0;
		virtual void Release() override = 0;
	};
}