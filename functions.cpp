/* Project: CS395 Alpha Milestone
-- Project Description: An experimental experience manager for the Camelot Virtual Environment.
-- Authors: Jake Hayden, John Colfer, Mac McNerney, Zac Foster
-- File: functions.cpp
-- File Description:
--		A number of functions that simplify important and commonly-used processes in Camelot.
*/

#include <iostream>
#include <string>
#include <vector>
#include "icon.h"
#include "functions.h"

using namespace std;

// Wait for given input before continueing
void functions::WaitFor(string message) {
	while (true) {
		string i;
		getline(cin, i);
		if (i == message) {
			break;
		}
	}
}

// Send a command to Camelot.
void functions::Action(string command, bool waitUntilSuccess) {
	cout << ("start " + command) << endl;
	if (waitUntilSuccess) {
		WaitFor("succeeded " + command);
	}
}

//Character Creation Function
void functions::SetupCharacter(string name, string bodyType, string clothing, string hairStyle, string hairColor, string position) {

	Action("CreateCharacter(" + name + ", " + bodyType + ")", true);

	if (clothing != "") {
		Action("SetClothing(" + name + ", " + clothing + ")", true);
	}
	if (hairStyle != "") {
		Action("SetHairStyle(" + name + ", " + hairStyle + ")", true);
	}
	if (hairColor != "") {
		Action("SetHairColor(" + name + ", " + hairColor + ")", true);
	}
	if (position != "") {
		Action("SetPosition(" + name + ", " + position + ")", true);
	}
}

//Icon Setup
void functions::SetupIcons(vector<Icon> icons) {

	for (int i = 0; i != icons.size(); i++) {
		Action("EnableIcon(" + icons[i].getTitle() + ", " + icons[i].getImage() + ", " + icons[i].getObject() + ", " + icons[i].getDescription() + ", " + icons[i].getIsDefault() + ")", true);
	}

}

//Does the inital setup for Dialog
void functions::SetupDialog(string mainChar, string talkingTo, bool walk) {
	string actionString = "";

	Action("DisableInput()", true);

	if (walk == true) {
		Action("WalkTo(" + mainChar + ", " + talkingTo + ")", true);
	}
	Action("ShowDialog()", true);
	Action("ClearDialog()", true);

	Action("SetLeft(" + mainChar + ")", true);

	Action("SetRight(" + talkingTo + ")", true);
	Action("EnableInput()", true);
}

void functions::ShowInv(string person, vector<string> inventory) {
	Action("HideDialog()", true);
	for (string item : inventory) {
		Action("AddToList(" + item + ")", true);
	}
	Action("ShowList(" + person + ")", true);
}

//Handles all of purchasing something for a coin
void functions::Grab(string purchase, string input, vector<string>& storeInv, vector<string>& inventory, bool& coin, bool& itemCheck, bool purchaseCheck) {

	Action("RemoveFromList(" + purchase + ")", true);
	for (int i = 0; i < (signed)storeInv.size(); i++) {
		if (storeInv[i] == purchase) {
			storeInv.erase(storeInv.begin() + i);
		}
	}
	Action("DisableIcon(" + input + ", " + purchase + ")", true);
	if (purchaseCheck) {
		inventory.erase(inventory.begin());
	}
	inventory.push_back(purchase);
	Action("HideList()", true);

	if (purchaseCheck) {
		coin = false;
		itemCheck = true;
	}

}

//Splits the input into one of its words. NumToSkip is to skip to the start of the word you want, Reverse is to start 
//at the end of the string
string functions::splitInput(string input, int numToSkip, bool reverse) {
	string output = "";

	//For going forwards
	if (!reverse) {
		for (int i = 0 + numToSkip; i < input.size(); i++) {
			if (input[i] == ' ') {
				i = input.size();
			}
			if (i != input.size()) {
				output = output + input[i];
			}
		}
	}

	//For going backwards
	else {
		for (int i = input.size() - 1; i > 0; i--) {
			if (input[i] == ' ') {
				i = 0;
			}
			if (i != 0) {
				output = input[i] + output;
			}
		}
	}

	return output;
}

