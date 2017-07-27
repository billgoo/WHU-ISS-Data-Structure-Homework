#include<iostream>
using namespace std;
void exchange(int &x,int &y)
{
	int temp;
	temp = x;
	x = y;
	y= temp;
};

void sort(int &i,int &j,int &k)
{
	void exchange(int &, int &);
	if (i >= j)
	{
		exchange(i, j);
	}
	if (j >= k)
	{
		exchange(j, k);
	}
	if (i >= j)
	{
		exchange(i, j);
	}
};

int main()
{
	void sort(int &,int &,int &);
	int i, j, k;
	cin >> i >> j >> k;
	sort(i, j, k);
	cout << i << j << k;
	return 0;



}