#include "token.h"


void Token::test_print(std::ostream &o) {
	o << "Token��{line:" << line << ",position:" << position << ",text:" << text << ",type:" << Token::getType(type) << "}" << endl;
}