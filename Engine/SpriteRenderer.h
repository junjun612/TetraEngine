#pragma once
#include "Component.h"

namespace Tetra
{
	// 리소스 텍스쳐
	class Texture;

	//===
	// Texture 를 출력해주는 컴포넌트
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
		// 관리
		void Init() override;
		void LoopStart() override;
		void LoopEnd() override;
		void Release() override;

		void ExportXML() override;
		void ImportXML() override;
	};
}