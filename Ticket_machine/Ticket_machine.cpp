#include <iostream>
#include "Person.h"
#include "AccountManager.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	Person person;
	AccountManager accountManager(person);
	accountManager.createAccount("Alex", "E", 2005, "Veteran");
	cout << person.cardNumber << endl;
	int status = person.statusCheck();
	cout << status << endl;
	accountManager.verifyAccount(person.cardNumber);
	return 0;
}