#pragma once
#include "Component.h"

namespace Tetra
{
	// 전방선언
	class ObjectError;

	class ComponentManager
	{
	private:
		std::list <Component *> componentList;

	protected:
		ComponentManager();

	public:
		static ComponentManager *Create();
		~ComponentManager();

		//===
		// 컴포넌트 관리
		template<typename ComponentType>
		void AddComponent(Object *object)
		{
			ComponentType *returnComponent = nullptr;
			returnComponent = ComponentType::Create(object);

			// typeid 로 에러 출력
			if (returnComponent == nullptr)
				Error::Throw<ObjectError>(object->GetName() + " 오브젝트에 컴포넌트 "
				+ typeid(ComponentType).name() + "을(를) 생성하는 것을 실패했습니다.");

			componentList.push_back(returnComponent);
		}

		template<typename ComponentType>
		ComponentType *GetComponent() const
		{
			for each(auto component in componentList)
			{
				// dynamic_cast 가 가능한 경우에만 true 반환
				if (dynamic_cast<ComponentType *>(component))
				{
					// 템플릿 타입과 인자변수의 타입이 같을 경우 true 반환
					if (IsSameType<ComponentType *>(dynamic_cast<ComponentType *>(component)))
					{
						return dynamic_cast<ComponentType *>(component);
					}
				}
			}

			// 에러는 Object::GetComponent 에서 출력
			return nullptr;
		}

		//===
		// 관리
		void Init();
		void LoopStart();
		void LoopEnd();
		void Release();
	};
}