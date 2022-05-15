/*
 * maintenance.h
 *
 *  Created on: May 15, 2022
 *      Author: User
 */

#ifndef MAINTENANCE_H_
#define MAINTENANCE_H_

#include "Control/employee.h"


class Maintenance_Member : public Employee{

public:
    Maintenance_Member(){};
	Maintenance_Member(string name , string SSN, string department , double salary):Employee(name , SSN, department ,  salary){};

	void setRoomsAvailability(vector<string>);

	void setVehiclesAvailability(vector<string>);

};



#endif /* MAINTENANCE_H_ */
