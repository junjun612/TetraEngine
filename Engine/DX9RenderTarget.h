#pragma once
#include "RenderTarget.h"
#include "DX9.h"

namespace Tetra
{
	// 전방 선언
	class GraphicSystem;

	//===
	// DX9의 텍스쳐 클래스
	class DX9RenderTarget : public RenderTarget
	{
	private:
		GETTER(LPDIRECT3DSURFACE9, surface, Surface);

		void CreateRenderTarget(GraphicSystem *graphicSystem, int width, int height) override;

	public:
		DX9RenderTarget(int width, int height);
		static DX9RenderTarget *CreateRenderTarget(GraphicSystem *graphicSystem, LPDIRECT3DSURFACE9 surface);
		~DX9RenderTarget();

		// 삭제
		virtual void Release() override;
	};
}