#pragma once

//===
// static 인스턴스를 하나만 만든 후
// 받아와서 사용할 수 있는 디자인패턴
template <typename SingletonType>
class Singleton
{
private:
	static SingletonType *instance;

public:
	// instance를 받아온다.
	static SingletonType *GetInstance()
	{
		if (instance == nullptr) instance = SingletonType::Create();

		return instance;
	}

	// insrtance 를 삭제한다.
	static void DestroyInstance()
	{
		if (instance != nullptr)
		{
			delete instance;
			instance = nullptr;
		}
	}
};

// instance 초기화
template<typename SingletonType> SingletonType* Singleton<SingletonType>::instance = nullptr;