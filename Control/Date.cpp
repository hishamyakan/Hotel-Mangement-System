/******************************************************************************
 *
 * Module: Date and Time
 *
 * File Name: myDate.cpp
 *
 * Description: Source file for Date and Time modules.
 *
 *******************************************************************************/

#include "Control/Date.h"
#include <QDate>

Date TodayDate = {QDate::currentDate().day(), QDate::currentDate().month(), QDate::currentDate().year()};


bool Date::isAfter(Date otherDate){


	if(this->year > otherDate.year)
		return true;

	else if((this->year == otherDate.year) &&
			(this->month > otherDate.month))
		return true;

	else if((this->year == otherDate.year) &&
			(this->month == otherDate.month) &&
			(this->day >  otherDate.day))
		return true;

	return false;
}

bool Date::isBefore(Date otherDate){

    return !isAfter(otherDate) && !isEqualTo(otherDate);

}

bool Date::isEqualTo(Date d){

    return this->day == d.day &&
            this->month == d.month &&
            this->year ==d.year;

}

bool Time::isAfter(Time otherTime){

	if(this->hours > otherTime.hours)
		return true;

	else if((this->hours == otherTime.hours) &&
			(this->minutes > otherTime.minutes))
		return true;

	else if((this->hours == otherTime.hours) &&
			(this->minutes == otherTime.minutes) &&
			(this->seconds >  otherTime.seconds))
		return true;

	return false;


}

bool Time::isBefore(Time otherTime){


        return !isAfter(otherTime);

}


bool Date::isBetween(Date d1 , Date d2){

    return (this->isAfter(d1)||isEqualTo(d1)) && this->isBefore(d2);

}

bool Time::isBetween(Time t1 , Time t2){

    return this->isAfter(t1) && this->isBefore(t2);

}

string Date::formattedDate(){

	return to_string(day)+"-"+to_string(month)+"-"+to_string(year);

}


string Time::formattedTime(){

	return to_string(hours)+":"+to_string(minutes)+":"+to_string(seconds);

}

int numberOfDaysBetweenTwoDates(Date start, Date end)
{
    QDate sDate = QDate(start.year,start.month,start.day);
    QDate eDate = QDate(end.year,end.month,end.day);
    return sDate.daysTo(eDate);
}
