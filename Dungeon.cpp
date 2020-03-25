/* Project: CS395 Alpha Milestone
-- Project Description: An experimental experience manager for the Camelot Virtual Environment.
-- Authors: Jake Hayden, John Colfer, Mac McNerney, Zac Foster
-- File: Ruins.cpp
-- File Description:
--		A file that defines a class representing the ruins location in the game. Coincides with the
--		"Ruins" Place in Camelot, and contains data and code for what can occur in this location.
*/
#include "Dungeon.h"
//#include "functions.cpp"

Dungeon::Dungeon() {}

//overloaded constructor for giving the location a Camelot name immediately
Dungeon::Dungeon(string name) {
	function.Action("CreatePlace(" + name + ", Dungeon)", true);
}

//functions for enabling/disabling furniture
void Dungeon::enableChest(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(Chest." + name + ")", true);
	}
	else
		function.Action("HideFurniture(Chest." + name + ")", true);

}
void Dungeon::enableTable(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(Table." + name + ")", true);
	}
	else
		function.Action("HideFurniture(Table." + name + ")", true);
}
void Dungeon::enableChair(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(Chair." + name + ")", true);
	}
	else
		function.Action("HideFurniture(Chair." + name + ")", true);
}
void Dungeon::enableBookshelf(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(Bookshelf." + name + ")", true);
	}
	else
		function.Action("HideFurniture(Bookshelf." + name + ")", true);
}
void Dungeon::enableCellDoor(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(CellDoor." + name + ")", true);
	}
	else
		function.Action("HideFurniture(CellDoor." + name + ")", true);
}
void Dungeon::enableRoundTable(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(RoundTable." + name + ")", true);
	}
	else
		function.Action("HideFurniture(RoundTable." + name + ")", true);
}
void Dungeon::enableDirtPile(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(DirtPile." + name + ")", true);
	}
	else
		function.Action("HideFurniture(DirtPile." + name + ")", true);
}
void Dungeon::enableBed(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(Bed." + name + ")", true);
	}
	else
		function.Action("HideFurniture(Bed." + name + ")", true);
}