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

class Port {
public:
	Port();
	Port(string name); //overloaded constructor for giving the location a Camelot name immediately

	//functions for enabling/disabling furniture
	void enableBarrel(bool enabled);
	void enableSmallStall(bool enabled);
	void enableBarrel2(bool enabled);
	void enableBigStall(bool enabled);
	void enableSmallShip(bool enabled);
	void enableBigShip(bool enabled);


	// name of the ruins place for Camelot's use
	string name;

	// icons relevant to this location only
	vector<Icon> icons;

	// names of all of the furniture
	string Barrel, SmallStall, Barrel2, BigStall, SmallShip, BigShip;

	// names of all the entrances
	string Exit;

	// inventories for furniture in this place
	vector<string> chestInv;

	//accessing common function calls
	functions function;
};