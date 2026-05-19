#ifndef UTILS_H
#define UTILS_H

#include <string>
using namespace std;

int getcurtime();
int aski(const string& q);
string asks(const string& q);
string choosetype();
int tominutes(int time);
int fromminutes(int minutes);
string formatime(int hhmm);
int subtractime(int t1, int t2);
int addtime(int t1, int t2);

#endif