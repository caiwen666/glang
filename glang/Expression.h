#pragma once
#include"parse.h"
#include "Node.h"
#include <vector>

using namespace std;

class Expression
{
public:
	Expression(parse& parser) :_parser(parser){
		//加入flag域队列
		Node* t = new Node();
		flag.push_back(&t);
		context_node = flag.back();
	};
	Node* parseToken();
	~Expression();
private:
	parse & _parser;



	Node** context_node;
	vector<Node**> flag;//flag域队列
	/*
		（会进入一个flag域
		）会退出一个域
		上移和下移时会对flag域中的主节点进行操作，域外的不受影响
		域退出后整个域作为一个主节点的左边或右边
	*/
};

