#include "AccountManager.h"
#include <iostream>
#include <string>
#include <random>
#include <fstream>
#include <sstream>


using namespace std;


AccountManager::AccountManager(Person& person)
    : person(person)
{
}

void AccountManager::createAccount(string firstName, string lastName, int birthYear, string discountReason) { // Creates an account for the person and saves the information in a file named after the card number
	person.firstName = firstName;
	person.lastName = lastName;
	person.birthYear = birthYear;
	person.setdiscountReason(discountReason);
	
	std::random_device seed;
 	std::mt19937 gen{seed()}; // seed the generator
 	std::uniform_int_distribution<> dist{10000, 99999}; // set min and max
  	int rand = dist(gen); // generate number
  	
  	person.cardNumber = birthYear * 1000000 + rand;
  	
  	stringstream ss;
  	
  	// Converting card number to string and adding it to file name
  	ss << person.cardNumber;
  	string cardNumber = ss.str();
  	ofstream MyFile("accounts/" + cardNumber + ".txt");
  	
  	// Converting birth year to string
  	stringstream ll;
  	ll << person.birthYear;
  	string birthYear_string = ll.str();
  	
  	MyFile << "First name: " + person.firstName + "\nLast name: " + person.lastName + "\nBirth year: " + birthYear_string;
  	MyFile.close();
  	
  	cout << "Account successfully created" << endl;		
}

bool AccountManager::fileExists(const std::string& filename) { //Verifies if the file exists
    std::ifstream file(filename);
    return file.good();
}

void AccountManager::verifyAccount(int cardNumber) {  // Verifies if the account exists and if it does, it reads the information from the file and displays it
	try{
		stringstream ss;
  	
  		// Converting card number to string and adding it to file name
  		ss << cardNumber;
  		string card = ss.str();
  		
		string filepath = "accounts/" + card + ".txt";
		
		if(fileExists(filepath)){
			cout << "Account found" << endl;
			cout << card << endl;
			ifstream file(filepath);
            string line;

            while (getline(file, line)) {

                size_t colonPos = line.find(":");

                if (colonPos != string::npos) {

                    string label = line.substr(0, colonPos);
                    string value = line.substr(colonPos + 2); // skip ": "

                    if (label == "First name") {
                    person.firstName = value;
                    }

                    else if (label == "Last name") {
                    person.lastName = value;
                    }

                    else if (label == "Birth year"){ 
                        person.birthYear = stoi(value);
                    }
                        
                }
            }

            file.close();
			string firstName = person.firstName;
			string lastName = person.lastName;
			int birthYear = person.birthYear;
			cout << "First name: " + firstName + "\nLast name: " + lastName + "\nBirth year: " + to_string(birthYear) << endl;
		}
		else{
			throw 505;
		}			
	}
	catch(int errorCode){
		cout << "Error, account not found!" << endl;
	}
}
