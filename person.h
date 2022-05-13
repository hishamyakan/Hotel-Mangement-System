/******************************************************************************
 *
 * Module: Person
 *
 * File Name: person.h
 *
 * Description: Header file for Person Interface.
 *
 *******************************************************************************/

#ifndef PERSON_H_
#define PERSON_H_

#include <string>
#include <vector>
using namespace std;


/******************************************************************************
 *                          Person Class                                      *
 ******************************************************************************/

class Person{

private:

	string name;

	string SSN;

	string address;

public:

	/*
	 * Description :
	 * Person empty Constructor.
	 */
	Person();

	/*
	 * Description :
	 * Person parameterized Constructor.
	 */
	Person(string name, string SSN , string address = "NONE");

	/*
	 * Description : Name Setter.
	 */
	void setName(string name);

	/*
	 * Description :SSN Setter.
	 */
	void setSSN(string SSN);

	/*
	 * Description : Address Setter.
	 */
	void setAddress(string address);

	/*
	 * Description : Name Getter.
	 */
	string getName();

	/*
	 * Description :SSN Getter.
	 */
	string getSSN();

	/*
	 * Description : Address Getter.
	 */
	string getAddress();

	/*
	 * Description :
	 * Shows the data values of a person on the console.
	 */
	virtual void show();

	/*
	 * Description :
	 * Person Destrcutor.
	 */
	virtual ~Person(){}


};

#endif /* PERSON_H_ */
