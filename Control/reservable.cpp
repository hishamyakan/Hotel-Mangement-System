/******************************************************************************
 *
 * Module: Reservable
 *
 * File Name: reservable.cpp
 *
 * Description: Source file for Reservable Interface and classes implementing it.
 *
 *******************************************************************************/

#include "reservable.h"


/******************************************************************************
 *                         Reservable Methods                                 *
 ******************************************************************************/

vector<Reservation *> Reservable::getReservations(){

	return this->reservations;

}

void Reservable::addReservation(Reservation * res){

	if(res != NULL)
		this->reservations.push_back(res);

}

/******************************************************************************
 *                            Room Methods                                    *
 ******************************************************************************/

Room::Room(RoomType type){

	static int id_generator[3] = {0,0,0};

	id_generator[type]++;

	this->type = type;

	isMaintained = true;

	switch(type){

	case SINGLE_ROOM:

		this->roomNumber = id_generator[type]+SINGLE_ROOM_OFFSET;
		break;

	case DOUBLE_ROOM:

		this->roomNumber = id_generator[type]+DOUBLE_ROOM_OFFSET;
		break;

	case ROYAL_SUITE:

		this->roomNumber = id_generator[type]+ROYAL_SUITE_OFFSET;
		break;


	}


}

void Room::modifyState(string state){

	if(state == "Available"){

		this->isMaintained = true;

	}

	else this->isMaintained = false;

}



/******************************************************************************
 *                            Hall Methods                                    *
 ******************************************************************************/
Hall::Hall(HallType type){

	static int id = 0;

	this->type = type;

	HallNumber = ++id;
}



/******************************************************************************
 *                           Vehicle Methods                                  *
 ******************************************************************************/

Vehicle::Vehicle(VehicleType type){

	static int id_generator[3] = {0,0,0};

	id_generator[type]++;

	this->type = type;

	isMaintained = true;

	switch(type){

	case CAR:

		this->vehicleNumber = id_generator[type]+CAR_OFFSET;
		break;

	case BUS:

		this->vehicleNumber = id_generator[type]+BUS_OFFSET;
		break;

	case LIMO:

		this->vehicleNumber = id_generator[type]+LIMO_OFFSET;
		break;


	}



}

void Vehicle::modifyState(string state){

	if(state == "Available"){

		this->isMaintained = true;

	}

	else this->isMaintained = false;

}



/******************************************************************************
 *                            Table Methods                                   *
 ******************************************************************************/
Table::Table(){

	static int id = 0 ;

	TableNumber = ++id;

}

