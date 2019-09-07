#include "Expression.h"
#include "ExpressionException.h"
#include <string>

using namespace std;

Expression::~Expression()
{
}

Node * Expression::parseToken()
{
	while (true) {
		Token * t = _parser.getToken();
		if (t->type == _end) {
			delete t;
			t = NULL;
			break;
		}
		if (t->type == _operator) {//如果是运算符，分情况
			if (t->text == "(") {//创建节点，根据当前情况判断在左边还是右边，将此节点加入flag域队列
				Node* temp = new Node();//创建节点
				if ((*context_node)->isOperator) {//判断左边还是右边
					if ((*context_node)->right != NULL) {//右边已经有人了
						throw ExpressionException(t, "左括号前的运算符已有左边");
					}
					//现在是右边
					(*context_node)->right = temp;
					//然后将node加入进去
					flag.push_back(&(*context_node)->right);
				}
				else {
					//左边
					(*context_node)->left = temp;
					flag.push_back(&(*context_node)->left);
				}
				//更新上下文
				context_node = flag.back();
				continue;
			}
			if (t->text == ")") {//将flag域队列的最后一个节点移除
				flag.pop_back();
				//更新上下文
				context_node = flag.back();
				continue;
			}

			Node* temp = new Node;
			if (t->text == "+"||t->text=="-") {
				//如果当前不是运算符的话
				if ((*context_node)->isOperator == false) {
					if ((*context_node)->token = NULL) {//说明是个空的节点，这种我们将左边置为0
						(*context_node)->left = new Node();
						(*context_node)->left->token = new Token(-1, "0");
					}
					else {//有token说明这里是个数字，token移到左边
						(*context_node)->left = new Node();
						(*context_node)->left->token = (*context_node)->token;
						(*context_node)->token = NULL;
					}
					//然后设置符号
					(*context_node)->isOperator == true;
					(*context_node)->token = new Token(t->position,t->text,t->type);
					//这里因为是复制过去，所以采用这种方式，当前的t会在循环结束后回收掉
				}
				else {//是运算符的话分两种情况
					if ((*context_node)->right == NULL) {//右边如果没有东西，那么就报错
						throw ExpressionException(t, "此运算符左边已有运算符");
					}
					else {
						//这里比较统一，一律
						/*
						1将temp的运算符设置为当前的运算符，然后context_node置为temp左边
						2设置temp为上下文
						3更新当前flag域
						4更新父flag域的指向
						*/
						temp->isOperator = true;
						temp->token = new Token(t->position, t->text, t->type);
						temp->left = (*context_node);
						context_node==&temp;
						if (flag.size() == 1) {
							flag.pop_back();
							flag.push_back(context_node);
							if ((*flag[flag.size() - 2])->right == NULL) {//如果倒数第二个flag的right为null,那么说明当前上下文在left，反之right
								(*flag[flag.size() - 2])->left = (*context_node);
							}
							else {
								(*flag[flag.size() - 2])->right = (*context_node);
							}
						}
					}
				}
				continue;
			}
			if (t->text == "*" || t->text == "/") {
				////////因为运算符基本上的逻辑都大同小异，所以直接复制过来了////////////
				//如果当前不是运算符的话
				if ((*context_node)->isOperator == false) {
					if ((*context_node)->token = NULL) {//说明是个空的节点，这种我们将左边置为0
						(*context_node)->left = new Node();
						(*context_node)->left->token = new Token(-1, "0");
					}
					else {//有token说明这里是个数字，token移到左边
						(*context_node)->left = new Node();
						(*context_node)->left->token = (*context_node)->token;
						(*context_node)->token = NULL;
					}
					//然后设置符号
					(*context_node)->isOperator == true;
					(*context_node)->token = new Token(t->position, t->text, t->type);
					//这里因为是复制过去，所以采用这种方式，当前的t会在循环结束后回收掉
				}
				else {//是运算符的话分两种情况
					if ((*context_node)->right == NULL) {//右边如果没有东西，那么就报错
						throw ExpressionException(t, "此运算符左边已有运算符");
					}
					else {
						//反之就有点麻烦
						//如果是*/运算符，那么
						/*
						1将temp的运算符设置为当前的运算符，然后context_node置为temp左边
						2设置temp为上下文//flag域应该不用更新，他俩是一致的
						*/
						
						//如果是+-运算符，那么
						/*
						1寻找切入点，循环判断
						4将当前上下文的right的符号设置为true，token复制到left，token为t
						*/
						temp->isOperator = true;
						temp->token = new Token(t->position, t->text, t->type);
						temp->left = (*context_node);
						context_node == &temp;
						if (flag.size() == 1) {
							flag.pop_back();
							flag.push_back(context_node);
							if ((*flag[flag.size() - 2])->right == NULL) {//如果倒数第二个flag的right为null,那么说明当前上下文在left，反之right
								(*flag[flag.size() - 2])->left = (*context_node);
							}
							else {
								(*flag[flag.size() - 2])->right = (*context_node);
							}
						}
					}
				}
				continue;
			}
		}
		if (t->type == _number) {//如果是数字
			if ((*context_node)->isOperator) {

			}
		}
		t->test_print(cout);
		delete t;
		t = NULL;
	}

	//解析结束

	return *flag[0];
}