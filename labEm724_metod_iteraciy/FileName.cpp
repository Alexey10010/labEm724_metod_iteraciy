#define _USE_MATH_DEFINES
#include <iostream>
#include <clocale>
#include <cmath>

using namespace std;

const double eps = 0.0001;

double fi(double xin)
{
	double x = log(pow(M_E, -xin) + 2);
	return x;
}

double f(double x)
{
	double y = pow(M_E, x) - pow(M_E, -x) - 2;
	return y;
}

double solve_equation(double(*f)(double), double x0)
{
	return f(x0);
}

int main() 
{
	setlocale(LC_ALL, "Rus");
	double x, x0, delta;
	int n = 0, a = 0, b = 1; //n - счётчик количества итераций
	x0 = b;
	do 
	{
		x = solve_equation(fi, x0); //Получение очередного приближения к корню
		n = n + 1;
		delta = abs(x - x0);
		x0 = x;
		//Вывод промежуточных результатов
		cout << "x" << n << " = " << x << ", f(x" << n << ") = " << solve_equation(f, x)
			 << endl;
	} while (delta > eps);
	cout << "Ответ: x" << n << " = " << x << ", f(x" << n << ") = " << solve_equation(f, x) 
		 << ", eps = " << eps;
	return 0;
}










