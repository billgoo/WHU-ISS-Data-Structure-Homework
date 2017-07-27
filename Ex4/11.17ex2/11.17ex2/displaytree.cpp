/****************************************
*Creat:Inorder traversal binary tree
*
*Author:B`G
*
*2014302580191
*
*Date:11/18/2015
*****************************************/

#include <iostream>
#include<string.h>
#include<stack> 
#pragma warning (disable:4996)
#pragma warning (disable:4018)
#pragma warning (disable:4553)
using namespace std;
const int MAX = 100;
struct BiTNode
{
	char data;
	BiTNode* lChild, *rChild;
};
BiTNode* createBinaryTree()
{
	int i;
	char ch;
	BiTNode *s, *t, *p[MAX];
	cout << "输入结点信息\n";
	cout << "输入当前是第几个结点:\n";
	cin >> i;
	cout << "输入当前结点的数据(输入#代表结束输入,输入$代表当前结点为空结点):\n";
	cin >> ch;
	while (ch != '#')
	{
		if (ch == '$')
		{
			ch = '\0';
		}
		s = (BiTNode*)malloc(sizeof(BiTNode));
		s->data = ch;
		s->lChild = s->rChild = NULL;
		p[i] = s;
		if (i == 1)
		{
			t = s;
		}
		else
		{
			int j = i / 2;
			if (i == 2 * j)
			{
				p[j]->lChild = s;
			}
			else
			{
				p[j]->rChild = s;
			}
		}
		cout << "输入结点信息\n";
		cout << "输入当前是第几个结点:\n";
		cin >> i;
		cout << "输入当前结点的数据(输入#时结束输入,输入@代表当前结点为空结点):\n";
		cin >> ch;
	}
	return t;
}

//输出树
void printBinaryTree(BiTNode* bt, int level, char c[128])
{
	int i;
	if (level < 127)
	{
		for (i = 1; i<level; ++i)
		{
			if (c[i])
			{
				cout << "|";
			}
			else
			{
				cout << " ";
			}
		}
		if (level)
		{
			cout << "+-";
		}
		if (bt == NULL)
		{
			cout << endl;
		}
		else
		{
			cout << bt->data << endl;
			if (bt->lChild || bt->rChild)
			{
				c[level + 1] = 1;
				printBinaryTree(bt->rChild, level + 1, c);
				c[level + 1] = 0;
				printBinaryTree(bt->lChild, level + 1, c);
			}
		}
	}
}

//main
int main()
{
	BiTNode *bt;
	bt = createBinaryTree();
	char c[128];
	printBinaryTree(bt, 0, c);
	cout << endl;
	system("pause");
	return 0;
}
