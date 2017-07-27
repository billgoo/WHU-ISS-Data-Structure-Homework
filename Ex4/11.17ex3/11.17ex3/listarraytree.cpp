/****************************************
*Given an array, turn it into a complete binary tree stored in a doubly-linked list
*
*Author:B`G
*
*2014302580191
*
*Date:11/18/2015
*****************************************/
#include <iostream>

using namespace std;

const int MAX = 100;
//�ṹ
struct BTNode
{
	char data;
	BTNode *leftchild, *rightchild;
};

//���������
BTNode* createBinaryTree(char a[], int n)
{
	BTNode *s, *t, *p[MAX];
	for (int i = 0; i < n; ++i)
	{
		s = (BTNode*)malloc(sizeof(BTNode));
		s->data = a[i];
		s->leftchild = s->rightchild = NULL;
		p[i + 1] = s;
		if (i + 1 == 1)
		{
			t = s;
		}
		else
		{
			int j = (i + 1) / 2;
			if (2 * j == (i + 1))
			{
				p[j]->leftchild = s;
			}
			else
			{
				p[j]->rightchild = s;
			}
		}
	}
	return t;
}

//����ǰ�����
void pre_order(BTNode* bt)
{
	if (bt)
	{
		cout << bt->data;
		pre_order(bt->leftchild);
		pre_order(bt->rightchild);
	}
}

//�����������
void in_order(BTNode* bt)
{
	if (bt)
	{
		in_order(bt->leftchild);
		cout << bt->data;
		in_order(bt->rightchild);
	}
}

//�����������
void post_order(BTNode* bt)
{
	if (bt)
	{
		post_order(bt->leftchild);
		post_order(bt->rightchild);
		cout << bt->data;
	}
}

//main
int main(int argc, const char * argv[]) {
	char a[10] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J' };
	BTNode* bt;
	bt = createBinaryTree(a, 10);
	cout << "�ö�������ǰ�����Ϊ: ";
	pre_order(bt);
	cout << endl;
	cout << "�����������������Ϊ: ";
	in_order(bt);
	cout << endl;
	cout << "�ö������ĺ������Ϊ: ";
	post_order(bt);
	cout << endl;
	system("pause");
	return 0;
}
