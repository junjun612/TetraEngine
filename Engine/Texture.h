#pragma once
#include "Resource.h"

namespace Tetra
{
	// 전방선언
	class GraphicTexture;

	//===
	// *.png, *.jpg 등
	// 이미지 파일을 불러온다.
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