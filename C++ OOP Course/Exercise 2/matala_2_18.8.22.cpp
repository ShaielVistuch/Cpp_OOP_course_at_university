// matala_2_18.8.22.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <math.h>
#include <iostream>
using namespace std;

#include "Complex.h"

int main()
{
    //Defining some starter numbers
    Complex x(1, -1);
    Complex y(6, -7);
    cout << "x: ";
    x.print();
    cout << "y: ";
    y.print();
    //TESTING the constructors and the print function
    Complex z; //the default constructor will give z a 0 _imaginary and 0 _real
    Complex w(2); //the second constructor would give w values of (2,0)
    Complex k(2, 0); //third constructor
    Complex m(0, 2); //third constructor
    cout << "z: " ;
    z.print(); //because z has _real,_imaginary=0, print function will print 0(0,0)
    cout << "w: ";
    w.print(); //expected to print using 1st option: 2(2,0)
    cout << "k: ";
    k.print(); //expected to print using 1st option: 2(2,0)
    cout << "m: ";
    m.print(); //expected to print using 2nd option: 2i(2,90)

    //This is what printing without the "print" function look like:
    //cout << z.get_real() << '+' << z.get_imaginary() << 'i' << endl;
    //of course, this isn't a good idea to print this way, since if z.get_imaginary returns a negetive value, the printing would look weird with a +- sign



    //TESTING THE "add" FUNCTION
    Complex sum_of_x_and_z;
    sum_of_x_and_z= z.add(x); //z is equal to 0. therefor we should expect that after runing this line, z will equal to x
    //let's print it to see if it works properly:
    cout << "sum_of_x_and_z: ";
    sum_of_x_and_z.print();
    //lets see that the add function works for two numbers that are both not 0
    Complex sum_of_y_and_x;
    sum_of_y_and_x = y.add(x);
    cout << "sum_of_y_and_x: ";
    sum_of_y_and_x.print();
    //notice that, like told in the moodle instructions, the "add" function doesn't change the values of the added values
    cout << "print y: " << endl;
    y.print();
    cout << "print x: " << endl;
    x.print();



    /*
    CHECKING THE "set" FUNCTION
    to make sure that one can only change both the imaginary and real part togheter, we can type:
    cout << "set only real part of x to 3: "  << endl;
    y.set_real(3);
    y.print();
    and indeed we get an error, that set_real can not be used here
    */
    //on the other hand, changing both the real part and imaginary part is allowed and works: 
    y.set(3,4);
    cout << "y after re-setting it is: " << x.absolute_value() << endl;
    y.print();


    //checking the absolute value and phase functions
    //As instructed, we should be able to call those function from this main loop (unlike the set_real and set_imaginary functions)
    cout << "absolute value of x: " << x.absolute_value() << endl;
    cout << "phase of x: " << x.phase() << endl;
    cout << "absolute value of y: " << y.absolute_value() << endl;
    cout << "phase of y: " << y.phase() << endl;
    
    //checking the get functions
    //we should be able to accesse each part of the complex number individualy
    cout << "real part of y: " << y.get_real() << endl;
    cout << "imaginary part of y: " << y.get_imaginary() << endl;

    //TESTING THE "sub" FUNCTION
    Complex a(5, -3);
    Complex b(1, -4);
    Complex e(7, 0);
    Complex a_minus_b;
    Complex a_minus_e;
    a_minus_b = a.sub(b);
    a_minus_e = a.sub(e);
    cout << "a-b is equal to: ";
    a_minus_b.print();
    cout << "a-e is equal to: ";
    a_minus_e.print();
    
    return 0;

}

