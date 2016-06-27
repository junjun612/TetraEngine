#pragma once
#include "Windows.h"
#include "Core.h"

#include "ComponentManager.h"

namespace Tetra
{
	//===
	// ������Ʈ ���� || ���� ���� ���� ó��
	class ObjectError : public Error
	{
	public:
		ObjectError(std::string content) : Error(content)  {}

		void Catch() override
		{
			std::string errorMessage = "������Ʈ ������ ���� �����մϴ�\n���� ���� : " + content;
			MessageBox(NULL, errorMessage.c_str(), "������Ʈ ����", MB_OK);
		}
	};

	//===
	// ���� ���� ������Ʈ
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
		// ������Ʈ ���� �Լ�
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

			// typeid �� ���� ���
			if (component == nullptr)
				Error::Throw<ObjectError>(name + "���� ã�� ������Ʈ " + GetTypeName<ComponentType>() + " �� �����ϴ�.");

			return component;
		}

		//===
		// ������Ʈ ���� �Լ�
		void Init();
		void LoopStart();
		void LoopEnd();
		void Release();
	};
}