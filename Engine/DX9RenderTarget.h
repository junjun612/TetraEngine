#pragma once
#include "RenderTarget.h"
#include "DX9.h"

namespace Tetra
{
	// ���� ����
	class GraphicSystem;

	//===
	// DX9�� �ؽ��� Ŭ����
	class DX9RenderTarget : public RenderTarget
	{
	private:
		GETTER(LPDIRECT3DSURFACE9, surface, Surface);

		void CreateRenderTarget(GraphicSystem *graphicSystem, int width, int height) override;

	public:
		DX9RenderTarget(int width, int height);
		static DX9RenderTarget *CreateRenderTarget(GraphicSystem *graphicSystem, LPDIRECT3DSURFACE9 surface);
		~DX9RenderTarget();

		// ����
		virtual void Release() override;
	};
}