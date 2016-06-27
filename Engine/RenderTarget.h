#pragma once
#include "Core.h"

namespace Tetra
{
	//===
	// 전방 선언
	class GraphicSystem;

	//===
	// Multi Render Target 을 하기위한 RenderTarget 인터페이스
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
				Error::Throw<SystemError>("렌더타겟 객체 생성을 실패하였습니다.");

			// 렌더타겟 시스템에 맞는 그래픽시스템을 쓰고 있을 경우
			if (dynamic_cast<GraphicSystemType *>(graphicSystem))
			{
				returnRenderTarget->CreateRenderTarget(graphicSystem, width, height);
			}
			else
			{
				Error::Throw<SystemError>("렌더타겟이 맞는 그래픽시스템으로 초기화되지 않았습니다.");
			}

			return returnRenderTarget;
		}
		~RenderTarget();

		// 삭제
		virtual void Release() = 0;
	};
}