// performs actions for the most common keywords received from Camelot
bool functions::checkCommonKeywords(string input, string modifiedInput, string playerName, vector<string> playerInv) {
	bool keywordFound = true;
	//If it's under the "Selected" keyword
	if (modifiedInput == "Selected") {

		modifiedInput = splitInput(input, 0, true);

		if (modifiedInput == "Start") {
			StartOption(playerName);
			Action("EnableInput()", true);
		}
		else if (modifiedInput == "Resume") {
			Action("HideMenu()", true);
			Action("EnableInput()", true);
			Action("EnableInput()", true);
		}
		else if (modifiedInput == "Quit") {
			Action("Quit()", true);
		}
		else if (modifiedInput == "end") {
			Action("HideDialog()", true);
		}
		else keywordFound = false;
	}
	//If it's under the "Key" keyword
	else if (modifiedInput == "Key") {

		modifiedInput = splitInput(input, 0, true);
		if (modifiedInput == "Inventory") {
			Action("ClearList()", true);
			for (string item : playerInv) {
				Action("AddToList(" + item + ")", true);
			}
			Action("ShowList(" + playerName + ")", true);
		}
		else if (modifiedInput == "Pause") {
			Action("DisableInput()", true);
			Action("ShowMenu()", true);
		}
		else keywordFound = false;
	}

	//If it's under the "Close" keyword
	else if (modifiedInput == "Close") {
		modifiedInput = splitInput(input, 0, true);
		if (modifiedInput == "Narration") {
			Action("HideNarration()", true);
		}
		else {
			CloseList();
		}
	}
	else keywordFound = false;

	return keywordFound;
}

//Closing narration box
void functions::CloseList() {
	Action("HideList()", true);
	Action("ClearList()", true);
	Action("EnableInput()", true);
}

//Transition to other areas
void functions::Transition(string character, string exit, string entrance) {
	Action("Exit(" + character + ", " + exit + ", true)", true);
	Action("Enter(" + character + ", " + entrance + ", true)", true);
}

//Start option
void functions::StartOption(string mainChar) {
	Action("SetCameraFocus(" + mainChar + ")", true);
	Action("HideMenu()", true);
	Action("EnableInput()", true);
}

//inventory interaction
void functions::AccessInventory(vector<string> inventory, string charName) {
	Action("HideDialog()", true);
	for (string item : inventory) {
		Action("AddToList(" + item + ")", true);
	}
	Action("ShowList(" + charName + ")", true);
}

void functions::WalkToPlace(string character, string location) {
	Action("DisableInput()", true);
	Action("WalkTo(" + character + ", " + location + ")", true);
	Action("EnableInput()", true);
}

