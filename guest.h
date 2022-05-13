/******************************************************************************
 *
 * Module: Guest
 *
 * File Name: guest.h
 *
 * Description: Header file for Guest Class.
 *
 *******************************************************************************/
#ifndef GUEST_H_
#define GUEST_H_

#include "person.h"
#include <vector>


typedef struct{

	string name;
	string ssn;

}GuestInfo;

/******************************************************************************
 *                          Guest Class                                      *
 ******************************************************************************/

class Guest : public Person{

private:

	string phoneNumber;

	string email;

public:

	/*
	 * Description :
	 * Guest empty Constructor.
	 */
	Guest();

	/*
	 * Description :
	 * Guest parameterized Constructor.
	 */
	Guest(string name,
			string SSN ,
			string address,
			string email,
			string phoneNumber);

	/*
	 * Description : Mail Setter.
	 */
	void setMail(string mail);


	/*
	 * Description : Phone number Setter.
	 */
	void setPhoneNumber(string number);

	/*
	 * Description : Mail Getter.
	 */
	string getMail();

	/*
	 * Description : Phone number Getter.
	 */
	string getPhoneNumber();

	/*
	 * Description :
	 * Shows the data values of a person on the console.
	 */
	void show();


};


#endif /* GUEST_H_ */
