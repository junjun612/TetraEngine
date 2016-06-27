#include "Transform.h"

#include "../Execute/MainSystem.h"


namespace Tetra
{
	Transform::Transform(Object *object) : Component(object)
	{
		position = Vector3F(0);
		for (int i = 0; i < 3; i++)	axis[i] = Vector3F(0);
		scale = Vector3F(1);

		matrix = Matrix::_GetIdentity();
		for (int i = 0; i < 3; i++)
			matrix.m4x4[i][i] = 0.2f;
	}


	Transform::~Transform()
	{
	}

	Transform *Transform::Create(Object *object)
	{
		Transform *returnComponent = new Transform(object);
		if (returnComponent == nullptr);

		return returnComponent;
	}

	void Transform::Init()
	{

	}

	void Transform::LoopStart()
	{
		matrix.m41 = position.x;
		matrix.m42 = position.y;
		matrix.m43 = position.z;
		GRP_SYS->SetTransform(matrix);
	}

	void Transform::LoopEnd()
	{

	}

	void Transform::Release()
	{

	}

	void Transform::ExportXML()
	{

	}

	void Transform::ImportXML()
	{

	}
}