#include "Graph.h"
#include "Node.h"
#include "Customer.h"
#include "Driver.h"


#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

Graph::Graph()
{

}

void Graph::read()
{
	adj_list.resize(100);
	facility_index["Hospital"] = 0;	facility_index["Vet"] = 1;
	facility_index["ATM"] = 2; facility_index["Supermarket"] = 3;
	facility_index["Hotel"] = 4; facility_index["School"] = 5;

	//////////////////// Graph input /////////////////////////
	
	string node1, node2;
	int weight;
	string transportation_method;
	Node tempNode;
	ifstream f, co, d;
	f.open("graph.txt");
	f >> num_nodes;
	f.ignore();
	f >> num_edges;
	f.ignore();
	nodes.push_back(tempNode);
	vector<string>facility_names;
	for (int i = 1; i <= num_nodes; i++)
	{
		int x; string y;
		tempNode.facilities.clear();
		tempNode.facilities.resize(6);
		getline(f, tempNode.name);
		getIdx[tempNode.name] = i;
		getName[i] = tempNode.name;
		f >> tempNode.Coordinates.first;
		f.ignore();
		f >> tempNode.Coordinates.second;
		f.ignore();
		for (int i = 0; i < 6; i++)
		{
			f >> x; f.ignore();
			for (int j = 0; j < x; j++)
			{
				getline(f, y);
				tempNode.facilities[i].push_back(y);
			}
		}
		nodes.push_back(tempNode);
	}
	for (int i = 1; i <= num_edges; i++) {
		getline(f, node1);
		getline(f, node2);
		f >> weight;
		f.ignore();
		getline(f, transportation_method);
		int a = getIdx[node1], b = getIdx[node2];
		////   input of vector <Dijkstra_edge> adj_list[200] == > implemented for Dijkstra algorihtm
		p.weight = weight;
		p.method = transportation_method;
		p.neighbour = b;
		adj_list[a].push_back(p);
		p.neighbour = a;
		adj_list[b].push_back(p);
		/////  input of vector<edge>edges ==> implemented for Bellman-Ford algorithm
		if (edges.size() == 0)
			edges.push_back(tempEdge);

		tempEdge.firstNode = a;
		tempEdge.secondNode = b;
		tempEdge.weight = weight;
		tempEdge.transportation = transportation_method;
		edges.push_back(tempEdge);
		tempEdge.firstNode = b;
		tempEdge.secondNode = a;
		edges.push_back(tempEdge);
	}
	f.close();
	//////////////////// Customers input /////////////////////////
	co.open("customer.txt");
	co >> costumer_num;
	co.ignore();
	for (int i = 0; i < costumer_num; i++) {

		new_C.ID = i;
		getline(co, new_C.name);
		getline(co, new_C.pass);
		getline(co, new_C.phone_num);
		C.push_back(new_C);

	}
	co.close();
	//////////////////// Drivers input /////////////////////////
	d.open("driver.txt");
	d >> drivers_num;
	d.ignore();
	for (int i = 0; i < drivers_num; ++i)
	{
		new_D.ID = i;
		getline(d, new_D.name);
		getline(d, new_D.pass);
		getline(d, new_D.phone_num);
		getline(d, new_D.car_name);
		getline(d, new_D.car_model);
		getline(d, new_D.color);
		getline(d, new_D.car_num);
		d >> new_D.rates_num;
		d.ignore();
		d >> new_D.rate;
		d.ignore();
		getline(d, new_D.location);
		nodes[getIdx[new_D.location]].node_drivers.push_back(i);
		d >> new_D.num_scopes;
		d.ignore();
		for (int j = 0; j < new_D.num_scopes; ++j)
		{
			string x;
			getline(d, x);
			new_D.prefered_scope.push_back(x);
		}
		D.push_back(new_D);
		new_D.prefered_scope.clear();
	}
	d.close();

}

