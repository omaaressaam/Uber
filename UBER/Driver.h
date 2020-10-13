#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Driver
{
  public:

	int ID;
	float rate;
	int rates_num;
	string name;
	string pass;
	string phone_num;
	string car_name;
	string color;
	string car_num;
	string car_model;
	string location;
	int num_scopes;
	vector <string> prefered_scope;

	Driver();
	void insert_driver(int ID, string n, string, string, string, string, string, string, string, int);
	void display_driver();
	~Driver();
};

