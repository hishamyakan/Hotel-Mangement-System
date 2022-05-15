/******************************************************************************
 *
 * Module: Reservation
 *
 * File Name: reservation.h
 *
 * Description: Header file for Reservation Interface and its subclasses.
 *
 *******************************************************************************/

#ifndef RESERVATION_H_
#define RESERVATION_H_

#include "guest.h"
#include "hotel_types.h"
#include <vector>

using namespace std;

/******************************************************************************
 *                        Reservation Class                                   *
 ******************************************************************************/
class Reservation{

private:

	Guest guest;

	vector<GuestInfo> extraGuests;

	PaymentMethod PayMethod;

	Date ReservationDate;

	Date EndDate;

public:

	Reservation(){PayMethod = CREDIT;}

	void setGuest(Guest guest);

	void setExtraGuests(vector<GuestInfo> extraGuests);

	void setPaymentMethod(PaymentMethod PayMethod);

	void setStartDate(Date ReservationDate);

	Guest getGuest();

	vector<GuestInfo> getExtraGuests();

	PaymentMethod getPaymentMethod();

	Date getStartDate();

	void setEndDate(Date EndDate);

	Date getEndDate();
};


/******************************************************************************
 *                      Room Reservation Class                                *
 ******************************************************************************/
class Room_Reservation : public Reservation{

private:


	//int numberOfDays;

public:

	RoomType type;

	Room_Reservation(){
		type = SINGLE_ROOM;
	}

	void setRoomType(RoomType type);

	void setRoomType(string type);

	//void setDuration(int days);

	string getRoomType();

	//int getDuration();



};

/******************************************************************************
 *                     Vehicle Reservation Class                              *
 ******************************************************************************/
class Vehicle_Reservation : public Reservation{

private:



public:

	VehicleType type;

	Vehicle_Reservation(){}

	void setType(VehicleType type);

	void setType(string type);

	string getType();

};

/******************************************************************************
 *                     Hall Reservation Class                                 *
 ******************************************************************************/
class Hall_Reservation : public Reservation{


private:



public:

	HallType type;

	Hall_Reservation(){}

	void setType(HallType type);

	void setType(string type);

	string getType();

};

/******************************************************************************
 *                      Table Reservation Class                               *
 ******************************************************************************/
class Table_Reservation : public Reservation{

private:

	Time ReservationTime;

	int duration;

	Time EndTime;

public:

	Table_Reservation(){}

	void setReservationTime(Time);

	void setDuration(int duration);

	void setEndTime(Time);

	Time getReservationTime();

	Time getEndTime();

	int getDuration();

};

extern vector<Reservation> current_reservations;

extern vector<Reservation> check_outs;
#endif /* RESERVATION_H_ */
