#include "Calander.h"
#include "MyDate.h"
#include <iostream>
#include <cstring>
using namespace std;
Calander::Calander() {




	_number_of_used_dates = 0;
}



Calander::Calander(const Calander& other) {//copy constructor
	int i = 0;
	while (i < 30) {
		_array[i] = other._array[i];
	}
	_number_of_used_dates = other._number_of_used_dates;
}
/**/
void Calander::setDate(int num, MyDate date) {//set new daet in int
	objectPointer = new MyDate;
	objectPointer->set_date(date.get_day(), date.get_month(), date.get_year(), date.get_comment());
	_array[num] = objectPointer;

}
void Calander::print_calander() {
	int i = 0;
	int count_number_of_null_dates = 0;
	while (i < 30) {
		if ((_array[i]) != nullptr) {//if there is a date saved in by this element of the array
			(*(_array[i])).print();//print it 
		}
		else {
			count_number_of_null_dates = count_number_of_null_dates + 1;//counting number of empty elemnts
		}
		i = i + 1;
	}
	
	if (count_number_of_null_dates == 30) {//if all 30 elements are null

		cout << "empty calander" << endl;
	}
}

void Calander::delete_date(int num) {
	if ((_array[num]) != nullptr) {
		//delete (this->_array[num]);
		delete _array[num];
		_array[num] = NULL;
	}
}
void Calander::deleteAll() {
	int i = 0;
	while (i < 30) {
		delete_date(i);//calling the delete function for each element
		i = i + 1;
	}
}
MyDate Calander::oldest() {
	int i = 0;
	MyDate oldest_date;
	while (i < 29) {
		if ((_array[i]) != nullptr) {
			if ((_array[i + 1]) != nullptr){//if the two elements we are looking at aren't null
				if ((*(_array[i])).isBefore(*(_array[i + 1])) == 1)//check which one is oldest and save it
					oldest_date = *(_array[i]);
				else
					oldest_date = *(_array[i + 1]);
			} 
		}
		i = i + 1;
	}
	return oldest_date;
}

bool Calander::isFree(int num) {
	if ((_array[num-1]) != nullptr) {//array start from 0 in c++
		//delete (this->_array[num]);
		cout << "this place is taken" << endl;
		return false;
	}
	else
		cout << "this place is free" << endl;
		return true;
}

int Calander::firstFree() {
	int i = 0; //initalaizing
	int place=0;
	while (i < 30) {
		if ((_array[i]) == nullptr) {//we ound a free element, now we can return it and finish running this function
			place = i+1;
			i = 100;
			return place;//we are returning the value as if the array start from place 1,  in order to make the first place diffrent from false
			// (otherwise we can just type place=i)
		}
		i = i + 1;
	}
	if (i == 30) {//if array is full we have to return 30
		cout << "array is full" << endl;
		return false;
	}
	
}

bool Calander::Insert(MyDate date) {
	int i = 0; //initalaizing
	while (i < 30) {
		if ((_array[i]) == nullptr) {//we ound a free element, now we can return it and finish running this function
			
			setDate(i, date);
			i = 100;
		}
		i = i + 1;
	}
	if (i==30) {//if array is full we have to return 30
		cout << "array is full" << endl;
		return false;
	}
}

int Calander::datesNum() {
	int i = 0; //initalaizing
	int count = 0;
	while (i < 30) {
		if ((_array[i]) != nullptr) {//we ound a free element, now we can return it and finish running this function
			count = count + 1;
		}
		i = i + 1;
	}
	return count;
}