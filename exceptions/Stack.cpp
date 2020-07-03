#include "Stack.h"

template<class T>
Stack<T>::Stack()
{
	data = nullptr;
	maxSize = 0;
	topIndex = 0;
}

template<class T>
Stack<T>::Stack(int size)
{
	if (size < 0)
		throw SizeLessThan_0_Exceptions("Size is less than 0");
	data = nullptr;
	maxSize = size;
	topIndex = 0;
}

template<class T>
bool Stack<T>::Push(T elem)
{
	if (!IsInfinity())
	{
		if (IsFull())
			throw StackOverFlowExceptions("Stack overflow");
		if (!IsFull())
		{
			T *temp = new T[topIndex + 1];
			for (int i = 0; i < topIndex; i++)
			{
				temp[i] = data[i];
			}
			temp[topIndex] = elem;
			++topIndex;
			delete[]data;
			data = temp;
			return true;
		}
		return false;
	}
	else if (IsInfinity())
	{
		T *temp = new T[topIndex + 1];
		for (int i = 0; i < topIndex; i++)
		{
			temp[i] = data[i];
		}
		temp[topIndex] = elem;
		++topIndex;
		delete[]data;
		data = temp;
		return true;
	}
}

template<class T>
T Stack<T>::Pop()
{
	if (!IsInfinity())
	{
		if (IsEmpty())
			throw CannotBeDeletedExceptions("Count of elements in stack are 0");
		if (!IsEmpty())
		{
			T *temp = new T[topIndex - 1];
			for (int i = 0; i < topIndex - 1; i++)
			{
				temp[i] = data[i];
			}
			T count = data[topIndex - 1];
			--topIndex;
			delete[]data;
			data = temp;
			return count;
		}
		return 0;
	}
	else if (IsInfinity())
	{
		T *temp = new T[topIndex - 1];
		for (int i = 0; i < topIndex - 1; i++)
		{
			temp[i] = data[i];
		}
		T count = data[topIndex - 1];
		--topIndex;
		delete[]data;
		data = temp;
		return count;
	}
}

template<class T>
T Stack<T>::Peek()
{
	if (IsEmpty())
		throw CannotBeDeletedExceptions("Count of elements in stack are 0");
	if (!IsEmpty())
		return data[topIndex - 1];

	return 0;
}

template<class T>
int Stack<T>::GetCount() const
{
	return topIndex;
}

template<class T>
bool Stack<T>::IsEmpty() const
{
	return topIndex == 0;
}

template<class T>
bool Stack<T>::IsFull() const
{
	return topIndex == maxSize;
}

template<class T>
bool Stack<T>::IsInfinity() const
{
	return maxSize == 0;
}

template<class T>
void Stack<T>::Clear()
{
	topIndex = 0;
	maxSize = 0;
	delete[]data;
}

template<class T>
Stack<T>::~Stack()
{
	if (data != nullptr)
		delete[]data;
}
