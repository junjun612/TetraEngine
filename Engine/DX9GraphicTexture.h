#pragma once
#include "GraphicTexture.h"
#include "DX9.h"

namespace Tetra
{
	// ���� ����
	class GraphicSystem;

	//===
	// DX9�� �ؽ��� Ŭ����
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