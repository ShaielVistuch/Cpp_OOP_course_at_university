#pragma once
#include <iostream>
#include <cstring>
class MyDate
{
	private:
		/*we can accese private info from function related to the class, but not from everyplace,
		(for examples: the main function or functions that arent defined and related to the class*/
		int _day;
		int _month;
		int _year;
		std::string _comment; 

	public:
		

		int get_day() const;
		int get_month() const;
		int get_year() const;
		//std::string get_comment() const;
		std::string get_comment() const;
		void print();
		void set_day(int da);
		void set_month(int mo);
		void set_comment(std::string co);
		void set_year(int ye);
		void init();
		
		MyDate();
		//MyDate(int d, int m, int y);
		MyDate(int d, int m, int y, std::string c = "unknown");
		MyDate(const MyDate& other);
		bool isBefore(const MyDate& other);
		void set_date(int day, int month, int year, std::string comment);
		void inc();
		void changeComment(std::string st);
};

