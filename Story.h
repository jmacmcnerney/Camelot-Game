/* Project: Camelot Narrative Story + Experience Manager
-- Project Description: An experience manager for the Camelot Virtual Environment.
-- Authors: John (Mac) McNerney, Zac Foster, John Colfer, Jake Hayden
-- File: Chapter2.h
-- File Description: Manages all functions and location files for chapter2.cpp.
*/
#pragma once
#include <vector>
#include "icon.h"
#include "Ruins.h"
#include "Cottage.h"
#include "ForestPath.h"
#include "City.h"
#include "functions.h"
#include "Blacksmith.h"
#include "AlchemyShop.h"
#include "Courtyard.h"
#include "CastleBedroom.h"
#include "CastleCrossroads.h"
#include "Port.h"
#include "GreatHall.h"
#include "Library.h"
#include "Camp.h"
#include "Dungeon.h"
#include "Hallway.h"
#include "DiningRoom.h"
#include "Storage.h"


using namespace std;

class Story {
public:
	Story();
	~Story();
	bool runSetup(); // runs initial setup for chapter 2. returns true if setup was successful.
	void run(); // begins chapter 2's execution

	// location setup functions. return true if setup was successful.
	bool setupCurrentCottage(string name);
	bool setupCurrentTown(string name);
	bool setupBlacksmithFoundry(string name);
	bool setupAlchemyShop(string name);
	bool setupCurrentForestPath(string name);
	bool setupForestPath2(string name);
	bool setupCurrentRuins(string name);
	bool setupPastRuins(string name, bool Enemy);
	bool setupPastCottage(string name);
	bool setupPastForestPath(string name);
	bool setupPastCity(string name);
	bool setupCourtyard(string name);
	bool setupCastleBedroom(string name);
	bool setupCastleCrossroads(string name);
	bool setupPort(string name);
	bool setupGreatHall(string name);
	bool setupLibrary(string name);
	bool setupCamp(string name);
	bool setupDungeon(string name);
	bool setupLeftHallway(string name);
	bool setupRightHallway(string name);
	bool setupDiningRoom(string name);
	bool setupStorage(string name);

	// location execution functions.
	void runCurrentCottage();
	void runCurrentTown();
	void runBlacksmithFoundry();
	void runAlchemyShop();
	void runCurrentForestPath();
	void runCurrentRuins();
	void runPastRuins(bool CharacterCheck);
	void runPastForestPath(bool CharacterCheck);
	void runPastCottage(bool CharacterCheck);
	void runPastCity(bool CharacterCheck);
	void runForestPath2();
	void runCurrentCastleCrossroads();
	void runCurrentGreatHall();
	void runCurrentPort();
	void runCurrentLibrary();
	void runCurrentPrison();
	void runCurrentStorage();
	void runLeftHallway();
	void runRightHallway();
	void runCurrentDiningRoom();
	void runCurrentCourtyard();
	void runCurrentCastleBedroom();
	void runCurrentCamp();

	void flashback1();



	// interactions relevant to this chapter.
	vector<Icon> icons;

	Ruins currentRuins, pastRuins;
	Cottage currentCottage, pastCottage;
	Blacksmith BlacksmithFoundry;
	ForestPath currentForestPath, pastForestPath, ForestPath2;
	City currentCity, pastCity;
	AlchemyShop Alchemy;
	Courtyard CurrentCourtyard;
	CastleBedroom CurrentCastleBedroom;
	CastleCrossroads CurrentCastleCrossroads;
	Port CurrentPort;
	GreatHall CurrentGreatHall;
	Library CurrentLibrary;
	Camp CurrentCamp;
	Dungeon CurrentPrison;
	Hallway LeftHallway, RightHallway;
	DiningRoom CurrentDiningRoom;
	Storage CurrentStorage;




	// character inventories for this chapter (to be moved to a universal story class)
	//vector<string> playerInv;
	vector<string> mathiasInv;
	vector<string> archieInv;

	// conditionals relevant to this chapter.
	//bool inCurrentRuins;
	vector<bool> checks;

	// parser string for this chapter.
	string modified_I;

	//accessing common functions
	functions function;
};