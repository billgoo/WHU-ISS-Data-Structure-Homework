/*
*���ߴ���ҵ��
*���ߣ�B`G
*12/8/2015
*/
#include <iostream>
#include <stack>
#include<algorithm>

using namespace std;
  
int Partition(int * a, int low, int high)
{
	int pivotkey = a[high];
	int p = low - 1;
	for (int j = low; j<high; j++)
	{
		if (a[j] <= pivotkey)
		{
			p++;
			if (p != j)
			{
				swap(a[p], a[j]);
			}                 
		}
	}
	p += 1;
	swap(a[p], a[high]);
	return p;
}

//����һ����¼�����������[low,high]  
typedef struct Region
{
	int low;
	int high;
}Region;

//�ǵݹ鷽ʽʵ�ֿ�������  
void quickSort(int *a, int n)
{
	stack<Region> regions;//����һ��ջ����  
	Region region;
	region.low = 0;
	region.high = n - 1;
	regions.push(region);
	while (!regions.empty())
	{
		region = regions.top();
		regions.pop();
		int p = Partition(a, region.low, region.high);
		if (p - 1>region.low)
		{
			Region regionlow;
			regionlow.low = region.low;
			regionlow.high = p - 1;
			regions.push(regionlow);
		}
		if (p + 1<region.high)
		{
			Region regionhigh;
			regionhigh.low = p + 1;
			regionhigh.high = region.high;
			regions.push(regionhigh);
		}
	}
}

void printArray(int *a, int n)
{
	for (int i = 0; i<n; i++)
		cout << a[i] << " ";
	cout << endl;
}

//main
int main()
{
	int a[] = { 49,38,65,97,76,13,27,49 };
	int n = sizeof(a) / sizeof(int);

	printArray(a, n); 
	quickSort(a, n);
	printArray(a, n);

	system("pause");
	return 0;
}






