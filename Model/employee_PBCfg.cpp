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

vector<Employee> Receptionists = {

		Receptionist("Ahmed Ali",      "674-36-1364" , "Reception" , 2000),
		Receptionist("Ahmed Assem",    "429-05-7643" , "Reception" , 2000),
		Receptionist("Farah Dessouki", "485-01-9435" , "Reception" , 2200),
		Receptionist("Mohamed Rokay",  "008-26-6314" , "Reception" , 2200),
		Receptionist("Hazem Mostafa",  "102-93-9099" , "Reception" , 2300)

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

		HouseKeeper("Bassem Khaled", "234-02-5643" , "House Keeping" , 2000),
		HouseKeeper("Abdo Moota","435-01-5611" , "House Keeping" , 2000),
		HouseKeeper("Bahgat Saber",   "576-01-1244" , "House Keeping" , 2200)

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
