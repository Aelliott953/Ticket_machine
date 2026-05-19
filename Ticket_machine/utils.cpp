#include "utils.h"
#include <iostream>
#include <limits>
#include <ctime>
#include <cmath>

using namespace std;

int getcurtime() {
    time_t now = time(nullptr);
    tm local{};
    localtime_s(&local, &now);
    return local.tm_hour * 100 + local.tm_min;
}

int aski(const string& q) {
    int ans;
    cout << q << endl;
    cin >> ans;
    return ans;
}
string asks(const string& q) {
    string ans;
    cout << q << endl;
    cin >> ans;
    return ans;
};

string choosetype() {
    int option;
    while (true) {
        cout << "Choose the type of your ticket:" << endl;
        cout << "1. normal" << endl;
        cout << "2. reduced" << endl;
        cout << "3. free" << endl;

        if (!(cin >> option)) {
            cout << "Wrong Input - press number next to desired option" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch(option) {
            case 1: return "normal";
            case 2: return "reduced";
            case 3: return "free";
            default:
                cout << "Wrong Input - press number next to desired option" << endl;
                break;
        }
    }
}

int tominutes(int time) {
    return (time / 100) * 60 + (time % 100);
}

int fromminutes(int minutes) {
    return (minutes / 60) * 100 + (minutes % 60);
}

string formatime(int hhmm) {
    int hours = hhmm / 100;
    int minutes = hhmm % 100;
    hours = hours % 24;
    return to_string(hours) + ":" + (minutes < 10 ? "0" : "") + to_string(minutes);
}

int subtractime(int t1, int t2) {
    return fromminutes(tominutes(t1) - tominutes(t2));
}

int addtime(int t1, int t2) {
    return fromminutes(tominutes(t1) + tominutes(t2));
}
string translatetype(int num) {

	switch (num) {
	case 0: return "normal";
	case 1: return "free";
	case 2: return "reduced";
	default: return "normal";
	}
}