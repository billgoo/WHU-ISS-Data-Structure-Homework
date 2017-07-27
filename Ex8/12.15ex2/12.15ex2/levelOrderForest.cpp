/*
*第八次作业：2
*作者：B`G
*12/16/2015
*/

#include<iostream>
#include<queue>

using namespace std;

//
template <class Type> struct BTNode {
	BTNode *left;
	Type data;
	BTNode *right;
	BTNode(Type x) {
		data = x;
		left = right = NULL;
	}
};

template <class Type> class LevelOrderForest;

template <class Type>
class BinaryTree {

private:
	BTNode<Type> *root;
	friend class LevelOrderForest<Type>;

public:
	BinaryTree(BTNode<Type>*t) 
	{
		root = t;
	}

};

//Base class for BT Iterator
template <class Type>
class forstIterator {

public:
	const BinaryTree <Type>*  T; 
	int length;
	const BTNode<Type> *current;

public:
	forstIterator(const BinaryTree <Type>*  BT, int leng):T(BT)
	{
		length = leng;
		current = NULL;
	}

	virtual ~forstIterator() {}
	virtual void First() = 0;
	virtual void operator ++ () = 0;
	operator bool() 
	{ 
		return current != NULL;
	}
	const Type operator()()const 
	{
		if (current)
		{
			return current->data;
		}
		return (Type)0;
	}

};

//Stack node definition
template <class Type>
struct StkNode {
	const BTNode <Type> *Node;
	StkNode(BTNode <Type> *N = NULL) : Node(N) {}
};


template <class Type>
class LevelOrderForest : public forstIterator <Type> {

	bool renew;

public:
	LevelOrderForest(const BinaryTree <Type> BT[], int length_i)
		: forstIterator<Type>(BT, length_i) { renew = false; }
	~LevelOrderForest() {}

	void First();
	void operator ++ ();
	
protected:
	queue < StkNode<Type> > myQueue;

};

template <class Type>
void LevelOrderForest<Type> ::First() {

	this->renew = true;
	
	for (int i = 0; i < this->length; i++) {
		StkNode <Type> tempNode;
		tempNode.Node = this->T[i].root;
		myQueue.push(tempNode);
	}

	this->current = this->T[0].root;
	operator++();

}

template <class Type>
void LevelOrderForest<Type> :: operator ++() {
	if (myQueue.empty()) {
		this->current = NULL;
		return;
	}
	StkNode<Type> w;
	w = myQueue.front();
	myQueue.pop();
	this->current = w.Node;

	if (w.Node->left != NULL) 
	{
		StkNode <Type> tempNode;
		tempNode.Node = w.Node->left;
		myQueue.push(tempNode);
	}

	if (w.Node->right != NULL) 
	{
		StkNode <Type> tempNode1;
		tempNode1.Node = w.Node->right;
		myQueue.push(tempNode1);
	}

}

int main() 
{
	//
	BTNode<int> *p = new BTNode<int>(6);
	p->left = new BTNode<int>(4);
	p->right = new BTNode<int>(10);
	p->left->left = new BTNode<int>(2);
	p->right->left = new BTNode<int>(8);
	p->right->right = new BTNode<int>(12);
	//
	BTNode<int> *q = new BTNode<int>(6);
	q->left = new BTNode<int>(4);
	q->right = new BTNode<int>(10);
	q->left->left = new BTNode<int>(2);
	q->right->left = new BTNode<int>(8);
	q->right->right = new BTNode<int>(12);

	BinaryTree<int> T1(p);
	BinaryTree<int> T2(q);
	//
	BinaryTree<int> forest[] = { T1 , T2 };

	LevelOrderForest<int> it(forest, 2);

	for (it.First(); it; ++it) 
	{
		cout << it() << "\n";
	}

	cout << endl;
	system("pause");
	return 0;
}

