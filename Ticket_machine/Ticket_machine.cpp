#include <iostream>
#include <vector>
#include "Ticket.h"
#include "utils.h"
#include "Person.h"
#include "AccountManager.h"

using namespace std;
string qname = "|------------Account Creation Terminal------------|\n"
               "|                 Enter First Name                |\n"
               "|-------------------------------------------------|\n\n";
string qname2 = "|------------Account Creation Terminal------------|\n"
"|                 Enter Last Name                 |\n"
"|-------------------------------------------------|\n\n";
string qyear = "|------------Account Creation Terminal------------|\n"
                "|                 Enter Birth Year                |\n"
                "|-------------------------------------------------|\n\n";
string qdiscount = "|------------Account Creation Terminal------------|\n"
                   "|              Enter Disocunt reason              |\n"
"|-------------------------------------------------|\n\n";
int main() {
    vector<Ticket> tickets;
    int option;
    int card_number;

    while (true) {
        Person person = Person();
        AccountManager accountManager(person);
        cout << "|-------------Ticket Machine Terminal-------------|" << endl;
        cout << "|                 Choose An Option                |" << endl;
        cout << "|          1. scan card (enter card number)       |" << endl;
        cout << "|          2. buy anonymous ticket                |" << endl;
        cout << "|          3. create account                      |" << endl;
        cout << "|-------------------------------------------------|"<<endl;

        if (!(cin >> option)) {
            cout << "Wrong Input - press number next to desired option" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

		switch(option) {
			case 1: {
				cout << "Enter your card number:" << endl;
				cin >> card_number;
				int iscorrect = accountManager.verifyAccount(card_number);
			if (iscorrect == 1) {
				cout << "Account verified" << endl;


                while (true) {
                    
                   
                    
                    person.age = person.calculateAge();
                            tickets.push_back(Ticket(
                                getcurtime(),
                                person.statusCheck(),
                                person.getFirstName(),
                                person.getLastName(),
                                aski("Input ticket duration HHMM format (eg. 01:23 would be 123)")
                            ));
                            cout << "Your ticket:" << endl;
                            tickets.back().showinfo();
                      
                    
                    break; // Exit the loop after a valid ticket is created
                }














			}
			else {
				cout << "Account not found. Please create an account first." << endl;
				}
				break;
			}

			case 2:
                tickets.push_back(Ticket(
                    getcurtime(),
                    choosetype(),
                    aski("Input ticket duration HHMM format (eg. 01:23 would be 123)")
                ));
                cout << "Your ticket:" << endl;
                tickets.back().showinfo();
                break;

			case 3:

				{
					
					accountManager.createAccount(asks(qname), asks(qname2), aski(qyear), asks(qdiscount));
				}
				break;

            default:
                cout << "Wrong Input - press number next to desired option" << endl;
                break;
        }
    }
}