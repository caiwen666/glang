#pragma once
#include <string>
#include <iostream>

using namespace std;

class Exception
{
public:
	virtual~Exception();
	void print(std::ostream&);
	string getMessage();
	string getName();
protected:
	string name = "Exception";
	string message = "null";
};

