#include "ParseException.h"


using namespace std;

ParseException::ParseException(int position, int line, string _message)
{
	name = "ParseException";
	stringstream s;
	s << "语法分析时在第" <<line << "行" << position << "处发生错误:";
	message = s.str()+_message;
}


ParseException::~ParseException()
{
}
