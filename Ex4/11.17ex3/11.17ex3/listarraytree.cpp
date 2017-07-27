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
//结构
struct BTNode
{
	char data;
	BTNode *leftchild, *rightchild;
};

//构造二叉树
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

//迭代前序遍历
void pre_order(BTNode* bt)
{
	if (bt)
	{
		cout << bt->data;
		pre_order(bt->leftchild);
		pre_order(bt->rightchild);
	}
}

//迭代中序遍历
void in_order(BTNode* bt)
{
	if (bt)
	{
		in_order(bt->leftchild);
		cout << bt->data;
		in_order(bt->rightchild);
	}
}

//迭代后序遍历
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
	cout << "该二叉树的前序遍历为: ";
	pre_order(bt);
	cout << endl;
	cout << "还二叉树的中序遍历为: ";
	in_order(bt);
	cout << endl;
	cout << "该二叉树的后序遍历为: ";
	post_order(bt);
	cout << endl;
	system("pause");
	return 0;
}
