#include "pch.h"
#include <iostream>
using namespace std;


int fdegree(double value,int n) {
	double k = value;
	if (n > 0) {
		while (n > 1) {
			value = value * k;
			n--;
		}
	}
	if (n == 0) {
		value = 1;
	}
	if (n < 0) {
		n =n*(-1);
		while (n > 1) {
			value = value * k;
			n--;
		}
		value = 1 / value;
		cout << value;
	}
	return(value);
}
int fact(int value) {
	int i = value;
	while (value > 1) {
		value--;
		i = i * value;
	}
	return(i);
}
double sqrt(double value) {
	int a = 0;
	double result;
	double arr[5];
	if (value == 0) {
		result = 0;
	}
	if (value < 0) {
		cout << "No solution in real numbers";
	}
	double k = 0, f = 100;
	while ((value < 1) && (value > 0)) {
		value = value * f;
		k++;
		while (a < 10000) {
			if (a*a == value) {
				result = a;
				break;
			}
			else {
				if ((a*a < value) && ((a + 1)*(a + 1) > value)) {
					arr[0] = a;
					for (int j = 1; j < 4; j++) {
						arr[j] = 0.5*(arr[j - 1] + (value / arr[j - 1]));
					}
					result = arr[3];
					break;
				}
			}
			a++;
		}
		result = (arr[3] /10/ (fdegree(f, (k / 2))));
	}
	if ((k == 0) && (value > 1)) {
		while (a < 10000) {
			if (a*a == value) {
				result = a;
				break;
			}
			else {
				if ((a*a < value) && ((a + 1)*(a + 1) > value)) {
					arr[0] = a;
					for (int j = 1; j < 4; j++) {
						arr[j] = 0.5*(arr[j - 1] + (value / arr[j - 1]));
					}
					result = arr[3];
					break;
				}
			}
			a++;
		}
	}
	return result;
}
int prime(int value) {
	int a = 1;
	for (int l = 2; l <= int(sqrt(value)); l++) {
		if (!(value%l)) {
			a = 0;
			break;
		}
	}
	
	return a;
}
int main()
{
	double value, degree;

	cout << "Enter the number and the degree to which to build the number: ";
	cin >> value >> degree;
	cout<<fdegree(value, degree)<<endl;

	cout << "Enter the number which factorial you need: ";
	cin >> value;
	cout<<fact(value)<<endl;

	cout << "Enter the number from which you want to extract the root: ";
	cin >> value;
	cout<<endl<<sqrt(value)<<endl;

	cout << "Enter the number you want to check for simplicity: ";
	cin >> value;
	if (prime(value)) {
		cout << "prime";
	}
	else {
		cout << "composite";
	}
	
	return 0;
}
