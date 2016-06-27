#pragma once
#include "System.h"
#include "Object.h"

#undef GetObject

namespace Tetra
{
	//===
	// ������Ʈ�� ���õ� ��ü�� �����ϴ� Ŭ����
	class ObjectManageSystem : public System
	{
	private:
		std::list <Object *> objectList;
		GETTER(int, objectCount, ObjectCount);

	protected:
		ObjectManageSystem();

	public:
		static ObjectManageSystem *Create();
		~ObjectManageSystem();

		//===
		// ������Ʈ �߰�
		void AddObject(Object *object);

		//===
		// ������Ʈ �޾ƿ���
		Object *GetObject(std::string objectName);
		Object *GetObject(int index);

		template <typename ObjectType>
		ObjectType *GetObject(std::string objectName)
		{
			for (auto object : objectList)
			{
				if (object->GetName() == objectName)
				{
					if (dynamic_cast<ObjectType *>(object))
					{
						return dynamic_cast<ObjectType *>(object);
					}
				}
			}

			Error::Throw<ObjectError>(fileName + " ������Ʈ�� ã�� �� �����ϴ�.");
			return nullptr;
		}

		//===
		// ����
		void Init() override;
		void LoopStart() override;
		void LoopEnd() override;
		void Release() override;
	};
}