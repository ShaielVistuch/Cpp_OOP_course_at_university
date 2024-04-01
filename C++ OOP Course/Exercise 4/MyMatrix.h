#pragma once
#include <fstream>
#include <iostream>
using namespace std;
void handler(int e);
class MyMatrix
{
private:
	double** _mat; // pointer to a dynamic 2D array (this is actually a pointer to a pointer to double)
	int _n; // column number
	int _m; // row number

	//set
	void set_element(int i, int j, double temp); //this function helps implement the cin function


public:
	MyMatrix(); //Default Constructor
	MyMatrix(const MyMatrix& other); //copy constractor
	MyMatrix(int m, int n);//Constructor
	
	//getters
	int get_row_number_m() const;
	int get_column_number_n() const;
	
	//operators
	double* operator[] (int row_num) const;
	friend ostream& operator<<(ostream& out, const MyMatrix& other);
	friend istream& operator>>(istream& in, MyMatrix& other);
	MyMatrix operator+(const MyMatrix& other) const; //adds two matrices
	MyMatrix operator-(const MyMatrix& other) const; //subtructs two matrices
	MyMatrix operator*(const MyMatrix& other) const; //multiplying two matrices
	MyMatrix operator*(double scalar) const; //multiplying by scalar
	bool operator==(const MyMatrix& other);
	MyMatrix& operator=(const MyMatrix& other);
	explicit operator double(); //note: we must make the operator explicit so that we will be able to explicitly choose when we want to cast the matrix and when we dont
	//for example: when multiplying a matrix by scalar, we don't wish the matrix would turn to a double
};

