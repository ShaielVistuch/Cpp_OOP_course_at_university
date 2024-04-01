#include "MyMatrix.h"
#include <math.h>

MyMatrix::MyMatrix() {
	_m = 3;
	_n = 3;
	_mat = new double* [3]; // _mat is a dynamic array of _m pointers to doubles
	for (int i = 0; i < _m; i++) {
		_mat[i] = new double[3]; // _mat[i] is the pointer in the place i in the array created before the first 'for' loop
		//new double creates a dynamic array of _n doubles and returns the address of the first element in the array of doubles into _mat[i] 
		//so now mat[i] holds the address of the first element in the newly created array of doubles
		for (int j = 0; j < 3; j++) {
			_mat[i][j] = 0;
		}
	}
}
void handler(int num) {
	switch (num) {
	case(0): {
		//trying to create matrix with an invalid number of rows and columns
		cout << "ERROR: The dimensions of the matrix must be positive." << endl;
		break;
	}
	case(1): {
		//creating a matrix with an invalid row number
		cout << "ERROR: the number of rows needs to be positive." << endl;
		break;
	}
	case(2): {
		//creating a matrix with an invalid column number
		cout << "ERROR: the number of columns needs to be positive." << endl;
		break;
	}
	case(3): {
		//trying to add or subtract matrices of different sizes
		cout << "ERROR: the sizes of the matrices need to match in order to add/subtract them." << endl;
		break;
	}
	case(4): {
		//trying to multiply matrices that don't match
		cout << "ERROR: in order to multiply two matrices, the number of columns of the 1st matrix must equal the number of rows of the 2nd matrix." << endl;
		break;
	}
	case(5): { //index out of range
		cout << "ERROR: the requested index Matrix[i][j] is out of range, please pick an element from within the matrix. " << endl;
		break;
	}
	}
	return;
}
MyMatrix::MyMatrix(const MyMatrix& other)
{
	/*
	we want to write a dynamic matrix - a matrix whose size can change. Therefore, we will not write:
	_mat = other._mat;
	_n = other._n;
	_m = other._m;
	but instead use a dynamic matrix, buit using dynaic allocation:
	*/
	_n = other._n;
	_m = other._m;
	_mat = new double* [_m]; 
	for (int i = 0; i < _m; i++) {
		_mat[i] = new double[_n]; // _mat[i] is the pointer in the place i in the array created before the first 'for' loop
		//new double creates a dynamic array of _n doubles and returns the address of the first element in the array of doubles into _mat[i] 
		//so now mat[i] holds the address of the first element in the newly created array of doubles
		for (int j = 0; j < _n; j++) {
			_mat[i][j] = other._mat[i][j];
			//this is where the copying of the other function takes place
		}
	}
}
MyMatrix::MyMatrix(int m, int n)//Constructor
{
	//exceptions: what if m and n are invalid?
	if (m <= 0 && n <= 0) throw int(0); // both sizes are invalid
	if (m <= 0) throw int(1); // number of rows is invalid
	if (n <= 0) throw int(2); // number of columns is invalid

	_n = n;
	_m = m;
	_mat = new double* [_m]; // _mat is a pointer to the first element of a dynamic array of _m pointers to doubles
	for (int i = 0; i < _m; i++) {
		_mat[i] = new double[_n]; // _mat[i] is the pointer in the place i in the array created before the first 'for' loop
		//new double creates a dynamic array of _n doubles and returns the address of the first element in the array of doubles into _mat[i] 
		//so now mat[i] holds the address of the first element in the newly created array of doubles
		for (int j = 0; j < _n; j++) {
			_mat[i][j] = 0;
		}
	}
}

int MyMatrix::get_row_number_m() const {
	return _m;
}
int MyMatrix::get_column_number_n() const {
	return _n;
}

double* MyMatrix::operator[] (int row_num) const{//this operator works on an array of double*. it returns the element at place row_num. that is, is returns a pointer double*
	//so it actualy returns the element at place row_num of _mat
	// 	   let's call array1 the array of double*
	// 
	//  the address of the begining of array1[row number] is assigned to _mat[row_number]
	//so     _mat[row number]=&_array1[row_number] (example: _mat=&_array1[0])
	if (row_num < 0) {
		throw int(1);
	}
	if (row_num >= this->get_row_number_m()) {
		throw (5);
	}
	return _mat[row_num];
}


istream& operator>>(istream& in, MyMatrix& other)
{
	//if the user accdently put the wrong values, we want to allow him to fix it
	//so we use the flag to countinue to ask for the valid values
	//only when valid values where typed, the while loop would end
	try 
		{
			int m;
			int n;
			cout << "Enter number of columns: ";
			in >> n;
			cout << endl << "Enter number of rows: ";
			in >> m;
			other = MyMatrix(m, n); //we can get an exception from running MyMatrix(m,n)

		}
	catch (int num) {
			throw int(num);
		}
	catch (...) { //in case an unhandeled exception was thrown
			cout << "Error Accured" << endl;
		}
	double temp;
	for (int i = 0; i < other.get_row_number_m(); i++) {
		for (int j = 0; j < other.get_column_number_n(); j++) {
			cout << "Please enter the element at row number " << i << " and colomn number " << j << ": ";
			in >> temp;
			other.set_element(i, j, temp);
		}
		
	}
	return in;
}
void MyMatrix::set_element(int i, int j, double temp) {
	//we need to check that:
	//i and j are at least 0 (remember that array uses zero-indexing
	//i and j refers to an index that's in the matrix (for example, a 3 by 2 matrix cant place an element in index i=4,j=5
	//try{
	if (i < 0 && j <= 0) {
		cout << "INDEX INVALID ";
		throw int(0);
	}
	if (i < 0 && j>0) {
		cout << "INDEX INVALID ";
		throw int(1);
	}
	if (j < 0 && i >0) {
		cout << "INDEX INVALID ";
		throw int(2);
	}
	if (!(i < this->get_row_number_m()) || !(this->get_column_number_n())) {
		cout << "INDEX INVALID ";
		throw int(5);
	}
	_mat[i][j] = temp;
	//}

	//catch (int e) {
	//	exceptionHandler(e);
	//}
	
}
ostream& operator<<(ostream& out, const MyMatrix& other) {
	for (int i = 0; i < other.get_row_number_m(); i++) {
		for (int j = 0; j < other.get_column_number_n(); j++) {
			double* temp = other[i]; //user defined operator [] on type MyMatrix
			out << temp[j]; //default [] operator
			cout << "  ";
		}
		cout << endl;
	}
	return out;
}

