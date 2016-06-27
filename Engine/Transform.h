#pragma once
#include "Component.h"

namespace Tetra
{
	//===
	// 3������ ��ġ ������ �������ִ� ������Ʈ
	class Transform : public Component
	{
	public:
		// ��ġ
		Vector3 position;

		// ������
		// axis �� right, up, front �� ������ �����ϴ�. 
		union
		{
			struct
			{
				Vector3 right;
				Vector3 up;
				Vector3 front;
			};
			struct
			{
				Vector3 axis[3];
			};
		};

		// ũ��
		Vector3 scale;

		// ���� ���
		Matrix matrix;

	protected:
		Transform(Object *object);

	public:
		static Transform *Create(Object *object);
		~Transform();

		//===
		// ����
		void Init() override;
		void LoopStart() override;
		void LoopEnd() override;
		void Release() override;

		void ExportXML() override;
		void ImportXML() override;
	};
}