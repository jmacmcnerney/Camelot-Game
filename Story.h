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

extern vector<string> playerInv;

//location boolean
extern string currentLocation;

extern bool fileWritten;
extern bool cheatsEnabled;

//Intro Quest Booleans
//Cottage
extern bool hasStorybook;
//City
extern bool hasBrokenLock;
extern bool hasFixedLock;
extern bool hasAppleMoney;
extern bool hasElderApple;
extern bool visitedFortuneteller;
extern bool visitedTownElder;
extern bool completedErrand;
//Ruins
extern bool sword_taken;
extern bool spellbook_taken;
extern bool item_placed;

//Flashback Booleans
extern bool ArchieEnemy;
extern bool MathiasFlashback;
extern bool ArchieFlashback;

//Green Puzzle Booleans
//Potion
extern bool hasGreenPotion;
extern bool hasStorageBottle;
extern bool hasStorageBread;
extern bool hasStorageHelmet;
extern bool hasStorageInkAndQuill;
extern bool hasStorageBag;
extern bool storageBreadPositionCorrect;
extern bool storageBottlePositionCorrect;
extern bool storagePuzzleSolved;
//Book
extern bool hasGreenBook;
extern bool hasLibraryGoldCup;
extern bool hasLibraryApple;
extern bool hasLibraryGreenKey;
extern bool libraryApplePositionCorrect;
extern bool libraryGoldCupPositionCorrect;
extern bool libraryGreenKeyPositionCorrect;
extern bool libraryPuzzleSolved;

//Blue Puzzle Booleans
//Potion
extern bool hasBluePotion;
extern bool visitedDiningRoom;
//Book
extern bool hasBlueBook;
extern bool spokenWithMerchant;
extern bool hasStrangeElixir;
extern bool drankStangeElixir;
//extern bool spokenWithSailor;
extern bool canWorkForBlacksmith;
extern bool hasCompass;
extern bool hasRedPotion;
//Book
extern bool hasRedBook;
extern bool hasLitTorch;
extern bool torchUnpocketed;
extern bool boatOnFire;
extern bool merchantDistracted;
extern bool hasTranslatingGlass;
extern bool iconEnabled;
extern bool isChestOpened;

//Purple Puzzle Booleans
//Potion
extern bool hasPurplePotion;
//Book
extern bool hasPurpleBook;
extern bool hasLegofTwo;
extern bool hasCloth;
extern bool givenRiddle;

extern bool camptest;

extern bool hasFirstPrisItem;
extern bool hasSecondPrisItem;
extern bool hasThirdPrisItem;
extern bool firstPrisRiddle;
extern bool secondPrisRiddle;
extern bool thirdPrisRiddle;
extern bool firstTalkPris;

extern bool firstTalkGuard;
extern bool hasBedroomAnswer;
extern bool hasReadBedroomNote;
extern bool hasSearchedBedroomCloset;

extern bool BedroomSpot1Full;
extern bool BedroomSpot2Full;
extern bool BedroomSpot3Full;
extern bool BedroomSpot4Full;
extern bool BedroomSpot5Full;
extern bool BedroomSpot6Full;

extern bool BedroomSpot1Correct;
extern bool BedroomSpot2Correct;
extern bool BedroomSpot3Correct;
extern bool BedroomSpot4Correct;
extern bool BedroomSpot5Correct;
extern bool BedroomSpot6Correct;

extern bool BedroomPuzzleFin;

extern int numCoins;

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
	bool setupCamp2(string name);
	bool setupFinalRuins(string name);
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
	void runCurrentCamp2();
	void runFinalRuins();

	void flashback1();



	// interactions relevant to this chapter.
	vector<Icon> icons;

	Ruins currentRuins, pastRuins, finalRuins;
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
	Camp CurrentCamp, CurrentCamp2;
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