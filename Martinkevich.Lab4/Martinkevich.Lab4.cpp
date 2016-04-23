#include <iostream>
#include <math.h>

using namespace std;

bool IsDataValid(double, double, double, int);
typedef double(*F) (double, double, int);
double TwinRates(double, double, int, double, F);
double Trapezium(double, double, int);
double Simpson(double, double, int);

int main()
{
	while (true)
	{
		double a, b, eps;
		int n;
		cout << "Enter a < b " << endl;
		cout << "a: ";
		cin >> a;
		cout << "b: ";
		cin >> b;
		cout << "Enter eps < 1: ";
		cin >> eps;
		cout << "Enter n > 0: ";
		cin >> n;
		if (IsDataValid(a, b, eps, n) != 0)
		{
			system("cls");
			F Form = Trapezium;
			cout << "Component formula of Trapezium: " << TwinRates(a, b, n, eps, Form) << endl;
			Form = Simpson;
			cout << "Component formula of Simpson: " << TwinRates(a, b, n, eps, Form) << endl;
			break;
		}
		system("pause");
		system("cls");
	}
	system("pause");
	return 0;
}

double TwinRates(double a, double b, int n, double eps, F Form)
{
	double PrIntegral = 0, NextIntegral = 1;
	while (fabs(PrIntegral - NextIntegral) > eps)
	{
		PrIntegral = Form(a, b, n);
		NextIntegral = Form(a, b, 2 * n);
		n = 2 * n;
	}
	double Integral = Form(a, b, n);
	return Integral;
}

double Trapezium(double a, double b, int n)
{
	double step = (b - a) / n;
	double t = a;
	double Integral = sin(t*t);
	while (t < b)
	{
		t = t + step;
		Integral = Integral + 2 * sin(t*t);
	}
	Integral = Integral + sin(b*b);
	Integral = (step / 2)*Integral;
	return Integral;
}

double Simpson(double a, double b, int n)
{
	double step = (b - a) / n;
	double t = a;
	double Integral = sin(t*t);
	while (t < b)
	{
		t = t + 2 * step;
		Integral = Integral + 2 * sin(t*t);
	}
	while (t < b)
	{
		t = t + step;
		Integral = Integral + 4 * sin(t*t);
	}
	Integral = Integral + sin(b*b);
	Integral = Integral*step;
	return Integral;
}


bool IsDataValid(double a, double b, double eps, int n)
{
	while ((a<b) && (n>0) && (eps > 0) && (eps < 1))
	{
		return true;
	}
	cout << "Error! Enter enother" << endl;
	return false;
}
