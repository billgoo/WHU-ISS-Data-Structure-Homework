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
//�ṹ
struct BTNode
{
	char data;
	BTNode *leftchild, *rightchild;
};

//������
BTNode* createBiTree()
{
	int i;
	char ch;
	BTNode *s, *t, *p[MAX];
	cout << "��������Ϣ\n";
	cout << "���뵱ǰ�ǵڼ������:\n";
	cin >> i;
	cout << "���뵱ǰ��������(����#�����������,����$����ǰ���Ϊ�ս��):\n";
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
		cout << "��������Ϣ\n";
		cout << "���뵱ǰ�ǵڼ������:\n";
		cin >> i;
		cout << "���뵱ǰ��������(����#ʱ��������,����$����ǰ���Ϊ�ս��):\n";
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
	int front = -1;//���׽���λ��
	int rear = 0;//��β����λ��
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
	cout << "�ö������Ĵ��ҵ���Ĳ�α���Ϊ:\n";
	levelTraversal(bt);
	cout << endl;
	system("pause");
	return 0;
}
