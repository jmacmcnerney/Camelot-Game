/* Project: CS395 Alpha Milestone
-- Project Description: An experimental experience manager for the Camelot Virtual Environment.
-- Authors: Jake Hayden, John Colfer, Mac McNerney, Zac Foster
-- File: Ruins.cpp
-- File Description:
--		A file that defines a class representing the ruins location in the game. Coincides with the
--		"Ruins" Place in Camelot, and contains data and code for what can occur in this location.
*/
#include "GreatHall.h"
//#include "functions.cpp"

GreatHall::GreatHall() {}

//overloaded constructor for giving the location a Camelot name immediately
GreatHall::GreatHall(string name) {
	function.Action("CreatePlace(" + name + ", GreatHall)", true);
}

//functions for enabling/disabling furniture
void GreatHall::enableLeftThrone(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(LeftThrone." + name + ")", true);
	}
	else
		function.Action("HideFurniture(LeftThrone." + name + ")", true);

}
void GreatHall::enableThrone(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(Throne." + name + ")", true);
	}
	else
		function.Action("HideFurniture(Throne." + name + ")", true);
}
void GreatHall::enableRightThrone(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(RightThrone." + name + ")", true);
	}
	else
		function.Action("HideFurniture(RightThrone." + name + ")", true);
}
void GreatHall::enableTable(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(Table." + name + ")", true);
	}
	else
		function.Action("HideFurniture(Table." + name + ")", true);
}