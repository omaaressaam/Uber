#include "Driver.h"
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

Driver::Driver() {
}

void Driver::insert_driver(int id, string n, string p, string pn, string cn, string l, string cnm, string c, string cm, int ns) {

	ID = id;
	name = n;
	pass = p;
	phone_num = pn;
	car_num = cn;
	location = l;
	car_name = cnm;
	color = c;
	car_model = cm;
	num_scopes = ns;
}

void Driver::display_driver()
{
	cout << endl << "Your Driver's Info : " << endl << endl;
	cout << "\t\tID                 : " << ID + 1 << endl;
	cout << "\t\tName               : " << name << endl;
	cout << "\t\tPhone number       : " << phone_num << endl;
	cout << "\t\tCar Name           : " << car_name << endl;
	cout << "\t\tCar Model          : " << car_model << endl;
	cout << "\t\tCar colour         : " << color << endl;
	cout << "\t\tCar Number         : " << car_num << endl;
	cout << "\t\tDriver's location  : " << location << endl;
	cout << "\t\tDriver's rate      : ";
	if (rate == 0)
		cout << " Unrated \n";
	else
	{
		cout << rate << endl;
	}
	cout << endl << endl;
}

Driver::~Driver() {

}