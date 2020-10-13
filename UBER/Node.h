#pragma once
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Node
{
public:
	string name;
	bool is_in_route;
	pair<int, int>Coordinates;
	
	vector<vector<string>>facilities;
	vector <int> node_drivers;

	Node();
	void get_values(string n, int x, int y);
	~Node();
};

