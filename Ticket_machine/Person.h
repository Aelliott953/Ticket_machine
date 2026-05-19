#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>

using namespace std;

class Person {
	private:	
		string firstName{""};
		string lastName{""};
		int birthYear{ 0 };
	public:
		string discountReason = "none";
		int cardNumber{ 0 };
		int age{ 0 };
		Person();	
		void setdiscountReason(string discountreason);
		string getdiscountReason();
		string statusCheck();
		int calculateAge();

		// Accessors for first and last name so external code can read private fields
		string getFirstName();
		string getLastName();

		friend class AccountManager;
};


#endif