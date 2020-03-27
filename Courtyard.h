/* Project: Camelot Narrative Story + Experience Manager
-- Project Description: An experience manager for the Camelot Virtual Environment.
-- Authors: John (Mac) McNerney, Zac Foster, John Colfer, Jake Hayden
-- File: Courtyard.h
-- File Description:
--		A file that describes a class representing the ruins location in the game. Coincides with the
--		"Courtyard" Place in Camelot, and contains data and code for what can occur in this location.
*/
#pragma once
#include <vector>
#include <string>
#include "functions.h"

using namespace std;

class Courtyard {
public:
	Courtyard();
	Courtyard(string name); //overloaded constructor for giving the location a Camelot name immediately

	//functions for enabling/disabling furniture
	void enableFountain(bool enabled);
	void enableBarrel(bool enabled);
	void enableSmallStall(bool enabled);
	void enableBigStall(bool enabled);
	void enableHorse(bool enabled);
	void enableTarget(bool enabled);
	void enableRightBench(bool enabled);
	void enableLeftBench(bool enabled);



	// name of the ruins place for Camelot's use
	string name;

	// icons relevant to this location only
	vector<Icon> icons;

	// names of all of the furniture
	string Fountain, Barrel, SmallStall, BigStall, Horse, Target, RightBench, LeftBench;

	// names of all the entrances
	string Gate, Exit;

	// inventories for furniture in this place
	vector<string> chestInv;

	//accessing common function calls
	functions function;
};