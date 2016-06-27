#pragma once

// Getter ����
#define GETTER(Type, MemberName, FaceName) \
private: \
	Type MemberName; \
public: \
	Type Get##FaceName() const { return MemberName; } \
private:

// Setter ����
#define SETTER(Type, MemberName, FaceName) \
private: \
	Type MemberName; \
public: \
	void Set##FaceName(Type value) { MemberName = value; } \
private:

// Getter, Setter ����
#define GETTERSETTER(Type, MemberName, FaceName) \
private: \
	Type MemberName; \
public: \
	Type Get##FaceName() const { return MemberName; } \
	void Set##FaceName(Type value) { MemberName = value; } \
private:

// protected Getter ����
#define PROTECTED_GETTER(Type, MemberName, FaceName) \
protected: \
	Type MemberName; \
public: \
	Type Get##FaceName() const { return MemberName; } \
protected:

// protected Setter ����
#define PROTECTED_SETTER(Type, MemberName, FaceName) \
protected: \
	Type MemberName; \
public: \
	void Set##FaceName(Type value) { MemberName = value; } \
protected: