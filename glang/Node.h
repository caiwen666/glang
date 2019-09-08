#pragma once
#include "token.h"

class Node
{
public:
	Node() {};
	~Node() {
		if (left != NULL) {
			delete left;
		}
		if (right != NULL) {
			delete right;
		}
		if (token != NULL) {
			delete token;
		}
	};
	Node* left=NULL;
	Node* right=NULL;
	bool isOperator=false;
	Token* token=NULL;
};

