#pragma once

//===
// �⺻ ���� ���
#include <cmath>

//===
// ���� ���� Ŭ����
#include "Vector3.h"
#include "Matrix4x4.h"

//===
// ��� �Լ���
// ���
static const float PI = 3.141592;	// ����

// ��� �Լ���
inline float Sin(float x)                   { return std::sin(x); }			// ����
inline float Cos(float x)                   { return std::cos(x); }			// �ڻ���
inline float Tan(float x)                   { return std::tan(x); }			// ź��Ʈ
inline float ASin(float x)                  { return std::asin(x); }		// ��ũ ����
inline float ACos(float x)                  { return std::acos(x); }		// ��ũ �ڻ���
inline float ATan(float x)                  { return std::atan(x); }		// ��ũ ź��Ʈ
inline float ATan2(float y, float x)        { return std::atan2(y, x); }
inline float Abs(float x)					{ return std::abs(x); }
inline float Log(float x)					{ return std::log(x); }
inline float Pow(float x, int y)			{ return std::pow(x, y); }
template <typename T>
inline T Sqrt(T x)							{ return std::sqrt(x); }

// ���� ���
inline float Radian2Degree(float x)			{ return x / PI * 180.0f; }
inline float Degree2Radian(float x)			{ return x / 180.0f; }

// ����
template <typename T>
inline float Lerp(T start, T end, float s)	{ return start + ((end - start) * s); }