#include "Texture.h"

// 싱글톤 사용을 위한 Include
#include "../Execute/MainSystem.h"

namespace Tetra
{
	Texture::Texture(std::string fileName, std::string filePath) : Resource(fileName, filePath)
	{
		graphicTexture = nullptr;
	}


	Texture::~Texture()
	{
	}

	void Texture::SetTextureFromFile(std::string filePath)
	{
		graphicTexture = GRP_SYS->CreateGraphicTexture(filePath);
		if (graphicTexture == nullptr)
			Error::Throw<ResourceError>(filePath + "에서 텍스쳐 파일을 생성할 수 없습니다.");
	}


	Texture *Texture::Create(std::string fileName, std::string filePath)
	{
		Texture *returnTexture = nullptr;
		returnTexture = new Texture(fileName, filePath);
		if (returnTexture == nullptr)
			Error::Throw<ResourceError>(fileName + "의 텍스쳐 객체 생성에 실패하였습니다.");

		returnTexture->SetTextureFromFile(filePath);

		return returnTexture;
	}

	void Texture::Release()
	{
		SAFE_RELEASE_DELETE(graphicTexture);
	}
}