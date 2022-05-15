/*
 * reservable_manager.h
 *
 *  Created on: May 15, 2022
 *      Author: User
 */

#ifndef RESERVABLE_MANAGER_H_
#define RESERVABLE_MANAGER_H_


#include "Control/reservable.h"
#include "Control/hotel_types.h"

#define NUMBER_OF_SINGLE_ROOMS		30
#define NUMBER_OF_DOUBLE_ROOMS		20
#define NUMBER_OF_ROYAL_SUITES		10

#define NUMBER_OF_CARS				10
#define NUMBER_OF_BUSSES			4
#define NUMBER_OF_LIMOS				3


#define NUMBER_OF_TABLES			20

#define NUMBER_OF_SMALL_HALLS		10
#define NUMBER_OF_MEDIUM_HALLS		10
#define NUMBER_OF_LARGE_HALLS		10



#define SINGLE_ROOM_INDEX			0
#define DOUBLE_ROOM_INDEX			1
#define ROYAL_SUITE_INDEX			2

#define	CAR_INDEX					3
#define BUS_INDEX					4
#define LIMO_INDEX					5


#define SMALL_HALL_INDEX			6
#define MEDIUM_HALL_INDEX			7
#define LARGE_HALL_INDEX			8

#define TABLE_INDEX 				9


extern vector<Room> rooms;

extern vector<Hall> Halls;

extern vector<Vehicle> Vehicles;

extern vector<Table> Tables;

void Reservable_Init();

void printReservables();

vector<int> MaintenanceCounts();

vector<int> AvailabilityCounts();

vector<ReservableInfo> getRooms();

vector<ReservableInfo> getVehicles();

void setRoomsStatus(vector<string> status);

void setVehiclesStatus(vector<string> status);


#endif /* RESERVABLE_MANAGER_H_ */