void functions::SetupDialogText(string message, string responseKey1, string response1, string responseKey2, string response2, string responseKey3, string response3, string responseKey4, string response4, string responseKey5, string response5, string responseKey6, string response6, string responseKey7, string response7) {
	Action("ClearDialog()", true);
	if ((responseKey7 != "nothing") && (response7 != "nothing")) {
		//Action("SetDialog(" + message + " [" + responseKey1 + "|" + response1 + "] [" + responseKey2 + "|" + response2 + "] [" + responseKey3 + "|" + response3 + "] [" + responseKey4 + "|" + response4 + "] [" + responseKey5 + "|" + response5 + "])", true);
		Action("SetDialog(" + message + "\\n[" + responseKey1 + "|" + response1 + "]\\n[" + responseKey2 + "|" + response2 + "]\\n[" + responseKey3 + "|" + response3 + "]\\n[" + responseKey4 + "|" + response4 + "]\\n[" + responseKey5 + "|" + response5 + "]\\n[" + responseKey6 + "|" + response6 + "]\\n[" + responseKey7 + "|" + response7 + "])", true);
	}
	else if ((responseKey6 != "nothing") && (response6 != "nothing")) {
		//Action("SetDialog(" + message + " [" + responseKey1 + "|" + response1 + "] [" + responseKey2 + "|" + response2 + "] [" + responseKey3 + "|" + response3 + "] [" + responseKey4 + "|" + response4 + "] [" + responseKey5 + "|" + response5 + "])", true);
		Action("SetDialog(" + message + "\\n[" + responseKey1 + "|" + response1 + "]\\n[" + responseKey2 + "|" + response2 + "]\\n[" + responseKey3 + "|" + response3 + "]\\n[" + responseKey4 + "|" + response4 + "]\\n[" + responseKey5 + "|" + response5 + "]\\n[" + responseKey6 + "|" + response6 + "])", true);
	}
	else if ((responseKey5 != "nothing") && (response5 != "nothing")) {
		//Action("SetDialog(" + message + " [" + responseKey1 + "|" + response1 + "] [" + responseKey2 + "|" + response2 + "] [" + responseKey3 + "|" + response3 + "] [" + responseKey4 + "|" + response4 + "] [" + responseKey5 + "|" + response5 + "])", true);
		Action("SetDialog(" + message + "\\n[" + responseKey1 + "|" + response1 + "]\\n[" + responseKey2 + "|" + response2 + "]\\n[" + responseKey3 + "|" + response3 + "]\\n[" + responseKey4 + "|" + response4 + "]\\n[" + responseKey5 + "|" + response5 + "])", true);
	}
	else if ((responseKey4 != "nothing") && (response4 != "nothing") && (responseKey5 == "nothing") && (response5 == "nothing")) {
		//Action("SetDialog(" + message + " [" + responseKey1 + "|" + response1 + "] [" + responseKey2 + "|" + response2 + "] [" + responseKey3 + "|" + response3 + "] [" + responseKey4 + "|" + response4 + "])", true);
		Action("SetDialog(" + message + "\\n[" + responseKey1 + "|" + response1 + "]\\n[" + responseKey2 + "|" + response2 + "]\\n[" + responseKey3 + "|" + response3 + "]\\n[" + responseKey4 + "|" + response4 + "])", true);
	}
	else if ((responseKey3 != "nothing") && (response3 != "nothing") && (responseKey4 == "nothing") && (response4 == "nothing")) {
		//comments are for 1.1.4
		//Action("SetDialog(" + message + " [" + responseKey1 + "|" + response1 + "] [" + responseKey2 + "|" + response2 + "] [" + responseKey3 + "|" + response3 + "])", true);
		Action("SetDialog(" + message + "\\n[" + responseKey1 + "|" + response1 + "]\\n[" + responseKey2 + "|" + response2 + "]\\n[" + responseKey3 + "|" + response3 + "])", true);
	}
	else if ((responseKey2 != "nothing") && (response2 != "nothing") && (responseKey3 == "nothing") && (response3 == "nothing")) {
		//Action("SetDialog(" + message + " [" + responseKey1 + "|" + response1 + "] [" + responseKey2 + "|" + response2 + "])", true);
		Action("SetDialog(" + message + "\\n[" + responseKey1 + "|" + response1 + "]\\n[" + responseKey2 + "|" + response2 + "])", true);
	}
	else {
		//Action("SetDialog(" + message + " [" + responseKey1 + "|" + response1 + "])", true);
		Action("SetDialog(" + message + "\\n[" + responseKey1 + "|" + response1 + "])", true);
	}
}

void functions::RemoveItem(string itemname, vector<string> &inventory) {
	for (size_t i = 0; i < inventory.size(); i++) {
		if (inventory[i] == itemname) {
			inventory.erase(inventory.begin() + i);
		}
	}
}

