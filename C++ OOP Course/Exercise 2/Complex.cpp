#include <iostream>
#include <math.h>
#include "Complex.h"
using namespace std;
#define PI 3.14159265

Complex Complex::set(int realpart, int imaginarypart) { //this funcion allows to change the real and imaginary part of a number togheter
	set_real(realpart);
	set_imaginary(imaginarypart);
	return (get_real(), get_imaginary());
}

void Complex::set_real(int r) { //changes only real part
	_real = r;
}

void Complex::set_imaginary(int i) { //changes only imaginary part
	_imaginary = i;
}

int Complex::get_real() const { //gets the real part
	return _real;
}

int Complex::get_imaginary() const { //gets the imaginary part
	return _imaginary;
}

double Complex::absolute_value() {
	return sqrt( pow(double(get_real()),2) + pow(double(get_imaginary()),2));
}
double Complex::phase() { //returns the absolute value
	return atan2((get_imaginary())  , double(get_real()))*180/PI;
}

Complex Complex::add(const Complex& c)  { //returns the sum of two numbers
	return Complex(get_real() + c.get_real(), get_imaginary() + c.get_imaginary());
}
Complex Complex::sub(const Complex& c) { //subsitute two numbers
	return Complex(get_real() - c.get_real(), get_imaginary() - c.get_imaginary());
}

void Complex::print() {
	
	if (get_imaginary() == 0){//print for real number
		cout << get_real() ;
		cout << "(" << absolute_value() << ',' << phase() << ')' << endl;
	}
	else if (get_real() == 0){ //print for imaginary number
		cout << get_imaginary() << 'i';
		cout << "(" << absolute_value() << ',' << phase() << ')' << endl;
	}
	else if (get_imaginary() < 0){ //print for complex number with a negitive imaginary part
		cout << get_real() << get_imaginary() << 'i' ;
		cout << "(" << absolute_value() << ',' << phase() << ')' << endl;
	}
	else { //else
		cout << get_real() << '+' << get_imaginary() << 'i' ;
		cout << "(" << absolute_value() << ',' << phase() << ')' << endl;
	}
}


