#include "Vector3.h"

#include "Math.h"

Vector3::Vector3(float x, float y, float z) 
	: x(x), y(y), z(z)
{
}

Vector3::~Vector3()
{
}

//===
// String ��ȯ
const std::string Vector3::ToString() const
{
	std::ostringstream stream;
	stream << "Vector3 [x : " << x << ", y : " << y << ", z : " << z << "]";

	std::string returnStr = stream.str();
	return returnStr;
}

//===
// static ��� �Լ�
// �������͸� ��ȯ�Ѵ�.
Vector3 Vector3::_GetNormalize(Vector3& vec)
{
	Vector3 result = vec / _GetLength(vec);
	return result;
}

// ������ ũ�⸦ ��ȯ�Ѵ�.
float Vector3::_GetLength(const Vector3& vec)
{
	float result = Sqrt(Pow(vec.x, 2) + Pow(vec.y, 2) + Pow(vec.z, 2));
	return result;
}

// ���� ���Ϳ��� dest ������ �Ÿ��� ��ȯ�Ѵ�.
float Vector3::_GetDistance(Vector3 &start, Vector3 &dest)
{
	return Abs((float)_GetLength(dest - start));
}

// ���� ������ �Ѵ�.
Vector3 Vector3::_GetCrossProduct(Vector3& v1, Vector3& v2)
{
	return Vector3((v1.y * v2.z) - (v1.z * v2.y),
				   (v1.z * v2.x) - (v1.x * v2.z),
				   (v1.x * v2.y) - (v1.y * v2.x));
}

// ���� ������ �Ѵ�.
float Vector3::_GetDotProduct(Vector3& v1, Vector3& v2)
{
	return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}