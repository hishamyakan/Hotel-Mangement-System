/*
 * maintenance.cpp
 *
 *  Created on: May 15, 2022
 *      Author: User
 */

#include "Control/reservable_manager.h"
#include "Control/maintenance.h"

void Maintenance_Member::setRoomsAvailability(vector<string> status){

	setRoomsStatus(status);


}

void Maintenance_Member::setVehiclesAvailability(vector<string> status){

	setVehiclesStatus(status);

}
