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
#include <ctype.h>

#define DICTIONARY "dictionary.txt"     //name of file representing the dictionary here

using namespace std;

//This methods load dictionary.txt into DataStructure tree
//1. Check if file exist in directory
//2. Load file into Tree
void LoadDictionary(DSTree*& tree){
	
	//Set your path 
	string path;
	path = "C:\\Users\\rayne\\source\\repos\\DSA\\AssignmentRL\\dictionary.txt"; // set your local path
	
	ifstream inFile;
	inFile.open(path);
	
	//inFile.open(path);
	if (inFile.is_open())
	{
		//DSTree* dict = new DSTree();
		//cout << "Found file" << endl;
		string x;
		while (inFile >> x)
		{
			tree->insert(x);
		}
	}
	else
	{
		cout << "Could not find file\n";
	}
	inFile.close();

}

//This method allows user to spellcheck his/her word
//1. Ask user for word
//2. Traverse through Tree
//3. If exist, display 
//4. Else, Display not exist

void CheckWord(DSTree* ds) {
	//User key in word
	string word;
	cout << "Please enter a word: ";
	cin >> word;

	if (ds->search(word) == true) {
		cout << word + " is found in the dictionary!" << endl;
	}
	else {
		cout << word + " not found!" << endl;
	}

}

void SpellCheckFile(DSTree* ds) {


	string file;
	cout << "Enter format of file (csv or txt): ";
	cin >> file;

	if (file == "csv") {
		cout << "No crime is so great as daring to EXCEL ~Winston Churchill" << endl;

		// Check file
		//Set your path 
		string path;
		path = "C:\\Users\\rayne\\source\\repos\\DSA\\AssignmentRL\\dictionary10K.csv"; // set your local path

		ifstream inFile;
		inFile.open(path);
		string getcontent;
		if (inFile.is_open())
		{
			while (getline(inFile, getcontent)) {
				if (ds->search(getcontent) == false) {
					cout << getcontent << endl;

				}
			}

			inFile.close();
		}
		else
		{
			cout << "Could not find file\n";
		}
		

	}
	else if (file == "txt") {
		cout << "Good choice!" << endl;
		//Set your path 
		string path;
		path = "C:\\Users\\rayne\\source\\repos\\DSA\\AssignmentRL\\dictionary10K.txt"; // set your local path

		ifstream inFile;
		inFile.open(path);
		string getcontent;
		if (inFile.is_open())
		{
			while (getline(inFile, getcontent)) {
				if (ds->search(getcontent) == false) {
					cout << getcontent << endl;

				}
			}

			inFile.close();
		}
		else
		{
			cout << "Could not find file\n";
		}
		
	}


}

void AddWord(DSTree* ds) {
	//User keys in word
	string word;
	while (true) {

		cout << "Please enter a word: ";
		cin >> word;
		if (ds->search(word) == false) {
			cout << "Cool your new word will be added!" << endl;
			break;
		}
		else {
			cout << "Word already exists, please try again!" << endl;
		}
	}
	//Insert into data structure
	ds->insert(word);
	//Insert into file
	ofstream myfile;
	myfile.open("dictionary.txt", ios_base::app);
	myfile << word; 
	myfile.close();

	
}

void DisplayWordwithCertainLet(DSTree* ds) {
	string letter;
	cout << "Please enter a letter: ";
	cin >> letter;
	

}

void errorHandler() {
	cout << "Hmmm, did you type something wrong? Please try again" << endl;

}

//This method is an interface for the user to select his / her options adding a new word / checking a word to dictionary
void UserProgam(DSTree*& dict) {
	/*The program gives a menu to user where he/she can choose either to
	check an existing file,
	create a new file or
	to add a word in the dictionary
	*/
	int choice;
	while (true)
	{		
		cout << "1. Check a word\n2. Spell Check a File\n3. Add Word\n4. NULL\n5. Display word that start with a certain letter\n6. Exit\n";
		cout << "Enter your choice:";
		cin >> choice;
		if (choice == 1) {
			CheckWord(dict);
		}
		else if (choice == 2) {
			SpellCheckFile(dict);
		}
		else if (choice == 3) {
			AddWord(dict);
		}
		else if (choice == 5) {
			DisplayWordwithCertainLet(dict);
		}
		else if (choice == 6) {
			cout << "Thank you for using this program!" << endl;
			break;
		}
		else {
			errorHandler();
		}
	}
}

//MAIN PROGRAM//
int main()
{
	
	DSTree* dict = new DSTree();
	LoadDictionary(dict);
	UserProgam(dict);
	
	return 0;

}



