/* Project: CS395 Alpha Milestone
-- Project Description: An experimental experience manager for the Camelot Virtual Environment.
-- Authors: Jake Hayden, John Colfer, Mac McNerney, Zac Foster
-- File: Ruins.cpp
-- File Description:
--		A file that defines a class representing the ruins location in the game. Coincides with the
--		"Ruins" Place in Camelot, and contains data and code for what can occur in this location.
*/
#include "CastleBedroom.h"
//#include "functions.cpp"

CastleBedroom::CastleBedroom() {}

//overloaded constructor for giving the location a Camelot name immediately
CastleBedroom::CastleBedroom(string name) {
	function.Action("CreatePlace(" + name + ", CastleBedroom)", true);
}

//functions for enabling/disabling furniture
void CastleBedroom::enableChest(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(Chest." + name + ")", true);
	}
	else
		function.Action("HideFurniture(Chest." + name + ")", true);

}
void CastleBedroom::enableCouch(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(Couch." + name + ")", true);
	}
	else
		function.Action("HideFurniture(Couch." + name + ")", true);
}
void CastleBedroom::enableFireplace(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(Fireplace." + name + ")", true);
	}
	else
		function.Action("HideFurniture(Fireplace." + name + ")", true);
}
void CastleBedroom::enableTable(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(Table." + name + ")", true);
	}
	else
		function.Action("HideFurniture(Table." + name + ")", true);
}
void CastleBedroom::enableRightChair(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(RightChair." + name + ")", true);
	}
	else
		function.Action("HideFurniture(RightChair." + name + ")", true);
}
void CastleBedroom::enableLeftChair(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(LeftChair." + name + ")", true);
	}
	else
		function.Action("HideFurniture(LeftChair." + name + ")", true);
}
void CastleBedroom::enableSmallTable(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(SmallTable." + name + ")", true);
	}
	else
		function.Action("HideFurniture(SmallTable." + name + ")", true);
}
void CastleBedroom::enableBed(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(Bed." + name + ")", true);
	}
	else
		function.Action("HideFurniture(Bed." + name + ")", true);
}
void CastleBedroom::enableCloset(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(Closet." + name + ")", true);
	}
	else
		function.Action("HideFurniture(Closet." + name + ")", true);
}