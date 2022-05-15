/******************************************************************************
 *
 * Module: Person
 *
 * File Name: person.cpp
 *
 * Description: Source file for Person Interface.
 *
 *******************************************************************************/

#include "person.h"
#include <iostream>

/*
 * Description :
 * Person Empty Constructor.
 */
Person::Person(){

	this->SSN = "NONE";
	this->address = "NONE";
	this->name = "NONE";
}

/*
 * Description :
 * Person parameterized Constructor.
 */
Person::Person(string name, string SSN , string address){

	this->name = name;

	this->SSN = SSN;

	this->address = address;

}

/*
 * Description : Name Setter.
 */
void Person::setName(string name){

	this->name = name;
}

/*
 * Description :SSN Setter.
 */
void Person::setSSN(string SSN){
	this->SSN = SSN;
}

/*
 * Description : Address Setter.
 */
void Person::setAddress(string address){
	this->address = address;
}

/*
 * Description : Name Getter.
 */
string Person::getName(){
	return name;
}

/*
 * Description :SSN Getter.
 */
string Person::getSSN(){
	return SSN;
}

/*
 * Description : Address Getter.
 */
string Person::getAddress(){
	return address;
}


/*
 * Description :
 * Shows the data values of a person on the console.
 */
void Person::show(){

	cout<<"Name : "<<name<<endl;

	cout<<"SSN : "<<SSN<<endl;

	if(address != "NONE")
		cout<<"Address : "<<address<<endl;


}
