/* Project: CS395 Alpha Milestone
-- Project Description: An experimental experience manager for the Camelot Virtual Environment.
-- Authors: Jake Hayden, John Colfer, Mac McNerney, Zac Foster
-- File: Ruins.cpp
-- File Description:
--		A file that defines a class representing the ruins location in the game. Coincides with the
--		"Ruins" Place in Camelot, and contains data and code for what can occur in this location.
*/
#include "Storage.h"
//#include "functions.cpp"

Storage::Storage() {}

//overloaded constructor for giving the location a Camelot name immediately
Storage::Storage(string name) {
	function.Action("CreatePlace(" + name + ", Storage)", true);
}

//functions for enabling/disabling furniture
void Storage::enableBarrel(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(Barrel." + name + ")", true);
	}
	else
		function.Action("HideFurniture(Barrel." + name + ")", true);

}
void Storage::enableChest(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(Chest." + name + ")", true);
	}
	else
		function.Action("HideFurniture(Chest." + name + ")", true);
}
void Storage::enableShelf(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(Shelf." + name + ")", true);
	}
	else
		function.Action("HideFurniture(Shelf." + name + ")", true);
}