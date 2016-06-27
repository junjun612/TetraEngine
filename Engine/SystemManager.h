#pragma once
#include "System.h"

namespace Tetra
{
	//===
	// ��� �ý����� �����ϴ� �Ŵ��� Ŭ����
	class SystemManager
	{
	private:
		std::list <System *> systemList;

	public:
		SystemManager();
		~SystemManager();

		// �ý��� �߰�
		void AddSystem(System *system);

		// �ý��� ã��
		template <typename SystemType>
		SystemType *GetSystem()
		{
			for (auto system : systemList)
			{
				// dynamic_cast �� ������ ��� ( �ڷ����� ���ų� ���� �θ�Ŭ������ �� )
				if (dynamic_cast<SystemType *>(system))
				{
					// ���ø� Ÿ�԰� ���ں����� Ÿ���� ���� ��� ��ȯ�� �ش�.
					return dynamic_cast<SystemType *>(system);
				}
			}

			// typeid �� ���� ���
			Error::JustCatch<SystemError>("�ý��� " + GetTypeName<SystemType>() + " ��(��) ã�� �� �����ϴ�.");
			return nullptr;
		}

		//===
		// ��ü �ý��� ����
		void LoopStart();
		void LoopEnd();
		void Release();
	};
}