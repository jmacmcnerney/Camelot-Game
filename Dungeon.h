/* Project: CS395 Alpha Milestone
-- Project Description: An experimental experience manager for the Camelot Virtual Environment.
-- Authors: Jake Hayden, John Colfer, Mac McNerney, Zac Foster
-- File: Ruins.h
-- File Description:
--		A file that describes a class representing the ruins location in the game. Coincides with the
--		"Ruins" Place in Camelot, and contains data and code for what can occur in this location.
*/
#pragma once
#include <vector>
#include <string>
#include "functions.h"

using namespace std;

class Dungeon {
public:
	Dungeon();
	Dungeon(string name); //overloaded constructor for giving the location a Camelot name immediately

	//functions for enabling/disabling furniture
	void enableChest(bool enabled);
	void enableTable(bool enabled);
	void enableChair(bool enabled);
	void enableBookshelf(bool enabled);
	void enableCellDoor(bool enabled);
	void enableRoundTable(bool enabled);
	void enableDirtPile(bool enabled);
	void enableBed(bool enabled);


	// name of the ruins place for Camelot's use
	string name;

	// icons relevant to this location only
	vector<Icon> icons;

	// names of all of the furniture
	string Chest, Table, Chair, Bookshelf, CellDoor, RoundTable, DirtPile, Bed;

	// names of all the entrances
	string Door;

	// inventories for furniture in this place
	vector<string> chestInv;

	//accessing common function calls
	functions function;
};