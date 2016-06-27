#pragma once
#include "GraphicSystem.h"
#include "DX9.h"

#include "DX9GraphicTexture.h"
#include "DX9RenderTarget.h"

namespace Tetra
{
	//===
	// DX9 �׷��� ���� Ŭ����
	class DX9GraphicSystem : public GraphicSystem
	{
	private:
		LPDIRECT3D9 d3d;
		GETTER(LPDIRECT3DDEVICE9, device, Device);

		LPD3DXSPRITE sprite;

	protected:
		DX9GraphicSystem(HWND hWnd);

	public:
		static DX9GraphicSystem *Create(HWND hWnd);
		virtual ~DX9GraphicSystem();

		//===
		// ȭ�� ���� �Լ�
		void ClearScreen() override;
		void Present() override;

		//===
		// ����
		void SetTransform(Matrix &mat) override;
		D3DXVECTOR3 GetSuitableVector(Vector3 vec);
		D3DXMATRIX GetSuitableMatrix(Matrix mat);

		//===
		// �ؽ��� ����
		GraphicTexture *CreateGraphicTexture(std::string filePath) override;
		void DrawGraphicTexture(GraphicTexture *graphicTexture, Matrix &matrix) override;
		void DrawTexture(Texture *graphicTexture, Matrix &matrix) override;

		//===
		// ����Ÿ�� ����
		RenderTarget *CreateRenderTarget(int width, int height) override;
		void SetRenderTarget(RenderTarget *rt) override;

		//===
		// �ʱ�ȭ �� ����
		void Init() override;
		void LoopStart() override;
		void LoopEnd() override;
		void Release() override;
	};
}