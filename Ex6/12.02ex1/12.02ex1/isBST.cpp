/*
*第六次作业：
*作者：B`G
*12/1/2015
*/
#include <iostream>
#include <stack>

using namespace std;

template <class Type> struct BTNode {
	BTNode *left;
	Type data;
	BTNode *right;
	BTNode(Type x) {
		data = x;
		left = right = NULL;
	}
};

template <class Type> class BinaryTree {
private:
	BTNode<Type> *t;
public:
	BinaryTree(BTNode<Type>*t) { t = t; }
};

template <class Type> struct StkNode {
	//Stack node definition
	const BTNode <Type> *Node;  //Node Address
	int PopTime;                                        //Counter
	StkNode(BTNode <Type> *N = NULL) : Node(N), PopTime(0) { }
};

template <class Type>
bool isBinarySearchTree(BTNode<Type> *t)
{
	static BTNode<Type> *prev = NULL;

	// traverse the tree in inorder fashion and keep track of prev node
	if (t)
	{
		if (!isBinarySearchTree(t->left))
			return false;

		// Allows only distinct valued nodes 
		if (prev != NULL && t->data <= prev->data)
			return false;

		prev = t;

		return isBinarySearchTree(t->right);
	}

	return true;
}

int main() 
{
	//是BST的
	BTNode<int> *p = new BTNode<int>(6);
	p->left = new BTNode<int>(4);
	p->right = new BTNode<int>(10);
	p->left->left = new BTNode<int>(2);
	p->right->left = new BTNode<int>(8);
	p->right->right = new BTNode<int>(12);
	BinaryTree<int> T(p);

	if ( isBinarySearchTree(p) )
	{
		cout << "\tp is Binary Search Tree!\n" << endl;
	}
	else
	{
		cout << "\tp is not Binary Search Tree!\n" << endl;
	}
	system("pause");
	return 0;
}

