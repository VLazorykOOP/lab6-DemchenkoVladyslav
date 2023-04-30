#include "Lab6Example.h"
#include <iostream>
#include <string>
#include <time.h>
using namespace std;
namespace SpaceExample2 {
	class Num
	{
	public:
		virtual double norma() = 0;
	};
	class Complex :Num {
	public:
		double a;
		double b;
		Complex()
		{
			a = 0;
			b = 0;
		}
		Complex(double n1, double n2)
		{
			a = n1;
			b = n2;
		}
		virtual double norma()override
		{
			return a * a + b * b;
		}
	};
	class Vector : Num {
	public:
		double* v;
		Vector()
		{
			v = new double[10] {0};
		}
		Vector(double n)
		{
			v = new double[10] {n};
		}
		virtual double norma()override
		{
			double sum = 0;
			for (int i = 0; i < 10; i++)
			{
				sum += (v[i] * v[i]);
			}
			return sqrt(sum);
		}
	};
	class Matrix : Num {
	public:
		double** v;
		Matrix()
		{
			v = new double* [2];
			v[0] = new double[2] {0};
			v[1] = new double[2] {0};
		}
		Matrix(double a, double b, double c, double d)
		{
			v = new double* [2];
			v[0] = new double[2] {a, b};
			v[1] = new double[2] {c, d};
		}
		virtual double norma() override
		{
			return v[0][0] * v[1][1] - v[0][1] * v[1][0];

		}
	};
	int mainExample2()
	{
		cout << "Complex 2 - 3i" << endl;
		cout << "Norma is:" << endl;
		Complex c = Complex(2, -3);
		cout << c.norma() << endl;
		cout << "Vector with 10 2" << endl;
		Vector v = Vector(2);
		cout << "Norma is:" << endl;
		cout << v.norma() << endl;
		cout << "Matrix" << endl;
		cout << "1 2" << endl;
		cout << "3 4" << endl;
		Matrix m = Matrix(1,2,3,4);
		cout << "Norma is:" << endl;
		cout << m.norma() << endl;
		return 0;
	}
}