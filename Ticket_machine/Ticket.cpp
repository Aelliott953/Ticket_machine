#include "Ticket.h"
#include "utils.h"
#include <iostream>
#include <cmath>
using namespace std;

Ticket::Ticket(int t, string typ, string n, string s, int d) {
    time = t;
    type = typ;
    name = n;
    surname = s;
    duration = d;
}

Ticket::Ticket(int t, string typ, int d) {
    time = t;
    type = typ;
    name = "Anonymous";
    surname = "Person";
    duration = d;
}

float Ticket::price() {
    float discountmult;
    if (type == "reduced") discountmult = 0.5;
    else if (type == "free") discountmult = 0;
    else discountmult = 1;

    return floor(
      2* ( 7177.814 +
        (-1.842789 - 7177.814) /
        (1.0 + pow(tominutes(duration) / 14907460000.0, 0.3419433)))
    ) * discountmult/2;
}

void Ticket::showinfo() {
    cout << endl;
    cout << "|-------------Ticket Information-------------|" << endl;
    cout << "      " << formatime(duration) << " duration " << type << " ticket" << endl;
    cout << "      bought by: " << name << " " << surname << " at: " << formatime(time) << endl;
    cout << "      valid until: " << formatime(addtime(time, duration)) << endl;
    cout << "      price: " << price() << endl;
    cout << "|-------------Ticket Information-------------|" << endl << endl;
}