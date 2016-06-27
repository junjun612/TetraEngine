#pragma once
#include "System.h"
#include "Resource.h"

namespace Tetra
{
	//===
	// ���ҽ��� ���õ� ��ü�� �����ϴ� Ŭ����
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
		// ���ҽ� �߰�
		void AddResource(Resource *resource);
		void AddResource(std::string xmlPath);

		//===
		// ���ҽ� �޾ƿ���
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

			Error::Throw<ResourceError>(fileName + " ���ҽ��� ã�� �� �����ϴ�.");
			return nullptr;
		}

		//===
		// �ʱ�ȭ �� ����
		void Init() override;
		void LoopStart() override;
		void LoopEnd() override;
		void Release() override;
	};
}