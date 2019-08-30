#pragma once
#include "Exception.h"
#include <sstream>

class ParseException :
	public Exception
{
public:
	ParseException(int position, int line, string _message);
	~ParseException();
};

