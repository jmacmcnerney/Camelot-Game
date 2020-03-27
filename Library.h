/* Project: Camelot Narrative Story + Experience Manager
-- Project Description: An experience manager for the Camelot Virtual Environment.
-- Authors: John (Mac) McNerney, Zac Foster, John Colfer, Jake Hayden
-- File: Library.h
-- File Description:
--		A file that describes a class representing the ruins location in the game. Coincides with the
--		"Library" Place in Camelot, and contains data and code for what can occur in this location.
*/
#pragma once
#include <vector>
#include <string>
#include "functions.h"

using namespace std;

class Library {
public:
	Library();
	Library(string name); //overloaded constructor for giving the location a Camelot name immediately

	//functions for enabling/disabling furniture
	void enableBookcase(bool enabled);
	void enableBookcase2(bool enabled);
	void enableBookcase3(bool enabled);
	void enableBookcase4(bool enabled);
	void enableTable(bool enabled);
	void enableChair(bool enabled);
	void enableAlchemistTable(bool enabled);
	void enableFireplace(bool enabled);
	void enableCauldron(bool enabled);
	void enableStand(bool enabled);
	void enableSpellbook(bool enabled);


	// name of the ruins place for Camelot's use
	string name;

	// icons relevant to this location only
	vector<Icon> icons;

	// names of all of the furniture
	string Bookcase, Bookcase2, Bookcase3, Bookcase4, Table, Chair, AlchemistTable, Fireplace, Cauldron, Stand, Spellbook;

	// names of all the entrances
	string Door;

	// inventories for furniture in this place
	vector<string> chestInv;

	//accessing common function calls
	functions function;
};