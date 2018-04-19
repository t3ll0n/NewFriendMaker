//-----------------------------------------------------------------------------------------------------
//
// Name: Tellon Smith
//
// Course: CS 3013 - Advanced Structures and Algorithms, Spring 16, Dr. Johnson
//
// Program Assignment : #5
//
// Due Date: Thursday, May. 5th, 2016, 2PM
//
// Purpose: This program uses a graph class containing an adjacency matrix to solve a problem. It reads
//          in a file containig people at a party who knows each other and ouputs the introdcutions 
//          that has to be made between persons so that everyone knows each other. 
//
//-----------------------------------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include "Graph.h"

using namespace std;

//Purpose: open input and ouput streams
//Requires: infile and outfile
//Returns: an opened input and output strea
void openFiles(ifstream & infile, ofstream & outfile);

//Purpose: prints headings
//Requires: opened output stream
//Returns: outfile with headings appended to it
void printHeading(ofstream & outfile);

//Purpose: prints headings
//Requires: none
//Returns: console with headings appended to it
void printHeading2();

//Purpose: prints a welcome message
//Requires: opened output stream
//Returns: outfile with welcome message appended to it
void printWelcomeMessage(ofstream & outfile);

//Purpose: prints an exit message
//Requires: opened output stream
//Returns: outfile with exit message appended to it
void printExitMessage(ofstream & outfile);

//Purpose: reads the info from the file into the adjacency matrix
//Requires: opened input stream, graph  
//Returns: graph with info added to adjacency matrix 
void readInput(ifstream & infile, Graph & graph);

//Purpose: prints the complement of the adjacency matrix (introductions to be made)
//Requires: opened output stream, graph
//Returns: output stream with introductions appended to it
void printComplement(ofstream & outfile, Graph & graph);

void main()
{
	//variable declarations
	ifstream infile;
	ofstream outfile;
	Graph graph;

	//begin process
	printHeading2();
	openFiles(infile, outfile);
	printHeading(outfile);
	printWelcomeMessage(outfile);	
	readInput(infile, graph);
	printComplement(outfile, graph);
	printExitMessage(outfile);

	//close files 
	infile.close();
	outfile.close();

	system("pause");
}

void openOutputFile(ofstream & outfile)
{
	char outFileName[40];

	//open output stream
	cout << "Enter the output file name: ";
	cin >> outFileName;
	outfile.open(outFileName);
}

void printHeading(ofstream & outfile)
{
	outfile << "\nName: Tellon Smith" << endl;
	outfile << "Course: CS 3013 - Advanced Structures and Algorithms, Spring 16, Dr. Johnson" << endl;
	outfile << "Program Assignment: #5" << endl;
	outfile << "Due Date: Thursday, May 5, 2016, 2PM" << endl;
	outfile << "Purpose: This program uses a graph class containing an adjacency matrix to" << endl;
	outfile << "solve a problem. It reads in a file containig people at a party who knows" << endl;
	outfile << "each other and ouputs the introdcutions that has to be made between persons so" << endl;
	outfile << "that everyone knows each other." << endl;
}

void printHeading2()
{
	cout << "\nName: Tellon Smith" << endl;
	cout << "Course: CS 3013 - Advanced Structures and Algorithms, Spring 16, Dr. Johnson" << endl;
	cout << "Program Assignment: #5" << endl;
	cout << "Due Date: Thursday, May 5, 2016, 2PM" << endl;
	cout << "Purpose: This program uses a graph class containing an adjacency matrix to" << endl;
	cout << "solve a problem. It reads in a file containig people at a party who knows" << endl;
	cout << "each other and ouputs the introdcutions that has to be made between persons so" << endl;
	cout << "that everyone knows each other." << endl;
}

void printWelcomeMessage(ofstream & outfile)
{
	outfile << "\nWelcome to the New Friend Maker Program!" << endl;
	outfile << "\n----------------------------------------------------------------------" << endl;
	outfile << "			New Friend Maker Program" << endl;
	outfile << "----------------------------------------------------------------------" << endl;
}

void printExitMessage(ofstream & outfile)
{
	outfile << "\nThank you for using the New Friend Maker Program... Goodbye!" << endl;
}

void openFiles(ifstream & infile, ofstream & outfile)
{
	char inFileName[40];
	char outFileName[40];

	//open input stream
	cout << "\nPlease enter the input file name: ";
	cin >> inFileName;
	infile.open(inFileName);

	//display error message if the specified file cannot be opened
	if (!infile)
	{
		cout << "\nERROR: cannot open the specified file. please run the program again." << endl;
		system("pause");
		exit(1);
	}

	//open output stream
	cout << "Enter the output file name: ";
	cin >> outFileName;
	outfile.open(outFileName);
}

void readInput(ifstream & infile, Graph & graph)
{
	int num;
	string x;
	string y;

	infile >> num; //read number persons/items/etc.

	graph.initializeMatrix(num); //initialize matrix with number persons/items/etc.
	
	//add edges
	while (infile >> x >> y)
	{
		graph.addEdge(x, y);
	}

}

void printComplement(ofstream & outfile, Graph & graph)
{
	vector<vector<int>> temp = graph.getComplement();

	outfile << "\nIntroductions To Be Made:" << endl;
	
	for (unsigned int i = 0; i < temp.size(); i++)
	{
		for (unsigned int j = 0; j < temp.size(); j++)
		{
			//avoids edges with an item and itself
			if (i != j)
			{
				//print if value equals 1
				if (temp[i][j] == 1)
				{
					outfile << graph.getItem(i);
					outfile << " needs to meet ";
					outfile << graph.getItem(j) << endl;
					temp[j][i] = 0; //because graph/matrix is undirected, the opposite position
					                //is changed to 0 to avoid re-printing the introduction
				}
			}
		}
	}
}