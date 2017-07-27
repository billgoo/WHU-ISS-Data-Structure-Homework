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


void creatBinTree(char *s, BinTree *&root)  //������������sΪ����A(B,C(D,E))��ʽ���ַ��� 
{
	int i;
	bool isRight = false;
	stack<BinTree*> s1;          //��Ž�� 
	stack<char> s2;              //��ŷָ���
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
				cout << temp->data << "���Һ�����" << s[i] << endl;
			}
			else
			{
				temp->lchild = p;
				cout << temp->data << "��������" << s[i] << endl;
			}
			if (s[i + 1] == '(')
				s1.push(p);
		}
		i++;
	}
}

void display(BinTree *root)        //��ʾ���νṹ 
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

void inOrder(BinTree *root)      //�ǵݹ��������
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
	cout << "��������������������A(B,C(D,E))��\n������Ϊ���ӣ�����ǰΪ���ӣ���Ϊ�Һ��ӣ�\n";
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