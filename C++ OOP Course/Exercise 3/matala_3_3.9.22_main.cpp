#include "MyDate.h"
#include "Calander.h"
using namespace std;
int main()
{
	Calander cal1,cal2;
	MyDate oldest_in_cal;
	MyDate date1(4, 9, 2022); //constractor without comment is called here
	MyDate date6(17, 9, 2022, "b-day");
	MyDate date7(18, 9, 2022, "anotherday");
	MyDate date8(20, 9, 2022, "20th of sptember");
	MyDate date9(7, 8, 2022, "date 9");
	
	
	MyDate p1(6, 1, 2004, "my birthday"); // normal constructor is called here
	MyDate p2 = p1; // Copy constructor is called here
	//lets check we got it right:
	cout << "date1: ";
	date1.print();
	cout << "p1: ";
	p1.print();
	cout << "p2: ";
	p2.print();
	//checking init function
	p2.init();
	cout << "p2 after init function update: ";
	p2.print();
	//cheking isBefore function
	cout << "p1.isBefore(p2): "<< p1.isBefore(p2) <<"    ";
	cout << "date1.isBefore(p1): " << date1.isBefore(p1)<<endl;

	
	cout << "************calander check*************"<<endl ;
	cout << "placing datte 6 in cal1 and printing the calander :" << endl;
	cal1.setDate(5, date6); 
	cal1.print_calander();
	cout << "placing date 7 and date 8 in cal2 and printing the calander :" << endl;
	cal2.setDate(5, date7);
	cal2.setDate(7, date8);
	cal2.print_calander();
	cout << "////chcking the oldest function using cal2////" << endl;
	oldest_in_cal = cal2.oldest();
	cout << "oldest date in cal2: ";
	oldest_in_cal.print();
	cout << "////chcking the isFree function////" << endl;
	cal1.isFree(6);//place 6 in 1-30 array -> place 5 in 0-29 array, therefor should be taken in this case
	cal1.isFree(7);//should be empty
	cout << "////chcking the Insert function with cal1////" << endl;
	cal1.Insert(date9);
	cal1.print_calander();
	cout << "////chcking the firstFree function////" << endl;
	cout<<cal1.firstFree()<<endl; //should be 2 since we are workin on a 1-30 array
	cout << "////chcking the isFree function////" << endl;
	cal1.isFree(2) ; //should be free since we are workin on a 1-30 array
	cal1.isFree(1); //should not be free since we are workin on a 1-30 array
	cout << "////chcking the datesNUm function////" << endl;
	cout<<cal1.datesNum()<<endl; //should be 2 in this case
	cout << "////chcking the delete_date function////" << endl;
	cal1.delete_date(5);
	cout << cal1.datesNum() << endl; //should be 2 in this case
	cout << "////chcking the deleteAll function////" << endl;
	cal2.deleteAll();
	cout << cal2.datesNum() << endl; //should be 2 in this case
	cout << "************end of calander check*************" << endl; 


	MyDate date2, date3, date4, date5;
	
	try {
		//int y;
		cout << "*****************************************************" << endl;
		cout << "*****************************************************" << endl;
		cout << "cheking the some more MyDate functions and exceptions" << endl;

		// 
		//regular
		date2.set_date(1,9,2022,"back to school day");
		date2.print();
		//needs catching - invalid day
		date3.set_date(-1, 9, 2022, "a bad back to school day");
		date3.print();
		//regular
		date4.set_date(3, 1, 1592, "pie day");
		date4.print();
		cout << "cheking the set_day set_month and set_year functions" << endl;
		date4.set_day(2); 
		date4.print();
		date4.set_month(2);
		date4.print();
		date4.set_year(2222);
		date4.print();
		//needs catching - invalid month
		date5.set_date(17, 50, 2023, "great day");
		date5.print();
		//set day
		date4.set_day(10);
		date4.print();
		//set month
		date5.set_month(11);
		//set year
		date5.set_month(1999);
		//set day+ catching
		date4.set_day(65);
		date4.print();

		//set_date deals with exeptions on its own, doesnt need to be in try block in the main function
	}
	//catch(const char* word)
	catch (int num) {
		cout << "main catch is activated"<<endl;
		if (num == 0) {
			cout << "invalid year, automaticly updated to 1" << endl;
		}
		else if (num == 1) {
			cout << "invalid month, automaticly updated to 1" << endl;
		}
		else if (num == 2) {
			cout << "invalid day, automaticly updated to 1" << endl;
		}
		date5.set_date(8, 5, 1000, "inside catch1 day");
		date5.print();
		cout << "date 5: ";
		date5.set_date(9, 14, 1000, "inside catch2 day");
		date5.print();

		cout << "date 5 after inc : " ;
		date5.inc();
		date5.print();
		cout << "date 5 after init : ";
		date5.init();
		date5.print();
		cout << "date 5 after change to comment : ";
		date5.changeComment("LAST DAY");
		date5.print();
	}
	
	return 0;
}

