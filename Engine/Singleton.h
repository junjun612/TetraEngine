#pragma once

//===
// static �ν��Ͻ��� �ϳ��� ���� ��
// �޾ƿͼ� ����� �� �ִ� ����������
template <typename SingletonType>
class Singleton
{
private:
	static SingletonType *instance;

public:
	// instance�� �޾ƿ´�.
	static SingletonType *GetInstance()
	{
		if (instance == nullptr) instance = SingletonType::Create();

		return instance;
	}

	// insrtance �� �����Ѵ�.
	static void DestroyInstance()
	{
		if (instance != nullptr)
		{
			delete instance;
			instance = nullptr;
		}
	}
};

// instance �ʱ�ȭ
template<typename SingletonType> SingletonType* Singleton<SingletonType>::instance = nullptr;