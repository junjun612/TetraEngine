#pragma once

//===
// 기본 수학 헤더
#include <cmath>

//===
// 직접 만든 클래스
#include "Vector3.h"
#include "Matrix4x4.h"

//===
// 계산 함수들
// 상수
static const float PI = 3.141592;	// 파이

// 계산 함수들
inline float Sin(float x)                   { return std::sin(x); }			// 사인
inline float Cos(float x)                   { return std::cos(x); }			// 코사인
inline float Tan(float x)                   { return std::tan(x); }			// 탄젠트
inline float ASin(float x)                  { return std::asin(x); }		// 아크 사인
inline float ACos(float x)                  { return std::acos(x); }		// 아크 코사인
inline float ATan(float x)                  { return std::atan(x); }		// 아크 탄젠트
inline float ATan2(float y, float x)        { return std::atan2(y, x); }
inline float Abs(float x)					{ return std::abs(x); }
inline float Log(float x)					{ return std::log(x); }
inline float Pow(float x, int y)			{ return std::pow(x, y); }
template <typename T>
inline T Sqrt(T x)							{ return std::sqrt(x); }

// 각도 계산
inline float Radian2Degree(float x)			{ return x / PI * 180.0f; }
inline float Degree2Radian(float x)			{ return x / 180.0f; }

// 보간
template <typename T>
inline float Lerp(T start, T end, float s)	{ return start + ((end - start) * s); }