void Graph::save()
{
	ofstream f, co, d;
	co.open("customer.txt", ios::trunc);

	co << costumer_num << endl;

	for (int i = 0; i < costumer_num; i++) {

		co << C[i].name << endl << C[i].pass << endl << C[i].phone_num << endl;
	}
	co.close();

	///////////////////////////////

	f.open("graph3.txt", ios::trunc);

	f << num_nodes << endl;
	f << num_edges << endl;

	for (int i = 1; i <= num_nodes; i++) {
		f << nodes[i].name << endl;
		f << nodes[i].Coordinates.first << endl;
		f << nodes[i].Coordinates.second << endl;
		for (int j = 0; j < 6; j++)
		{
			f << nodes[i].facilities[j].size() << endl;
			for (int k = 0; k < nodes[i].facilities[j].size(); k++)
			{
				f << nodes[i].facilities[j][k] << endl;
			}
		}
	}
	for (int i = 1; i < edges.size(); i += 2)
	{
		f << getName[edges[i].firstNode] << endl << getName[edges[i].secondNode];
		f << endl << edges[i].weight << endl << edges[i].transportation << endl;
	}
	f.close();

	d.open("driver.txt", ios::trunc);
	d << drivers_num << endl;
	for (int i = 0; i < drivers_num; ++i)
	{
		d << D[i].name << endl;
		d << D[i].pass << endl;
		d << D[i].phone_num << endl;
		d << D[i].car_name << endl;
		d << D[i].car_model << endl;
		d << D[i].color << endl;
		d << D[i].car_num << endl;
		d << D[i].rates_num << endl;
		d << D[i].rate << endl;
		d << D[i].location << endl;
		d << D[i].num_scopes << endl;
		for (int j = 0; j < D[i].num_scopes; j++)
		{
			d << D[i].prefered_scope[j] << endl;
		}
	}
	d.close();
}

void Graph::addNode(string na, int x, int y)
{
	Node n;
	if (num_nodes == 0)
	{
		nodes.push_back(n);
	}
	n.get_values(na, x, y);
	n.facilities.resize(6);
	nodes.push_back(n);
	num_nodes++;
	getIdx[n.name] = num_nodes;
	getName[num_nodes] = n.name;
}

void Graph::addEdge(string First, string Second, string method, int w)
{
	string First_node, Second_node, transportation_method;
	int weight;
	First_node = First;
	Second_node = Second;
	weight = w;
	transportation_method = method;
	Bellman_edge temp_edge;
	Dijkstra_edge tempEdge;
	int a = getIdx[First_node], b = getIdx[Second_node];

	if (num_edges == 0)
	{
		edges.push_back(temp_edge);
	}
	num_edges++;

	/////////////////////////////// add edges for Dijkstra ////////////////////////////////////////

	tempEdge.neighbour = b;
	tempEdge.weight = weight;
	tempEdge.method = transportation_method;
	adj_list[a].push_back(tempEdge);
	tempEdge.neighbour = a;
	adj_list[b].push_back(tempEdge);

	////////////////////////////// add edges for bellman-ford /////////////////////////////////////

	temp_edge.firstNode = a;
	temp_edge.secondNode = b;
	temp_edge.weight = weight;
	temp_edge.transportation = transportation_method;
	edges.push_back(temp_edge);
	temp_edge.firstNode = b;
	temp_edge.secondNode = a;
	edges.push_back(temp_edge);
}

void Graph::deleteGraph() {

	for (int i = 1; i <= num_nodes; i++) {

		adj_list[i].clear();

	}
	nodes.clear();
	edges.clear();
	num_nodes = 0;
	num_edges = 0;

}

void Graph::displaygraph() {

	for (int i = 1; i <= num_nodes; i++) {

		cout << "neighbours of  - " << getName[i] << " - are  { ";

		for (int j = 0; j < adj_list[i].size(); j++)
		{
			if (j > 0)
			{
				cout << " , ";
			}
			cout << getName[adj_list[i][j].neighbour] << " with weight : " << adj_list[i][j].weight;
			cout << " " << adj_list[i][j].method;
		}
		cout << " }" << endl << endl << endl;
	}
	cout << endl << endl;

}

void Graph::view_driver_info(int i)
{
	D[i].display_driver();
}

void Graph::rate(int i, int j) {

	D[i].rate *= D[i].rates_num;
	D[i].rates_num++;
	D[i].rate += j;
	D[i].rate /= D[i].rates_num;

}

