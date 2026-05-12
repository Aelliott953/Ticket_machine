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
		int statusCheck();
		int calculateAge();
		
		friend class AccountManager;
};


#endif