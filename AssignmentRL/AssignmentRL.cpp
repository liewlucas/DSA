// AssignmentRL.cpp : Defines the entry point for the console application.
// TEAM DETAILS
// TEAM: Lucas & RAYNER
// Lucas:  S10179187J
// Rayner: S10177641K
//
//Basic Features
//Check a word
//Spellcheck CSV (dictionark10k.csv)
//Spellcheck txt file (dictionary10k.txt)
//Add a new Word
//DisplayLetters with certain letter
//ADVANCE FEATURES
//Insertion error
//Substitution Error

#include <cstdlib>
#include "stdafx.h"
#include "DsTree.h"
#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>

#define DICTIONARY "dictionary.txt"     //name of file representing the dictionary here

using namespace std;


enum typeOfError {INSERTION,ERROR,CORRECT};
//This methods load dictionary.txt into DataStructure tree
//1. Check if file exist in directory
//2. Load file into Tree
void LoadDictionary(DSTree*& tree){
	//Set your path 
	string path;
	path = "C:\\Users\\rayne\\source\\repos\\DSA\\AssignmentRL\\dictionary.txt"; // set your local path
	ifstream inFile;
	inFile.open(path);
	if (inFile.is_open())
	{
		//DSTree* dict = new DSTree();
		//cout << "Found file" << endl;
		string x;
		while (inFile >> x)
		{
			tree->insert(x); // Add each line to data structure
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
//2. If tree is empty, return false 
//3. Get root address
//4. If next node is null, word does not exist
//5. If entire word is found returns true
//6. When true, display word found 
//7. Else, Display not found

void CheckWord(DSTree* ds) {
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
/*
PseudoCode for check a file
1.Prompt User if they want to open up file in csv or txt format
2.Set path and find the specific file in folder
3.Open up file
4.Loop through each line
5.Check if the word exists in dictionary 
6.If it does not, display the word
*/
void SpellCheckFile(DSTree* ds) {


	string file;
	cout << "Enter format of file (csv or txt): ";
	cin >> file;
	//WHEN USER ENTERS CSV
	if (file == "csv") {
		cout << "No crime is so great as daring to EXCEL ~Winston Churchill" << endl;

		//Set file path
		string path;
		path = "C:\\Users\\rayne\\source\\repos\\DSA\\AssignmentRL\\dictionary10K.csv"; // set your local path

		ifstream inFile;
		inFile.open(path);
		string getcontent;
		if (inFile.is_open())
		{
			while (getline(inFile, getcontent)) {
				//Loop through each line and check if word exists in dict.
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
/*
PsuedoCode for addword
Objectives: Add word to Tree, Append word to file
1.Check if word exists in dictionary
2.Insert each new alphabet in the tree until the word is formed 
3.Open File (dictionary.txt)
4.Add to file
5.Close file
*/
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
	ds->searchClosest(ds, letter);
}

void errorHandler() {
	cout << "Hmmm, did you type something wrong? Please try again" << endl;

}
/*Psuedocode for Insertion Error
Check for extra character
1. Check if the word already exists in the dictionary
2. If it does, return false and display the word is already correct
3. Get the length of the word
4. Remove the character from the string input at index "i"
5.
6.









*/



void insertyerror(DSTree* ds) {
	string word;
	cout << "Enter word you wanna search for insertion errors:";
	cin >> word;
	ds->InsertionError(word);
}

/*
PseudoCode for Substitution Error
1. Check the length of input and word from the file, if they are equal,
proceed further, otherwise move to next word of the file.
2.Start a loop from i= (length of input-1) to i>= 0 (Decrement variable i)
3.Make input string at index "i" == the first alphabet in the character list
4.Start a loop from j = 0 to j = 25
5.Check input == word from file. If condition is true
*/
void SubstitutionError() {
	char lower_alpha[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' }; 
	string word;
	cout << "Enter word:";
	cin >> word;
	int lenOfWord;
	lenOfWord = word.length();
	bool ExchangedChar;
	string path;
	path = "C:\\Users\\rayne\\source\\repos\\DSA\\AssignmentRL\\dictionary.txt"; // set your local path
	ifstream inFile;
	inFile.open(path);
	string getcontent;
	if (inFile.is_open())
	{
		while (getline(inFile, getcontent)) {
			if (getcontent == word) {
				ExchangedChar = false;
				break;
			}

			if (getcontent.length() == lenOfWord) {
				for (int i = lenOfWord - 1; i >= 0; i--) {
					string newWord;
					newWord = word;
					newWord[i] = lower_alpha[0];
					for (int j = 0; j < 26; j++) {
						if (newWord == getcontent) {
							ExchangedChar = true;
							break;
							

						}
						else {
							newWord[i] = lower_alpha[j + 1];
						}
					}
				}
			}
		}


		if (ExchangedChar == true) {
			cout << "Substitution error" << endl;
		}

		else if (ExchangedChar == false) {
			cout << "The word is correct!" << endl;
		}
		else {
			cout << "No such word" << endl;
		}


		inFile.close();
	}
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
		cout << "1. Check a word\n2. Spell Check a File\n3. Add Word\n4. Display word that start with a certain letter\n5. Insertion Error\n6. Substitution Error\n7. Exit\n";
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
		else if (choice == 4) {
			DisplayWordwithCertainLet(dict);
		}
		else if (choice == 5) {
			insertyerror(dict);
		}
		else if (choice == 6) {
			SubstitutionError();
		}
		else if (choice == 7) {
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
	//Variables
	//Set new tree
	DSTree* dict = new DSTree();
	//Import dictionary.txt to data structure
	LoadDictionary(dict);
	//Load Interface
	UserProgam(dict);
	return 0;

}



