#pragma once
#include <iostream>
#include <string>
using namespace std; 

const int CHAR_SIZE = 128;

class DSTree
{
public:
	bool isleaf;
	DSTree*character[CHAR_SIZE];

	//CONSTRUCTOR 
	DSTree();

	//INSERT NEW WORD INTO DICTIONARY
	void insert(const string);

	//SEARCH FROM DICTIONARY
	bool search(const string);

	//display all words from user input
	void searchbour (DSTree*, const string)
};

