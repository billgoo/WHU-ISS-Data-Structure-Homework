//Josephus method
#include<iostream>
using namespace std;

int fun(int n, int i, int r) {

	if (i == 1)
		return (n + r - 1) % n;
	else
		return (fun(n - 1, i - 1, r) + r) % n;

}//������

int main(int argc, char* argv[])
{
	int n, r;
	cout << "Enter the total number of people:\n";
	cin >> n;
	cout << "Enter the roll number:\n";
	cin >> r;
	//����
	for (int i = 1; i <= n; i++)
	{
		cout << fun(n, i, r) + 1;
	}
	//ѭ��
	system("pause");
	return 0;
}