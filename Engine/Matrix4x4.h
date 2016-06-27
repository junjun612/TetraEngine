#pragma once
#include <sstream>
#include <string>
#include "Math.h"

class Vector3;

//===
// 3차원에서 공간의 계산을 위한 클래스
class Matrix4x4
{
public:
	//===
	// m11 m12..., m4x4[1][1], m16[1] 로 접근이 가능하다.
	union {
		struct {
			float        m11, m12, m13, m14;
			float        m21, m22, m23, m24;
			float        m31, m32, m33, m34;
			float        m41, m42, m43, m44;
		};
		float m4x4[4][4];
		float m16[16];
	};

public:
	Matrix4x4();
	virtual ~Matrix4x4();

	//===
	// 연산자 오버로딩
	Matrix4x4 operator+(const Matrix4x4& mat);
	Matrix4x4 operator-(const Matrix4x4& mat);
	Matrix4x4 operator*(const Matrix4x4& mat);
	void operator+=(const Matrix4x4& mat) { (*this) = (*this) + mat; }
	void operator-=(const Matrix4x4& mat) { (*this) = (*this) - mat; }
	void operator*=(const Matrix4x4& mat) { (*this) = (*this) * mat; }
	void operator=(const Matrix4x4& mat)
	{
		for (int i = 0; i < 16; i++)
			(*this).m16[i] = mat.m16[i];
	}
	bool operator==(const Matrix4x4& mat)
	{
		for (int i = 0; i < 16; i++)
			if (m16[i] != mat.m16[i]) return false;

		return true;
	}

	//===
	// String 변환
	const std::string ToString() const;

	//===
	// static 계산 함수
	// 단위행렬을 반환한다.
	static Matrix4x4 _GetIdentity();

	// 전치 행렬로 변환한다. (D3D11)
	static Matrix4x4 _GetTranspose(Matrix4x4 mat);
};

typedef Matrix4x4 Matrix;