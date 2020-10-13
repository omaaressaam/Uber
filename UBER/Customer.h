#pragma once
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
class Customer
{
public:

	int ID;
	string name;
	string pass;
	string phone_num;

	Customer();
	void display_customer();
	void add_customer(string, string, string);
	void estimation(int, string);
	pair <string, string > pickup();
	~Customer();
};

