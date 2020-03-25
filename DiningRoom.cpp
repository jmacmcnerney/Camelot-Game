/* Project: CS395 Alpha Milestone
-- Project Description: An experimental experience manager for the Camelot Virtual Environment.
-- Authors: Jake Hayden, John Colfer, Mac McNerney, Zac Foster
-- File: Ruins.cpp
-- File Description:
--		A file that defines a class representing the ruins location in the game. Coincides with the
--		"Ruins" Place in Camelot, and contains data and code for what can occur in this location.
*/
#include "DiningRoom.h"
//#include "functions.cpp"

DiningRoom::DiningRoom() {}

//overloaded constructor for giving the location a Camelot name immediately
DiningRoom::DiningRoom(string name) {
	function.Action("CreatePlace(" + name + ", DiningRoom)", true);
}

//functions for enabling/disabling furniture
void DiningRoom::enableFireplace(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(Fireplace." + name + ")", true);
	}
	else
		function.Action("HideFurniture(Fireplace." + name + ")", true);

}
void DiningRoom::enableFrontLeftChair(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(FrontLeftChair." + name + ")", true);
	}
	else
		function.Action("HideFurniture(FrontLeftChair." + name + ")", true);
}
void DiningRoom::enableFrontRightChair(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(FrontRightChair." + name + ")", true);
	}
	else
		function.Action("HideFurniture(FrontRightChair." + name + ")", true);
}
void DiningRoom::enableRightChair(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(RightChair." + name + ")", true);
	}
	else
		function.Action("HideFurniture(RightChair." + name + ")", true);
}
void DiningRoom::enableBackRightChair(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(BackRightChair." + name + ")", true);
	}
	else
		function.Action("HideFurniture(BackRightChair." + name + ")", true);
}
void DiningRoom::enableBackLeftChair(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(BackLeftChair." + name + ")", true);
	}
	else
		function.Action("HideFurniture(BackLeftChair." + name + ")", true);
}
void DiningRoom::enableLeftChair(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(LeftChair." + name + ")", true);
	}
	else
		function.Action("HideFurniture(LeftChair." + name + ")", true);
}
void DiningRoom::enableDiningTable(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(DiningTable." + name + ")", true);
	}
	else
		function.Action("HideFurniture(DiningTable." + name + ")", true);
}
void DiningRoom::enableTable(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(Table." + name + ")", true);
	}
	else
		function.Action("HideFurniture(Table." + name + ")", true);
}
void DiningRoom::enableShelf(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(Shelf." + name + ")", true);
	}
	else
		function.Action("HideFurniture(Shelf." + name + ")", true);
}