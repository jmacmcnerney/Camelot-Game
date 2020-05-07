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
#include "Story.h"
#include <fstream>

using namespace std;

ofstream myfile;

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
			//myfile.open("log.txt");
			StartOption(playerName);
			Action("EnableInput()", true);
		}
		else if (modifiedInput == "Resume") {
			Action("HideMenu()", true);
			Action("EnableInput()", true);
			Action("EnableInput()", true);
		}
		else if (modifiedInput == "Credits") {
			Action("SetNarration(\"Created by Mac McNerney, Zac Foster, Jake Hayden and John Colfer using Steven G Ware's Camelot Virtual Environment\"", true);
			Action("ShowNarration()", true);
		}
		else if (modifiedInput == "Quit") {
			//myfile.close();
			Action("Quit()", true);
		}
		else if (modifiedInput == "end") {
			Action("HideDialog()", true);
		}

		else if (modifiedInput == "teleportCheats") {
			//function.Action("FadeOut()", true);
			Action("ClearDialog()", true);
			Action("SetDialog(Where?\\n[teleportToArlanCottage|Arlan Cottage]\\n[teleportToCurrentTown|Current Town]\\n[teleportToBlacksmithFoundry|Blacksmith Foundry]\\n[teleportToAlchemyShop|Alchemy Shop]\\n[teleportToCurrentForestPath|Current Forest Path]\\n[teleportToCurrentRuins|Current Ruins]\\n[teleportToPastCottage|Past Cottage]\\n[teleportToPastCity|Past City]\\n[teleportToPastForestPath|Past Forest Path]\\n[teleportToPastRuins|Past Ruins]\\n[teleportToForestPath2|Forest Path 2]\\n[teleportToCurrentCastleCrossroads|Current Castle Crossroads]\\n[teleportToCurrentPort|Current Port]\\n[teleportToCurrentGreatHall|Current Great Hall]\\n[teleportToCurrentStorage|Current Storage]\\n[teleportToRightHallway|Right Hallway]\\n[teleportToCurrentLibrary|Current Library]\\n[teleportToCurrentCastleBedroom|Current Castle Bedroom]\\n[teleportToLeftHallway|Left Hallway]\\n[teleportToCurrentDiningRoom|Current Dining Room]\\n[teleportToCurrentPrison|Current Prison]\\n[teleportToCurrentCourtyard|Current Courtyard]\\n[end|Exit Menu])", true);
		}

		else if (modifiedInput == "teleportToArlanCottage") { Action("HideDialog()", true); Action("SetPosition(Arlan, ArlanCottage)", true); currentLocation = "ArlanCottage"; }
		else if (modifiedInput == "teleportToCurrentTown") { Action("HideDialog()", true); Action("SetPosition(Arlan, CurrentTown)", true); currentLocation = "CurrentTown"; }
		else if (modifiedInput == "teleportToAlchemyShop") { Action("HideDialog()", true); Action("SetPosition(Arlan, AlchemyShop)", true); currentLocation = "AlchemyShop"; }
		else if (modifiedInput == "teleportToCurrentForestPath") { Action("HideDialog()", true); Action("SetPosition(Arlan, CurrentForestPath)", true); currentLocation = "CurrentForestPath"; }
		else if (modifiedInput == "teleportToCurrentRuins") { Action("HideDialog()", true); Action("SetPosition(Arlan, CurrentRuins)", true); currentLocation = "CurrentRuins"; }
		else if (modifiedInput == "teleportToPastCottage") { Action("HideDialog()", true); Action("SetPosition(Arlan, PastCottage)", true); currentLocation = "PastCottage"; }
		else if (modifiedInput == "teleportToPastCity") { Action("HideDialog()", true); Action("SetPosition(Arlan, PastCity)", true); currentLocation = "PastCity"; }
		else if (modifiedInput == "teleportToPastForestPath") { Action("HideDialog()", true); Action("SetPosition(Arlan, PastForestPath)", true); currentLocation = "PastForestPath"; }
		else if (modifiedInput == "teleportToPastRuins") { Action("HideDialog()", true); Action("SetPosition(Arlan, PastRuins)", true); currentLocation = "PastRuins"; }
		else if (modifiedInput == "teleportToForestPath2") { Action("HideDialog()", true); Action("SetPosition(Arlan, ForestPath2)", true); currentLocation = "ForestPath2"; }
		else if (modifiedInput == "teleportToCurrentCastleCrossroads") { Action("HideDialog()", true); Action("SetPosition(Arlan, CurrentCastleCrossroads)", true); currentLocation = "CurrentCastleCrossroads"; }
		else if (modifiedInput == "teleportToCurrentPort") { Action("HideDialog()", true); Action("SetPosition(Arlan, CurrentPort)", true); currentLocation = "CurrentPort"; }
		else if (modifiedInput == "teleportToCurrentGreatHall") { Action("HideDialog()", true); Action("SetPosition(Arlan, CurrentGreatHall)", true); currentLocation = "CurrentGreatHall"; }
		else if (modifiedInput == "teleportToCurrentStorage") { Action("HideDialog()", true); Action("SetPosition(Arlan, CurrentStorage)", true); currentLocation = "CurrentStorage"; }
		else if (modifiedInput == "teleportToRightHallway") { Action("HideDialog()", true); Action("SetPosition(Arlan, RightHallway)", true); currentLocation = "RightHallway"; }
		else if (modifiedInput == "teleportToCurrentLibrary") { Action("HideDialog()", true); Action("SetPosition(Arlan, CurrentLibrary)", true); currentLocation = "CurrentLibrary"; }
		else if (modifiedInput == "teleportToCurrentCastleBedroom") { Action("HideDialog()", true); Action("SetPosition(Arlan, CurrentCastleBedroom)", true); currentLocation = "CurrentCastleBedroom"; }
		else if (modifiedInput == "teleportToLeftHallway") { Action("HideDialog()", true); Action("SetPosition(Arlan, LeftHallway)", true); currentLocation = "LeftHallway"; }
		else if (modifiedInput == "teleportToCurrentDiningRoom") { Action("HideDialog()", true); Action("SetPosition(Arlan, CurrentDiningRoom)", true); currentLocation = "CurrentDiningRoom"; }
		else if (modifiedInput == "teleportToCurrentPrison") { Action("HideDialog()", true); Action("SetPosition(Arlan, CurrentPrison)", true); currentLocation = "CurrentPrison"; }
		else if (modifiedInput == "teleportToCurrentCourtyard") { Action("HideDialog()", true); Action("SetPosition(Arlan, CurrentCourtyard)", true); currentLocation = "CurrentCourtyard"; }

		else if (modifiedInput == "itemCheats") {
			Action("ClearDialog()", true);
			Action("SetDialog(Which Item?\\n[addStorybookCheat|Storybook]\\n[addBrokenLockCheat|BrokenLock]\\n[addFixedLockCheat|FixedLock]\\n[addAppleMoneyCheat|AppleMoney]\\n[addElderAppleCheat|ElderApple]\\n[addMathiasSwordCheat|MathiasSword]\\n[addArchieSpellbookCheat|ArchieSpellbook]\\n[addGreenPotionCheat|GreenPotion]\\n[addStorageBottleCheat|StorageBottle]\\n[addStorageBreadCheat|StorageBread]\\n[addStorageHelmetCheat|StorageHelmet]\\n[addStorageInkAndQuillCheat|StorageInkAndQuill]\\n[addStorageBagCheat|StorageBag]\\n[addGreenBookCheat|GreenBook]\\n[addLibraryGoldCupCheat|LibraryGoldCup]\\n[addLibraryAppleCheat|LibraryApple]\\n[addLibraryGreenKeyCheat|LibraryGreenKey]\\n[addBluePotionCheat|BluePotion]\\n[addBlueBookCheat|BlueBook]\\n[addRedPotionCheat|RedPotion]\\n[addRedBookCheat|RedBook]\\n[addPurplePotionCheat|PurplePotion]\\n[addPurpleBookCheat|PurpleBook]\\n[end|Exit])", true);
		}

		else if (modifiedInput == "addStorybookCheat") { ItemCheats("Storybook", hasStorybook); }
		else if (modifiedInput == "addBrokenLockCheat") { ItemCheats("Broken Lock", hasBrokenLock); }
		else if (modifiedInput == "addFixedLockCheat") { ItemCheats("Fixed Lock", hasFixedLock); }
		else if (modifiedInput == "addAppleMoneyCheat") { ItemCheats("Apple Money", hasAppleMoney); }
		else if (modifiedInput == "addElderAppleCheat") { ItemCheats("Elder Apple", hasElderApple); }
		else if (modifiedInput == "addMathiasSwordCheat") { ItemCheats("MathiasSword", sword_taken); }
		else if (modifiedInput == "addArchieSpellbookCheat") { ItemCheats("ArchieSpellbook", spellbook_taken); }
		else if (modifiedInput == "addGreenPotionCheat") { ItemCheats("Potion Of Cleansing", hasGreenPotion); }
		else if (modifiedInput == "addStorageBottleCheat") { ItemCheats("Storage Bottle", hasStorageBottle); }
		else if (modifiedInput == "addStorageBreadCheat") { ItemCheats("Storage Bread", hasStorageBread); }
		else if (modifiedInput == "addStorageHelmetCheat") { ItemCheats("Storage Helmet", hasStorageHelmet); }
		else if (modifiedInput == "addStorageInkAndQuillCheat") { ItemCheats("Storage InkAndQuill", hasStorageInkAndQuill); }
		else if (modifiedInput == "addStorageBagCheat") { ItemCheats("Storage Bag", hasStorageBag); }
		else if (modifiedInput == "addGreenBookCheat") { ItemCheats("Book Of Incantations", hasGreenBook); }
		else if (modifiedInput == "addLibraryGoldCupCheat") { ItemCheats("Library GoldCup", hasLibraryGoldCup); }
		else if (modifiedInput == "addLibraryAppleCheat") { ItemCheats("Library Apple", hasLibraryApple); }
		else if (modifiedInput == "addLibraryGreenKeyCheat") { ItemCheats("Library GreenKey", hasLibraryGreenKey); }
		//else if (i == "addBluePotionCheat") { ItemCheats("BluePotion", hasBluePotion); }
		//else if (i == "addBlueBookCheat") { ItemCheats("BlueBook", hasBlueBook); }
		//else if (i == "addRedPotionCheat") { ItemCheats("RedPotion", hasRedPotion); }
		//else if (i == "addRedBookCheat") { ItemCheats("Translated Book", hasRedBook); }
		//else if (i == "addPurplePotionCheat") { ItemCheats("Potion of Healing", hasPurplePotion); }
		//else if (i == "addPurpleBookCheat") { ItemCheats("Book of Tactics", hasPurplebook); }

		else if (modifiedInput == "booleanCheats") {
			Action("ClearDialog()", true);
			Action("SetDialog(Pick One.\\n[visitedFortunetellerBoolCheat|visitedFortuneteller]\\n[visitedTownElderBoolCheat|visitedTownElder]\\n[completedErrandBoolCheat|completedErrand]\\n[itemPlacedBoolCheat|itemPlaced]\\n[ArchieEnemyBoolCheat|ArchieEnemy]\\n[MathiasFlashbackBoolCheat|MathiasFlashback]\\n[ArchieFlashbackBoolCheat|ArchieFlashback]\\n[end|Exit])", true);
		}

		else if (modifiedInput == "visitedFortunetellerBoolCheat") { visitedFortuneteller = true; }
		else if (modifiedInput == "visitedTownElderBoolCheat") { visitedTownElder = true; }
		else if (modifiedInput == "completedErrandBoolCheat") { completedErrand = true; }
		else if (modifiedInput == "itemPlacedBoolCheat") { item_placed = true; }
		else if (modifiedInput == "ArchieEnemyBoolCheat") { ArchieEnemy = true; }
		else if (modifiedInput == "MathiasFlashbackBoolCheat") { MathiasFlashback = true; }
		else if (modifiedInput == "ArchieFlashbackBoolCheat") { ArchieFlashback = true; }

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

	else if (modifiedInput == "Inspect") {
		modifiedInput = splitInput(input, 0, true);
		if (modifiedInput == "PotionOfPower") {
			Action("SetNarration(There is still quite a bit of the potion left. You feel like you should probably save it just in case.)", true);
			Action("ShowNarration()", true);
		}
		else keywordFound = false;
	}

	else if (modifiedInput == "ReadBookOfLore") {
		modifiedInput = splitInput(input, 0, true);
		if (modifiedInput == "BookOfLore") {
			Action("HideList()", true);
			Action("ClearList()", true);
			Action("SetNarration(The book describes an ancient tome that instills its owner with unimaginable power. Those who posess it are said to be destined to rule to world.)", true);
			Action("ShowNarration()", true);
		}
	}

	/*-------------------CHEATS-------------------*/
	else if (modifiedInput == "accessCheatMenu") {
			//function.Action("ClearDialog()", true);
			//function.Action("SetDialog(Category\\n[teleportCheats|Teleport Cheats]\\n[itemCheats][Item Cheats])", true);
			Action("HideList()", true);
			SetupDialogText("Category", "teleportCheats", "Teleport Cheats", "itemCheats", "Item Cheats", "booleanCheats", "Boolean Cheats");
			Action("ShowDialog()", true);
	}
	/*-------------------CHEATS-------------------*/
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
	Action("DisableInput()", true);
	Action("Exit(" + character + ", " + exit + ", true)", true);
	Action("Enter(" + character + ", " + entrance + ", true)", true);
	Action("EnableInput()", true);
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

