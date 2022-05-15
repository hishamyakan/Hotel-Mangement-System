/******************************************************************************
 *
 * Module: Employee
 *
 * File Name: Employee_PBCfg.cpp
 *
 * Description: Source file for Employee Configuration.
 *
 *******************************************************************************/
#include <vector>

#include "Control/employee.h"
#include "Control/hr_member.h"
#include "Control/maintenance.h"

vector<Employee> Receptionists = {

		Receptionist_Member("Ahmed Ali",      "674-36-1364" , "Receptionist" , 2000),
		Receptionist_Member("Ahmed Assem",    "429-05-7643" , "Receptionist" , 2000),
		Receptionist_Member("Farah Dessouki", "485-01-9435" , "Receptionist" , 2200),
		Receptionist_Member("Mohamed Rokay",  "008-26-6314" , "Receptionist" , 2200),
		Receptionist_Member("Hazem Mostafa",  "102-93-9099" , "Receptionist" , 2300)

};

vector<Employee> HRs = {

		HR_Member("Mohamed Gameel", "579-00-9485" , "HR" , 2000),
		HR_Member("Ranim Hosny",    "426-17-7214" , "HR" , 2000),
		HR_Member("Hadeel Afifi",   "516-03-2420" , "HR" , 2200),
		HR_Member("Ayman Abbas ",  "498-86-4833" , "HR" , 2200),

};

vector<Employee> Maintenance_Members= {

		Maintenance_Member("Asser Ali", "435-07-5070" , "Maintenance" , 2000),
		Maintenance_Member("Mustafa Nasser","469-64-1977" , "Maintenance" , 2000),
		Maintenance_Member("Ayman Yehia",   "502-78-2692" , "Maintenance" , 2200),


};

vector<Employee> HouseKeepers = {

		HouseKeeper("Bassem Khaled", "234-02-5643" , "HouseKeeping" , 2000),
		HouseKeeper("Abdo Moota","435-01-5611" , "HouseKeeping" , 2000),
		HouseKeeper("Bahgat Saber",   "576-01-1244" , "HouseKeeping" , 2200)

};

vector<Employee> Others = {


};

vector<vector<Employee>> EmployeeDatabase = {
		Receptionists ,
		HRs,
		Maintenance_Members,
		HouseKeepers,
		Others
};
