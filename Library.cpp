/* Project: CS395 Alpha Milestone
-- Project Description: An experimental experience manager for the Camelot Virtual Environment.
-- Authors: Jake Hayden, John Colfer, Mac McNerney, Zac Foster
-- File: Ruins.cpp
-- File Description:
--		A file that defines a class representing the ruins location in the game. Coincides with the
--		"Ruins" Place in Camelot, and contains data and code for what can occur in this location.
*/
#include "Library.h"
//#include "functions.cpp"

Library::Library() {}

//overloaded constructor for giving the location a Camelot name immediately
Library::Library(string name) {
	function.Action("CreatePlace(" + name + ", Library)", true);
}

//functions for enabling/disabling furniture
void Library::enableBookcase(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(Bookcase." + name + ")", true);
	}
	else
		function.Action("HideFurniture(Bookcase." + name + ")", true);

}
void Library::enableBookcase2(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(Bookcase2." + name + ")", true);
	}
	else
		function.Action("HideFurniture(Bookcase2." + name + ")", true);
}
void Library::enableBookcase3(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(Bookcase3." + name + ")", true);
	}
	else
		function.Action("HideFurniture(Bookcase3." + name + ")", true);
}
void Library::enableBookcase4(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(Bookcase4." + name + ")", true);
	}
	else
		function.Action("HideFurniture(Bookcase4." + name + ")", true);
}
void Library::enableTable(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(Table." + name + ")", true);
	}
	else
		function.Action("HideFurniture(Table." + name + ")", true);
}
void Library::enableChair(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(Chair." + name + ")", true);
	}
	else
		function.Action("HideFurniture(Chair." + name + ")", true);
}
void Library::enableAlchemistTable(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(AlchemistTable." + name + ")", true);
	}
	else
		function.Action("HideFurniture(AlchemistTable." + name + ")", true);
}
void Library::enableFireplace(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(Fireplace." + name + ")", true);
	}
	else
		function.Action("HideFurniture(Fireplace." + name + ")", true);
}
void Library::enableCauldron(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(Cauldron." + name + ")", true);
	}
	else
		function.Action("HideFurniture(Cauldron." + name + ")", true);
}
void Library::enableStand(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(Stand." + name + ")", true);
	}
	else
		function.Action("HideFurniture(Stand." + name + ")", true);
}
void Library::enableSpellbook(bool enabled) {
	if (enabled) {
		function.Action("ShowFurniture(Spellbook." + name + ")", true);
	}
	else
		function.Action("HideFurniture(Spellbook." + name + ")", true);
}