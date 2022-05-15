/*
 * hr_member.h
 *
 *  Created on: May 15, 2022
 *      Author: User
 */

#ifndef HR_MEMBER_H_
#define HR_MEMBER_H_

#include "employee.h"

class HR_Member : public Employee{

public :

	HR_Member(){}
	HR_Member(string name , string SSN, string department , double salary):Employee(name , SSN, department ,  salary){};

	void saveEmployeeData(vector<EmployeeInfo>);

	vector<EmployeeInfo> getEmployeeData();

};


#endif /* HR_MEMBER_H_ */
