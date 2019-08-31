#pragma once
#include "token.h"

class Node
{
public:
	Node() {};
	~Node() {};
	Node* left=NULL;
	Node* right=NULL;
	bool isOperator=false;
	Token* token=NULL;

};

