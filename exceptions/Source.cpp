#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>
#include "Stack.h"
using namespace std;

class MathematicalErrorExceptions : public exception
{
public:
	MathematicalErrorExceptions(const char * message) : exception(message) {}
};

class LackOfMemoryExceptions : public exception
{
public:
	LackOfMemoryExceptions(const char * message) : exception(message) {}
};

class IncorrectInputExceptions : public exception
{
public:
	IncorrectInputExceptions(const char * message) : exception(message) {}
};

class IncorrectWorkWithFileExceptions : public exception
{
public:
	IncorrectWorkWithFileExceptions(const char * message) : exception(message) {}
};

class EmptyArrayExceptions : public exception
{
public:
	EmptyArrayExceptions(const char * message) : exception(message) {}
};

class GoingOutsideThe_int : public exception
{
public:
	GoingOutsideThe_int(const char * message) : exception(message) {}
};

int StringToInt(string str)
{
	bool i = false;
	for (char s : str)
	{
		if (s < 48 || s > 57)
		{
			if (str[i] == '-' && i == false)
			{
				i = true;
				continue;
			}
			throw invalid_argument("Bad argument, in string there are one or more letters");
		}
	}
	long number;
	number = atoi(str.c_str());
	if (number > 2147483647 || number < -2147483647)
		throw GoingOutsideThe_int("Going outside the int");
	return number;
}

int main()
{
	try
	{
		cout << StringToInt("-123456789987") << endl;
	}
	catch (invalid_argument& a)
	{
		cout << a.what() << endl;
	}
	catch (GoingOutsideThe_int& b)
	{
		cout << b.what() << endl;
	}
	

	system("pause");
	return 0;
}