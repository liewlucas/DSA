#pragma once
#include <iostream>
#include <string>
using namespace std;

const int CHAR_SIZE = 128;

//DSTREEEEE
class DSTree {
private:
public:
	bool isLeaf;
	DSTree* alphabet[CHAR_SIZE];

	// Contructor
	DSTree();
	// Insert header
	void insert(const string);
	// Search header
	bool search(const string);

	// Display all words from closest input
	const void searchClosest(DSTree*, const string);

	// Traverse through tree
	void traverse(string, DSTree*);
	
	//check for insertion error
	bool InsertionError(string);

	
};