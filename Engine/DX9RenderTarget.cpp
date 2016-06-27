#include "DX9RenderTarget.h"

#include "DX9GraphicSystem.h"

namespace Tetra
{
	DX9RenderTarget::DX9RenderTarget(int width, int height) : RenderTarget(width, height)
	{
		surface = nullptr;
	}


	DX9RenderTarget::~DX9RenderTarget()
	{
	}

	DX9RenderTarget *DX9RenderTarget::CreateRenderTarget(GraphicSystem *graphicSystem, LPDIRECT3DSURFACE9 surface)
	{
		DX9RenderTarget *returnRenderTarget = new DX9RenderTarget(0, 0);

		returnRenderTarget->surface = surface;

		if (returnRenderTarget->GetSurface() == nullptr)
			Error::Throw<SystemError>("렌더타겟을 생성할 수 없습니다.");

		return returnRenderTarget;
	}

	void DX9RenderTarget::CreateRenderTarget(GraphicSystem *graphicSystem, int width, int height)
	{
		DX9GraphicSystem *dx9GraphicSystem = dynamic_cast<DX9GraphicSystem *>(graphicSystem);

		dx9GraphicSystem->GetDevice()->CreateRenderTarget(width, height, 
			D3DFMT_A8R8G8B8, D3DMULTISAMPLE_NONE, 0, TRUE, &surface, NULL);

		if (surface == nullptr)
			Error::Throw<SystemError>("렌더타겟을 생성할 수 없습니다.");
	}

	void DX9RenderTarget::Release()
	{
		SAFE_RELEASE(surface);
	}
}