/*void functions::LibraryItem(string action, string itemname, string position, bool &positionOccupied, bool &hasItem, bool &correctPosition, vector<string> &inventory) {
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
}*/

void functions::ItemCheats(string itemname, bool &hasItem) {
	if (!hasItem) {
		playerInv.push_back(itemname);
		hasItem = true;
	}
	else if (hasItem) {
		RemoveItem(itemname, playerInv);
		hasItem = false;
	}
}

void functions::ItemHandler(string itemname, string action, string position, string location, vector<string>& inventory, bool& inventoryErrorCheck, string& onLeft, string& onRight, string& onCenter, bool& correctLeft, bool& correctRight, bool& correctCenter) {
	bool puzzleItemsInInv = false;
	int substrCounter = 0;
	string substrWord, placementLocation, leftItem, rightItem, centerItem = "";
	//if (location == "BobsHouse") { substrWord = "Shelf"; substrCounter = substrWord.length(); placementLocation = "Shelf"; }
	if (location == "CurrentLibrary") { substrWord = "Library"; substrCounter = substrWord.length(); placementLocation = "AlchemistTable"; leftItem = "Library Apple"; rightItem = "Library GreenKey"; centerItem = "Library GoldCup"; }
	if (location == "CurrentStorage") { substrWord = "Storage"; substrCounter = substrWord.length(); placementLocation = "Shelf"; leftItem = "Storage Bread"; rightItem = "Storage Bottle"; }
	if (action == "ShowPlaceInventory") {
		if (((onLeft == "") && (position == "Left")) || ((onRight == "") && (position == "Right")) || ((onCenter == "") && (position == "Center"))) {
			Action("ClearList()", true);
			for (string item : inventory) {
				if (item.substr(0, substrCounter) == substrWord) {
					if (!inventoryErrorCheck) { Action("DisableIcon(PlaceItem, " + item + ")", true); }
					Action("AddToList(" + item + ")", true);
					Action("EnableIcon(PlaceItem, Hand, " + item + ", Place, true)", true);
					puzzleItemsInInv = true;
				}
			}
			Action("ShowList(Arlan)", true);
			if (puzzleItemsInInv) { inventoryErrorCheck = false; }
		}
		else {
			Action("SetNarration(Space Occupied)", true);
			Action("ShowNarration()", true);
		}
	}
	else if (action == "PlaceItem") {
		for (string item : inventory) {
			if (item.substr(0, substrCounter) == substrWord) {
				Action("DisableIcon(PlaceItem, " + item + ")", true);
			}
		}
		inventoryErrorCheck = true;
		Action("HideList()", true);
		Action("ClearList()", true);
		RemoveItem(itemname, inventory);
		//Action("SetPosition(" + itemname + ", " + location + "." + placementLocation + "." + position + ")", true);
		Action("Put(Arlan, " + itemname + ", " + location + "." + placementLocation + "." + position + ")", true);
		Action("EnableIcon(PickUp, Hand, " + itemname + ", Pick Up, true)", true);
		if (position == "Left") { 
			onLeft = itemname;
			if (itemname == leftItem) { correctLeft = true; }
		}
		if (position == "Right") { 
			onRight = itemname;
			if (itemname == rightItem) { correctRight = true; }
		}
		if (position == "Center") { 
			onCenter = itemname; 
			if (itemname == centerItem) { correctCenter = true; }
		}
	}
	else if (action == "PickUp") {
		Action("Take(Arlan, " + itemname + ", " + location + "." + placementLocation + "." + position + ")", true);
		Action("Pocket(Arlan, " + itemname + ")", true);
		//Action("SetPosition(" + itemname + ")", true);
		inventory.push_back(itemname);
		Action("DisableIcon(PickUp, " + itemname + ")", true);
		if (onLeft == itemname) { onLeft = ""; correctLeft = false; }
		if (onRight == itemname) { onRight = ""; correctRight = false; }
		if (onCenter == itemname) { onCenter = ""; correctCenter = false; }
	}
}

void functions::MusicHandler(string musicName, string location, bool& musicPlaying) {
	/*if (action == "Play") {
		if (musicPlaying) {
			Action("StopSound()", true);
			musicPlaying = false;
		}
		Action("PlaySound(" + musicName + ", " + location + ", true)", true);
		musicPlaying = true;
	}
	else if (action == "Stop") {
		if (!musicPlaying) {
			return;
		}
		Action("StopSound(" + musicName + ", " + location + ")", true);
		musicPlaying = false;
	}*/
	if (musicPlaying) {
		Action("StopSound()", true);
		musicPlaying = false;
	}
	Action("PlaySound(" + musicName + ", " + location + ", true)", true);
	musicPlaying = true;
}