#include "parse.h"
#include "ParseException.h"


Token* parse::getToken() {

	while (_position < _code.size()) {
		char this_text = _code[_position];
		_position++;


		if (this_text == ' ') {
			continue;
		}

		if (context_token != NULL&&isdigit(this_text) == 0 && this_text != '.') {
			if (context_mode == doubleNum&&context_token->text.substr(context_token->text.size()-1, context_token->text.size())==".") {
				throw ParseException(_position, _line, "小数点后没有数字");
			}
			//回退，重新解析本字符，在此之前把数字给结算一下
			_position--;
			Token* t = context_token;
			context_token = NULL;
			context_mode = common;
			return t;
		}
		
		if (this_text == '+'			//运算符号，直接返回 #0001
			|| this_text == '-'
			|| this_text == '*'
			|| this_text == '/'
			) {
			Token* t = new Token(_position, string(1,this_text), _operator);
			return t;
		}

		if (this_text == '(' ) {
			context_block++;
			Token* t = new Token(_position, string(1, this_text), _operator);
			return t;
		}

		if (this_text == ')') {
			context_block--;
			Token* t = new Token(_position, string(1, this_text), _operator);
			return t;
		}

		if (this_text == '.') {			//小数
			if (context_token==NULL) {
				throw ParseException(_position, _line, "小数点前没有数字");
			}
			if (context_mode == doubleNum) {
				throw ParseException(_position, _line, "数字中出现多个小数点");
			}
			context_token->text += '.';
			context_mode = doubleNum;
			continue;
		}

		if (isdigit(this_text) != 0) {
			if (context_token != NULL) {
				context_token->text += this_text;
			}
			else {
				context_token = new Token(_position, string(1,this_text), _number);
			}
			//context_token
			continue;
		}

		throw ParseException(_position, _line, string("没有被识别的字符:")+this_text);

	}
	if (context_block != 0) {
		throw ParseException(_position, _line, string("缺少右括号来结束括号，需要结束的左括号数量:")+to_string(context_block));
	}
	if (context_mode == doubleNum&&context_token->text.substr(context_token->text.size() - 1, context_token->text.size()) == ".") {
		throw ParseException(_position, _line, "小数点后没有数字");
	}
	
	if (context_token != NULL) {
		Token* t = context_token;
		context_token = NULL;
		context_mode = common;
		return t;
	}

	Token* t = new Token(_position, "end", _end);
	return t;
}