#pragma once
#include <sstream>
#include <string>

//===
// 3차원 공간의 좌표를 나타낸다
// + x, y, z or r, g, b 로 접근이 가능하다.
class Vector3
{
public:
	//===
	// xyz, rgb 둘 다 접근이 가능하게 만든다.
	union
	{
		struct
		{
			float x, y, z;
		};
		struct
		{
			float r, g, b;
		};
	};

public:
	Vector3(float x = 0.0f, float y = 0.0f, float z = 0.0f);
	virtual ~Vector3();

	//===
	// 연산자 오버로딩
	Vector3 operator+(const Vector3& vec) { return Vector3(x + vec.x, y + vec.y, z + vec.z); }
	Vector3 operator-(const Vector3& vec) { return Vector3(x - vec.x, y - vec.y, z - vec.z); }
	Vector3 operator*(const float& value) { return Vector3(x * value, y * value, z * value); }
	Vector3 operator/(const float& value) { if (value == 0) return Vector3(0, 0, 0); else return Vector3(x / value, y / value, z / value); }
	void operator+=(const Vector3& vec)   { (*this) = (*this) + vec; }
	void operator-=(const Vector3& vec)   { (*this) = (*this) - vec; }
	void operator*=(const float& value)   { (*this) = (*this) * value; }
	void operator/=(const float& value)   { (*this) = (*this) / value; }
	void operator=(const Vector3& vec)    { x = vec.x; y = vec.y; z = vec.z; }
	bool operator==(const Vector3& vec)   { if (x == vec.x && y == vec.y && z == vec.z) return true; else return false; }

	//===
	// String 변환
	const std::string ToString() const;

	//===
	// static 계산 함수
	// 단위벡터를 반환한다.
	static Vector3 _GetNormalize(Vector3& vec);

	// 벡터의 크기를 반환한다.
	static float _GetLength(const Vector3& vec);
	// 현재 벡터에서 dest 까지의 거리를 반환한다.
	static float _GetDistance(Vector3 &start, Vector3 &dest);

	// 벡터 내적을 한다.
	static Vector3 _GetCrossProduct(Vector3& v1, Vector3& v2);
	// 벡터 외적을 한다.
	static float _GetDotProduct(Vector3& v1, Vector3& v2);
};

// Vector == Color
typedef Vector3 Color3;
#define Vector3F(f) Vector3(f, f, f)