/*
 * hotel_types.h
 *
 *  Created on: May 9, 2022
 *      Author: User
 */

#ifndef HOTEL_TYPES_H_
#define HOTEL_TYPES_H_

#include "Date.h"


typedef enum{

	ROYAL_SUITE,SINGLE_ROOM , DOUBLE_ROOM

}RoomType;

typedef enum{

	CONFERENCE_HALL , MEETING_HALL, WEDDING_HALL

}HallType;


typedef enum{

	CAR , BUS , LIMO

}VehicleType;


typedef enum{

	CASH , CREDIT

}PaymentMethod;

#endif /* HOTEL_TYPES_H_ */
