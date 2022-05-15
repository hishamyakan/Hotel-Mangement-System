/*
 * maintenance.cpp
 *
 *  Created on: May 15, 2022
 *      Author: User
 */

#include "reservable_manager.h"
#include "maintenance.h"

void Maintenance_Member::setRoomsAvailability(vector<string> status){

	setRoomsStatus(status);


}

void Maintenance_Member::setVehiclesAvailability(vector<string> status){

	setVehiclesStatus(status);

}
