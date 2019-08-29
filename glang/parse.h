#pragma once
#include <string>
#include "token.h"

using namespace std;

class parse{
public:
	parse(string code) :_code(code), _position(0),context_mode(parseMode.common){
	}
	void execute() {}
	Token* getToken() {}
private:
	string _code;//现行代码
	int _position;//解析到的位置
	int _line=1;

	char context_mode;
	short context_block;//括号计次
	Token* context_token;
};

struct {
	char common = 0;
	char doubleNum = 1;
}parseMode;
