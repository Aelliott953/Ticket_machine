#include <iostream>
#include <vector>
#include "Ticket.h"
#include "utils.h"

using namespace std;

int main() {
    vector<Ticket> tickets;
    int option;
    int card_number;

    while (true) {
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
            case 1:
                cin >> card_number;
                break;

            case 2:
                tickets.emplace_back(
                    getcurtime(),
                    choosetype(),
                    aski("Input ticket duration HHMM format (eg. 01:23 would be 123)")
                );
                cout << "Your ticket:" << endl;
                tickets.back().showinfo();
                break;

            case 3:
                // Account creation placeholder
                break;

            default:
                cout << "Wrong Input - press number next to desired option" << endl;
                break;
        }
    }
}