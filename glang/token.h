#pragma once
#include <string>
#include <iostream>

using namespace std;

enum type_token {
	_number = 0,
	_operator = 1,
	_end = 2,
};

class Token {

public:
	static string getType(type_token &t) {
		if (t == _end) {
			return "end";
		}
		if (t == _operator) {
			return "operator";
		}
		if (t == _number) {
			return "number";
		}
	}
	void test_print(std::ostream&);


	const int position;
	const int line = 1;
	string text;
	type_token type;
	Token(int _position, string _text, type_token _type = _number) :position(_position), text(_text), type(_type) {}
};

