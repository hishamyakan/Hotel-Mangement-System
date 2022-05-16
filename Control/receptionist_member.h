/*
 * receptionist.h
 *
 *  Created on: May 15, 2022
 *      Author: User
 */

#ifndef RECEPTIONIST_MEMBER_H_
#define RECEPTIONIST_MEMBER_H_

#include "Control/employee.h"
#include "Control/reservation.h"
class Receptionist_Member : public Employee{

public:

	Receptionist_Member(){}

	Receptionist_Member(string name , string SSN, string department , double salary):Employee(name , SSN, department ,  salary){};

	bool reserveRoom(Room_Reservation);

	bool reserveHall(Hall_Reservation);

	bool reserveVehicle(Vehicle_Reservation);

	bool reserveTable(Table_Reservation);


};

#endif /* RECEPTIONIST_MEMBER_H_ */
