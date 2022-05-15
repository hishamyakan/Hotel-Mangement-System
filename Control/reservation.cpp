/******************************************************************************
 *
 * Module: Reservation
 *
 * File Name: reservation.cpp
 *
 * Description: Source file for Reservation Interface and its subclasses.
 *
 *******************************************************************************/

#include "Control/reservation.h"

/******************************************************************************
 *                        Reservation Methods                                 *
 ******************************************************************************/

void Reservation::setGuest(Guest guest){

	this->guest = guest;

}

void Reservation::setExtraGuests(vector<GuestInfo> extraGuests){

	this->extraGuests = extraGuests;

}

void Reservation::setPaymentMethod(PaymentMethod PayMethod){

	this->PayMethod = PayMethod;

}

void Reservation::setStartDate(Date ReservationDate){

	this->ReservationDate = ReservationDate;

}

Guest Reservation::getGuest(){

	return guest;
}

vector<GuestInfo> Reservation::getExtraGuests(){

	return extraGuests;

}

PaymentMethod Reservation::getPaymentMethod(){

	return PayMethod;

}

Date Reservation::getStartDate(){

	return ReservationDate;

}




/******************************************************************************
 *                   Room Reservation Methods                                 *
 ******************************************************************************/

void Room_Reservation::setRoomType(RoomType type){

	this->type = type;

}

void Room_Reservation::setRoomType(string type){

	if(type == "Single Room"){
		this->type = SINGLE_ROOM;
	}

	else if(type == "Double Room"){
		this->type = DOUBLE_ROOM;
	}
	else if(type == "Royal Suite"){
		this->type = ROYAL_SUITE;
	}
}



void Room_Reservation::setEndDate(Date EndDate){

	this->EndDate = EndDate;

}
/*
void Room_Reservation::setDuration(int days){

	this->numberOfDays = days;

}
 */
string Room_Reservation::getRoomType(){

	switch(type){

	case ROYAL_SUITE:

		return "Royal Suite";

	case SINGLE_ROOM:

		return "Single Room";
	case DOUBLE_ROOM:

		return "Double Room";
	}
	return "Single Room";
}


Date Room_Reservation::getEndDate(){

	return EndDate;

}
/*
int Room_Reservation::getDuration(){

	return this->numberOfDays;
}
 */
/******************************************************************************
 *                     Vehicle Reservation Methods                            *
 ******************************************************************************/

void Vehicle_Reservation::setType(VehicleType type){

	this->type = type;

}
void Vehicle_Reservation::setType(string type){

	if(type == "Car"){
		this->type = CAR;
	}

	else if(type == "Bus"){
		this->type = BUS;
	}

	else if(type == "Limousine Car"){
		this->type  = LIMO;
	}
}

string Vehicle_Reservation::getType(){

	switch(type){

	case CAR:
		return "Car";

	case LIMO:
		return "Limousine Car";

	case BUS:
		return "Bus";


	}
	return "None";

}

/******************************************************************************
 *                     Hall Reservation Methods                               *
 ******************************************************************************/


void Hall_Reservation::setType(HallType type){

	this->type = type;

}

void Hall_Reservation::setType(string type){

	if(type == "Small"){

		this->type = SMALL;

	}
	else if(type == "Large"){
		this->type = LARGE;
	}
	else{
		this->type = MEDIUM;
	}

}

string Hall_Reservation::getType(){

	switch(type){

	case SMALL:

		return "Small";

	case MEDIUM:

		return "Medium";
	case LARGE:

		return "Large";
	}
	return "Medium";
}

/******************************************************************************
 *                       Table Reservation Methods                            *
 ******************************************************************************/

void Table_Reservation::setReservationTime(Time t){

	ReservationTime = t;

}

void Table_Reservation::setDuration(int duration){

	this->duration = duration;

}

void Table_Reservation::setEndTime(Time t){

	EndTime = t;

}

Time Table_Reservation::getReservationTime(){

	return ReservationTime;

}

Time Table_Reservation::getEndTime(){

	return EndTime;

}

int Table_Reservation::getDuration(){

	return duration;
}
