#include "Matrix4x4.h"


Matrix4x4::Matrix4x4()
{
}


Matrix4x4::~Matrix4x4()
{
}

//===
// ������ �����ε�
Matrix4x4 Matrix4x4::operator+(const Matrix4x4& mat)
{
	Matrix4x4 tmp = (*this);

	for (int i = 0; i < 16; i++)
		tmp.m16[i] += mat.m16[i];

	return tmp;
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4& mat)
{
	Matrix4x4 tmp;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			tmp.m4x4[i][j] = 0;

			for (int k = 0; k < 4; k++)
			{
				tmp.m4x4[i][j] += (*this).m4x4[i][k] * mat.m4x4[k][j];
			}
		}
	}

	return tmp;
}

Matrix4x4 Matrix4x4::operator-(const Matrix4x4& mat)
{
	Matrix4x4 tmp = (*this);

	for (int i = 0; i < 16; i++)
		tmp.m16[i] -= mat.m16[i];

	return tmp;
}

//===
// String ��ȯ
const std::string Matrix4x4::ToString() const
{
	std::ostringstream stream;

	stream << "Matrix4x4 " << std::endl;
	for (int i = 0; i < 4; i++)
	{
		char str[128];
		sprintf_s(str, "[ %.2f, %.2f, %.2f, %.2f ]", m4x4[i][0], m4x4[i][0], m4x4[i][0], m4x4[i][0]);
		stream << str << std::endl;
	}

	std::string returnStr = stream.str();
	return returnStr;
}

//===
// static ��� �Լ�
// ��������� ��ȯ�Ѵ�.
Matrix4x4 Matrix4x4::_GetIdentity()
{
	Matrix4x4 tmp;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i == j)
				tmp.m4x4[i][j] = 1.0f;
			else
				tmp.m4x4[i][j] = 0.0f;
		}
	}

	return tmp;
}

// ��ġ ��ķ� ��ȯ�Ѵ�. (D3D11)
Matrix4x4 Matrix4x4::_GetTranspose(Matrix4x4 mat)
{
	Matrix4x4 returnMat;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			returnMat.m4x4[i][j] = mat.m4x4[j][i];

	return returnMat;
}