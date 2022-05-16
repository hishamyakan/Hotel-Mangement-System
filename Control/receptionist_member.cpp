/*
 * receptionist.cpp
 *
 *  Created on: May 15, 2022
 *      Author: User
 */


#include "Control/receptionist_member.h"
#include "Control/reservable.h"
#include "Control/reservable_manager.h"
#include <vector>
#include "Control/Date.h"

bool Receptionist_Member::reserveRoom(Room_Reservation res){


    vector<Room*> possible_rooms;

    for(size_t i = 0 ; i < rooms.size() ; i++){

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

            if(!start.isBetween(room_prev_reservations->getStartDate(), room_prev_reservations->getEndDate() )&&

                    !end.isBetween(room_prev_reservations->getStartDate(), room_prev_reservations->getEndDate()) &&

                    (start.isAfter(room_prev_reservations->getEndDate()) ||

                            end.isBefore(room_prev_reservations->getStartDate()))){


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

    current_room_reservations.push_back(res);

    final_ptr->addReservation(&current_room_reservations.back());

    return true;

}

bool Receptionist_Member::reserveHall(Hall_Reservation res){

    vector<Hall*> possible_halls ;

    for(size_t i = 0 ; i < Halls.size() ; i++){

        if(res.type == Halls[i].type){

            possible_halls.push_back(&Halls[i]);

        }

    }

    Hall* final_ptr = NULL;

    bool tenfa3 = true;

    for(auto hall_ptr : possible_halls){

        if(hall_ptr->getReservations().size() == 0){

            final_ptr = hall_ptr;
            break;

        }

        tenfa3 = true;

        for(auto hall_prev_reservation : hall_ptr->getReservations()){


            if(res.getStartDate().isEqualTo(hall_prev_reservation->getStartDate())){

                tenfa3 = false;
                break;
            }

        }

        if(tenfa3){
            final_ptr = hall_ptr;
            break;
        }

    }

    if(NULL == final_ptr){

        return false;

    }

    current_hall_reservations.push_back(res);

    final_ptr->addReservation(&current_hall_reservations.back());

    return true;

}

bool Receptionist_Member::reserveVehicle(Vehicle_Reservation res){

    vector<Vehicle*> possible_vehicles ;

    for(size_t i = 0 ; i < Vehicles.size() ; i++){

        if(res.type == Vehicles[i].type){

            possible_vehicles.push_back(&Vehicles[i]);

        }

    }

    Vehicle* final_ptr = NULL;

    bool tenfa3 = true;

    for(auto vehicle_ptr : possible_vehicles){

        if(vehicle_ptr->getReservations().size() == 0){

            final_ptr = vehicle_ptr;
            break;

        }

        tenfa3 = true;

        for(auto vehicle_prev_reservation : vehicle_ptr->getReservations()){


            if(res.getStartDate().isEqualTo(vehicle_prev_reservation->getStartDate())){

                tenfa3 = false;
                break;
            }

        }

        if(tenfa3 && vehicle_ptr->maintained()){
            final_ptr = vehicle_ptr;
            break;
        }

    }

    if(NULL == final_ptr){

        return false;

    }

    current_vehicle_reservations.push_back(res);

    final_ptr->addReservation(&current_vehicle_reservations.back());

    return true;

}

bool Receptionist_Member::reserveTable(Table_Reservation res){

    static int i = 0 ;

    current_table_reservations.push_back(res);

    Tables[i++%NUMBER_OF_TABLES].addReservation(&current_table_reservations.back());


    return true;



}


long long Receptionist_Member::getPayment(string SSN){

    long long price = 0;

    for(size_t i = 0 ; i < current_room_reservations.size() ; i++){


        if(current_room_reservations[i].getGuest().getSSN() == SSN){


            if(current_room_reservations[i].getStartDate().isBefore(TodayDate)){

                long long value = 0;

                switch(current_room_reservations[i].type){

                case SINGLE_ROOM:
                    value = SINGLE_ROOM_PRICE;
                    break;

                case DOUBLE_ROOM:
                    value = DOUBLE_ROOM_PRICE;
                    break;

                case ROYAL_SUITE:
                    value = ROYAL_SUITE_PRICE;
                    break;

                }
                price += value* numberOfDaysBetweenTwoDates(current_room_reservations[i].getStartDate() ,
                        TodayDate);



            }


        }

    }

    /*Get his Vehicle reservations: */
    for(size_t i = 0 ; i < current_vehicle_reservations.size() ; i++){


        if(current_vehicle_reservations[i].getGuest().getSSN() == SSN){


            if(current_vehicle_reservations[i].getStartDate().isBefore(TodayDate)||
                    current_vehicle_reservations[i].getStartDate().isEqualTo(TodayDate)){

                long long value = 0;

                switch(current_vehicle_reservations[i].type){

                case CAR:
                    value = CAR_PRICE;
                    break;

                case BUS:
                    value = BUS_PRICE;
                    break;

                case LIMO:
                    value = LIMO_PRICE;
                    break;

                }
                price += value;

            }


        }

    }

    /*Get his Hall reservations: */
    for(size_t i = 0 ; i < current_hall_reservations.size() ; i++){


        if(current_hall_reservations[i].getGuest().getSSN() == SSN){


            if(current_hall_reservations[i].getStartDate().isBefore(TodayDate) ||
                    current_hall_reservations[i].getStartDate().isEqualTo(TodayDate)){

                long long value = 0;

                switch(current_hall_reservations[i].type){

                case SMALL:
                    value = SMALL_HALL_PRICE;
                    break;

                case MEDIUM:
                    value = MEDIUM_HALL_PRICE;
                    break;

                case LARGE:
                    value = LARGE_HALL_PRICE;
                    break;

                }
                price += value;

            }


        }

    }

    /*Get his Table reservations: */
    for(size_t i = 0 ; i < current_table_reservations.size() ; i++){


        if(current_table_reservations[i].getGuest().getSSN() == SSN){

            if(current_table_reservations[i].getStartDate().isBefore(TodayDate) ||
                    current_table_reservations[i].getStartDate().isEqualTo(TodayDate)){


                price+= TABLE_PRICE;


            }



        }

    }


    return price;

}

