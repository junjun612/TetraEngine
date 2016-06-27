#pragma once
#include "Core.h"

namespace Tetra
{
	//===
	// ���� ����
	class GraphicSystem;

	//===
	// Multi Render Target �� �ϱ����� RenderTarget �������̽�
	class RenderTarget
	{
	private:
		virtual void CreateRenderTarget(GraphicSystem *graphicSystem, int width, int height) = 0;

	protected:
		PROTECTED_GETTER(int, width, Width);
		PROTECTED_GETTER(int, height, Height);

	protected:
		RenderTarget(int width, int height);

	public:
		template <typename RenderTargetType, typename GraphicSystemType>
		static RenderTarget *Create(GraphicSystem *graphicSystem, int width, int height)
		{
			RenderTarget *returnRenderTarget = nullptr;
			returnRenderTarget = new RenderTargetType(width, height);
			if (returnRenderTarget == nullptr)
				Error::Throw<SystemError>("����Ÿ�� ��ü ������ �����Ͽ����ϴ�.");

			// ����Ÿ�� �ý��ۿ� �´� �׷��Ƚý����� ���� ���� ���
			if (dynamic_cast<GraphicSystemType *>(graphicSystem))
			{
				returnRenderTarget->CreateRenderTarget(graphicSystem, width, height);
			}
			else
			{
				Error::Throw<SystemError>("����Ÿ���� �´� �׷��Ƚý������� �ʱ�ȭ���� �ʾҽ��ϴ�.");
			}

			return returnRenderTarget;
		}
		~RenderTarget();

		// ����
		virtual void Release() = 0;
	};
}
