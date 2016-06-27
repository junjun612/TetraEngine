#pragma once
#include "Core.h"
#include "Windows.h"

namespace Tetra
{
	//===
	// ���ҽ� ���� || ���� ���� ���� ó��
	class ResourceError : public Error
	{
	public:
		ResourceError(std::string content) : Error(content)  {}

		void Catch() override
		{
			std::string errorMessage = "��ҽ� ������ ���� �����մϴ�. \n���� ���� : " + content;
			MessageBox(NULL, errorMessage.c_str(), "���ҽ� ����", MB_OK);
		}
	};

	//===
	// �ҷ��� ���ҽ�
	class Resource
	{
	private:
		// �����̸�, ���
		GETTERSETTER(std::string, fileName, FileName);
		GETTER(std::string, filePath, FilePath);

		// Ÿ��
		GETTERSETTER(std::string, resourceTypeName, ResourceType);

	protected:
		Resource(std::string fileName, std::string filePath);

	public:
		template <typename ResourceType>
		static ResourceType *Create(std::string fileName, std::string filePath)
		{
			return ResourceType::Create(fileName, filePath);
		}
		virtual ~Resource();

		// ����
		virtual void Release() = 0;

		// resource�� resourceType ���� Ȯ��
		template <typename ResourceType>
		static bool IsThisResourceType(Resource *resource)
		{
			if (static_cast<ResourceType *>(resource)) return true;
			else return false;
		}
	};
}