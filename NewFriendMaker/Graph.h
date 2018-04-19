//Tellon Smith
//CMPS 3013 - Program 5
//Graph.h
//This file declares a graph using a 2D vector to represent an adjacency matrix using 0's ans 1's.

#pragma once

#include <iostream>
#include <vector>

using namespace std;

#pragma once
class Graph
{
public:
	//default constructor
	Graph();

	//parameterized constructor
	Graph(int num);

	//copy constructor
	Graph(Graph & otherGraph);

	//destructor
	~Graph();

	//Purpose: sets the number of rows and columns for the adjacency matrix with all values set to 0 
	//Requires: int, the number of rows and columns
	//Returns: maxtrix filled with 0's
	void initializeMatrix(int num);

	//Purpose: adds an edge between two items
	//Requires: two strings, the two items to add the edge between 
	//Returns:  adjacency matrix with edge added
	void addEdge(string x, string y);

	//Purpose: generates and return the complement of the adjacency matrix
	//Requires: none
	//Returns: complement adjacency matrix
	vector<vector<int>> getComplement();

	//Purpose: gets an item from the item list matched with the ID (position in vector) provided
	//Requires: int, the ID (position in vector) of the item to return
	//Returns: string, the item matching the ID (position in vector)
	string getItem(int id);		

private:
	//Purpose: adds an item to the item list if it does not exist 
	//Requires: string, the item to add
	//Returns: item list with new item added
	void addItem(string item);

	//Purpose: checks to see if an item already exist in the item list
	//Requires: string, item to check exist
	//Returns: true if item aldready exist, false if it does not
	bool findItem(string item);

	//Purpose: gets the id (position in vector) of an item
	//Requires: string, the item to get the ID (position in vector) for
	//Returns: int, the ID (position in vector)
	int getItemID(string item);

	vector<vector<int>> matrix;
	vector<string> itemList; //stores the items and uses it's position in the vector as it's ID
};

