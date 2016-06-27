#include "Texture.h"

// �̱��� ����� ���� Include
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
			Error::Throw<ResourceError>(filePath + "���� �ؽ��� ������ ������ �� �����ϴ�.");
	}


	Texture *Texture::Create(std::string fileName, std::string filePath)
	{
		Texture *returnTexture = nullptr;
		returnTexture = new Texture(fileName, filePath);
		if (returnTexture == nullptr)
			Error::Throw<ResourceError>(fileName + "�� �ؽ��� ��ü ������ �����Ͽ����ϴ�.");

		returnTexture->SetTextureFromFile(filePath);

		return returnTexture;
	}

	void Texture::Release()
	{
		SAFE_RELEASE_DELETE(graphicTexture);
	}
}