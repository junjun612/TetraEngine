#pragma once

/*
/ GetTypeName<Type>()
/   Type �ڷ����� �̸��� std::string ���� �޾ƿ´�.
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
/   var�� �ڷ����� std::string ���� �޾ƿ´�.
*/
template <typename Type>
std::string GetTypeName(Type var)
{
	std::string typeName = typeid(var).name();

	// class Type * -> Type
	typeName = typeName.substr(6, typeName.size() - 6 - 2);

	return typeName;
}