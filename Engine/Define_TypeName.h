#pragma once

/*
/ GetTypeName<Type>()
/   Type 자료형의 이름을 std::string 으로 받아온다.
*/
template <typename Type>
std::string GetTypeName()
{
	Type *typeVar = nullptr;
	std::string typeName = typeid(typeVar).name();

	// class Type * -> Type
	typeName = typeName.substr(6, typeName.size() - 6 - 2);

	return typeName; 
}

/*
/ GetTypeName(var)
/   var의 자료형을 std::string 으로 받아온다.
*/
template <typename Type>
std::string GetTypeName(Type var)
{
	std::string typeName = typeid(var).name();

	// class Type * -> Type
	typeName = typeName.substr(6, typeName.size() - 6 - 2);

	return typeName;
}