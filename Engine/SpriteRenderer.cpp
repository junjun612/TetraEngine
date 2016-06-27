#include "SpriteRenderer.h"

#include "../Execute/MainSystem.h"

namespace Tetra
{
	SpriteRenderer::SpriteRenderer(Object *object) : Component(object)
	{
		sourceTexture = nullptr;
	}


	SpriteRenderer::~SpriteRenderer()
	{
	}

	SpriteRenderer *SpriteRenderer::Create(Object *object)
	{
		SpriteRenderer *returnComponent = new SpriteRenderer(object);
		if (returnComponent == nullptr);

		return returnComponent;
	}

	void SpriteRenderer::Init()
	{

	}

	void SpriteRenderer::LoopStart()
	{
		if (sourceTexture == nullptr)
			Error::JustCatch<ObjectError>(object->GetName() + "���� Texture�� �ҽ��� ã�� �� �����ϴ�.");

		GRP_SYS->DrawTexture(sourceTexture, object->GetComponent<Transform>()->matrix);
	}

	void SpriteRenderer::LoopEnd()
	{

	}

	void SpriteRenderer::Release()
	{

	}

	void SpriteRenderer::ExportXML()
	{

	}

	void SpriteRenderer::ImportXML()
	{

	}
}