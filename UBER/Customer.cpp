#include "Customer.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

Customer::Customer() {

}

void Customer::display_customer()
{

	cout << "Name         : " << name << endl;
	cout << "Phone number : " << phone_num << endl;
}

void Customer::add_customer(string n, string ps, string p) {

	name = n;
	pass = ps;
	phone_num = p;

}

pair <string, string > Customer::pickup() {

	pair <string, string > k;

	cout << endl << endl << "\tPlease, Enter your location    : ";
	cin >> k.first;
	cout << endl << endl << "\tPlease, Enter your destination : ";
	cin >> k.second;
	cout << endl << endl;

	return k;
}

void Customer::estimation(int x, string trans) {

	cout << endl << "\tYour estimated distance is about  " << x << " km";

	cout << endl << endl << "\tYour estimated price is about     " << x * 6 << " L.E";

	cout << endl << endl << "\tYour estimated time is about      " << x * 5 << " Minutes";

	cout << endl << endl;

}

Customer::~Customer() {
}