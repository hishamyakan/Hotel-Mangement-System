/******************************************************************************
 *
 * Module: Guest
 *
 * File Name: guest.cpp
 *
 * Description: Source file for Guest Class.
 *
 *******************************************************************************/

#include "Control/guest.h"
#include <iostream>
/*
 * Description :
 * Guest empty Constructor.
 */
Guest::Guest(){

	this->email = "NONE";

	this->phoneNumber = "NONE";

}

/*
 * Description :
 * Guest parameterized Constructor.
 */
Guest::Guest(string name,
		  string SSN ,
		  string address,
		  string email,
		  string phoneNumber):Person(name,SSN,address){

		this->email = email;

		this-> phoneNumber = phoneNumber;

}

/*
 * Description : Mail Setter.
 */
void Guest::setMail(string email){

	this->email = email;
}


/*
 * Description : Phone number Setter.
 */
void Guest::setPhoneNumber(string number){

	this->phoneNumber = number;
}

/*
 * Description : Mail Getter.
 */
string Guest::getMail(){

	return email;
}

/*
 * Description : Phone number Getter.
 */
string Guest::getPhoneNumber(){
	return phoneNumber;
}

/*
 * Description :
 * Shows the data values of a person on the console.
 */
void Guest::show(){

	Person(getName(),getSSN() , getAddress()).show();

	if(email != "NONE")
		cout<<"Email : "<<email<<endl;

	if(phoneNumber != "NONE")
		cout<<"Phone Number : "<<phoneNumber<<endl;


}
