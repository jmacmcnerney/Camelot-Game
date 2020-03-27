/* Project: Camelot Narrative Story + Experience Manager
-- Project Description: An experience manager for the Camelot Virtual Environment.
-- Authors: John (Mac) McNerney, Zac Foster, John Colfer, Jake Hayden
-- File: DiningRoom.h
-- File Description:
--		A file that describes a class representing the ruins location in the game. Coincides with the
--		"DiningRoom" Place in Camelot, and contains data and code for what can occur in this location.
*/
#pragma once
#include <vector>
#include <string>
#include "functions.h"

using namespace std;

class DiningRoom {
public:
	DiningRoom();
	DiningRoom(string name); //overloaded constructor for giving the location a Camelot name immediately

	//functions for enabling/disabling furniture
	void enableFireplace(bool enabled);
	void enableFrontLeftChair(bool enabled);
	void enableFrontRightChair(bool enabled);
	void enableRightChair(bool enabled);
	void enableBackRightChair(bool enabled);
	void enableBackLeftChair(bool enabled);
	void enableLeftChair(bool enabled);
	void enableDiningTable(bool enabled);
	void enableTable(bool enabled);
	void enableShelf(bool enabled);



	// name of the ruins place for Camelot's use
	string name;

	// icons relevant to this location only
	vector<Icon> icons;

	// names of all of the furniture
	string Fireplace, FrontLeftChair, FrontRightChair, RightChair, BackRightChair, BackLeftChair, LeftChair, DiningTable, Table, Shelf;

	// names of all the entrances
	string Door, BackDoor;

	// inventories for furniture in this place
	vector<string> chestInv;

	//accessing common function calls
	functions function;
};