MyMatrix MyMatrix::operator+(const MyMatrix& other) const {
	//NOTE: how does operator overloading of binary operators (like + and -) work?
	//binary operators work on two variables. lets imagine that comp1 and comp2 are two varibles of class Complex,
	//  in which each object has int _imaginarypart and int realPart. . 
	//lets imagine that we overload the operator + to add to variables of type Complex.
	//then what does comp1+comp2 does?
	//+ is treated as the name of the function. It id the same as typing comp1.function(comp2) 
	//so, inside the mplementation of the operator + for complex classes, 
	//  writing _imgainaryPart or _realPart will give us imaginary or real part of comp1, the variable to the right.
	//in addition, in the CHATIMA of the operator, we will pass comp2 as a const by refrence. (const Complex & other)
	//NOTE: the operator + doesn't change either of the variables, rather, it returns their sum! thats why we put another const on comp1
	if ((_m != other._m) ||( _n != other._n)) {
		throw int(3);
	}

	MyMatrix sum(_m, _n);
	for (int i = 0; i < _m; i++) {
		for (int j = 0; j < _n; j++) {
			//sum._mat[i] - user defined operator [] on type MyMatrix
			// (sum._mat[i])[j] - default [] operator
			sum._mat[i][j] = _mat[i][j] + other._mat[i][j];
		}
	}

	return sum;
}


MyMatrix MyMatrix::operator-(const MyMatrix& other) const {
	if ((_m != other._m) || (_n != other._n)) {
		throw int(3);
	}

	MyMatrix sum(_m, _n);
	for (int i = 0; i < _m; i++) {
		for (int j = 0; j < _n; j++) {
			//sum._mat[i] - user defined operator [] on type MyMatrix
			// (sum._mat[i])[j] - default [] operator
			sum._mat[i][j] = _mat[i][j] - other._mat[i][j];
		}
	}

	return sum;
}

MyMatrix MyMatrix::operator*(const MyMatrix& other) const {
	if (_n != other._m) {
		throw int(4);
	}
	MyMatrix result(_m, other._n);

	for (int i = 0; i < result._m; i++) {
		for (int j = 0; j < result._n; j++) {
			// Calculate sum:
			double sum = 0;
			for (int k = 0; k < _n; k++) {
				sum += _mat[i][k] * other._mat[k][j];
			}
			result._mat[i][j] = sum;
		}
	}
	return result;
}


MyMatrix MyMatrix::operator*(double scalar) const {
	MyMatrix product(_m, _n);//the matrix returned
	for (int i = 0; i < _m; ++i) {
		for (int j = 0; j < _n; j++) {
			product._mat[i][j] = scalar * this->_mat[i][j]; //multiplying each element
		}
	}
	return product;
}

bool MyMatrix::operator==(const MyMatrix& other) {

	bool flag=true;
	if (_m != other._m || _n != other._n) {
		flag = false; //if sizes dont match, of course the matrices aren't equal
	}
	if (flag != false) {
		for (int i = 0; i < _m; i++) {
			for (int j = 0; j < _n; j++) {
				if (!(_mat[i][j] == other._mat[i][j])) {
					flag = false;//if one element doesn't match, the matrices don't match
				}
			}
		}
	}

	return flag;
}

MyMatrix& MyMatrix::operator=(const MyMatrix& other)
{
	if (*this == other) { 
		// if we try to do mat = mat, the calues of mat one would be deleted 
		//(since mat is on the right and when applying operator =, the dynamic allocation would be freed in order to replace it with a new allocation)
		//then, when we try to place the values at the left of the operator =, it would be a problem - since those values were already deleted
		//that's why we must first check, when using the = operator, that the objects on the right and left sides are not the same object.
		//if they are the same, we don't need to do anything but return the object 
		return *this;
	}

	// free dynamically allocated memory
	for (int i = 0; i < _m; i++) {
		delete[] _mat[i];// delete array within matrix
	}
	delete[] _mat; 	// delete actual matrix

	_n = other._n;
	_m = other._m;

	_mat = new double* [_m];
	for (int i = 0; i < _m; i++) {
		_mat[i] = new double[_n];
		for (int j = 0; j < _n; j++) {
			_mat[i][j] = other._mat[i][j];//redefining the matrix
		}

	}

	return *this;
}


MyMatrix::operator double() {//turn object MyMatrix into doubble
	double sum_of_elements = 0;//sum
	for (int i = 0; i < _m; i++) {
		for (int j = 0; j < _n; j++) {
			sum_of_elements = sum_of_elements +_mat[i][j];
		}

	}
	return sum_of_elements;
}