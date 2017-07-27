#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

void outsort(string &input, vector<string> &output, int x)
{
	if (x == input.size())
	{
		return;
	}
	if (x == 0)
	{
		string outNum("");
		outNum += input[x];
		output.push_back(outNum);
	}
	else
	{
		vector<string> newOutput;// ��ջ����
		int size = output.size();// ��i������ջ
		for (int i = 0; i < size; ++i)
		{
			// ��i����ջ����
			int count = output[i].size();// Ѱ��ǰһ����ջ�������±�
			int userx;
			for (int j = 0; j < count; ++j)
			{
				if (input[x - 1] == output[i][j])
				{
					userx = j;
					break;
				}
			}//inner first for
			string tmp(output[i]);
			for (int j = userx; j <= count; ++j)
			{
				tmp.insert(tmp.begin() + j, input[x]);
				newOutput.push_back(tmp);
				tmp.erase(tmp.begin() + j);
			}//inner second for
		}//out for end here
		swap(output, newOutput);
	}//else end here
	outsort(input, output, x + 1);
}

vector<string> outcome (string input) {
	vector<string> result;
	int size = input.size();
	if (size <= 0)
		return result;
	outsort(input, result, 0);
	sort(result.begin(), result.end());
	return result;
}

int main()
{
	int n;
	n = 4;
	string number("");
	int num;
	cout << "Input four numbers in order:\n";

	while (n > 0 && cin >> num)
	{
		number += num + '0';
		n--;
	}
	
	vector<string> outNum = outcome(number);
	int size = outNum.size();

	for (int i = 0; i < size; ++i)
	{
		int count = outNum[i].size();
		for (int j = 0; j < count; ++j)
		{
			if (j == 0)
			{
				cout << outNum[i][j];
			}
			else
			{
				cout << " " << outNum[i][j];
			}
		}//inner for
		cout << "    " << size << "th different forms" << endl;
	}//out for

	system("pause");
	return 0;
}