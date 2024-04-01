// matala_1_15.8.22.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Header.h"

int main() 
{
    int x = 5;
    int y = 2;
    float z = 1.5;
    int rows = 3;
    int cols = 2;
    double w = 0.0123456789;
    


    std::cout << "******************************\n" << "Question 1:" << std::endl;
    /*pow when a is int:*/
    std::cout << "result: " << pow(x, y) << std::endl;
    /*pow when a is float:*/
    std::cout << "result2: " << pow(z, y) << std::endl;
    /*pow when a is double:*/
    std::cout << "result3: " << pow(w, y) << std::endl;
    /*pow when a and b aren't entered:*/
    std::cout << "result4: " << pow() << std::endl;


    std::cout << "******************************\n" << "Question 2:" << std::endl;
        int* ptr, size;

    /*using the next two lines I will collect the size of the array from the user*/
    std::cout << "Size: ";
    std::cin >> size;

    /*now i will call the program. inside the program we are going to collect the remaining info*/
    ptr = createAndInput(size);
    std::cout << "Size after update using reference: " << size << "\n and the array elements are: \n";

    /*the next two lines are here to organize the output. it will print the element of the array*/
    for (int i = 0; i < size; i++)
        std::cout << i + 1 << ". element: " << ptr[i] << std::endl;
    /*now we will free the array*/
    delete[] ptr;


    std::cout << "******************************\n" << "Question 3:" << std::endl;
    int** matrix = new int* [rows];
    /*now we will print the matrix element using a loop*/
    matrix = createAndInput2(rows, cols);
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++) {
            std::cout << "value of the element at row number: " << i + 1 << " cols number: " << j+1 << " is: " << matrix[i][j] << std::endl;
        }
    }
    /*now we will print the matrix size: */
    std::cout << "\nmatrix size is:  " << rows << " rows and " << cols << " cols ";
    /*now we will free the matrix:*/
    for (int i = 0; i < rows; i++)
        delete[] matrix[i];
    delete[] matrix;

    return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

