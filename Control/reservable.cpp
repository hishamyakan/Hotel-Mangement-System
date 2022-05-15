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
#include "Date.h"
#include <iostream>
using namespace std;

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
		this->pricePerDay = SINGLE_ROOM_PRICE_PER_DAY;

		break;

	case DOUBLE_ROOM:

		this->roomNumber = id_generator[type]+DOUBLE_ROOM_OFFSET;
		this->pricePerDay = DOUBLE_ROOM_PRICE_PER_DAY;
		break;

	case ROYAL_SUITE:

		this->roomNumber = id_generator[type]+ROYAL_SUITE_OFFSET;
		this->pricePerDay = ROYAL_SUITE_PRICE_PER_DAY;
		break;


	}


}

void Room::modifyState(string state){

	if(state == "Available"){

		this->isMaintained = true;

	}

	else this->isMaintained = false;

}

void Room::show(){

	cout<<"Room: "<<this->roomNumber<<endl;
	cout<<"Type: "<<this->type<<endl;
	cout<<endl;

}

string Room::getType(){

	switch(type){

	case SINGLE_ROOM:

		return "Single";

	case DOUBLE_ROOM:

		return "Double";

	case ROYAL_SUITE:

		return "Royal Suite";
	}

	return "Single";

}


bool Room::isAvailable(Date d){

	for(auto ptr : this->getReservations()){

		if(d.isBetween(ptr->getStartDate() , ptr->getEndDate()) )

			return false;

	}

	return true;
}
/******************************************************************************
 *                            Hall Methods                                    *
 ******************************************************************************/
Hall::Hall(HallType type){

	static int id = 0;

	this->type = type;

	HallNumber = ++id;
}

void Hall::show(){

	cout<<"Hall: "<<this->HallNumber<<endl;
	cout<<"Type: "<<this->type<<endl;
	cout<<endl;

}

string Hall::getType(){

	switch(type){

	case SMALL:

		return "Small";

	case MEDIUM:

		return "Medium";

	case LARGE:

		return "Large";
	}

	return "Small";

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



void Vehicle::show(){

	cout<<"Vehicle: "<<this->vehicleNumber<<endl;
	cout<<"Type: "<<this->type<<endl;
	cout<<endl;

}


string Vehicle::getType(){

	switch(type){

	case CAR:

		return "Car";

	case BUS:

		return "Bus";

	case LIMO:

		return "Limousine Car";
	}

	return "Car";

}

bool Vehicle::isAvailable(Date d){

	for(auto ptr : this->getReservations()){

		if(d.isBetween(ptr->getStartDate() , ptr->getEndDate()) )

			return false;

	}

	return true;
}
/******************************************************************************
 *                            Table Methods                                   *
 ******************************************************************************/
Table::Table(){

	static int id = 0 ;

	TableNumber = ++id;

}


void Table::show(){

	cout<<"Table: "<<this->TableNumber<<endl;
	cout<<endl;

}
