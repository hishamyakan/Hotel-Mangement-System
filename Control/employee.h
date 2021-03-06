/******************************************************************************
 *
 * Module: Employee
 *
 * File Name: employee.h
 *
 * Description: Header file for Employee Class.
 *
 *******************************************************************************/

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#include <string>
#include <vector>
#include "Control/person.h"
using namespace std;


typedef struct EmployeeInfo{

	string name ;

	string SSN ;

	string department;

	double salary;

	EmployeeInfo(string name , string SSN , string department , double salary){

		this->name = name;

		this->SSN = SSN;

		this->department = department;

		this->salary = salary;

	}

}EmployeeInfo;

/******************************************************************************
 *                          Employee Class                                      *
 ******************************************************************************/

class Employee : public Person{

private:

	string department;

	double salary;

	string email;

	string password;



public:

	Employee();

	Employee(string name , string SSN, string department , double salary);

	void setDepartment(string department);

	void setSalary(double salary);

	void setMail(string mail);

	void setPassword(string password);

	string getDepartment();

	double getSalary();

	string getMail();

	string getPassword();

	bool verifyPassword(string password);

	EmployeeInfo getInfo();

	void show();

};




class Manager : public Employee{

public:

	Manager(){}


	void saveEmployeeData(vector<EmployeeInfo>);

	vector<EmployeeInfo> getEmployeeData();

};

class HouseKeeper : public Employee{

public:
	HouseKeeper();
	HouseKeeper(string name , string SSN, string department , double salary):Employee(name , SSN, department ,  salary){};
};



extern vector<vector<Employee>> EmployeeDatabase;


#endif /* EMPLOYEE_H_ */
