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
#include "person.h"
using namespace std;


typedef struct {

	string name ;

	string SSN ;

	string department;

	double salary;

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




class Receptionist : public Employee{

public:

	Receptionist();
	Receptionist(string name , string SSN, string department , double salary):Employee(name , SSN, department ,  salary){};
};

class Manager : public Employee{

public:

	Manager();

};

class HouseKeeper : public Employee{

public:
	HouseKeeper();
	HouseKeeper(string name , string SSN, string department , double salary):Employee(name , SSN, department ,  salary){};
};

class HR_Member : public Employee{

public :

	HR_Member();
	HR_Member(string name , string SSN, string department , double salary):Employee(name , SSN, department ,  salary){};
};

class Maintenance_Member : public Employee{

public:
	Maintenance_Member();
	Maintenance_Member(string name , string SSN, string department , double salary):Employee(name , SSN, department ,  salary){};
};


extern vector<vector<Employee>> EmployeeDatabase;


#endif /* EMPLOYEE_H_ */
