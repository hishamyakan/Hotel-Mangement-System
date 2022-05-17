/******************************************************************************
 *
 * Module: Date and Time
 *
 * File Name: myDate.h
 *
 * Description: Header file for Date and Time modules.
 *
 *******************************************************************************/

#ifndef DATE_H_
#define DATE_H_

#include <QDate>
#include <string>
using namespace std;

typedef struct Date{

	int day ;
	int month ;
	int year;

	bool isBefore(Date otherDate);

	bool isAfter(Date otherDate);

	bool isBetween(Date d1 , Date d2);

    bool isEqualTo(Date d);

	string formattedDate();
}Date;


typedef struct Time{

	int hours;

	int minutes;

	int seconds;

	bool isBefore(Time otherTime);

	bool isAfter(Time otherTime);

	bool isBetween(Time t1 , Time t2);

	string formattedTime();

}Time;


int numberOfDaysBetweenTwoDates(Date start, Date end);


extern Date TodayDate;

#endif /* DATE_H_ */

