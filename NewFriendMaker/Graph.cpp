//Tellon Smith
//CMPS 3013 - Program 5
//Graph.cpp
//Implements the Graph class in Graph.h

#include "Graph.h"

using namespace std;

Graph::Graph()
{

}

Graph::Graph(int num)
{
	initializeMatrix(num);
}

Graph::Graph(Graph & otherGraph)
{
	matrix = otherGraph.matrix;
	itemList = otherGraph.itemList;
}

Graph::~Graph()
{

}

void Graph::initializeMatrix(int num)
{
	//resize vector
	matrix.resize(num, vector<int>(num, 0));

	//set all items to 0
	for (unsigned int i = 0; i < matrix.size(); i++)
	{
		for (unsigned int j = 0; j < matrix.size(); j++)
		{
			matrix[i][j] = 0;
		}
	}
}

void Graph::addEdge(string x, string y)
{
	int xID;
	int yID;
	
	//add x to the item list if it does not already exist in the list
	if (!findItem(x))
	{
		addItem(x);
	}
	//add y to the item list if it does not already exist in the list
	if (!findItem(y))
	{
		addItem(y);
	}

	//get item id's (position in vector)
	xID = getItemID(x);
	yID = getItemID(y);

	//create undirected edges
	matrix[xID][yID] = 1;
	matrix[yID][xID] = 1;
}

vector<vector<int>> Graph::getComplement()
{
	vector<vector<int>> temp = matrix;

	for (unsigned int i = 0; i < temp.size(); i++)
	{
		for (unsigned int j = 0; j < temp.size(); j++)
		{
			if (i != j)//avoids edges with an item and itself
			{
				//turns 0's into 1's
				if (temp[i][j] == 0)
				{
					temp[i][j] = 1;
				}
				//turns 1's into 0's
				else
				{
					temp[i][j] = 0;
				}
			}
		}
	}
	//return complement
	return temp;
}

string Graph::getItem(int id)
{
	return itemList[id];
}

void Graph::addItem(string item)
{
	itemList.push_back(item);
}

bool Graph::findItem(string item)
{
	bool found = false;

	for (unsigned int i = 0; i < itemList.size(); i++)
	{
		//if item matches
		if (itemList[i] == item)
		{
			found = true;
		}
	}
	return found;
}

int Graph::getItemID(string item)
{
	bool found = false;
	int id = 0;

	while (!found)
	{
		//if item matches
		if (itemList[id] == item)
		{
			found = true;
		}
		else
		{
			id++;
		}
	}
	return id;
}