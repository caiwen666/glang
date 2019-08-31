#pragma once
#include"parse.h"
#include "Node.h"
#include <vector>

using namespace std;

class Expression
{
public:
	Expression(parse& parser) :_parser(parser){
		//����flag�����
		Node* t = new Node();
		flag.push_back(&t);
		context_node = flag.back();
	};
	Node* parseToken();
	~Expression();
private:
	parse & _parser;



	Node** context_node;
	vector<Node**> flag;//flag�����
	/*
		�������һ��flag��
		�����˳�һ����
		���ƺ�����ʱ���flag���е����ڵ���в���������Ĳ���Ӱ��
		���˳�����������Ϊһ�����ڵ����߻��ұ�
	*/
};

