#pragma once
#include "Component.h"

namespace Tetra
{
	//===
	// 3차원의 위치 정보를 저장해주는 컴포넌트
	class Transform : public Component
	{
	public:
		// 위치
		Vector3 position;

		// 축정보
		// axis 와 right, up, front 로 접근이 가능하다. 
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

		// 크기
		Vector3 scale;

		// 최종 행렬
		Matrix matrix;

	protected:
		Transform(Object *object);

	public:
		static Transform *Create(Object *object);
		~Transform();

		//===
		// 관리
		void Init() override;
		void LoopStart() override;
		void LoopEnd() override;
		void Release() override;

		void ExportXML() override;
		void ImportXML() override;
	};
}