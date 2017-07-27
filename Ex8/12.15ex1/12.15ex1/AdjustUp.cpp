/*
*第八次作业：1
*作者：B`G
*12/15/2015
*/

#include<iostream> 

using namespace std;

//创建最小堆
template<typename Type>class MinHeap
{
private:
	Type *heap;
	static const int defaultsize = 1000;
	int MaxSize;
	int currentsize;
public:
	MinHeap<Type>(int size)
	{
		currentsize = 0;
		Maxsize = defaultsize>size ? size : defaultsize;
	}
	MinHeap<Type>(Type a[], int n);
	bool Insert(Type n);
	bool IsFull()
	{
		return currentsize == MaxSize;
	}
	bool IsEmpty()
	{
		return currentsize == 0;
	}
	bool Delete(Type n);
	void AdjustUp(int start, int n);
	void SortArray();
	void Print();
	
};

//最小...
template<typename Type> MinHeap<Type>::MinHeap(Type a[], int n)
{

	MaxSize = defaultsize>n ? n : defaultsize;
	currentsize = MaxSize;
	heap = new Type[MaxSize];
	for (int i = 0; i<MaxSize; i++)
	{
		heap[i] = a[i];
	}
	int temp = (MaxSize - 2) / 2;
	for (int i = temp; i >= 0; i--)
	{
		AdjustUp(i, currentsize);
	}
}

//插入
template<typename Type>bool MinHeap<Type>::Insert(Type n)
{
	if (currentsize == MaxSize)
	{
		cout << "the heap is full!" << endl;
	}
	heap[currentsize] = n;
	int j = currentsize;
	while (j>0)
	{
		int P = j / 2 - 1;
		if (heap[P]<heap[j])
			break;
		int temp;
		temp = heap[P];
		heap[P] = heap[currentsize];
		heap[currentsize] = temp;
		j = P;
	}
	currentsize++;
	return 1;
}

//删除
template<typename Type>bool MinHeap<Type>::Delete(Type n)
{
	if (currentsize == 0)
	{
		cout << "this heap is empty!" << endl;
	}
	bool flag = 0;
	for (int i = 0; i<currentsize; i++)
	{
		if (heap[i] == n)
		{
			flag = 1;
			heap[i] = heap[currentsize - 1];
			AdjustUp(i, currentsize - 2);
			currentsize--;
			i = 0;
		}
		if (i == currentsize - 1 && flag == 0)
		{
			cout << "there is no this element!" << endl;
		}
	}
	return 1;
}

//....
template<typename Type>void MinHeap<Type>::Print()
{
	for (int i = 0; i<currentsize; i++)
	{
		cout << heap[i] << "   ";
	}
	cout << endl;
}

//AdjustUp()
template<typename Type>void MinHeap<Type>::AdjustUp(int start, int n)
{
	int L, R, min;
	L = start * 2 + 1;
	R = L + 1;

	if (heap[start]>heap[L] && L<n)
	{
		min = L;
	}
	else
	{
		min = start;
	}//1

	if (heap[min]>heap[R] && R<n)
	{
		min = R;
	}//2

	if (start != min)
	{
		int temp;
		temp = heap[start];
		heap[start] = heap[min];
		heap[min] = temp;
		AdjustUp(min, n);
	}//3

}

//
template<typename Type>void MinHeap<Type>::SortArray()
{
	int num = currentsize;

	for (int i = currentsize - 1; i>0; i--)
	{
		int temp;
		temp = heap[i];
		heap[i] = heap[0];
		heap[0] = temp;
		num -= 1;
		AdjustUp(0, num);
	}//

}

//main
int main()
{
	int init[30] = { 17,6,22,29,14,0,21,13,27,18,2,28,8
		,26,3,12,20,4,9,23,15,1,11,5,19,24,16,7,10,25 };
	MinHeap<int> heape(init, 30);

	//调试
	cout << "\n 输出最小堆！" << endl;
	heape.Print();
	cout << "\n" << endl;

	//插入元素
	heape.Insert(20);
	cout << "\n 输出插入结点以后的最小堆！" << endl;
	heape.Print();
	cout << "\n" << endl;

	//执行放入最小堆
	heape.Delete(20);
	heape.SortArray();
	cout << "\n 倒序输出整个数组！" << endl;
	heape.Print();
	cout << "\n\n" << endl;

	system("pause");
	return 0;
}