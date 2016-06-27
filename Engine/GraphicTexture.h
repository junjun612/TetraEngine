#pragma once
#include "Core.h"

namespace Tetra
{
	//===
	// 전방 선언
	class GraphicSystem;

	//===
	// GraphicSystem 마다 하나씩 있는 텍스쳐 클래스의 인터페이스
	class GraphicTexture
	{
	private:
		virtual void SetTextureFromFile(GraphicSystem *graphicSystem, std::string filePath) = 0;

	protected:
		GraphicTexture();

	public:
		template <typename GraphicTextureType, typename GraphicSystemType>
		static GraphicTexture *Create(GraphicSystem *graphicSystem, std::string filePath)
		{
			GraphicTexture *returnTexture = nullptr;
			returnTexture = new GraphicTextureType();
			if (returnTexture == nullptr)
				Error::Throw<SystemError>(filePath + " 그래픽텍스쳐 객체 생성을 실패하였습니다.");

			// 텍스쳐 시스템에 맞는 그래픽시스템을 쓰고 있을 경우
			if (dynamic_cast<GraphicSystemType *>(graphicSystem))
			{
				returnTexture->SetTextureFromFile(graphicSystem, filePath);
			}
			else
			{
				Error::Throw<SystemError>(filePath + " 가 맞는 그래픽시스템으로 초기화되지 않았습니다.");
			}

			return returnTexture;
		}
		virtual ~GraphicTexture();

		// 삭제
		virtual void Release() = 0;
	};
}