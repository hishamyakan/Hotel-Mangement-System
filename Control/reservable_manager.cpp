/*
 * reservable_manager.cpp
 *
 *  Created on: May 15, 2022
 *      Author: User
 */


#include "Control/reservable_manager.h"
#include "Control/reservable.h"
#include <iostream>
using namespace std;

void Reservable_Init(){

	//ReservableDatabase = vector<vector<Reservable>>(10);
	/*
	vector<Reservable> single, Double , Royal;
	vector<Reservable> Small , Medium , Large;
	vector<Reservable>Car,Bus,Limo;
	vector<Reservable> tables;
	 */

	rooms = vector<Room>();
	Halls = vector<Hall>();
	Vehicles = vector<Vehicle>();
	Tables = vector<Table>();

	/*Initializing Rooms*/
	for(int i = 0 ; i < NUMBER_OF_SINGLE_ROOMS ; i++){

		rooms.push_back(Room(SINGLE_ROOM));

	}


	for(int i = 0 ; i < NUMBER_OF_DOUBLE_ROOMS ; i++){

		rooms.push_back(Room(DOUBLE_ROOM));

	}


	for(int i = 0 ; i < NUMBER_OF_ROYAL_SUITES ; i++){

		rooms.push_back(Room(ROYAL_SUITE));

	}

	/*Initializing Halls*/

	for(int i = 0 ; i < NUMBER_OF_SMALL_HALLS ; i++){

		Halls.push_back(Hall(SMALL));

	}




	for(int i = 0 ; i < NUMBER_OF_MEDIUM_HALLS ; i++){

		Halls.push_back(Hall(MEDIUM));

	}




	for(int i = 0 ; i < NUMBER_OF_LARGE_HALLS ; i++){

		Halls.push_back(Hall(LARGE));

	}





	/*Initializing Vehicles*/

	for(int i = 0 ; i < NUMBER_OF_CARS ; i++){

		Vehicles.push_back(Vehicle(CAR));

	}




	for(int i = 0 ; i < NUMBER_OF_LIMOS ; i++){

		Vehicles.push_back(Vehicle(LIMO));

	}



	for(int i = 0 ; i < NUMBER_OF_BUSSES ; i++){

		Vehicles.push_back(Vehicle(BUS));

	}



	/*Initializing Tables*/

	for(int i = 0 ; i < NUMBER_OF_TABLES ; i++){

		Tables.push_back(Table());

	}


}


void printReservables(){

	for(auto room : rooms){
		room.show();
	}

	for(auto Hall : Halls){
		Hall.show();
	}

	for(auto v : Vehicles){
		v.show();
	}

	for(auto table : Tables){
		table.show();
	}
}


vector<int> MaintenanceCounts(){

	vector<int> result(6,0);

	for(auto room : rooms){

		switch(room.type){

		case SINGLE_ROOM:


			result[SINGLE_ROOM_INDEX] += (room.maintained())?1:0 ;

			break;

		case DOUBLE_ROOM:

			result[DOUBLE_ROOM_INDEX] += (room.maintained())?1:0 ;

			break;




		case ROYAL_SUITE:

			result[ROYAL_SUITE_INDEX] += (room.maintained())?1:0 ;

			break;

		}
	}

	for(auto v : Vehicles){
		switch(v.type){

		case CAR:


			result[CAR_INDEX] += (v.maintained())?1:0 ;

			break;

		case LIMO:

			result[LIMO_INDEX] += (v.maintained())?1:0 ;

			break;




		case BUS:

			result[BUS_INDEX] += (v.maintained())?1:0 ;

			break;

		}
	}
	return result;

}


vector<int> AvailabilityCounts(){

	vector<int> result(6,0);

	for(auto room : rooms){

		switch(room.type){

		case SINGLE_ROOM:


			result[SINGLE_ROOM_INDEX] += (room.maintained()&&room.isAvailable())?1:0 ;

			break;

		case DOUBLE_ROOM:

			result[DOUBLE_ROOM_INDEX] += (room.maintained()&&room.isAvailable())?1:0 ;

			break;




		case ROYAL_SUITE:

			result[ROYAL_SUITE_INDEX] += (room.maintained()&&room.isAvailable())?1:0 ;

			break;

		}
	}

	for(auto v : Vehicles){
		switch(v.type){

		case CAR:


			result[CAR_INDEX] += (v.maintained()&&v.isAvailable())?1:0 ;

			break;

		case LIMO:

			result[LIMO_INDEX] += (v.maintained()&&v.isAvailable())?1:0 ;

			break;




		case BUS:

			result[BUS_INDEX] += (v.maintained()&&v.isAvailable())?1:0 ;

			break;

		}
	}
	return result;

}

vector<ReservableInfo> getRooms(){

	vector<ReservableInfo> result;
	for(auto room :rooms){

		ReservableInfo inf;

		inf.number = room.getNumber();

		inf.type = room.getType();

		inf.status = room.maintained()?"Available":"UnAvailable";

		result.push_back(inf);
	}

	return result;
}

vector<ReservableInfo> getVehicles(){

	vector<ReservableInfo> result;

	for(auto vehicle :Vehicles){

		ReservableInfo inf;

		inf.number = vehicle.getNumber();

		inf.type = vehicle.getType();

		inf.status = vehicle.maintained()?"Available":"UnAvailable";

		result.push_back(inf);
	}

	return result;
}



vector<ReservableInfo> getRooms2(){

	vector<ReservableInfo> result;

	for(auto room :rooms){

		ReservableInfo inf;

		inf.number = room.getNumber();

		inf.type = room.getType();

		inf.status = (room.maintained()&&room.isAvailable())?"Available":"UnAvailable";

		result.push_back(inf);
	}

	return result;

}

vector<ReservableInfo> getVehicles2(){

	vector<ReservableInfo> result;

	for(auto vehicle :Vehicles){

		ReservableInfo inf;

		inf.number = vehicle.getNumber();

		inf.type = vehicle.getType();

		inf.status = (vehicle.maintained()&&vehicle.isAvailable())?"Available":"UnAvailable";

		result.push_back(inf);
	}

	return result;

}




void setRoomsStatus(vector<string> status){

	for(size_t i = 0 ; i < rooms.size() ; i++){

		rooms[i].modifyState(status[i]);

	}

}

void setVehiclesStatus(vector<string> status){

	for(size_t i = 0 ; i < Vehicles.size() ; i++){

		Vehicles[i].modifyState(status[i]);

	}

}
