#pragma once

// �� ���� �ڷ����� ���ٸ� true, �ƴϸ� false�� �ִ´�.
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
/   var�� �ڷ����� Type �̸� true�� ��ȯ�Ѵ�.
*/
template <typename Type, typename VarType>
bool IsSameType(VarType var)
{
	bool isSame = std::is_same<Type, VarType>::value;

	return isSame;
}

/*
/ IsSameType(var1, var2)
/   var1 �� var2�� Ÿ���� ������ true�� ��ȯ�Ѵ�.
*/
template <typename VarType1, typename VarType2>
bool IsSameType(VarType1 var1, VarType2 var2)
{
	bool isSame = std::is_same<VarType1, VarType2>::value;

	return isSame;
}