// AssignmentRL.cpp : Defines the entry point for the console application.
// TEAM DETAILS
// TEAM: Lucas & RAYNER
// Lucas:
// Rayner: S10177641K
//
//Features
//
//

#include "stdafx.h"
#include "DsTree.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

using namespace std;

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
	while (true)
	{
		cout << "1. Check a word\n2. Spell Check a File\n3. Add Word\n4. NULL\n5. Display word that start with a certain letter\n6. Exit\n";
		cout << "Enter your choice:";
		cin >> choice;

		
		if (choice == 1) {
			CheckWord();
		}
		if (choice == 2) {
			SpellCheckFile();
		}
		if (choice == 3) {
			AddWord();
		}
		if (choice == 4) {
		
		}
		if (choice == 5) {
			
		}
		if (choice == 6) {
			cout << "Thank you for using this program!" << endl;
			break;

		}
	}





}




int main()
{
	UserProgram();
	system("PAUSE");
	return 0;

}