void functions::LibraryItem(string action, string itemname, string position, bool &positionOccupied, bool &hasItem, bool &correctPosition, vector<string> &inventory) {
	Action("HideDialog()", true);
	//Action("ShowNarration()", true);
	if (action == "place") {
		if (hasItem) {
			if (!positionOccupied) {
				Action("SetNarration(" + itemname + " Removed From Inventory)", true);
				RemoveItem(itemname, inventory);
				Action("SetPosition(" + itemname + ", CurrentLibrary.AlchemistTable." + position + ")", true);
				positionOccupied = true;
				hasItem = false;
				if ((itemname == "Library Apple" && position == "Left") || (itemname == "Library GoldCup" && position == "Center") || (itemname == "Library GreenKey" && position == "Right")) {
					correctPosition = true;
				}
				//return;
			}
			else {
				Action("SetNarration(There is already an item in that position.)", true);
			}
		}
		else if (!hasItem) {
			Action("SetNarration(You do not have that item in your inventory.)", true);
			//return;
		}
	}
	else if (action == "take") {
		positionOccupied = false;
		correctPosition = false;
		if (hasItem) {
			Action("SetNarration(" + itemname + " is already in your inventory.)", true);
			//return;
		}
		else if (!hasItem) {
			Action("SetPosition(" + itemname + ")", true);
			inventory.push_back(itemname);
			Action("SetNarration(" + itemname + " Added To Inventory.)", true);
			hasItem = true;
			//return;
		}
	}
	Action("ShowNarration()", true);
}

void functions::StorageItem(string action, string itemname, string position, bool& positionOccupied, bool& hasItem, bool& correctPosition, vector<string>& inventory) {
	Action("HideDialog()", true);
	if (action == "place") {
		if (hasItem) {
			if (!positionOccupied) {
				Action("SetNarration(" + itemname + " Removed From Inventory)", true);
				RemoveItem(itemname, inventory);
				Action("SetPosition(" + itemname + ", CurrentStorage.Shelf." + position + ")", true);
				positionOccupied = true;
				hasItem = false;
				if ((itemname == "Storage Bottle" && position == "Right") || (itemname == "Storage Bread" && position == "Left")) {
					correctPosition = true;
				}
			}
			else {
				Action("SetNarration(There is already an item in that position.)", true);
			}
		}
		else if (!hasItem) {
			Action("SetNarration(You do not have that item in your inventory.)", true);
		}
	}
	else if (action == "take") {
		positionOccupied = false;
		correctPosition = false;
		if (hasItem) {
			Action("SetNarration(" + itemname + " is already in your inventory.)", true);
		}
		else if (!hasItem) {
			Action("SetPosition(" + itemname + ")", true);
			inventory.push_back(itemname);
			Action("SetNarration(" + itemname + " Added To Inventory.)", true);
			hasItem = true;
		}
	}
	Action("ShowNarration()", true);
}

//This entire function may be outdated
void functions::PuzzleItem(string action, string itemname, string position, bool& positionOccupied, bool& hasItem, bool& correctPosition, vector<string>& inventory) {
	Action("HideDialog()", true);
	if (action == "place") {
		if (hasItem) {
			if (!positionOccupied) {
				Action("SetNarration(" + itemname + " Removed From Inventory)", true);
				RemoveItem(itemname, inventory);
				Action("SetPosition(" + itemname + ", CurrentLibrary.AlchemistTable." + position + ")", true);
				positionOccupied = true;
				hasItem = false;
				if ((itemname == "Library Apple" && position == "Left") || (itemname == "Library GoldCup" && position == "Center") || (itemname == "Library GreenKey" && position == "Right")) {
					correctPosition = true;
				}
			}
			else {
				Action("SetNarration(There is already an item in that position.)", true);
			}
		}
		else if (!hasItem) {
			Action("SetNarration(You do not have that item in your inventory.)", true);
		}
	}
	else if (action == "take") {
		positionOccupied = false;
		correctPosition = false;
		if (hasItem) {
			Action("SetNarration(" + itemname + " is already in your inventory.)", true);
		}
		else if (!hasItem) {
			Action("SetPosition(" + itemname + ")", true);
			inventory.push_back(itemname);
			Action("SetNarration(" + itemname + " Added To Inventory.)", true);
			hasItem = true;
		}
	}
	Action("ShowNarration()", true);
}