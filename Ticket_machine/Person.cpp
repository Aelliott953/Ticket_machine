#include "Person.h"
#include <string>
#include <iostream>
#include <format>
#include <chrono>

using namespace std;

Person::Person(){
}

void Person::setdiscountReason(string discountreason){
		discountReason = discountreason;
		}   

string Person::statusCheck(){
	if(discountReason == "Veteran"||age<=3)
	{
		return "free";
	}

	if(age > 50 || age < 12 && age>3 || discountReason=="Student"|| discountReason == "Elderly") {
		return "reduced";
	}

	else{
		return "normal";
	}	
}

int Person::calculateAge(){
	const auto now = chrono::system_clock::now();
	string currentYear= format("{:%Y}", now); 
	age = stoi(currentYear) - birthYear;
	return age;
}

// Implementations for the newly declared getters
string Person::getFirstName() {
	return firstName;
}

string Person::getLastName() {
	return lastName;
}

//int Person::displayStatus(int status){
//
//}




	