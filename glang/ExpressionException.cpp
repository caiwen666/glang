#include "ExpressionException.h"
#include <sstream>


ExpressionException::ExpressionException(Token* t, string _message)
{
	name = "ExpressionException";
	stringstream s;
	s << "解析表达式时在第" << t->line << "行" << t->position << "处发生错误:";
	message = s.str() + _message+"，引起出错的token的内容:"+t->text;
}


ExpressionException::~ExpressionException()
{
}
