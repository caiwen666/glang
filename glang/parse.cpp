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
				throw ParseException(_position, _line, "С�����û������");
			}
			//���ˣ����½������ַ����ڴ�֮ǰ�����ָ�����һ��
			_position--;
			Token* t = context_token;
			context_token = NULL;
			context_mode = common;
			return t;
		}
		
		if (this_text == '+'			//������ţ�ֱ�ӷ��� #0001
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

		if (this_text == '.') {			//С��
			if (context_token==NULL) {
				throw ParseException(_position, _line, "С����ǰû������");
			}
			if (context_mode == doubleNum) {
				throw ParseException(_position, _line, "�����г��ֶ��С����");
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

		throw ParseException(_position, _line, string("û�б�ʶ����ַ�:")+this_text);

	}
	if (context_block != 0) {
		throw ParseException(_position, _line, string("ȱ�����������������ţ���Ҫ����������������:")+to_string(context_block));
	}
	if (context_mode == doubleNum&&context_token->text.substr(context_token->text.size() - 1, context_token->text.size()) == ".") {
		throw ParseException(_position, _line, "С�����û������");
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