void Graph::delete_node(string name)
{

	int node_index = getIdx[name];

	//////**** deleting in adj_list ****/////
	for (int i = 1; i <= num_nodes; i++)
	{
		////// deleting it from it's neighbours in adj_list /////
		for (int j = 0; j < adj_list[i].size(); j++)
		{
			if (adj_list[i][j].neighbour == node_index)
			{
				it = adj_list[i].begin();
				std::advance(it, j);
				adj_list[i].erase(it);
				j--;
			}
		}
		////// updating all node indices in adj_list[i] /////
		for (int j = 0; j < adj_list[i].size(); j++)
		{
			if (adj_list[i][j].neighbour > node_index)
			{
				adj_list[i][j].neighbour--;
			}
		}
	}
	it2 = adj_list.begin();
	std::advance(it2, node_index);
	adj_list.erase(it2);

	///////////////// Erasing all edges containing the node to be deleted  //////////
	for (int i = 0; i < edges.size(); i++)
	{
		if (edges[i].firstNode == node_index || edges[i].secondNode == node_index)
		{
			it3 = edges.begin();
			std::advance(it3, i);
			edges.erase(it3);
			i--;
		}
	}
	num_edges = edges.size() / 2;
	////////////// Updating indices already present in vector<Bellman_edge>edges /////////
	for (int i = 0; i < edges.size(); i++)
	{
		if (edges[i].firstNode > node_index)
		{
			edges[i].firstNode--;
		}
		if (edges[i].secondNode > node_index)
		{
			edges[i].secondNode--;
		}
	}
	vector<Node>::iterator node_itr;
	node_itr = nodes.begin();
	std::advance(node_itr, node_index);
	nodes.erase(node_itr);
	num_nodes--;
	/////////  updating data in getIdx  //////

	for (int i = 1; i <= num_nodes; i++)
	{
		getIdx[nodes[i].name] = i;
		getName[i] = nodes[i].name;
	}
	getIdx[name] = 0;
}

void Graph::insert_customer(string First, string Second, string method) {

	Customer t;
	t.add_customer(First, Second, method);
	C.push_back(t);
	costumer_num++;
}

void Graph::add_driver(vector<string> j, string n, string p, string pn, string cn, string l, string cnm, string c, string cm, int i)
{
	Driver temp_D;
	temp_D.insert_driver(D.size(), n, p, pn, cn, l, cnm, c, cm, i);
	temp_D.prefered_scope = j;
	nodes[getIdx[temp_D.location]].node_drivers.push_back(D.size());
	D.push_back(temp_D);
	drivers_num++;
}

int Graph::find_captain()
{
	for (int i = 0; i <= num_nodes - 1; ++i)
	{
		int idx = dist_order[i].second;
		for (int j = 0; j < nodes[idx].node_drivers.size(); j++)
		{
			int count = 0;
			for (int k = 0; k < child.size(); k++)
			{
				bool valid = false;
				for (int l = 0; l < D[nodes[idx].node_drivers[j]].prefered_scope.size(); ++l)
				{
					if (child[k] == D[nodes[idx].node_drivers[j]].prefered_scope[l])
					{
						valid = true;
					}
				}
				if (valid)
				{
					count++;
				}
			}
			if (count == child.size())
			{
				return nodes[idx].node_drivers[j];
			}
		}
	}
	return -1;
}

int Graph::Dijkstra(int l, int m, string chosen_tranport, bool search) {

	set < pair<int, int> > setds;
	dist.assign(num_nodes + 1, INT_MAX);
	vector <int>  parent(num_nodes + 1, -1);
	setds.insert(make_pair(0, l));
	dist[l] = 0;
	dist_order.resize(num_nodes + 1);
	for (int i = 1; i <= num_nodes; ++i)
	{
		dist_order[i].second = i;
	}
	while (!setds.empty())
	{
		pair<int, int> tmp = *(setds.begin());
		setds.erase(setds.begin());

		int u = tmp.second;

		vector <Dijkstra_edge>::iterator i;
		int c;
		for (i = adj_list[u].begin(), c = 0; i != adj_list[u].end(); ++i, ++c)
		{

			int v = i->neighbour;
			int weight = i->weight;

			if (dist[v] > dist[u] + weight && adj_list[u][c].method == chosen_tranport)
			{
				if (dist[v] != INT_MAX)
					setds.erase(setds.find(make_pair(dist[v], v)));

				parent[v] = u;
				dist[v] = dist[u] + weight;
				setds.insert(make_pair(dist[v], v));
			}

		}

	}
	dist_order[0].first = INT_MAX;
	for (int i = 1; i <= num_nodes; i++)
	{
		dist_order[i].first = dist[i];
	}
	sort(dist_order.begin(), dist_order.end());



	if (dist[m] == INT_MAX)  /// if your methoud does not succeded
	{
		return dist[m];
	}

	int x = m;
	if (search == 0) {
		while (true)
		{
			child.push_back(getName[x]);
			if (parent[x] != -1)
				x = parent[x];
			else
				break;
		}
	}

	return dist[m];
}

