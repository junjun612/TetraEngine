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
// String 변환
const std::string Vector3::ToString() const
{
	std::ostringstream stream;
	stream << "Vector3 [x : " << x << ", y : " << y << ", z : " << z << "]";

	std::string returnStr = stream.str();
	return returnStr;
}

//===
// static 계산 함수
// 단위벡터를 반환한다.
Vector3 Vector3::_GetNormalize(Vector3& vec)
{
	Vector3 result = vec / _GetLength(vec);
	return result;
}

// 벡터의 크기를 반환한다.
float Vector3::_GetLength(const Vector3& vec)
{
	float result = Sqrt(Pow(vec.x, 2) + Pow(vec.y, 2) + Pow(vec.z, 2));
	return result;
}

// 현재 벡터에서 dest 까지의 거리를 반환한다.
float Vector3::_GetDistance(Vector3 &start, Vector3 &dest)
{
	return Abs((float)_GetLength(dest - start));
}

// 벡터 내적을 한다.
Vector3 Vector3::_GetCrossProduct(Vector3& v1, Vector3& v2)
{
	return Vector3((v1.y * v2.z) - (v1.z * v2.y),
				   (v1.z * v2.x) - (v1.x * v2.z),
				   (v1.x * v2.y) - (v1.y * v2.x));
}

// 벡터 외적을 한다.
float Vector3::_GetDotProduct(Vector3& v1, Vector3& v2)
{
	return (v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z);
}