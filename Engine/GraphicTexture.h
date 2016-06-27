#pragma once
#include "Core.h"

namespace Tetra
{
	//===
	// ���� ����
	class GraphicSystem;

	//===
	// GraphicSystem ���� �ϳ��� �ִ� �ؽ��� Ŭ������ �������̽�
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
				Error::Throw<SystemError>(filePath + " �׷����ؽ��� ��ü ������ �����Ͽ����ϴ�.");

			// �ؽ��� �ý��ۿ� �´� �׷��Ƚý����� ���� ���� ���
			if (dynamic_cast<GraphicSystemType *>(graphicSystem))
			{
				returnTexture->SetTextureFromFile(graphicSystem, filePath);
			}
			else
			{
				Error::Throw<SystemError>(filePath + " �� �´� �׷��Ƚý������� �ʱ�ȭ���� �ʾҽ��ϴ�.");
			}

			return returnTexture;
		}
		virtual ~GraphicTexture();

		// ����
		virtual void Release() = 0;
	};
}