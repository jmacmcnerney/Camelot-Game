/* Project: CS395 Alpha Milestone
-- Project Description: An experimental experience manager for the Camelot Virtual Environment.
-- Authors: Jake Hayden, John Colfer, Mac McNerney, Zac Foster
-- File: Ruins.cpp
-- File Description:
--		A file that defines a class representing the ruins location in the game. Coincides with the
--		"Ruins" Place in Camelot, and contains data and code for what can occur in this location.
*/
#include "Hallway.h"
//#include "functions.cpp"

Hallway::Hallway() {}

//overloaded constructor for giving the location a Camelot name immediately
Hallway::Hallway(string name) {
	function.Action("CreatePlace(" + name + ", Hallway)", true);
}

//functions for enabling/disabling furniture