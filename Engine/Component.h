#pragma once
#include "Core.h"

namespace Tetra
{
	// ���漱��
	class Object;

	//===
	// ������Ʈ ���� ������Ʈ
	class Component
	{
	protected:
		// ���� ������Ʈ
		Object *object;

	protected:
		Component(Object *object);

	public:
		template<typename ComponentType>
		static ComponentType *Create(Object *object)
		{
			return ComponentType::Create(object);
		}
		~Component();

		//===
		// ����
		virtual void Init() = 0;
		virtual void LoopStart() = 0;
		virtual void LoopEnd() = 0;
		virtual void Release() = 0;

		//===
		// XML ����
		virtual void ExportXML() = 0;
		virtual void ImportXML() = 0;
	};
}