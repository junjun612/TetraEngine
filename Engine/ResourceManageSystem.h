#pragma once
#include "System.h"
#include "Resource.h"

namespace Tetra
{
	//===
	// 리소스에 괸련된 전체를 관리하는 클래스
	class ResourceManageSystem : public System
	{
	private:
		std::list <Resource *> resourceList;
		GETTER(int, resourceCount, ResourceCount);

	protected:
		ResourceManageSystem();

	public:
		static ResourceManageSystem *Create();
		~ResourceManageSystem();

		//===
		// 리소스 추가
		void AddResource(Resource *resource);
		void AddResource(std::string xmlPath);

		//===
		// 리소스 받아오기
		Resource *GetResource(std::string fileName);
		Resource *GetResource(int index);
		template <typename ResouceType>
		ResouceType *GetResource(std::string fileName)
		{
			for (auto resource : resourceList)
			{
				if (resource->GetFileName() == fileName)
				{
					if (dynamic_cast<ResouceType *>(resource))
					{
						return dynamic_cast<ResouceType *>(resource);
					}
				}
			}

			Error::Throw<ResourceError>(fileName + " 리소스를 찾을 수 없습니다.");
			return nullptr;
		}

		//===
		// 초기화 및 관리
		void Init() override;
		void LoopStart() override;
		void LoopEnd() override;
		void Release() override;
	};
}