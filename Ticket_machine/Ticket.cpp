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
    // Use double for intermediate math and explicit std::pow/std::floor to avoid overload
    double discountmult;
    if (type == "reduced") discountmult = 0.5;
    else if (type == "free") discountmult = 0.0;
    else discountmult = 1.0;

    double minutes = static_cast<double>(tominutes(duration));
    double base = 7177.814;
    double numerator = -1.842789 - base;
    double denom = 1.0 + std::pow(minutes / 14907460000.0, 0.3419433);
    double value = std::floor(2.0 * (base + numerator / denom));

    return static_cast<float>(value * (discountmult / 2.0));
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