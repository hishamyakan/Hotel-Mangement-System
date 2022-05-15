/*
 * employee_manager.h
 *
 *  Created on: May 13, 2022
 *      Author: User
 */

#ifndef EMPLOYEE_MANAGER_H_
#define EMPLOYEE_MANAGER_H_

#include <vector>
#include "employee.h"
using namespace std;


#define RECEPTIONIST_INDEX 			 0
#define HR_INDEX 					 1
#define MAINTENANCE_INDEX 			 2
#define HOUSEKEEPER_INDEX 			 3
#define OTHERS_INDEX 			 	 4

extern vector<vector<Employee>> EmployeeDatabase;

void saveDatabase(vector<EmployeeInfo> info);

vector<EmployeeInfo> getEmployees();
/*void addEmployee(EmployeeInfo info);*/


#endif /* EMPLOYEE_MANAGER_H_ */
