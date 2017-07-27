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

using namespace std;

const int MAX = 100;
//结构
struct BTNode
{
	char data;
	BTNode *leftchild, *rightchild;
};

//构造树
BTNode* createBiTree()
{
	int i;
	char ch;
	BTNode *s, *t, *p[MAX];
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
		s = (BTNode*)malloc(sizeof(BTNode));
		s->data = ch;
		s->leftchild = s->rightchild = NULL;
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
				p[j]->leftchild = s;
			}
			else
			{
				p[j]->rightchild = s;
			}
		}
		cout << "输入结点信息\n";
		cout << "输入当前是第几个结点:\n";
		cin >> i;
		cout << "输入当前结点的数据(输入#时结束输入,输入$代表当前结点为空结点):\n";
		cin >> ch;
	}
	return t;
}
void levelTraversal(BTNode* bt)
{
	if (bt == NULL)
	{
		return;
	}
	int front = -1;//队首结点的位置
	int rear = 0;//队尾结点的位置
	BTNode* quene[MAX];
	quene[rear] = bt;
	while (front != rear)
	{
		++front;
		cout << quene[front]->data;
		if (quene[front]->rightchild)
		{
			++rear;
			quene[rear] = quene[front]->rightchild;
		}
		if (quene[front]->leftchild)
		{
			++rear;
			quene[rear] = quene[front]->leftchild;
		}
	}
}

//main
int main(int argc, const char * argv[])
{
	BTNode* bt;
	bt = createBiTree();
	cout << "该二叉树的从右到左的层次遍历为:\n";
	levelTraversal(bt);
	cout << endl;
	system("pause");
	return 0;
}
