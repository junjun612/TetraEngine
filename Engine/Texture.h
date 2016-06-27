#pragma once
#include "Resource.h"

namespace Tetra
{
	// ���漱��
	class GraphicTexture;

	//===
	// *.png, *.jpg ��
	// �̹��� ������ �ҷ��´�.
	class Texture : public Resource
	{
	private:
		GETTER(GraphicTexture *, graphicTexture, GraphicTexture);
		void SetTextureFromFile(std::string filePath);

	protected:
		Texture(std::string fileName, std::string filePath);

	public:
		static Texture *Create(std::string fileName, std::string filePath);
		~Texture();

		void Release() override;
	};
}