#include "Exception.h"



Exception::~Exception()
{
}

void Exception::print(std::ostream &s) {
	s << "<" << name << ">" << message << endl;
}

string Exception::getName() {
	return name;
}

string Exception::getMessage() {
	return message;
}