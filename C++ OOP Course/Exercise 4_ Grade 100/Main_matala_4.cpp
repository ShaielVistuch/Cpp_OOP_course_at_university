#include "MyMatrix.h"

int main() {

	//*********************************************************************************
	cout << "---------------------------------------------" << endl;
	cout << "| Constructors and cout operator (<<) test: |" << endl;
	cout << "---------------------------------------------" << endl << endl;


	cout << "Deafult constructor check:" << endl;
	MyMatrix mat1;
	cout << "mat1 is: " << endl;
	cout << mat1 << endl;


	cout << "Copy constructor check:" << endl;
	cout << "copying mat1 to a new matrix mat 2" << endl;
	MyMatrix mat2 = mat1;
	cout << "mat2 is: " << endl;
	cout << mat2 << endl;

	try {
		cout << "User defined constructor check:" << endl;
		MyMatrix mat3(2, 3);
		cout << "mat3 is: " << endl;
		cout << mat3 << endl;

	}
	catch (int num) {
		handler(num);
	}

	try {
		cout << "User defined constructor check:" << endl;
		MyMatrix mat3(2, -3); //error
		cout << "mat3 is: " << endl;
		cout << mat3 << endl;

	}
	catch (int num) {
		handler(num);
	}


	cout << "\n\n\nOOOOOOOOOOOOOOOOOO" << endl;
	cout << "| Cin test (>>): |" << endl;
	cout << "OOOOOOOOOOOOOOOOOO" << endl;
	MyMatrix mat4;
	try {
		//during running we will define mat4 to cause an exception and see that the code works
		cin >> mat4;
		cout << endl;
		cout << "mat4 is: " << endl;
		cout << mat4 << endl;
	}
	catch (int num) {
		handler(num);
	}

	try {
		//define a valid matrix
		cin >> mat4;
		cout << endl;
		cout << "mat4 is: " << endl;
		cout << mat4 << endl;
	}
	catch (int num) {
		handler(num);
	}



	cout << "\n\n\n*************************************" << endl;
	cout << "| Multipication by scalar test (*): |" << endl;
	cout << "*************************************" << endl;
	try {
		cout << "Multiplying mat4 by 3 gives: " << "\n" << mat4 * 3 << endl;
	}
	catch (int num) {
		cout << endl;
		handler(num);
	}

	try {
		//unless mat5 is a square matrix, this would cause an exepction
		cout << "Multiplying mat4 by 1 gives: " << "\n" << mat4 * 1 << endl;
	}
	catch (int num) {
		cout << endl;
		handler(num);
	}

	try {
		//unless mat5 is a square matrix, this would cause an exepction
		cout << "Multiplying mat4 by 0 gives: " << "\n" << mat4 * 0 << endl;
	}
	catch (int num) {
		cout << endl;
		handler(num);
	}





	cout << "\n\n\n-----------------------------" << endl;
	cout << "| Checking the == operator: |" << endl;
	cout << "-----------------------------" << endl;
	cout << "NOTE: 0 means false, 1 means true" << endl;
	MyMatrix mat11, mat22, mat33;
	try {
		cout << "mat 11 is:" << "\n" << mat11 << endl;
		cout << "please enter elements for mat22: " << endl;
		cin >> mat22;
		cout << "are mat22 and mat11 the same? " << (mat11 == mat22) << endl;

	}
	catch (int num) {
		cout << endl;
		handler(num);
	}

	try {
		//pick so that mat22=mat33
		cout << "please enter elements for mat33: " << endl;
		cin >> mat33;
		cout << "are mat22 and mat33 the same? " << (mat33 == mat22) << endl;
	}
	catch (int num) {
		cout << endl;
		handler(num);
	}

	cout << "\n\n\nXXXXXXXXXXXXXXXXXXXXXXX" << endl;
	cout << "| Checking the = operator: |" << endl;
	cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;

	cout << "let's check if mat22=mat22 gives the rigth result:" << endl;
	mat22 = mat22;
	cout << "mat22 after the operation is:" << '\n' << mat22 << endl;

	cout << "Remember that mat11 is:" << '\n' << mat11 << endl;
	MyMatrix mat44;
	try {
		cout <<"define mat44:" << endl;
		cin >> mat44;
		cout << "mat44 is" << endl;
	}
	catch(int num){
		cout << endl;
		handler(num);
	}
	cout << "let's check if mat44=mat11 gives the righ result:" << endl;
	mat44 = mat11;
	cout << "mat11 after the operation is:" << '\n' << mat11 << endl;
	cout << "mat44 after the operation is:" << '\n' << mat44 << endl;











	cout << "\n\n\n>>>>>>>>>>>>>>>>>" << endl;
	cout << "| Sum test (+): |" << endl;
	cout << ">>>>>>>>>>>>>>>>>" << endl;

	MyMatrix mat5;
	try {
		cin >> mat5;
		cout << endl;
		cout << "mat5 is: " << endl;
		//at5 not a square;
		cout << mat5 << endl;
		cout << "The sum of mat4 and mat5 is: " << "\n" << mat4 + mat5 << endl;
	}
	catch (int num) {
		cout << endl;
		handler(num);
	}
 




	cout << "\n\n\n-------------------------" << endl;
	cout << "| Subtruction test (-): |" << endl;
	cout << "-------------------------" << endl;
	cout << "we will use cin to define to matrices mat6 and mat7, and subtruct mat5 from mat6 and mat6 from mat7." << endl;
	MyMatrix mat6,mat7;
	try {
		//define mat6 to cause an error when mat6-mat5
		cin >> mat6;
		cout << endl;
		cout << "mat6 is: " << endl;
		cout << mat6 << endl;
		cout << "Subtructing mat5 from mat6 gives: " << "\n" << mat6 - mat5 << endl;
	}
	catch (int num) {
		cout << endl;
		handler(num);
	}

	try {
		//define mat7 so that mat7-mat6 is valid
		cin >> mat7;
		cout << endl;
		cout << "mat7 is: " << endl;
		cout << mat7 << endl;
		cout << "Subtructing mat6 from mat7 gives: " << "\n" << mat7 - mat6 << endl;
	}
	catch (int num) {
		cout << endl;
		handler(num);
	}



	cout << "\n\n\n*******************************************" << endl;
	cout << "| Multipication of two matrices test (*): |" << endl;
	cout << "*******************************************" << endl;
	cout << "we will use cin to define mat8, then multiply mat8 by mat5 and multiply mat5 by itself." << endl;
	MyMatrix mat8;
	try {
		cin >> mat8;
		cout << endl;
		cout << "mat8 is: " << endl;
		cout << mat8 << endl;
		cout << "Multiplying mat5 by mat8 gives: " << "\n" << mat5*mat8 << endl;
	}
	catch (int num) {
		cout << endl;
		handler(num);
	}

	try {
		//unless mat5 is a square matrix, this would cause an exepction
		cout << "Multiplying mat5 by itself gives: " << "\n" << mat5*mat5 << endl;
	}
	catch (int num) {
		cout << endl;
		handler(num);
	}

	cout << "\n\n\n------------------------------" << endl;
	cout << "| Casting operator check (): |" << endl;
	cout << "------------------------------" << endl;

	MyMatrix mat111;
	try {
		cin >> mat111;
		cout << endl;
		cout << "mat111 is: " << endl;
		double sum = (double)mat111;
		cout << "The sum of the elements of mat111 are: " << "\n" << sum << endl;
	}
	catch (int num) {
		cout << endl;
		handler(num);
	}

}

