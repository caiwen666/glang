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

class _another {
public:
	int a = 0;
	int b = 1;
	_another(const _another &c) {
		a = c.a;
		b = c.b;
	}
	_another() {}
};

class _class {//统一的测试类
public:
	int a = 0;
	int b = 1;
	_another* c = NULL;
	_class(const _class & a) {
		c = new _another(*a.c);
		cout << "_class copy" << endl;
	}
	_class() {

	}
	~_class() {
		if (c != NULL) {
			delete c;
			c = NULL;
		}
	}
};



namespace test {
	void pointer_ref() {
		//指针的引用
		vector<_class**> v;//指针的指针的向量
		_class* p = new _class();//第一个实例化类的指针
		_class* p1 = new _class();//第二个实例化类的指针
		_class** ref = &p;//将ref指向第一个指针
		v.push_back(ref);//push到向量
		(*ref)->a = 5;//更改数据
		ref = &p1;//重新指向第二个指针
		(*ref)->a = 6;//更改数据
		//v[0] = ref;//修改数据,不修改的话还是指向原来第一个指针
		cout << (*v[0])->a << endl;//测试结果
	}

	void pointer_copy_a() {
		//没有类的指针复制
		int a = 5;
		int* p=&a;
		*p = 1;
		cout << a << endl;
		*p = a;
		*p = 2;
		cout << a << endl;
	}
	void pointer_copy() {
		//指针的引用的copy
		_class* p = new _class();//第一个实例化类的指针
		_class* p1 = new _class();//第二个实例化类的指针
		_class** ref = &p;//将ref指向第一个指针

		p->c = new _another;
		p1->c = new _another;
		cout << "第一个类中的指针地址:" << &(p->c) << endl;
		cout << "第二个类中的指针地址:" << &(p1->c) << endl;

		(*ref) = p1;
		//p=p1
		cout << "已复制" << endl;
		cout << "第一个类中的指针地址:" << &(p->c) << endl;
		cout << "第二个类中的指针地址:" << &(p1->c) << endl;
		ref = &p;

		*(*ref) = *p1;
		//p=p1
		cout << "已复制" << endl;
		cout << "第一个类中的指针地址:" << &(p->c) << endl;
		cout << "第二个类中的指针地址:" << &(p1->c) << endl;
		ref = &p;

		ref = &p1;
		//p=p1
		cout << "已复制" << endl;
		cout << "第一个类中的指针地址:" << &(p->c) << endl;
		cout << "第二个类中的指针地址:" << &(p1->c) << endl;
		ref = &p;

		*ref = new _class(*p1);
		//p=p1
		cout << "已复制" << endl;
		cout << "第一个类中的指针地址:" << &(p->c) << endl;
		cout << "第二个类中的指针地址:" << &(p1->c) << endl;

		delete p;
		delete p1;
	}
}

int main()
{
	test::pointer_copy();
	//向量中的没有变化，所以向量中也要更新
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
	_CrtDumpMemoryLeaks();
	system("pause");
    return 0;
}

