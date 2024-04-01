#include <iostream>
#include "Header.h"
using namespace std;
#include <stdio.h>

int pow(int a, int b) {
    /*this program is used when a is an integer
    in order to know that this program was used, we will print that:*/
    std::cout << "Called pow for (int)^b" << endl;
    /*the above line was not a requirement, but I got inspiration for it from the excresise we did in class*/

    int result = a;
    for (int i = 0; i < b; i++)
    {
        result = a * a;
    }
    return result;
}
float pow(float a, int b) {
    /*this program is used when a is a float
    in order to know that this program was used, we will print that:*/
    std::cout << "Called pow for (float)^b" << endl;
    /*the above line was not a requirement, but I got inspiration for it from the excresise we did in class*/

    /*we will use a loop for the calculation*/
    float result = a;
    for (int i = 0; i < b; i++)
    {
        result = a * a;
    }
    return ((float)result);

}

double pow(double a, int b) {
    /*this program is used when a is a float
in order to know that this program was used, we will print that:*/
    std::cout << "Called pow for (double)^b" << endl;
    /*the above line was not a requirement, but I got inspiration for it from the excresise we did in class*/


    /*we will use a loop for the calculation*/
    double result = a;
    for (int i = 0; i < b; i++)
    {
        result = a * a;
    }
    return ((double)result);

}


int* createAndInput(int& size)
{
    std::cout << "Size updated: ";
    std::cin >> size;
    int* ptr = new int[size];

    for (int i = 0; i < size; i++) {
        /*the next line doesnt have any effect on fulfiling the task
        however, this line prints the number of the element (first element, second element of the array) 
        and then prints the text: ".element"
        overall, the next line is responsible for printing #.element 
        where # is the order of the current element we are looking at*/
        std::cout << "enter element number ";
        std::cout << i + 1 << " : ";
        /*the next line gets an input from the user and put it into ptr[i]*/
        std::cin >> ptr[i];
        /*after entering all the elements, the user will type the "enter" button.*/
    }

    return ptr;
}



int** createAndInput2(int& rows, int& cols)
{
    /*now we will get the number of rows and cols from the user*/
    std::cout << "enter the number of rows: ";
    std::cin >> rows;
    std::cout << "enter the number of cols: ";
    std::cin >> cols;
    int** matrix = new int* [rows];
    for (int i = 0; i < rows; i++)
        matrix[i] = new int[cols];
    /*now we weill loop to recive the elements of the matrix from the user*/
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++) {
            std::cout << "enter element number at matrix[" << i + 1 << "][" << j + 1 << "]";
            std::cin >> matrix[i][j];
        }
    }


    return matrix;
}


