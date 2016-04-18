#include <iostream>
#include <math.h>

using namespace std;

bool IsDataValid(double, double, double, double);
double Trapezium(double, double, double);
double Simpson(double, double, double);
double TwinRates(double, double, double, double);
double TwinRate(double, double, double, double);

int main()
{
	while (true)
	{
		double a, b, n, eps;
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
			cout << "Component formula of Trapezium: " << TwinRates(a, b, n, eps) << endl;
			cout << "Component formula of Simpson: " << TwinRate(a, b, n, eps) << endl;
			break;
		}
		system("pause");
		system("cls");
	}
	system("pause");
	return 0;
}

double TwinRates(double a, double b, double n, double eps)
{
	double PrIntegral = 0, NextIntegral = 1;
	while (fabs(PrIntegral - NextIntegral) < eps)
	{
		PrIntegral = Trapezium(a, b, n);
		NextIntegral = Trapezium(a, b, 2 * n);
		n = 2 * n;
	}
	double Integral = Trapezium(a, b, n);
	return Integral;
}

double Trapezium(double a, double b, double n)
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

double Simpson(double a, double b, double n)
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
	Integral = Integral*step / 3;
	return Integral;
}

double TwinRate(double a, double b, double n, double eps)
{
	double PrIntegral = 0, NextIntegral = 1;
	while (fabs(PrIntegral - NextIntegral) < eps)
	{
		PrIntegral = Simpson(a, b, n);
		NextIntegral = Simpson(a, b, 2 * n);
		n = 2 * n;
	}
	double Integral = Simpson(a, b, n);
	return Integral;
}

bool IsDataValid(double a, double b, double eps, double n)
{
	while ((a<b) && (n>0) && (eps > 0) && (eps < 1))
	{
		return true;
	}
	cout << "Error! Enter enother" << endl;
	return false;
}

