#include "ParseException.h"


using namespace std;

ParseException::ParseException(int position, int line, string _message)
{
	name = "ParseException";
	stringstream s;
	s << "�﷨����ʱ�ڵ�" <<line << "��" << position << "����������:" << _message;
	message = s.str();
}


ParseException::~ParseException()
{
}
