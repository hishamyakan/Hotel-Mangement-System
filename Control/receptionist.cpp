/*
 * receptionist.cpp
 *
 *  Created on: May 15, 2022
 *      Author: User
 */


#include "receptionist.h"
#include "reservable.h"
#include "reservable_manager.h"
#include <vector>

bool Receptionist_Member::reserveRoom(Room_Reservation res){


	vector<Room*> possible_rooms;

	for(int i = 0 ; i < rooms.size() ; i++){

		if(res.type == rooms[i].type){

			possible_rooms.push_back(&rooms[i]);

		}

	}

	Date start = res.getStartDate();
	Date end  = res.getEndDate();

	Room* final_ptr = NULL;

	bool tenfa3 = true;

	for(auto room_ptr : possible_rooms){


		if(room_ptr->getReservations().size() == 0){

			final_ptr = room_ptr;
			break;

		}
		tenfa3 = true;

		for(auto room_prev_reservations : room_ptr->getReservations()){

			if(start.isAfter(room_prev_reservations->getEndDate()) ||

				end.isBefore(room_prev_reservations->getStartDate())){


					/*Do Nothing*/

			}

			else{
				tenfa3 = false;
				break;
			}

		}

		if(tenfa3 && room_ptr->maintained()){
			final_ptr = room_ptr;
			break;
		}


	}

	if(final_ptr == NULL){
		return false;
	}

	current_reservations.push_back(res);

	final_ptr->addReservation(&current_reservations.back());

	return true;

}

bool Receptionist_Member::reserveHall(Hall_Reservation res){

}

bool Receptionist_Member::reserveVehicle(Vehicle_Reservation res){

}

bool Receptionist_Member::reserveTable(Table_Reservation res){

}
