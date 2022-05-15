/*
 * employee_manager.cpp
 *
 *  Created on: May 13, 2022
 *      Author: User
 */


#include "Control/employee_manager.h"


static Employee toEmp(EmployeeInfo info){

	return Employee(info.name , info.SSN , info.department , info.salary);

}

static EmployeeInfo toInfo(Employee info){

	EmployeeInfo res = {info.getName() , info.getSSN() , info.getDepartment() , info.getSalary()};

	return res;
}

static int index(string department){

	if(department == "Receptionist"){
		return RECEPTIONIST_INDEX;
	}

	else if(department == "HR"){
		return HR_INDEX;
	}

	else if(department == "Maintenance"){
			return MAINTENANCE_INDEX;
		}

	else if(department == "HouseKeeping"){
			return HOUSEKEEPER_INDEX;
		}

	else{
		return OTHERS_INDEX;
	}

}
static void addEmployee(EmployeeInfo info){

	//Employee emp(info.name , info.SSN , info.department , info.salary);

	EmployeeDatabase[index(info.department)].push_back(toEmp(info));


}

void saveDatabase(vector<EmployeeInfo> info){

	for(size_t i = 0 ; i < EmployeeDatabase.size() ; i++){

		EmployeeDatabase[i].clear();

	}

	for(auto emp : info){

		addEmployee(emp);

	}


}

vector<EmployeeInfo> getEmployees(){

	vector<EmployeeInfo> result;

	//if(department == "All"){


		for(auto record : EmployeeDatabase){
			for(auto emp : record){

				result.push_back(toInfo(emp));

			}
		}

	//}

	/*else{

		vector<Employee> temp =  EmployeeDatabase[index(department)];

		for(auto emp : temp){
			result.push_back(toInfo(emp));
		}

	}
*/
	return result;


}
