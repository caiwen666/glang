// demo.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

void print(vector<int>* v) {
	
	vector<int>::iterator i = v->begin();
	for (; i != v->end(); i++) {
		cout << *i << endl;
	}
}

class aa {
public:
	int a = 0;
	int b = 1;
};

class _class {
public:
	int a = 0;
	int b = 1;
};

int main()
{
	vector<_class**> v;
	_class* p = new _class();
	_class** ref = &p;
	v.push_back(ref);
	v.pop_back();
	(*ref)->a = 5;
	cout << p->a << endl;
	/*
	vector<aa&> a;
	aa * q1 = new aa();
	aa b = *q1;
	b.a = 2;
	b.b = 2;
	a.push_back(b);

	aa* q2 = new aa();
	aa c = *q2;
	c.a = 4;
	c.b = 4;
	a.push_back(c);

	a.pop_back();
	cout << c.a << c.b;

	aa* p1 = &b;
	delete p1;
	p1 = NULL;
	aa* p2 = &c;
	delete p2;
	p2 = NULL;
	cout << b.a << b.b;
	*/
	system("pause");
    return 0;
}

