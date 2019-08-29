#pragma once
#include "Exception.h"
class ParseException :
	public Exception
{
public:
	ParseException(int position, int line, string _message);
	~ParseException();
};

