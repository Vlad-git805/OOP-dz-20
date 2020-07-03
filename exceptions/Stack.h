#pragma once
#include <iostream>
#include <exception>
#include <stdexcept>
using namespace std;

class SizeLessThan_0_Exceptions : public exception
{
public:
	SizeLessThan_0_Exceptions(const char * message) : exception(message) {}
};

class StackOverFlowExceptions : public exception
{
public:
	StackOverFlowExceptions(const char * message) : exception(message) {}
};

class CannotBeDeletedExceptions : public exception
{
public:
	CannotBeDeletedExceptions(const char * message) : exception(message) {}
};

template<class T>
class Stack
{
	T *data;
	int maxSize;
	int topIndex;

public:
	Stack();
	Stack(int size);
	~Stack();

	bool Push(T elem);
	T Pop();
	T Peek();
	int GetCount() const;
	bool IsEmpty() const;
	bool IsFull() const;
	bool IsInfinity() const;
	void Clear();
};