/*
 * hotel_types.h
 *
 *  Created on: May 9, 2022
 *      Author: User
 */

#ifndef HOTEL_TYPES_H_
#define HOTEL_TYPES_H_

#include "Control/Date.h"


typedef enum{

	ROYAL_SUITE,SINGLE_ROOM , DOUBLE_ROOM

}RoomType;

typedef enum{

	SMALL, MEDIUM , LARGE

}HallType;


typedef enum{

	CAR , BUS , LIMO

}VehicleType;


typedef enum{

	CASH , CREDIT

}PaymentMethod;


typedef struct{

	int number;

	string type;

	string status;

}ReservableInfo;

typedef struct{

    Date reservationDate;

    string type;

    void* reservation_ptr;

}Guest_ReservationsInfo;


#endif /* HOTEL_TYPES_H_ */
