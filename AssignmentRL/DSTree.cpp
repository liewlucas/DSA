#include "stdafx.h"
#include "DSTree.h"


DSTree::DSTree()
{
	// Initialise Lead node to false
	isLeaf = false;
	for (int i = 0; i < CHAR_SIZE; i++)
	{
		alphabet[i] = nullptr; // set letter to null since no letter has been initiated in the tree
	}
}

void DSTree::insert(string word)
{
	// Create pointer pointing to address of root node (this)
	DSTree* curr = this;
	for (int i = 0; i < word.length(); i++)
	{
		// Create node if path not found
		if (curr->alphabet[word[i]] == nullptr) // If address of index Letter is null
		{
			curr->alphabet[word[i]] = new DSTree(); // Sets index Letter of character array to new DS
		}
		curr = curr->alphabet[word[i]]; // Traverse from root to inserted word
	}

	// set current node as leaf
	curr->isLeaf = true;
}
bool DSTree::search(const string word)
{
	
	if (this == nullptr)
	{
		return false; // If tree is empty, return false
	}

	DSTree* curr = this; // Get root address
	for (int i = 0; i < word.length(); i++)
	{
		// traverse to next node
		curr = curr->alphabet[word[i]];

		if (curr == nullptr) // If next node is null, meaning word does not exist
		{
			return false;
		}
	}
	return curr->isLeaf; // If entire word is found returns true
}




// Display Certain Letter implementation

bool DSTree::InsertionError(string word) {
	bool checkdaword = false;
	DSTree* newNode = this;
	
	if (newNode->search(word)) {
		cout << "Word is already correct\n";
		return false;
	}

	else {
	
		for (int i = 0; i < word.length(); i++)
		{
			string tempWord = word;
			tempWord.erase(i,1);
			if (newNode->search(tempWord)) {
				cout << "Insertion error detected." << endl;	//Loop through  a given word // if in the range of 0-1/1-2 there is an additonla word, insertion error is detected
				checkdaword = true;

			}
		}

		if (!checkdaword) {
			cout << "Word does not exist." << endl;
			return false;
		}
		return true;
	}
}








