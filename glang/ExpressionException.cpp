#include "ExpressionException.h"
#include <sstream>


ExpressionException::ExpressionException(Token* t, string _message)
{
	name = "ExpressionException";
	stringstream s;
	s << "�������ʽʱ�ڵ�" << t->line << "��" << t->position << "����������:";
	message = s.str() + _message+"����������token������:"+t->text;
}


ExpressionException::~ExpressionException()
{
}
