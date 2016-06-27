#pragma once
#include "Core.h"
#include "Windows.h"

namespace Tetra
{
	//===
	// 리소스 생성 || 루프 도중 에러 처리
	class ResourceError : public Error
	{
	public:
		ResourceError(std::string content) : Error(content)  {}

		void Catch() override
		{
			std::string errorMessage = "라소스 문제에 의해 종료합니다. \n에러 내용 : " + content;
			MessageBox(NULL, errorMessage.c_str(), "리소스 에러", MB_OK);
		}
	};

	//===
	// 불러온 리소스
	class Resource
	{
	private:
		// 파일이름, 경로
		GETTERSETTER(std::string, fileName, FileName);
		GETTER(std::string, filePath, FilePath);

		// 타입
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

		// 삭제
		virtual void Release() = 0;

		// resource가 resourceType 인지 확인
		template <typename ResourceType>
		static bool IsThisResourceType(Resource *resource)
		{
			if (static_cast<ResourceType *>(resource)) return true;
			else return false;
		}
	};
}