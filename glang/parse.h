#pragma once
#include "token.h"

using namespace std;

enum parseMode {
	common = 0,
	doubleNum = 1
};

class parse{
public:
	parse(string code) :_code(code), _position(0), context_mode(common) {}
	Token* getToken();
private:
	string _code;//���д���
	int _position;//��������λ��
	int _line=1;

	parseMode context_mode;
	short context_block;//���żƴ�
	Token* context_token;
};


