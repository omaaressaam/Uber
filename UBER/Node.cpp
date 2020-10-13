#include "Node.h"
#include <string>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Node::Node()
{
}

void Node::get_values(string n, int x, int y)
{
	name = n;
	Coordinates.first = x;
	Coordinates.second = y;
}

Node::~Node()
{}
