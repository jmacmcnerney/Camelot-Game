/* Project: Camelot Narrative Story + Experience Manager
-- Project Description: An experience manager for the Camelot Virtual Environment.
-- Authors: John (Mac) McNerney, Zac Foster, John Colfer, Jake Hayden
-- File: functions.h
-- File Description: A number of functions that simplify important and commonly-used processes in Camelot.
*/
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "icon.h"

using namespace std;
class functions {
public:


	// Wait for given input before continueing
	void WaitFor(string message);

	// Send a command to Camelot.
	void Action(string command, bool waitUntilSuccess);

	//Character Creation Function
	void SetupCharacter(string name, string bodyType, string clothing, string hairStyle, string hairColor, string position);

	//Icon Setup
	void SetupIcons(vector<Icon> icons);

	//Does the inital setup for Dialog
	void SetupDialog(string mainChar, string talkingTo, bool walk);

	void ShowInv(string person, vector<string> inventory);

	//Handles all of purchasing something for a coin
	void Grab(string purchase, string input, vector<string>& storeInv, vector<string>& inventory, bool& coin, bool& itemCheck, bool purchaseCheck);

	//Splits the input into one of its words. NumToSkip is to skip to the start of the word you want, Reverse is to start 
	//at the end of the string
	string splitInput(string input, int numToSkip, bool reverse);

	// performs actions for the most common keywords received from Camelot
	bool checkCommonKeywords(string input, string modifiedInput, string playerName, vector<string> playerInv);

	//Closing narration box
	void CloseList();

	//Transition to other areas
	void Transition(string character, string exit, string entrance);

	//Start option
	void StartOption(string mainChar);

	//inventory interaction
	void AccessInventory(vector<string> inventory, string charName);

	//Walk To Input Disables and Enables
	void WalkToPlace(string character, string location);

	//Dialog Text Setup
	void SetupDialogText(string message, string responseKey1, string response1, string responseKey2 = "nothing", string response2 = "nothing", string responseKey3 = "nothing", string response3 = "nothing", string responseKey4 = "nothing", string response4 = "nothing", string responseKey5 = "nothing", string response5 = "nothing", string responseKey6 = "nothing", string response6 = "nothing", string responseKey7 = "nothing", string response7 = "nothing");

	//Removing An Item
	void RemoveItem(string itemname, vector<string> &inventory);

	//Library Item Handler
	void LibraryItem(string action, string itemname, string position, bool &positionOccupied, bool &hasItem, bool &correctPosition, vector<string> &inventory);
	
	//Puzzle Item Handler
	void StorageItem(string action, string itemname, string position, bool& positionOccupied, bool& hasItem, bool& correctPosition, vector<string>& inventory);

	//Puzzle Item Handler
	void PuzzleItem(string action, string itemname, string position, bool& positionOccupied, bool& hasItem, bool& correctPosition, vector<string>& inventory);

	//Cheat Item Menu
	void ItemCheats(string itemname, bool &hasItem);

	//Item Handler
	void ItemHandler(string itemname, string action, string position, string location, vector<string>& inventory, bool& inventoryErrorCheck, string& onLeft, string& onRight, string& onCenter, bool& correctLeft, bool& correctRight, bool& correctCenter);
};