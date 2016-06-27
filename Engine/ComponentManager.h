#pragma once
#include "Component.h"

namespace Tetra
{
	// ���漱��
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
		// ������Ʈ ����
		template<typename ComponentType>
		void AddComponent(Object *object)
		{
			ComponentType *returnComponent = nullptr;
			returnComponent = ComponentType::Create(object);

			// typeid �� ���� ���
			if (returnComponent == nullptr)
				Error::Throw<ObjectError>(object->GetName() + " ������Ʈ�� ������Ʈ "
				+ typeid(ComponentType).name() + "��(��) �����ϴ� ���� �����߽��ϴ�.");

			componentList.push_back(returnComponent);
		}

		template<typename ComponentType>
		ComponentType *GetComponent() const
		{
			for each(auto component in componentList)
			{
				// dynamic_cast �� ������ ��쿡�� true ��ȯ
				if (dynamic_cast<ComponentType *>(component))
				{
					// ���ø� Ÿ�԰� ���ں����� Ÿ���� ���� ��� true ��ȯ
					if (IsSameType<ComponentType *>(dynamic_cast<ComponentType *>(component)))
					{
						return dynamic_cast<ComponentType *>(component);
					}
				}
			}

			// ������ Object::GetComponent ���� ���
			return nullptr;
		}

		//===
		// ����
		void Init();
		void LoopStart();
		void LoopEnd();
		void Release();
	};
}