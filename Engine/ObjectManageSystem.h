#pragma once
#include "System.h"
#include "Object.h"

#undef GetObject

namespace Tetra
{
	//===
	// 오브젝트에 괸련된 전체를 관리하는 클래스
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
		// 오브젝트 추가
		void AddObject(Object *object);

		//===
		// 오브젝트 받아오기
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

			Error::Throw<ObjectError>(fileName + " 오브젝트를 찾을 수 없습니다.");
			return nullptr;
		}

		//===
		// 관리
		void Init() override;
		void LoopStart() override;
		void LoopEnd() override;
		void Release() override;
	};
}