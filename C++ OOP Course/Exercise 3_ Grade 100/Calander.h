#pragma once
#include <iostream>
#include <cstring>
#include "MyDate.h"
#include <iostream>
#include <cstring>
#include <array>
class Calander
{
private:

	//WORKS
	//MyDate* _array[30];
	//END 
	// 
	MyDate* _array[30];
	MyDate* objectPointer;
	// 
	//MyDate d1, d2, d3, d4, d5, d6, d7, d8, d9, d10, d11, d12, d13, d14, d15, d16, d17, d18, d19, d20, d21, d22, d23, d24, d25, d26, d27, d28, d29, d30;

	//static MyDate* _array[30];
	//std::array<std::unique_ptr<MyDate>, 30> _array;
	//std::array<MyDate *, 30> _array {{nullptr}};
	//td::array<MyDate*, 30> arraycal{nullptr};
	int _number_of_used_dates;

public:
	Calander();
	Calander(const Calander& other);
	void setDate(int num, MyDate date);
	void print_calander();
	void delete_date(int num);
	void deleteAll();
	MyDate oldest();
	bool isFree(int num);
	int firstFree();
	bool Insert(MyDate date);
	int datesNum();
};
