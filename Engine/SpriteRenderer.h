#pragma once
#include "Component.h"

namespace Tetra
{
	// ���ҽ� �ؽ���
	class Texture;

	//===
	// Texture �� ������ִ� ������Ʈ
	class SpriteRenderer : public Component
	{
	private:
		GETTERSETTER(Texture *, sourceTexture, SourceTexture);

	protected:
		SpriteRenderer(Object *object);

	public:
		static SpriteRenderer *Create(Object *object);
		~SpriteRenderer();

		//===
		// ����
		void Init() override;
		void LoopStart() override;
		void LoopEnd() override;
		void Release() override;

		void ExportXML() override;
		void ImportXML() override;
	};
}