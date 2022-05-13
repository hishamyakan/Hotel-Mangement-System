/******************************************************************************
 *
 * Module: Employee
 *
 * File Name: Employee.cpp
 *
 * Description: Source file for Employee Class.
 *
 *******************************************************************************/
#include "employee.h"
#include <iostream>
using namespace std;

Employee::Employee(){
	department = "NONE";
	salary = 0 ;
}

Employee::Employee(string name , string SSN, string department , double salary):Person(name,SSN){

	this->department = department;

	this->salary = salary;

}

void Employee::setDepartment(string department){
	this->department = department;
}

void Employee::setSalary(double salary){
	this->salary = salary;
}

void Employee::setMail(string mail){
	this->email = mail;
}

void Employee::setPassword(string password){
	this->password = password;
}

string Employee::getDepartment(){
	return department;
}

double Employee::getSalary(){
	return salary;
}

string Employee::getMail(){
	return email;
}

string Employee::getPassword(){
	return password;
}

bool Employee::verifyPassword(string password){
	return this->password == password;
}

EmployeeInfo Employee::getInfo(){

	EmployeeInfo temp = {getName() , getSSN() , department ,salary};
	return temp;

}

void Employee::show(){

	Person p(getName() , getSSN());
	p.show();
	cout<<"Department : "<<department<<endl;
	cout<<"Salary : "<<salary<<endl;

}

