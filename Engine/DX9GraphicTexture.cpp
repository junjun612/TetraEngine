#include "DX9GraphicTexture.h"

#include "DX9GraphicSystem.h"

namespace Tetra
{
	DX9GraphicTexture::DX9GraphicTexture()
	{
		texture = nullptr;
	}


	DX9GraphicTexture::~DX9GraphicTexture()
	{
	}

	void DX9GraphicTexture::SetTextureFromFile(GraphicSystem *graphicSystem, std::string filePath)
	{
		DX9GraphicSystem *dx9GraphicSystem = dynamic_cast<DX9GraphicSystem *>(graphicSystem);

		D3DXCreateTextureFromFileEx(dx9GraphicSystem->GetDevice(), filePath.c_str(), D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2,
			1, 0, D3DFMT_UNKNOWN, D3DPOOL_MANAGED, D3DX_FILTER_NONE, D3DX_FILTER_NONE,
			NULL, NULL, NULL, &texture);

		if (texture == nullptr)
			Error::Throw<SystemError>(filePath + " 에서 텍스쳐를 생성할 수 없습니다.");
	}

	void DX9GraphicTexture::Release()
	{
		SAFE_RELEASE(texture);
	}
}