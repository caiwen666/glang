#pragma once
#include "Exception.h"
#include "Token.h"

class ExpressionException :
	public Exception
{
public:
	ExpressionException(Token* t, string _message);
	~ExpressionException();
};

