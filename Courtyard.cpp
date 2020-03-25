/* Project: CS395 Alpha Milestone
-- Project Description: An experimental experience manager for the Camelot Virtual Environment.
-- Authors: Jake Hayden, John Colfer, Mac McNerney, Zac Foster
-- File: Ruins.cpp
-- File Description:
--		A file that defines a class representing the ruins location in the game. Coincides with the
--		"Ruins" Place in Camelot, and contains data and code for what can occur in this location.
*/
#include "Courtyard.h"
//#include "functions.cpp"

Courtyard::Courtyard() {}

//overloaded constructor for giving the location a Camelot name immediately
Courtyard::Courtyard(string name) {
	function.Action("CreatePlace(" + name + ", Courtyard)", true);
}

//functions for enabling/disabling furniture
void Courtyard::enableFountain(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(Fountain." + name + ")", true);
	}
	else
		function.Action("HideFurniture(Fountain." + name + ")", true);

}
void Courtyard::enableBarrel(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(Barrel." + name + ")", true);
	}
	else
		function.Action("HideFurniture(Barrel." + name + ")", true);
}
void Courtyard::enableSmallStall(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(SmallStall." + name + ")", true);
	}
	else
		function.Action("HideFurniture(SmallStall." + name + ")", true);
}
void Courtyard::enableBigStall(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(BigStall." + name + ")", true);
	}
	else
		function.Action("HideFurniture(BigStall." + name + ")", true);
}
void Courtyard::enableHorse(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(Horse." + name + ")", true);
	}
	else
		function.Action("HideFurniture(Horse." + name + ")", true);
}
void Courtyard::enableTarget(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(Target." + name + ")", true);
	}
	else
		function.Action("HideFurniture(Target." + name + ")", true);
}
void Courtyard::enableRightBench(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(RightBench." + name + ")", true);
	}
	else
		function.Action("HideFurniture(RightBench." + name + ")", true);
}
void Courtyard::enableLeftBench(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(LeftBench." + name + ")", true);
	}
	else
		function.Action("HideFurniture(LeftBench." + name + ")", true);
}