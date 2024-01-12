#include "MyDate.h"
#include "Calander.h"
#include <cstring>
using namespace std;

MyDate::MyDate() //constructor 1: default with no arguments, it set the date to 1.1.2020
{
	_day = 1;
	_month = 1;
	_year = 2020;
}
MyDate::MyDate(int d, int m, int y, std::string c) //constructor 2: takes arguments from user
{
	_day = d;
	_month = m;
	_year = y;
	_comment = c;
	
}



MyDate::MyDate(const MyDate& other)//copy constructor
{
	_day = other._day;
	_month = other._month;
	_year = other._year;
	_comment = other._comment;

}
void MyDate::init() {//initalaizing 
	set_year(2022);
	set_month(9);
	set_day(18);


}

void MyDate::inc() {
	try{//splitting for cases like in the table
	if (_month == 1 || _month == 3 || _month == 5 || _month == 7 || _month == 8 || _month == 10 || _month == 12) {
		if (_day < 31)
			_day = _day+1;
		else {
			throw 3;
		}
	}
	else if (_month == 4 || _month == 6 || _month == 9 || _month == 11) {
		if ( _day< 30)
			_day = _day+1;
		else {
			throw 3;
		}
	}
	else {
		if (_day < 28)
			_day = _day + 1;
		else {
			throw 3;
		}
	}
	}
	catch(int num){
		if (num ==3) {
			_day = 1;
			if (_month ==12) {
				_year = _year + 1;
				_month = 1;
			}
			else {
				_month = 1;
			}
		}
	}
	
}

bool MyDate::isBefore(const MyDate& other)
{
	if (_year < other._year)
		return true;
	else if (_year > other._year)
		return false;
	else // (_year == other._year)
	{
		if (_month < other._month)
			return true;
		else if (_month > other._month)
			return false;
		else // (_month == other._month)
		{
			if (_day < other._day)
				return true;
			else
				return false;
		}
	}
}


int MyDate::get_day() const { //gets the day
	return _day;
}

int MyDate::get_month() const { //gets the month
	return _month;
}
int MyDate::get_year() const { //gets the year
	return _year;
}
std::string MyDate::get_comment() const { //gets the comment
	return _comment; 
}

void MyDate::set_day(int da) { //sets the date
	if (_month == 1 || _month == 3 || _month == 5 || _month == 7 || _month == 8 || _month == 10|| _month == 12){
		if (da > 0 and da < 32)
			_day = da;
		else {
			throw 2;//2:invalid day
		}
	}
	else if (_month == 4 || _month == 6 || _month == 9 || _month == 11) {
		if (da > 0 and da < 31)
			_day = da;
		else{
			throw 2;
		}
	}
	else{
		if (da > 0 and da < 29)
			_day = da;
		else{
			throw 2;
		}
	}
	//main will treat this exeption, i wanted to practice throwing the exeptions to main, however, it proved to be unusefull for the set_date function, so i only did it for the smaller st functions
	//set_date will manage and treat its own exepctions so we can call it several times in main without worring it might end up in the main catch 
}

void MyDate::set_month(int mo)  { 
	if (mo == 1 || mo ==2 || mo == 3 || mo == 4 || mo == 5 || mo == 6 || mo == 7 ||
		mo == 8 || mo == 9 || mo == 10 || mo == 11 || mo == 12)
		_month = mo;
	else{
		throw 1;//1:invalid month
	}
	//main will treat this exeption
}
void MyDate::set_year(int ye)  { //gets the imaginary part
	if (ye < 1){
		throw 0;//0:invalid year
	}
	else{
		_year=ye;
	}
	//main will treat this exeption
}
void MyDate::set_comment(std::string co)  { 
	_comment=co; 
}
void MyDate::changeComment(std::string st) {
	_comment = st;
}
void MyDate::set_date(int day, int month, int year, string comment) { //sets date
	try {
		set_comment(comment);
		set_year(year);
		set_month(month);
		set_day(day);
	}
	catch (int num) {//i made set_date catch and treat its own errors, since this way we can easly call the function without worring we might have an exeption
		
		if (num==0){
			_year = int(1);
			cout<< "invalid year, automaticly updated to 1: ";
		}
		else if (num == 1) {
			_month = int(1);
			cout << "invalid month, automaticly updated to 1: ";
		}
		else if (num == 2) {
			_day = int(1);
			cout << "invalid day, automaticly updated to 1: ";
		}
	}
}
void MyDate::print() {
	/*
	if (sizeof(_comment) == 0) {//print when commet doesnt exist
		cout << get_day() << "/" << get_month() << "/" << get_year() << endl;
	}
	*/
	if (_comment == "unknown") {//print when commet doesnt exist
		cout << get_day()<< "/" << get_month() << "/" << get_year() << endl;
	}
	else { //print date + comment
		cout << get_day() << "/" << get_month() << "/" << get_year() << ' ' << get_comment() << endl;
	}
}



