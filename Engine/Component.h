#pragma once
#include "Core.h"

namespace Tetra
{
	// 전방선언
	class Object;

	//===
	// 오브젝트 내의 컴포넌트
	class Component
	{
	protected:
		// 주인 오브젝트
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
		// 관리
		virtual void Init() = 0;
		virtual void LoopStart() = 0;
		virtual void LoopEnd() = 0;
		virtual void Release() = 0;

		//===
		// XML 관리
		virtual void ExportXML() = 0;
		virtual void ImportXML() = 0;
	};
}