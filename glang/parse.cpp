#include "parse.h"
#include "token.h"
#include "ParseException.h"

void parse::execute() {

}

Token* parse::getToken() {

	while (_position < _code.length) {
		char this_text = _code[_position];
		_position++;



		if (this_text == ' ') {
			continue;
		}

		if (isdigit(this_text) == 0 && !context_token->text.empty()) {
			Token* t = new Token(_position, string(1, this_text), context_type);
			return t;
		}

		
		if (this_text == '+'			//运算符号，直接返回 #0001
			|| this_text == '-'
			|| this_text == '*'
			|| this_text == '/'
			|| this_text == '('
			|| this_text == ')') {
			Token* t = new Token(_position, string(1,this_text), type_token._operator);
			return t;
		}

		if (this_text == '.') {			//小数
			if (context_token==NULL) {
				throw ParseException(_position, _line, "小数点前没有数字");
			}

			context_token->text += '.';
			context_mode = parseMode.doubleNum;
			continue;
		}

		if (isdigit(this_text) != 0) {
			context_token
		}
	}
}