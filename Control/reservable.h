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


#define SINGLE_ROOM_OFFSET 100
#define DOUBLE_ROOM_OFFSET 200
#define ROYAL_SUITE_OFFSET 300


#define CAR_OFFSET  20
#define BUS_OFFSET  30
#define LIMO_OFFSET 40


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

	virtual bool isOccupied() = 0;

	virtual ~Reservable(){}

	vector<Reservation *> getReservations();

	void addReservation(Reservation *);
};



/******************************************************************************
 *                           Room Class                                       *
 ******************************************************************************/
class Room : public Reservable{

private:

	int roomNumber;

	int pricePerDay;

	RoomType type;

	bool isMaintained;

public:

	Room(RoomType type);

	void modifyState(string state);

	bool maintained(){return isMaintained;}
};


/******************************************************************************
 *                           Hall Class                                       *
 ******************************************************************************/

class Hall : public Reservable{

private:

	int HallNumber;

	HallType type;

public:

	Hall(HallType  type);

};



/******************************************************************************
 *                          Vehicle Class                                     *
 ******************************************************************************/
class Vehicle : public Reservable{

private:

	int vehicleNumber;

	VehicleType type;

	bool isMaintained;

public:

	Vehicle(VehicleType type);

	void modifyState(string state);

};



/******************************************************************************
 *                           Table Class                                      *
 ******************************************************************************/

class Table : public Reservable{

	int TableNumber;

public:
	Table();

};

#endif /* RESERVABLE_H_ */
