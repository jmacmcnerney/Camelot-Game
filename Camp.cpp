/* Project: CS395 Alpha Milestone
-- Project Description: An experimental experience manager for the Camelot Virtual Environment.
-- Authors: Jake Hayden, John Colfer, Mac McNerney, Zac Foster
-- File: Ruins.cpp
-- File Description:
--		A file that defines a class representing the ruins location in the game. Coincides with the
--		"Ruins" Place in Camelot, and contains data and code for what can occur in this location.
*/
#include "Camp.h"
//#include "functions.cpp"

Camp::Camp() {}

//overloaded constructor for giving the location a Camelot name immediately
Camp::Camp(string name) {
	function.Action("CreatePlace(" + name + ", Camp)", true);
}

//functions for enabling/disabling furniture
void Camp::enablePlant(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(Plant." + name + ")", true);
	}
	else
		function.Action("HideFurniture(Plant." + name + ")", true);

}
void Camp::enableBarrel(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(Barrel." + name + ")", true);
	}
	else
		function.Action("HideFurniture(Barrel." + name + ")", true);
}
void Camp::enableStall(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(Stall." + name + ")", true);
	}
	else
		function.Action("HideFurniture(Stall." + name + ")", true);
}
void Camp::enableChest(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(Chest." + name + ")", true);
	}
	else
		function.Action("HideFurniture(Chest." + name + ")", true);
}
void Camp::enableLeftLog(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(LeftLog." + name + ")", true);
	}
	else
		function.Action("HideFurniture(LeftLog." + name + ")", true);
}
void Camp::enableCauldron(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(Cauldron." + name + ")", true);
	}
	else
		function.Action("HideFurniture(Cauldron." + name + ")", true);
}
void Camp::enableRoast(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(Roast." + name + ")", true);
	}
	else
		function.Action("HideFurniture(Roast." + name + ")", true);
}
void Camp::enableFirepit(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(Firepit." + name + ")", true);
	}
	else
		function.Action("HideFurniture(Firepit." + name + ")", true);
}
void Camp::enableLog(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(Log." + name + ")", true);
	}
	else
		function.Action("HideFurniture(Log." + name + ")", true);
}
void Camp::enableRightLog(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(RightLog." + name + ")", true);
	}
	else
		function.Action("HideFurniture(RightLog." + name + ")", true);
}
void Camp::enableHorse(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(Horse." + name + ")", true);
	}
	else
		function.Action("HideFurniture(Horse." + name + ")", true);
}