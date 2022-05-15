/******************************************************************************
 *
 * Module: Reservable
 *
 * File Name: reservable.h
 *
 * Description: Header file for Reservable Interface and classes implementing it.
 *
 *******************************************************************************/

#ifndef RESERVABLE_H_
#define RESERVABLE_H_

#include "reservation.h"
#include "hotel_types.h"

#define SINGLE_ROOM_OFFSET 			100
#define DOUBLE_ROOM_OFFSET 			200
#define ROYAL_SUITE_OFFSET 			300


#define CAR_OFFSET  				20
#define BUS_OFFSET  				30
#define LIMO_OFFSET 				40


#define SINGLE_ROOM_PRICE_PER_DAY 	500
#define DOUBLE_ROOM_PRICE_PER_DAY	600
#define ROYAL_SUITE_PRICE_PER_DAY	700


/******************************************************************************
 *                        Reservable Class                                    *
 ******************************************************************************/
class Reservable{

private:

	vector<Reservation *> reservations;

public:

	Reservable(){}

	//Reservable(){}

	vector<Reservation *> getReservations();

	void addReservation(Reservation *);

	virtual void show(){};

	virtual ~Reservable(){};
};



/******************************************************************************
 *                           Room Class                                       *
 ******************************************************************************/
class Room : public Reservable{

private:

	int roomNumber;

	int pricePerDay;

	bool isMaintained;

public:

	RoomType type;

	Room(RoomType type);

	void modifyState(string state);

	bool maintained(){return isMaintained;}

	string getType();

	int getNumber(){return roomNumber;}

	bool isAvailable(Date date = TodayDate);

	void show();
};


/******************************************************************************
 *                           Hall Class                                       *
 ******************************************************************************/

class Hall : public Reservable{

private:

	int HallNumber;

public:

	HallType type;

	Hall(HallType  type);

	string getType();

	void show();

};



/******************************************************************************
 *                          Vehicle Class                                     *
 ******************************************************************************/
class Vehicle : public Reservable{

private:

	int vehicleNumber;

	bool isMaintained;

public:

	VehicleType type;

	Vehicle(VehicleType type);

	bool maintained(){return isMaintained;}

	void modifyState(string state);

	int getNumber(){return vehicleNumber;}

	bool isAvailable(Date date = TodayDate);

	string getType();

	void show();

};



/******************************************************************************
 *                           Table Class                                      *
 ******************************************************************************/

class Table : public Reservable{

	int TableNumber;

public:
	Table();

	void show();

};

#endif /* RESERVABLE_H_ */
