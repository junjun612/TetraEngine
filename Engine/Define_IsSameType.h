#pragma once

// 두 개의 자료형이 같다면 true, 아니면 false를 넣는다.
template <typename Type1, typename Type2>
struct is_same
{
	const bool value = false;
};

template <typename Type1>
struct is_same<Type1, Type1>
{
	const bool value = true;
};

/*
/ IsSameType<Type>(var)
/   var의 자료형이 Type 이면 true를 반환한다.
*/
template <typename Type, typename VarType>
bool IsSameType(VarType var)
{
	bool isSame = std::is_same<Type, VarType>::value;

	return isSame;
}

/*
/ IsSameType(var1, var2)
/   var1 과 var2의 타입이 같으면 true를 반환한다.
*/
template <typename VarType1, typename VarType2>
bool IsSameType(VarType1 var1, VarType2 var2)
{
	bool isSame = std::is_same<VarType1, VarType2>::value;

	return isSame;
}