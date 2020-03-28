/* Project: Camelot Narrative Story + Experience Manager
-- Project Description: An experience manager for the Camelot Virtual Environment.
-- Authors: John (Mac) McNerney, Zac Foster, John Colfer, Jake Hayden
-- File: Camp.h
-- File Description:
--		A file that describes a class representing the ruins location in the game. Coincides with the
--		"Camp" Place in Camelot, and contains data and code for what can occur in this location.
*/
#pragma once
#include <vector>
#include <string>
#include "functions.h"

using namespace std;

class Camp {
public:
	Camp();
	Camp(string name); //overloaded constructor for giving the location a Camelot name immediately

	//functions for enabling/disabling furniture
	void enablePlant(bool enabled);
	void enableBarrel(bool enabled);
	void enableStall(bool enabled);
	void enableChest(bool enabled);
	void enableLeftLog(bool enabled);
	void enableCauldron(bool enabled);
	void enableRoast(bool enabled);
	void enableFirepit(bool enabled);
	void enableLog(bool enabled);
	void enableRightLog(bool enabled);
	void enableHorse(bool enabled);

	// name of the ruins place for Camelot's use
	string name;

	// icons relevant to this location only
	vector<Icon> icons;

	// names of all of the furniture
	string Plant, Barrel, Stall, Chest, LeftLog, Cauldron, Roast, Firepit, Log, RightLog, Horse;

	// names of all the entrances
	string Exit;

	// inventories for furniture in this place
	vector<string> chestInv;

	//accessing common function calls
	functions function;
};