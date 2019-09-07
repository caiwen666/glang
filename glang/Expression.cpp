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
		if (t->type == _operator) {//�����������������
			if (t->text == "(") {//�����ڵ㣬���ݵ�ǰ����ж�����߻����ұߣ����˽ڵ����flag�����
				Node* temp = new Node();//�����ڵ�
				if ((*context_node)->isOperator) {//�ж���߻����ұ�
					if ((*context_node)->right != NULL) {//�ұ��Ѿ�������
						throw ExpressionException(t, "������ǰ��������������");
					}
					//�������ұ�
					(*context_node)->right = temp;
					//Ȼ��node�����ȥ
					flag.push_back(&(*context_node)->right);
				}
				else {
					//���
					(*context_node)->left = temp;
					flag.push_back(&(*context_node)->left);
				}
				//����������
				context_node = flag.back();
				continue;
			}
			if (t->text == ")") {//��flag����е����һ���ڵ��Ƴ�
				flag.pop_back();
				//����������
				context_node = flag.back();
				continue;
			}

			Node* temp = new Node;
			if (t->text == "+"||t->text=="-") {
				//�����ǰ����������Ļ�
				if ((*context_node)->isOperator == false) {
					if ((*context_node)->token = NULL) {//˵���Ǹ��յĽڵ㣬�������ǽ������Ϊ0
						(*context_node)->left = new Node();
						(*context_node)->left->token = new Token(-1, "0");
					}
					else {//��token˵�������Ǹ����֣�token�Ƶ����
						(*context_node)->left = new Node();
						(*context_node)->left->token = (*context_node)->token;
						(*context_node)->token = NULL;
					}
					//Ȼ�����÷���
					(*context_node)->isOperator == true;
					(*context_node)->token = new Token(t->position,t->text,t->type);
					//������Ϊ�Ǹ��ƹ�ȥ�����Բ������ַ�ʽ����ǰ��t����ѭ����������յ�
				}
				else {//��������Ļ����������
					if ((*context_node)->right == NULL) {//�ұ����û�ж�������ô�ͱ���
						throw ExpressionException(t, "�������������������");
					}
					else {
						//����Ƚ�ͳһ��һ��
						/*
						1��temp�����������Ϊ��ǰ���������Ȼ��context_node��Ϊtemp���
						2����tempΪ������
						3���µ�ǰflag��
						4���¸�flag���ָ��
						*/
						temp->isOperator = true;
						temp->token = new Token(t->position, t->text, t->type);
						temp->left = (*context_node);
						context_node==&temp;
						if (flag.size() == 1) {
							flag.pop_back();
							flag.push_back(context_node);
							if ((*flag[flag.size() - 2])->right == NULL) {//��������ڶ���flag��rightΪnull,��ô˵����ǰ��������left����֮right
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
				////////��Ϊ����������ϵ��߼�����ͬС�죬����ֱ�Ӹ��ƹ�����////////////
				//�����ǰ����������Ļ�
				if ((*context_node)->isOperator == false) {
					if ((*context_node)->token = NULL) {//˵���Ǹ��յĽڵ㣬�������ǽ������Ϊ0
						(*context_node)->left = new Node();
						(*context_node)->left->token = new Token(-1, "0");
					}
					else {//��token˵�������Ǹ����֣�token�Ƶ����
						(*context_node)->left = new Node();
						(*context_node)->left->token = (*context_node)->token;
						(*context_node)->token = NULL;
					}
					//Ȼ�����÷���
					(*context_node)->isOperator == true;
					(*context_node)->token = new Token(t->position, t->text, t->type);
					//������Ϊ�Ǹ��ƹ�ȥ�����Բ������ַ�ʽ����ǰ��t����ѭ����������յ�
				}
				else {//��������Ļ����������
					if ((*context_node)->right == NULL) {//�ұ����û�ж�������ô�ͱ���
						throw ExpressionException(t, "�������������������");
					}
					else {
						//��֮���е��鷳
						//�����*/���������ô
						/*
						1��temp�����������Ϊ��ǰ���������Ȼ��context_node��Ϊtemp���
						2����tempΪ������//flag��Ӧ�ò��ø��£�������һ�µ�
						*/
						
						//�����+-���������ô
						/*
						1Ѱ������㣬ѭ���ж�
						4����ǰ�����ĵ�right�ķ�������Ϊtrue��token���Ƶ�left��tokenΪt
						*/
						temp->isOperator = true;
						temp->token = new Token(t->position, t->text, t->type);
						temp->left = (*context_node);
						context_node == &temp;
						if (flag.size() == 1) {
							flag.pop_back();
							flag.push_back(context_node);
							if ((*flag[flag.size() - 2])->right == NULL) {//��������ڶ���flag��rightΪnull,��ô˵����ǰ��������left����֮right
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
		if (t->type == _number) {//���������
			if ((*context_node)->isOperator) {

			}
		}
		t->test_print(cout);
		delete t;
		t = NULL;
	}

	//��������

	return *flag[0];
}