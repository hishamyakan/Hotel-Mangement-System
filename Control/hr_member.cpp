/*
 * hr_member.cpp
 *
 *  Created on: May 15, 2022
 *      Author: User
 */

#include "Control/hr_member.h"
#include "Control/employee_manager.h"



void HR_Member::saveEmployeeData(vector<EmployeeInfo> info){

	saveDatabase(info);

}

vector<EmployeeInfo> HR_Member::getEmployeeData(){

	return getEmployees();

}



void Manager::saveEmployeeData(vector<EmployeeInfo> info){

	saveDatabase(info);

}

vector<EmployeeInfo> Manager::getEmployeeData(){

	return getEmployees();

}
