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
using namespace std;

typedef struct node
{
	char data;
	struct node *lchild, *rchild;
}BinTree;

typedef struct node1
{
	BinTree *btnode;
	bool isFirst;
}BTNode;


void creatBinTree(char *s, BinTree *&root)  //创建二叉树，s为形如A(B,C(D,E))形式的字符串 
{
	int i;
	bool isRight = false;
	stack<BinTree*> s1;          //存放结点 
	stack<char> s2;              //存放分隔符
	BinTree *p, *temp;
	root->data = s[0];
	root->lchild = NULL;
	root->rchild = NULL;
	s1.push(root);
	i = 1;
	while (i<=strlen(s)-1)
	{
		if (s[i] == '(')
		{
			s2.push(s[i]);
			isRight = false;
		}
		else if (s[i] == ',')
		{
			isRight = true;
		}
		else if (s[i] == ')')
		{
			s1.pop();
			s2.pop();
		}
		else if (isalpha(s[i]))
		{
			p = (BinTree *)malloc(sizeof(BinTree));
			p->data = s[i];
			p->lchild = NULL;
			p->rchild = NULL;
			temp = s1.top();
			if (isRight == true)
			{
				temp->rchild = p;
				cout << temp->data << "的右孩子是" << s[i] << endl;
			}
			else
			{
				temp->lchild = p;
				cout << temp->data << "的左孩子是" << s[i] << endl;
			}
			if (s[i + 1] == '(')
				s1.push(p);
		}
		i++;
	}
}

void display(BinTree *root)        //显示树形结构 
{
	if (root != NULL)
	{
		cout << root->data;
		if (root->lchild != NULL)
		{
			cout << '(';
			display(root->lchild);
		}
		if (root->rchild != NULL)
		{
			cout << ',';
			display(root->rchild);
			cout << ')';
		}
	}
}

void inOrder(BinTree *root)      //非递归中序遍历
{
	stack<BinTree*> s;
	BinTree *p = root;
	while (p != NULL || !s.empty())
	{
		while (p != NULL)
		{
			s.push(p);
			p = p->lchild;
		}
		if (!s.empty())
		{
			p = s.top();
			cout << p->data << " ";
			s.pop();
			p = p->rchild;
		}
	}
}

//main
int main(int argc, char *argv[])
{
	cout << "创建二叉树，输入形如A(B,C(D,E))，\n括号内为孩子，逗号前为左孩子，后为右孩子：\n";
	char s[100];
	while (scanf("%s", s) == 1)
	{
		BinTree *root = (BinTree *)malloc(sizeof(BinTree));
		creatBinTree(s, root);
		display(root);
		cout << endl;
		inOrder(root);
		cout << endl;
	}
	system("pause");
	return 0;
}