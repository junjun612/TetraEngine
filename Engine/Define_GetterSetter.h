#pragma once

// Getter 설정
#define GETTER(Type, MemberName, FaceName) \
private: \
	Type MemberName; \
public: \
	Type Get##FaceName() const { return MemberName; } \
private:

// Setter 설정
#define SETTER(Type, MemberName, FaceName) \
private: \
	Type MemberName; \
public: \
	void Set##FaceName(Type value) { MemberName = value; } \
private:

// Getter, Setter 설정
#define GETTERSETTER(Type, MemberName, FaceName) \
private: \
	Type MemberName; \
public: \
	Type Get##FaceName() const { return MemberName; } \
	void Set##FaceName(Type value) { MemberName = value; } \
private:

// protected Getter 설정
#define PROTECTED_GETTER(Type, MemberName, FaceName) \
protected: \
	Type MemberName; \
public: \
	Type Get##FaceName() const { return MemberName; } \
protected:

// protected Setter 설정
#define PROTECTED_SETTER(Type, MemberName, FaceName) \
protected: \
	Type MemberName; \
public: \
	void Set##FaceName(Type value) { MemberName = value; } \
protected: