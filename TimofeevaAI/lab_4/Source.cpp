#include <iostream>
#include <conio.h>
#include <stdio.h>
using namespace std;

double Stepen(float number, int stepen)
{
	float  p, d;
	p = number;
	d = number;
	if (number == 0)
		return 0;
	if (stepen > 0)
	{
		for (int i = 1; i < stepen; i++)
		{
			number = d * p;
			d = number;
		}
	}
	else if (stepen < 0)
	{
		number = 1;
		for (int i = 0; i > stepen; i--)
		{
			number = number / p;
		}
	}
	else if (stepen == 0)
	{
		number = 1;
	}
	return number;
}

int Fact(int c)
{
	if (c < 0)
		return -1;
	else
	{
	   if (c > 0)
	   {
		 int f = 1;
		 for (int i = 1; i < c + 1; i++)
		 {
			 f *= i;
		 }
		 return f;
	   }
	   else
	   return 0;
	}
}


double Koren(double n)
{
	float sqrt = 0;
	if (n < 0)
		return -1;
	else
	{
		if (n > 0)
		{
			for (int i = 0; i < 10000; i++)
			{
				sqrt = 1 + (n - 1) / (sqrt + 1);
			}
			return sqrt;
		}
		else
			return 0;
	}
	
}


int Simple(int m)
{
	if (m <= 0)
		return -1;
	else
	{
		bool n = true;
		for (int i = 2; i <= Koren(m); i++)
		{
			if (m%i == 0)
				n = false;
		}
		if (n == true)
			return 1;
		else
			return 0;
	}
}

int main()
{
	float a, b, h, g, f;
	
	cout << "Enter a number: ";
	cin >> a;
	cout << "Enter stepen: ";
	cin >> b;
	cout << "Result: " << Stepen(a, b) <<endl;

	cout << "Enter a number to find factorial: ";
	cin >> h;
	Fact(h);
	if (Fact(h) == -1)
		cout <<"Negative number"<<endl;
	else
	cout << "Factorial: " << Fact(h) << endl;

	cout << "Enter a number to extract the square root: ";
	cin >> g;
	Koren(g);
	if (Koren(g) == -1)
		cout<<"Negative number"<<endl;
	else
	cout<<"Sqrt: "<<Koren(g)<<endl;
	
	cout << "Enter a number to determine its simplicity: ";
	cin >> f;
	Simple(f);
	if (Simple(f) == 1)
		cout << "Simple"<<endl;
	else
		cout << "Not simple"<<endl;
	system("pause");
}