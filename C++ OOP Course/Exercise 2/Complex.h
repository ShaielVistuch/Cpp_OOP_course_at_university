#pragma once
#include <iostream>

#include <math.h>
class Complex
{
	private:
		/*we can accese private info from function related to the class, but not from everyplace, 
		(for examples: the main function or functions that arent defined and related to the class*/
		int _real;
		int _imaginary;
		void set_real(int r);
		void set_imaginary(int i);
	public:
		/*we can access from everywhere*/
		Complex() //constructor 1: default with no arguments, it set _real and _imaginary to 0
		{
			_real = 0;
			_imaginary = 0;
		}
		Complex(int r) //constructor 2: real number, it set _imaginary to 0
		{
			_real = r;
			_imaginary = 0;
		}
		Complex(int r, int c) //constructor 3: complex number
		{
			_real = r;
			_imaginary= c;
		}
		
		//void add(int AnotherReal, int AnotherComp);
		/*Complex();
		Complex(int realpart);
		*/
		Complex set(int realpart, int imaginarypart);
		
		Complex add(const Complex& c);
		Complex sub(const Complex& c);
		/*
		void set_real(int r);
		void set_imaginary(int i);
		*/
		int get_real() const;
		int get_imaginary() const;
		void print();
		double absolute_value();
		double phase();
};

