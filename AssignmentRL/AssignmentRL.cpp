// AssignmentRL.cpp : Defines the entry point for the console application.
// TEAM DETAILS
// TEAM: Lucas & RAYNER
// Lucas:
// Rayner: S10177641K
//
//Features
//
//

#include <cstdlib>
#include "stdafx.h"
#include "DsTree.h"
#include <iostream>
#include <string>
#include <fstream>


#define DICTIONARY "dictionary.txt"     //name of file representing the dictionary here

using namespace std;

//This methods load dictionary.txt into DataStructure tree
void LoadDictionary(){
	
	//Set your path 
	string path;
	path = "C:\\Users\\rayne\\source\\repos\\DSA\\AssignmentRL\\dictionary.txt"; // set your local path
	
	ifstream inFile;
	inFile.open(path);
	
	//inFile.open(path);
	if (inFile.is_open())
	{
		cout << "Found file" << endl;
	}
	else
	{
		cout << "Could not find file\n";
	}
	inFile.close();

}

void CheckWord() {

}

void SpellCheckFile() {
}

void AddWord() {}

void DisplayWordwithCertainLet() {

}




//This method is an interface for the user to select his / her options adding a new word / checking a word to dictionary
void UserProgam() {
	/*The program gives a menu to user where he/she can choose either to
	check an existing file,
	create a new file or
	to add a word in the dictionary
	*/
	int choice;
	LoadDictionary();
	while (true)
	{		
		cout << "1. Check a word\n2. Spell Check a File\n3. Add Word\n4. NULL\n5. Display word that start with a certain letter\n6. Exit\n";
		cout << "Enter your choice:";
		cin >> choice;

		if (choice == 6) {
			cout << "Thank you for using this program!" << endl;
			break;

		}
	}





}




int main()
{
	UserProgam();
	return 0;

}



