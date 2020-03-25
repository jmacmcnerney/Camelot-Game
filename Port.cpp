/* Project: CS395 Alpha Milestone
-- Project Description: An experimental experience manager for the Camelot Virtual Environment.
-- Authors: Jake Hayden, John Colfer, Mac McNerney, Zac Foster
-- File: Ruins.cpp
-- File Description:
--		A file that defines a class representing the ruins location in the game. Coincides with the
--		"Ruins" Place in Camelot, and contains data and code for what can occur in this location.
*/
#include "Port.h"
//#include "functions.cpp"

Port::Port() {}

//overloaded constructor for giving the location a Camelot name immediately
Port::Port(string name) {
	function.Action("CreatePlace(" + name + ", Port)", true);
}

//functions for enabling/disabling furniture
void Port::enableBarrel(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(Barrel." + name + ")", true);
	}
	else
		function.Action("HideFurniture(Barrel." + name + ")", true);

}
void Port::enableSmallStall(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(SmallStall." + name + ")", true);
	}
	else
		function.Action("HideFurniture(SmallStall." + name + ")", true);
}
void Port::enableBarrel2(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(Barrel2." + name + ")", true);
	}
	else
		function.Action("HideFurniture(Barrel2." + name + ")", true);
}
void Port::enableBigStall(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(BigStall." + name + ")", true);
	}
	else
		function.Action("HideFurniture(BigStall." + name + ")", true);
}
void Port::enableSmallShip(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(SmallShip." + name + ")", true);
	}
	else
		function.Action("HideFurniture(SmallShip." + name + ")", true);
}
void Port::enableBigShip(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(BigShip." + name + ")", true);
	}
	else
		function.Action("HideFurniture(BigShip." + name + ")", true);
}