#pragma once
#include "Windows.h"
#include "Core.h"

#include "ComponentManager.h"

namespace Tetra
{
	//===
	// 오브젝트 생성 || 루프 도중 에러 처리
	class ObjectError : public Error
	{
	public:
		ObjectError(std::string content) : Error(content)  {}

		void Catch() override
		{
			std::string errorMessage = "오브젝트 문제에 의해 종료합니다\n에러 내용 : " + content;
			MessageBox(NULL, errorMessage.c_str(), "오브젝트 에러", MB_OK);
		}
	};

	//===
	// 게임 내의 오브젝트
	class Object
	{
	private:
		GETTERSETTER(std::string, name, Name);
		ComponentManager *componentManager;

	protected:
		Object(std::string objectName);

	public:
		static Object *Create(std::string objectName);
		~Object();

		//===
		// 컴포넌트 관리 함수
		template <typename ComponentType>
		void AddComponent()
		{
			componentManager->AddComponent<ComponentType>(this);
		}

		template<typename ComponentType>
		ComponentType *GetComponent()
		{
			ComponentType *component = nullptr;
			component = componentManager->GetComponent<ComponentType>();

			// typeid 로 에러 출력
			if (component == nullptr)
				Error::Throw<ObjectError>(name + "에서 찾는 컴포넌트 " + GetTypeName<ComponentType>() + " 가 없습니다.");

			return component;
		}

		//===
		// 컴포넌트 관리 함수
		void Init();
		void LoopStart();
		void LoopEnd();
		void Release();
	};
}