#pragma once
#include <string>

using namespace std;
class Token {

public:
	const int position;
	const int line = 1;
	string text;
	int type;
	Token(int _position, string _text, int _type = type_token._number) :position(_position), text(_text), type(_type) {}
};

struct {
	char _number = 0;
	char _operator = 1;
	char _end = 2;
}type_token;