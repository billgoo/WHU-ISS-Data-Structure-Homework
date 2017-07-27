#include <iostream>
#include<cstdlib>
#include <list>
#include<vector>
#include<iomanip>
#include<algorithm>

using namespace std;

struct Term {
	float coef;//coefficient
	int exp;//exponent
	Term(float c, int e) 
	{
		this->coef = c;
		this->exp = e;
	}
};

class Polynominal //class of polyminal
{
public:
	list  <Term>  mulPoly;//make a list
	void inputPoly();//input
	void outputPoly();//output
	friend Polynominal operator * (Polynominal &, Polynominal &);//overload *
private:
	int polyLen = 0;//nembers of different exponent items of polynominal

};

void Polynominal::inputPoly() 
{
	cout << "Input the length of the polynominal(The default is 0)" << endl;
	cin >> this->polyLen;
	for (int i = 0; i < this->polyLen; i++)//set each item
	{
		float cItem;
		int eItem;
		cout << "Input the coefficient of the " << i + 1 << " item" << endl;
		cin >> cItem;
		cout << "Input the exponent of the " << i + 1 << " item" << endl;
		cin >> eItem;
		Term linkPoly { cItem , eItem };//temporary polynominal
		this->mulPoly.push_back(linkPoly);
	}//for end here
}//input end here

void Polynominal::outputPoly() 
{
	cout << "The polynominal " << " = ";
	list <Term> :: iterator  polyList;//temp iterator
	//定义动态数组便于赋值排序
	//系数
	float *a = new float;
	//指数
	int *b = new int;
	//排序合并后系数，长度小于等于 a[]
	float *c = new float;
	
	int i = 0;//数组长度，在for 中定义

	for (polyList = this->mulPoly.begin(); polyList != this->mulPoly.end(); polyList++)
	{//output

		a[i] = (*polyList).coef;
		b[i] = (*polyList).exp;
		i++;
		//实现数值存储便于排序调用
		/*if (polyList == this->mulPoly.begin())//first item
		{
			if ((*polyList).exp == 0)//指数为０时
			{
				cout << (*polyList).coef ;
			}
			else if ((*polyList).exp == 1)//指数为１时
			{
				if ((*polyList).coef == 1)//合并系数为+-1
				{
					cout << "X";
				}
				else if((*polyList).coef == -1)
				{
					cout << "-X";
				}
				else
				{
					cout << (*polyList).coef << "X" ;
				}
			}
			else//指数大于等于２时
			{
				if ((*polyList).coef == 1)
				{
					cout << "X^" << (*polyList).exp;
				}
				else if ((*polyList).coef == -1)
				{
					cout << "-X^" << (*polyList).exp;
				}
				else
				{
					cout << (*polyList).coef << "X^" << (*polyList).exp;
				}
			}
		}//以下循环同上
		else
		{
			if ((*polyList).coef > 0)//second
			{
				if ((*polyList).exp == 0)
				{
					cout << "+" << (*polyList).coef;
				}
				else if ((*polyList).exp == 1)
				{
					if ((*polyList).coef == 1)
					{
						cout << "+X";
					}
					else
					{
						cout << "+" << (*polyList).coef << "X";
					}
				}
				else
				{
					if ((*polyList).coef == 1)
					{
						cout << "+X^" << (*polyList).exp;
					}
					else
					{
						cout << "+" << (*polyList).coef << "X^" << (*polyList).exp;
					}
				}
			}
			else if ((*polyList).coef < 0)
			{
				if ((*polyList).exp == 0)
				{
					cout << (*polyList).coef;
				}
				else if ((*polyList).exp == 1)
				{
					if ((*polyList).coef == -1)
					{
						cout << "-X";
					}
					else
					{
						cout << (*polyList).coef << "X";
					}
				}
				else
				{
					if ((*polyList).coef == -1)
					{
						cout << "-X^" << (*polyList).exp;
					}
					else
					{
						cout << (*polyList).coef << "X^" << (*polyList).exp;
					}
				}
			}
		}//out else end here*/
	}//end for 
	int n;
	n = i + 1;//便于排序故定义
	sort(b + 0, b + n);//排序
	
	for (int j = 0; j < i; j++)
	{
		if (b[j]==b[j+1])
		{
			c[j] = 0;
			c[j + 1] = a[j] + a[j + 1];
		}
		else
		{
			c[j] = a[j];
			c[j + 1] = a[j + 1];
		}
	}//合并同类项
	delete[] a;

	for (int k = 0; k < n; k++)
	{
		if (k = 0)//first item
		{
			if (b[k] == 0 && c[k] != 0)//指数为０时
			{
				cout << c[k];
			}
			else if (b[k] == 1)//指数为１时
			{
				if (c[k] == 1)//合并系数为+-1
				{
					cout << "X";
				}
				else if (c[k] == -1)
				{
					cout << "-X";
				}
				else if(c[k] != 0 && c[k] != 1 && c[k] != -1)
				{
					cout << c[k] << "X";
				}
			}
			else//指数大于等于２时
			{
				if (c[k] == 1)
				{
					cout << "X^" << b[k];
				}
				else if (c[k] == -1)
				{
					cout << "-X^" << b[k];
				}
				else if (c[k] != 0 && c[k] != 1 && c[k] != -1)
				{
					cout << c[k] << "X^" << b[k];
				}
			}
		}//以下循环同上,第一项指数
		else
		{
			if (c[k] > 0)//second
			{
				if (b[k] == 0)
				{
					cout << "+" << c[k];
				}
				else if (b[k] == 1)
				{
					if (c[k] == 1)
					{
						cout << "+X";
					}
					else
					{
						cout << "+" << c[k] << "X";
					}
				}
				else
				{
					if (c[k] == 1)
					{
						cout << "+X^" << b[k];
					}
					else
					{
						cout << "+" << c[k] << "X^" << b[k];
					}
				}
			}//if coef>0 end here
			else if (c[k] < 0)
			{
				if (b[k] == 0)
				{
					cout << c[k];
				}
				else if (b[k] == 1)
				{
					if (c[k] == -1)
					{
						cout << "-X";
					}
					else
					{
						cout << c[k] << "X";
					}
				}
				else
				{
					if (c[k] == -1)
					{
						cout << "-X^" << b[k];
					}
					else
					{
						cout << c[k] << "X^" << b[k];
					}
				}

			}// coef<0 end here

		}//out else end here

	}//for end here
	delete[] b;
	delete[] c;
	
	cout << endl;//结束 这次 输出
	
}

Polynominal operator *(Polynominal & firPoly, Polynominal & secPoly)
{
	Polynominal result;
	list <Term> :: iterator alist;
	list <Term> :: iterator blist;
	for (alist = firPoly.mulPoly.begin(); alist != firPoly.mulPoly.end(); alist++)
	{
		for (blist = secPoly.mulPoly.begin(); blist != secPoly.mulPoly.end(); blist++)
		{
			float rec;
			int ree;
			//两个单项式相乘
			rec = (*alist).coef * (*blist).coef;
			ree = (*alist).exp + (*blist).exp;
			Term rePoly
			{
				rec ,ree
			};
			result.mulPoly.push_back(rePoly);
		}//inner for
	}//outer for
	return result;
}//end *

int main()
{
	Polynominal ah, bh, ch;
	ah.inputPoly();      //input polynomial a
	ah.outputPoly();
	bh.inputPoly();      //input polynomial b
	bh.outputPoly();
	ch = ah*bh;
	ch.outputPoly();    //output the result
	system("pause");
	return 0;
}