int Graph::bellman_ford(int start, int destination, string chosen_tranport) {

	//////////// NEW ///////////////////
	int distance = INT_MAX;
	////////////////////////////////////
	vector <int>  dist(num_nodes + 1, INT_MAX);
	vector <int>  parent(num_nodes + 1, -1);
	vector <string>  child;
	dist[start] = 0;
	dist_order.resize(num_nodes + 1);
	for (int i = 1; i <= num_nodes; ++i)
	{
		dist_order[i].second = i;
	}
	for (int i = 1; i <= num_nodes; ++i)
	{
		for (int j = 1; j < edges.size(); ++j)
		{
			if (dist[edges[j].firstNode] != INT_MAX && edges[j].transportation == chosen_tranport)
			{
				if (dist[edges[j].firstNode] + edges[j].weight < dist[edges[j].secondNode])
				{
					parent[edges[j].secondNode] = edges[j].firstNode;
					dist[edges[j].secondNode] = dist[edges[j].firstNode] + edges[j].weight;
				}
			}
		}
	}
	dist_order[0].first = INT_MAX;
	for (int i = 1; i <= num_nodes; i++)
	{
		dist_order[i].first = dist[i];
	}
	sort(dist_order.begin(), dist_order.end());
	if (dist[destination] == INT_MAX)
	{
		return dist[destination];
	}
	int x = destination;
	while (true)
	{
		child.push_back(getName[x]);
		if (parent[x] != -1)
			x = parent[x];
		else
			break;
	}
	cout << "Your route passes by : ";

	for (int i = child.size() - 1; i >= 0; i--) {
		cout << child[i];
		if (i > 0)
			cout << " --> ";
	}
	child.clear();
	cout << endl;
	if (chosen_tranport == "Uber")
	{
		new_C.estimation(dist[destination], "estana");
	}
	return dist[destination];
}

void Graph::add_place(string First, string Second, int t)
{
	string node_name = First, new_place_name = Second;
	nodes[getIdx[node_name]].facilities[t].push_back(new_place_name);
}

void Graph::fill_dist_bellman_ford(int start)
{
	dist.resize(num_nodes + 1);
	fill(dist.begin(), dist.end(), INT_MAX);
	vector <int>  parent(num_nodes + 1, -1);
	vector <string>  child;
	dist[start] = 0;
	dist_order.resize(num_nodes + 1);
	for (int i = 1; i <= num_nodes; ++i)
	{
		dist_order[i].second = i;
	}
	for (int i = 1; i <= num_nodes; ++i)
	{
		for (int j = 1; j < edges.size(); ++j)
		{
			if (dist[edges[j].firstNode] != INT_MAX)
			{
				if (dist[edges[j].firstNode] + edges[j].weight < dist[edges[j].secondNode])
				{
					parent[edges[j].secondNode] = edges[j].firstNode;
					dist[edges[j].secondNode] = dist[edges[j].firstNode] + edges[j].weight;
				}
			}
		}
	}
	dist_order[0].first = INT_MAX;
	for (int i = 1; i <= num_nodes; i++)
	{
		dist_order[i].first = dist[i];
	}
	sort(dist_order.begin(), dist_order.end());
}

int Graph::search_by_facility_and_name(string location, string name)
{
	vector<string>places;
	fill_dist_bellman_ford(getIdx[location]);
	for (int i = 0; i < dist_order.size() - 1; i++)
	{
		for (int k = 0; k < 6; k++)
		{
			for (int j = 0; j < nodes[dist_order[i].second].facilities[k].size(); j++)
			{
				if (nodes[dist_order[i].second].facilities[k][j] == name)
				{
					return getIdx[nodes[dist_order[i].second].name];
				}
			}
		}
	}

	return -1;

}

Graph::~Graph()
{
}