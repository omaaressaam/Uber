#pragma once

#include <vector>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include "Driver.h"
#include "Node.h"
#include "Customer.h"

using namespace std;

class Graph
{
public:

	struct Bellman_edge
	{
		int firstNode;
		int secondNode;
		int weight;
		string transportation;
	};

	struct Dijkstra_edge
	{
		int neighbour;
		int weight;
		string method;
	};

	vector < Node > nodes;
	vector < Driver > D;
	vector < Customer > C;
	vector< vector < Dijkstra_edge> > adj_list;

	vector<Dijkstra_edge>::iterator it;
	vector< vector <Dijkstra_edge> >::iterator it2;
	vector<Bellman_edge>::iterator it3;

	Customer new_C;
	Driver new_D;
	map<string, int> getIdx;
	map<int, string> getName;
	Dijkstra_edge p;
	pair < string, string > pick;
	int costumer_num = 0, drivers_num = 0;
	int num_nodes, num_edges;
	int weight;

	vector <string>  child;
	vector <int>  dist;
	vector < pair<int, int> > dist_order;

	Bellman_edge tempEdge;
	vector<Bellman_edge>edges;

	map<string, int>facility_index;

	Graph();

	void read();  
	void save();  
	void addNode(string, int, int);  
	void addEdge(string, string, string, int);  
	void deleteGraph();   
	void displaygraph();
	void insert_customer(string, string, string);
	void rate(int, int);
	void add_driver(vector<string>, string, string, string, string, string, string, string, string, int);
	void delete_node(string);
	int find_captain();  
	void view_driver_info(int);
	int Dijkstra(int start, int destination, string chosen_transport, bool search);
	int bellman_ford(int start, int destination, string chosen_tranport);
	void add_place(string, string, int);
	void fill_dist_bellman_ford(int start);  
	int search_by_facility_and_name(string location, string name);  

	~Graph();
};
