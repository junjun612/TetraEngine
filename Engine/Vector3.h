#pragma once
#include <sstream>
#include <string>

//===
// 3���� ������ ��ǥ�� ��Ÿ����
// + x, y, z or r, g, b �� ������ �����ϴ�.
class Vector3
{
public:
	//===
	// xyz, rgb �� �� ������ �����ϰ� �����.
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
	// ������ �����ε�
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
	// String ��ȯ
	const std::string ToString() const;

	//===
	// static ��� �Լ�
	// �������͸� ��ȯ�Ѵ�.
	static Vector3 _GetNormalize(Vector3& vec);

	// ������ ũ�⸦ ��ȯ�Ѵ�.
	static float _GetLength(const Vector3& vec);
	// ���� ���Ϳ��� dest ������ �Ÿ��� ��ȯ�Ѵ�.
	static float _GetDistance(Vector3 &start, Vector3 &dest);

	// ���� ������ �Ѵ�.
	static Vector3 _GetCrossProduct(Vector3& v1, Vector3& v2);
	// ���� ������ �Ѵ�.
	static float _GetDotProduct(Vector3& v1, Vector3& v2);
};

// Vector == Color
typedef Vector3 Color3;
#define Vector3F(f) Vector3(f, f, f)