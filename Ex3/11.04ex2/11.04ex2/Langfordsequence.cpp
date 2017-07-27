/*
*Author:B`G
*Date:14/11/2015
*11.04ex2 solution
*DFS find Langford Sequece
*/
#include<iostream>

using namespace std;

int n = 0, indexReal = 0, indexTotal = 0;
//class langford Langford
class Langford
{
public:
	int langford[100];
	bool langfordNum[100];
	bool landfordSit[100];
	Langford();
	~Langford();

private:

};

Langford::Langford()
{
	memset(langford, 0, sizeof(langford));
	for (int i = 0; i < 100; i++)
	{
		langfordNum[i] = false;
		landfordSit[i] = false;
	}
}

Langford::~Langford()
{

}

//DFS function
//void Search(Langford langford, int Sit, int Dep);
void Search(Langford langford, int Sit, int Dep)
{
	if (Dep == n)
	{
		for (int i = 1; i <= n * 2; i++)
		{
			cout << langford.langford[i] << " ";
		}
		cout << endl;
		indexTotal++;
		return;
	}
	else
	{
		indexReal++;
		indexTotal++;
	}
	
	if (langford.landfordSit[Sit] && Sit < 2 * n)
	{
		Search(langford, Sit + 1, Dep);
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (!langford.langfordNum[i] && !langford.landfordSit[Sit + i + 1]
				&& (Sit + i + 1) <= 2 * n)
			{
				int t1 = langford.langford[Sit];
				int t2 = langford.langford[Sit + i + 1];
				langford.langford[Sit] = i;
				langford.langford[Sit + i + 1] = i;
				langford.langfordNum[i] = true;
				langford.landfordSit[Sit] = true;
				langford.landfordSit[Sit + i + 1] = true;
				//ตÝน้
				Search(langford, Sit + 1, Dep + 1);
				langford.langford[Sit] = t1;
				langford.langford[Sit + i + 1] = t2;
				langford.langfordNum[i] = false;
				langford.landfordSit[Sit] = false;
				langford.landfordSit[Sit + i + 1] = false;
			}//inner if

		}//for end here

	}//out if
};

//function judge if n larger than 3
void Judge(int m)
{
	if (m >= 3)
	{
		n = m;
	}
	else
	{
		cout << " Please input a positive integer greater than 3!" << endl;
		cin >> m;

		Judge(m);
	}
};

//function main
int main()
{
	int m;
	cout << " It is a program to calculate langford sequence!"
		<< "\n Please input a positive integer n(n>=3): " << endl;
	cin >> m;
	Judge(m);
	Langford Langford;
	Search(Langford, 1, 0);
	if (indexReal == indexTotal)
	{
		cout << "There is no langford sequence!" << endl;
	}
	system("pause");
	return 0;
}
