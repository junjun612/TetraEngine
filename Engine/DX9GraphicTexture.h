#pragma once
#include "GraphicTexture.h"
#include "DX9.h"

namespace Tetra
{
	// 전방 선언
	class GraphicSystem;

	//===
	// DX9의 텍스쳐 클래스
	class DX9GraphicTexture : public GraphicTexture
	{
	private:
		GETTER(LPDIRECT3DTEXTURE9, texture, Texture);
		void SetTextureFromFile(GraphicSystem *graphicSystem, std::string filePath) override;

	public:
		DX9GraphicTexture();
		virtual ~DX9GraphicTexture();

		void Release() override;
	};
}