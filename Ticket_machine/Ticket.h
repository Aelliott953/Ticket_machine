#ifndef TICKET_H
#define TICKET_H

#include <string>
using namespace std;

class Ticket {
private:
    int time;
    string type;
    string name;
    string surname;
    int duration;

public:
    Ticket(int t, string typ, string n="Anonymous", string s="User", int d=0);
    Ticket(int t, string typ, int d=0);

    float price();
    void showinfo();
};

#endif