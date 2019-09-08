// demo.cpp : �������̨Ӧ�ó������ڵ㡣
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

class _class {//ͳһ�Ĳ�����
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
		//ָ�������
		vector<_class**> v;//ָ���ָ�������
		_class* p = new _class();//��һ��ʵ�������ָ��
		_class* p1 = new _class();//�ڶ���ʵ�������ָ��
		_class** ref = &p;//��refָ���һ��ָ��
		v.push_back(ref);//push������
		(*ref)->a = 5;//��������
		ref = &p1;//����ָ��ڶ���ָ��
		(*ref)->a = 6;//��������
		//v[0] = ref;//�޸�����,���޸ĵĻ�����ָ��ԭ����һ��ָ��
		cout << (*v[0])->a << endl;//���Խ��
	}

	void pointer_copy_a() {
		//û�����ָ�븴��
		int a = 5;
		int* p=&a;
		*p = 1;
		cout << a << endl;
		*p = a;
		*p = 2;
		cout << a << endl;
	}
	void pointer_copy() {
		//ָ������õ�copy
		_class* p = new _class();//��һ��ʵ�������ָ��
		_class* p1 = new _class();//�ڶ���ʵ�������ָ��
		_class** ref = &p;//��refָ���һ��ָ��

		p->c = new _another;
		p1->c = new _another;
		cout << "��һ�����е�ָ���ַ:" << &(p->c) << endl;
		cout << "�ڶ������е�ָ���ַ:" << &(p1->c) << endl;

		(*ref) = p1;
		//p=p1
		cout << "�Ѹ���" << endl;
		cout << "��һ�����е�ָ���ַ:" << &(p->c) << endl;
		cout << "�ڶ������е�ָ���ַ:" << &(p1->c) << endl;
		ref = &p;

		*(*ref) = *p1;
		//p=p1
		cout << "�Ѹ���" << endl;
		cout << "��һ�����е�ָ���ַ:" << &(p->c) << endl;
		cout << "�ڶ������е�ָ���ַ:" << &(p1->c) << endl;
		ref = &p;

		ref = &p1;
		//p=p1
		cout << "�Ѹ���" << endl;
		cout << "��һ�����е�ָ���ַ:" << &(p->c) << endl;
		cout << "�ڶ������е�ָ���ַ:" << &(p1->c) << endl;
		ref = &p;

		*ref = new _class(*p1);
		//p=p1
		cout << "�Ѹ���" << endl;
		cout << "��һ�����е�ָ���ַ:" << &(p->c) << endl;
		cout << "�ڶ������е�ָ���ַ:" << &(p1->c) << endl;

		delete p;
		delete p1;
	}
}

int main()
{
	test::pointer_copy();
	//�����е�û�б仯������������ҲҪ����
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

