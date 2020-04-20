/* Project: Camelot Narrative Story + Experience Manager
-- Project Description: An experience manager for the Camelot Virtual Environment.
-- Authors: John (Mac) McNerney, Zac Foster, John Colfer, Jake Hayden
-- File: Chapter2.cpp
-- File Description: Chapter 2 execution.
*/
#include "Chapter2.h"
#include <chrono>
#include <thread>
#include <vector>
#include <string>
using namespace std;

vector<string> playerInv;

//location boolean
string currentLocation = "ArlanCottage";

//event booleans
bool item_placed = false;
bool sword_taken = false;
bool spellbook_taken = false;
bool hasStorybook = false;
bool hasBrokenLock = false;
bool hasFixedLock = false;
bool hasAppleMoney = false;
bool hasElderApple = false;
bool visitedFortuneteller = false;
bool visitedTownElder = false;
bool completedErrand = false;
bool ArchieEnemy = false;
bool MathiasFlashback = false;
bool ArchieFlashback = false;
bool hasGreenPotion = true;
bool hasStorageBottle = false;
bool hasStorageBread = false;
bool hasStorageHelmet = false;
bool hasStorageInkAndQuill = false;
bool hasStorageBag = false;
bool storageBreadPositionCorrect = false;
bool storageBottlePositionCorrect = false;
bool storagePuzzleSolved = false;
bool hasGreenBook = true;
bool hasLibraryGoldCup = false;
bool hasLibraryApple = false;
bool hasLibraryGreenKey = false;
bool libraryApplePositionCorrect = false;
bool libraryGoldCupPositionCorrect = false;
bool libraryGreenKeyPositionCorrect = false;
bool libraryPuzzleSolved = false;
bool hasBluePotion = false;
bool hasBlueBook = false;
bool visitedDiningRoom = false;
bool canWorkForBlacksmith = false;
bool hasCompass = false;
bool hasRedPotion = false;
bool hasRedBook = false;
bool hasPurplePotion = false;
bool hasPurpleBook = false;

bool camptest = true;

bool hasFirstPrisItem = false;
bool hasSecondPrisItem = false;
bool hasThirdPrisItem = false;
bool firstPrisRiddle = false;
bool secondPrisRiddle = false;
bool thirdPrisRiddle = false;
bool firstTalkPris = true;

bool firstTalkGuard = true;
bool hasBedroomAnswer = false;
bool hasReadBedroomNote = false;
bool hasSearchedBedroomCloset = false;

int numCoins = 0;

Chapter2::Chapter2() {
	runSetup();
	//function.Action("SetPosition(Arlan, CurrentPrison.Chest)", true);
	run();
}

Chapter2::~Chapter2() {
}

bool Chapter2::runSetup() { // runs initial setup for chapter 2. returns true if setup was successful.
	//location setup calls
	setupCurrentCottage("ArlanCottage");
	setupCurrentTown("CurrentTown");
	setupBlacksmithFoundry("BlacksmithFoundry");
	setupCurrentForestPath("CurrentForestPath");
	setupForestPath2("ForestPath2");
	setupCurrentRuins("CurrentRuins");
	//delete this
	setupPastRuins("PastRuins", ArchieEnemy);
	setupPastCottage("PastCottage");
	setupPastForestPath("PastForestPath");
	setupPastCity("PastCity");
	setupAlchemyShop("AlchemyShop");
	setupCourtyard("CurrentCourtyard");
	setupCastleBedroom("CurrentCastleBedroom");
	setupCastleCrossroads("CurrentCastleCrossroads");
	setupPort("CurrentPort");
	setupGreatHall("CurrentGreatHall");
	setupLibrary("CurrentLibrary");
	setupCamp("CurrentCamp");
	setupCamp2("CurrentCamp2");
	setupFinalRuins("FinalRuins");
	setupDungeon("CurrentPrison");
	setupLeftHallway("LeftHallway");
	setupRightHallway("RightHallway");
	setupDiningRoom("CurrentDiningRoom");
	setupStorage("CurrentStorage");
	function.Action("ShowMenu()", true);

	return true;
}

void Chapter2::run() { // begins chapter 2's execution
	while (true) {
		if (currentLocation == "ArlanCottage") {
			runCurrentCottage();
		}
		else if (currentLocation == "CurrentTown"){
			runCurrentTown();
		}
		else if (currentLocation == "BlacksmithFoundry") {
			runBlacksmithFoundry();
		}
		else if (currentLocation == "AlchemyShop") {
			runAlchemyShop();
		}
		else if (currentLocation == "CurrentForestPath") {
			runCurrentForestPath();
		}
		else if (currentLocation == "CurrentRuins") {
			runCurrentRuins();
		}
		else if (currentLocation == "PastRuins") {
			runPastRuins(ArchieEnemy);
		}
		else if (currentLocation == "PastForestPath") {
			runPastForestPath(ArchieEnemy);
		}
		else if (currentLocation == "PastCottage") {
			runPastCottage(ArchieEnemy);
		}
		else if (currentLocation == "PastCity") {
			runPastCity(ArchieEnemy);
		}
		else if (currentLocation == "ForestPath2") {
			runForestPath2();
		}
		else if (currentLocation == "CurrentCastleCrossroads") {
			runCurrentCastleCrossroads();
		}
		else if (currentLocation == "CurrentPort") {
			runCurrentPort();
		}
		else if (currentLocation == "CurrentGreatHall") {
			runCurrentGreatHall();
		}
		else if (currentLocation == "CurrentStorage") {
			runCurrentStorage();
		}
		else if (currentLocation == "RightHallway") {
			runRightHallway();
		}
		else if (currentLocation == "CurrentLibrary") {
			runCurrentLibrary();
		}
		else if (currentLocation == "CurrentCastleBedroom") {
			runCurrentCastleBedroom();
		}
		else if (currentLocation == "LeftHallway") {
			runLeftHallway();
		}
		else if (currentLocation == "CurrentDiningRoom") {
			runCurrentDiningRoom();
		}
		else if (currentLocation == "CurrentPrison") {
			runCurrentPrison();
		}
		else if (currentLocation == "CurrentCourtyard") {
			runCurrentCourtyard();
		}
		else if (currentLocation == "CurrentCamp") {
			runCurrentCamp();
		}
		else if (currentLocation == "CurrentCamp2") {
			runCurrentCamp2();
		}
		else if (currentLocation == "FinalRuins") {
			runFinalRuins();
		}
	}
}

//Flashback execution function
void Chapter2::flashback1() {
	//flashback transistion
	function.Action("WalkTo(Arlan, CurrentRuins.Altar)", true);
	function.Action("SetCameraMode(Focus)", true);
	function.Action("SetNarration(The air around you feels wierd. Something pulls you to a slumber.)", true);
	function.Action("ShowNarration()", true);
	bool inNarration = true;
	while (inNarration) {
		string i;
		getline(cin, i);

		if (i == "input Close Narration") {
			function.Action("HideNarration()", true);
			inNarration = false;
		}
	}
	function.Action("HideNarration()", true);
	function.Action("SetExpression(Arlan, Surprised)", true);
	this_thread::sleep_for(chrono::milliseconds(500));
	function.Action("SetCameraMode(Follow)", true);
	function.Action("Die(Arlan)", true);
	function.Action("FadeOut()", true);
	currentLocation = "PastCottage";
	//runPastCottage(ArchieEnemy);
}

// location setup functions. return true if setup was successful.
bool Chapter2::setupCurrentCottage(string name) {
	currentCottage = Cottage(name);

	//character setup
	function.SetupCharacter("Arlan", "B", "LightArmour", "Long", "Brown", "ArlanCottage.Bed");
	function.SetupCharacter("Dad", "B", "Peasant", "Spiky", "Black", "ArlanCottage.Bookshelf");

	//item and placement
	function.Action("CreateItem(Storybook, BlueBook)", true);

	//icon setup
	currentCottage.icons.push_back(Icon("Talk_To_Dad", "Talk", "Dad", "Talk to Dad", "true"));
	currentCottage.icons.push_back(Icon("Open_Door", "Open", "ArlanCottage.Door", "Exit the Cottage", "true"));
	function.SetupIcons(currentCottage.icons);
	return true;
}

bool Chapter2::setupCurrentTown(string name) {
	currentCity = City(name);

	//character setup
	function.SetupCharacter("Apple Merchant", "C", "Merchant", "Long", "Blonde", "CurrentTown.Horse");
	function.SetupCharacter("Town Elder", "H", "Noble", "Musketeer_Full", "Gray", "CurrentTown.Plant");

	//items
	function.Action("CreateItem(MathiasSword, Sword)", true);
	function.Action("CreateItem(Apple Money, Coin)", true);
	function.Action("CreateItem(Elder Apple, Apple)", true);
	function.Action("CreateItem(Broken Lock, Lock)", true);

	//icons
	//Talk To Town Elder
	currentCity.icons.push_back(Icon("Talk To Town Elder", "Talk", "Town Elder", "Talk To Town Elder", "true"));
	//Talk To Apple Merchant
	currentCity.icons.push_back(Icon("Talk To Apple Merchant", "Talk", "Apple Merchant", "Talk To Apple Merchant", "true"));
	//Buy Apple
	currentCity.icons.push_back(Icon("Buy Apple", "Coin", "Elder Apple", "Buy Elder Apple", "true"));
	//Pick Up MathiasSword
	currentCity.icons.push_back(Icon("Take_MathiasSword", "Hand", "MathiasSword", "Take the sword", "true"));
	//Enter BlacksmithFoundry
	currentCity.icons.push_back(Icon("Enter Blacksmith Foundry", "Hand", "CurrentTown.RedHouseDoor", "Enter Blacksmith Foundry", "true"));
	currentCity.icons.push_back(Icon("Enter_AlchemyShop", "Open", "CurrentTown.BrownHouseDoor", "Enter Alchemy Shop", "true"));
	function.SetupIcons(currentCity.icons);

	return true;
}

bool Chapter2::setupBlacksmithFoundry(string name) {
	BlacksmithFoundry = Blacksmith(name);

	//character setup
	function.SetupCharacter("Blacksmith", "B", "HeavyArmour", "Musketeer_Beard", "Blonde", "BlacksmithFoundry.Anvil");

	//items
	function.Action("CreateItem(Fixed Lock, Lock)", true);

	//icons
	//Talk To Blacksmith
	BlacksmithFoundry.icons.push_back(Icon("Talk To Blacksmith", "Talk", "Blacksmith", "Talk To Blacksmith", "true"));
	//Exit Blacksmith Foundry
	BlacksmithFoundry.icons.push_back(Icon("Exit Blacksmith Foundry", "Hand", "BlacksmithFoundry.Door", "Exit Blacksmith Foundry", "true"));
	function.SetupIcons(BlacksmithFoundry.icons);

	return true;
}

bool Chapter2::setupAlchemyShop(string name) {
	Alchemy = AlchemyShop(name);

	//character setup
	function.SetupCharacter("Fortuneteller", "G", "Witch", "Ponytail", "Gray", "AlchemyShop.AlchemistTable");

	//icon setup
	Alchemy.icons.push_back(Icon("Talk_To_FortuneTeller", "Talk", "Fortuneteller", "Talk to Fortune Teller", "true"));
	Alchemy.icons.push_back(Icon("Exit_Shop", "Open", "AlchemyShop.Door", "Exit Alchemy Shop", "true"));
	function.SetupIcons(Alchemy.icons);

	return true;
}

bool Chapter2::setupCurrentForestPath(string name) {
	currentForestPath = ForestPath(name);

	//character setup

	//items and their placement
	function.Action("CreateItem(ArchieSpellbook, SpellBook)", true);

	//icons
	currentForestPath.icons.push_back(Icon("Take_ArchieSpellbook", "Hand", "ArchieSpellbook", "Take the spellbook", "true"));
	function.SetupIcons(currentForestPath.icons);

	return true;
}

bool Chapter2::setupCurrentRuins(string name) {
	currentRuins = Ruins(name);

	//character setup

	//items and their placement
	function.Action("CreateItem(LeaderFlashPotion, GreenPotion)", true);//potion to activate flashback 1

	//icons
	currentRuins.icons.push_back(Icon("Take", "Hand", "LeaderFlashPotion", "Take the Potion", "true"));
	function.SetupIcons(currentRuins.icons);


	return true;
}

bool Chapter2::setupPastCottage(string name) {
	pastCottage = Cottage(name);

	function.Action("CreateItem(Letter, OpenScroll)", true);
	function.Action("SetPosition(Letter, PastCottage.Shelf)", true);

	//character setup

	//icons
	pastCottage.icons.push_back(Icon("Open", "Exit", "PastCottage.Door", "Leave the Room", "true"));
	pastCottage.icons.push_back(Icon("Read", "Research", "Letter", "Read the Letter", "true"));
	function.SetupIcons(pastCottage.icons);


	return true;
}

bool Chapter2::setupPastForestPath(string name) {
	pastForestPath = ForestPath(name);

	//character setup

	//icons

	return true;
}

bool Chapter2::setupPastCity(string name) {
	pastCity = City(name);

	//character setup

	//icons
	pastCottage.icons.push_back(Icon("Open", "Exit", "PastCity.GreenHouseDoor", "Go Inside", "true"));
	function.SetupIcons(pastCity.icons);

	return true;
}

bool Chapter2::setupPastRuins(string name, bool Enemy) {
	pastRuins = Ruins(name);

	string EnemyName = "";

	if (camptest) {
		function.SetupCharacter("Archie", "D", "Warlock", "Mage_Full", "Red", name + ".Altar");
		function.SetupCharacter("Mathias", "F", "HeavyArmour", "Short_Full", "Brown", name + ".Altar");
		return true;
	}

	//character setup
	if (Enemy) {
		function.SetupCharacter("Archie", "D", "Warlock", "Mage_Full", "Red", name + ".Altar");
		pastRuins.icons.push_back(Icon("Talk to Archie", "Talk", "Archie", "Talk to Archie", "true"));
		EnemyName = "Archie";
	}
	else {
		function.SetupCharacter("Mathias", "F", "HeavyArmour", "Short_Full", "Brown", name + ".Altar");
		pastRuins.icons.push_back(Icon("Talk To Mathias", "Talk", "Mathias", "Talk to Mathias", "true"));
		EnemyName = "Mathias";
	}

	//icons
	function.SetupIcons(pastRuins.icons);

	//items
	function.Action("CreateItem(MysteriousSkull, Skull)", true);
	function.Action("SetPosition(MysteriousSkull, " + name + ".Altar)", true);
	function.Action("Face(" + EnemyName + ", MysteriousSkull)", true);
	function.Action("Kneel(" + EnemyName + ")", true);

	return true;
}

bool Chapter2::setupForestPath2(string name) {
	ForestPath2 = ForestPath(name);

	//character setup

	//items
	function.Action("CreateItem(PrisonerSword, Sword)", true);
	//icons

	return true;
}

bool Chapter2::setupCourtyard(string name) {
	CurrentCourtyard = Courtyard(name);

	//character setup

	//items

	//icons

	return true;
}

bool Chapter2::setupCastleBedroom(string name) {
	CurrentCastleBedroom = CastleBedroom(name);

	//character setup
	//CurrentCastleBedroom.enableRightChair(false);
	//CurrentCastleBedroom.enableLeftChair(true);
	function.Action("HideFurniture(CurrentCastleBedroom.LeftChair)", true);
	function.Action("HideFurniture(CurrentCastleBedroom.RightChair)", true);

	//items
	function.Action("CreateItem(CastleBedroomSkull, Skull)", true);
	function.Action("CreateItem(CastleBedroomLock, Lock)", true);
	function.Action("CreateItem(CastleBedroomBag, Bag)", true);
	function.Action("CreateItem(CastleBedroomInkAndQuill, InkandQuill)", true);
	function.Action("CreateItem(CastleBedroomJewelKey, JewelKey)", true);
	function.Action("CreateItem(CastleBedroomGoldCup, GoldCup)", true);
	function.Action("CreateItem(CastleBedroomPuzzle, OpenScroll)", true);
	function.Action("CreateItem(CastleBedroomCrime, OpenScroll)", true);
	function.Action("CreateItem(CastleBedroomApple1, Apple)", true);
	function.Action("CreateItem(CastleBedroomApple2, Apple)", true);
	function.Action("CreateItem(CastleBedroomApple3, Apple)", true);
	function.Action("CreateItem(CastleBedroomApple4, Apple)", true);
	function.Action("CreateItem(CastleBedroomApple5, Apple)", true);
	function.Action("CreateItem(CastleBedroomApple6, Apple)", true);
	//function.Action("CreateItem(CastleBedroom, RedPotion)", true);

	function.Action("SetPosition(CastleBedroomPuzzle, CurrentCastleBedroom.SmallTable)", true);
	function.Action("SetPosition(CastleBedroomApple1, CurrentCastleBedroom.Table.FrontLeft)", true);
	function.Action("SetPosition(CastleBedroomApple2, CurrentCastleBedroom.Table.FrontRight)", true);
	function.Action("SetPosition(CastleBedroomApple3, CurrentCastleBedroom.Table.Right)", true);
	function.Action("SetPosition(CastleBedroomApple4, CurrentCastleBedroom.Table.BackRight)", true);
	function.Action("SetPosition(CastleBedroomApple5, CurrentCastleBedroom.Table.BackLeft)", true);
	function.Action("SetPosition(CastleBedroomApple6, CurrentCastleBedroom.Table.Left)", true);


	//icons
	CurrentCastleBedroom.icons.push_back(Icon("Read_Puzzle", "research", "CastleBedroomPuzzle", "Read Puzzle", "true"));
	CurrentCastleBedroom.icons.push_back(Icon("Search_Bedroom_Closet", "hand", "CurrentCastleBedroom.Closet", "Search Closet", "true"));

	CurrentCastleBedroom.icons.push_back(Icon("Pickup Lock", "hand", "CastleBedroomLock", "Pickup Lock", "true"));
	CurrentCastleBedroom.icons.push_back(Icon("Pickup Skull", "hand", "CastleBedroomSkull", "Pickup Skull", "true"));
	CurrentCastleBedroom.icons.push_back(Icon("Pickup Bag", "hand", "CastleBedroomBag", "Pickup Bag", "true"));
	CurrentCastleBedroom.icons.push_back(Icon("Pickup InkAndQuill", "hand", "CastleBedroomInkAndQuill", "Pickup Ink and Quill", "true"));
	CurrentCastleBedroom.icons.push_back(Icon("Pickup JewelKey", "hand", "CastleBedroomJewelKey", "Pickup Jewel Key", "true"));
	CurrentCastleBedroom.icons.push_back(Icon("Pickup GoldCup", "hand", "CastleBedroomGoldCup", "Pickup Gold Cup", "true"));
	CurrentCastleBedroom.icons.push_back(Icon("Search_Chest", "magnifyingglass", "CurrentCastleBedroom.Chest", "Search Chest", "true"));

	CurrentCastleBedroom.icons.push_back(Icon("Pickup Apple1", "hand", "CastleBedroomApple1", "Pickup Apple", "true"));
	CurrentCastleBedroom.icons.push_back(Icon("Pickup Apple2", "hand", "CastleBedroomApple2", "Pickup Apple", "true"));
	CurrentCastleBedroom.icons.push_back(Icon("Pickup Apple3", "hand", "CastleBedroomApple3", "Pickup Apple", "true"));
	CurrentCastleBedroom.icons.push_back(Icon("Pickup Apple4", "hand", "CastleBedroomApple4", "Pickup Apple", "true"));
	CurrentCastleBedroom.icons.push_back(Icon("Pickup Apple5", "hand", "CastleBedroomApple5", "Pickup Apple", "true"));
	CurrentCastleBedroom.icons.push_back(Icon("Pickup Apple6", "hand", "CastleBedroomApple6", "Pickup Apple", "true"));
	function.SetupIcons(CurrentCastleBedroom.icons);

	return true;
}

bool Chapter2::setupPort(string name) {
	CurrentPort = Port(name);

	//character setup
	function.SetupCharacter("PortMerchant", "H", "Merchant", "Short", "Gray", "CurrentPort.SmallStall");
	function.SetupCharacter("Sailor", "D", "Peasant", "Musketeer", "Gray", "CurrentPort.BigShip");

	//items
	function.Action("CreateItem(Compass, Compass)", true);
	function.Action("CreateItem(BookOfLore, BlueBook)", true);

	//icons
	CurrentPort.icons.push_back(Icon("Talk to PortMerchant", "Talk", "PortMerchant", "Talk To Port Merchant", "true"));
	CurrentPort.icons.push_back(Icon("Talk to Sailor", "Talk", "Sailor", "Talk To Sailor", "true"));
	CurrentPort.icons.push_back(Icon("ReadBookOfLore", "Research", "BookOfLore", "Read the Book", "true"));
	function.SetupIcons(CurrentPort.icons);

	return true;
}

bool Chapter2::setupGreatHall(string name) {
	CurrentGreatHall = GreatHall(name);

	//character setup

	//items

	//icons
	CurrentGreatHall.icons.push_back(Icon("Enter Right Door", "Hand", "CurrentGreatHall.RightDoor", "Enter", "true"));
	CurrentGreatHall.icons.push_back(Icon("Enter Left Door", "Hand", "CurrentGreatHall.LeftDoor", "Enter", "true"));
	CurrentGreatHall.icons.push_back(Icon("Enter Basement Door", "Hand", "CurrentGreatHall.BasementDoor", "Enter", "true"));
	CurrentGreatHall.icons.push_back(Icon("Enter Gate", "Hand", "CurrentGreatHall.Gate", "Enter", "true"));
	function.SetupIcons(CurrentGreatHall.icons);

	return true;
}

bool Chapter2::setupCastleCrossroads(string name) {
	CurrentCastleCrossroads = CastleCrossroads(name);

	//character setup

	//items

	//icons

	return true;
}

bool Chapter2::setupLibrary(string name) {
	CurrentLibrary = Library(name);

	//character setup

	//items
	function.Action("CreateItem(Book Of Incantations, GreenBook)", true);
	function.Action("CreateItem(Library GoldCup, GoldCup)", true);
	function.Action("SetPosition(Library GoldCup, CurrentLibrary.AlchemistTable.Right)", true);
	function.Action("CreateItem(Library GreenKey, GreenKey)", true);
	function.Action("SetPosition(Library GreenKey, CurrentLibrary.AlchemistTable.Left)", true);
	function.Action("CreateItem(Library Apple, Apple)", true);
	function.Action("SetPosition(Library Apple, CurrentLibrary.AlchemistTable.Center)", true);

	//icons
	CurrentLibrary.icons.push_back(Icon("Library Alchemist Table", "Hand", "CurrentLibrary.AlchemistTable", "Interact With Alchemist Table", "true"));
	CurrentLibrary.icons.push_back(Icon("Library Table", "Hand", "CurrentLibrary.Table", "Interact With Table", "true"));
	CurrentLibrary.icons.push_back(Icon("Library Spellbook", "Hand", "CurrentLibrary.SpellBook", "Read Spellbook", "true"));
	//Placement icons
	/*CurrentLibrary.icons.push_back(Icon("Place Library Apple Left", "Hand", "Library Apple", "Place The Apple Left", "false"));
	CurrentLibrary.icons.push_back(Icon("Place Library Apple Center", "Hand", "Library Apple", "Place The Apple Center", "true"));
	CurrentLibrary.icons.push_back(Icon("Place Library Apple Right", "Hand", "Library Apple", "Place The Apple Right", "false"));
	CurrentLibrary.icons.push_back(Icon("Place Library GoldCup Left", "Hand", "Library GoldCup", "Place The GoldCup Left", "false"));
	CurrentLibrary.icons.push_back(Icon("Place Library GoldCup Center", "Hand", "Library GoldCup", "Place The GoldCup Center", "false"));
	CurrentLibrary.icons.push_back(Icon("Place Library GoldCup Right", "Hand", "Library GoldCup", "Place The GoldCup Right", "true"));
	CurrentLibrary.icons.push_back(Icon("Place Library GreenKey Left", "Hand", "Library GreenKey", "Place The GreenKey Left", "true"));
	CurrentLibrary.icons.push_back(Icon("Place Library GreenKey Center", "Hand", "Library GreenKey", "Place The GreenKey Center", "false"));
	CurrentLibrary.icons.push_back(Icon("Place Library GreenKey Right", "Hand", "Library GreenKey", "Place The GreenKey Right", "false"));*/

	//CurrentLibrary.icons.push_back(Icon("Library Chair", "Hand", "CurrentLibrary.Chair", "Rest", "true"));
	function.SetupIcons(CurrentLibrary.icons);

	//furniture
	function.Action("HideFurniture(CurrentLibrary.Chair)", true);

	return true;
}

bool Chapter2::setupCamp(string name) {
	CurrentCamp = Camp(name);

	//character setup

	//items

	//icons

	return true;
}

bool Chapter2::setupCamp2(string name) {
	CurrentCamp2 = Camp(name);

	function.Action("HideFurniture(" + name + ".Plant)", true);
	function.Action("HideFurniture(" + name + ".Barrel)", true);
	function.Action("HideFurniture(" + name + ".Stall)", true);
	function.Action("HideFurniture(" + name + ".LeftLog)", true);
	function.Action("HideFurniture(" + name + ".Cauldron)", true);
	function.Action("HideFurniture(" + name + ".Roast)", true);
	function.Action("HideFurniture(" + name + ".Firepit)", true);
	//function.Action("HideFurniture(" + name + ".Log)", true);
	function.Action("HideFurniture(" + name + ".RightLog)", true);
	function.Action("HideFurniture(" + name + ".Horse)", true);

	//character setup

	//items
	function.Action("CreateItem(AncientTome, EvilBook)", true);

	//icons
	CurrentCamp2.icons.push_back(Icon("OpenChest", "chest, ", name + ".Chest", "Open the Chest", "true"));
	function.SetupIcons(CurrentCamp2.icons);

	return true;
}

bool Chapter2::setupFinalRuins(string name) {
	finalRuins = Ruins(name);

	//character setup

	//items
	function.Action("CreateItem(MathiasSword2, Sword)", true);

	//icons

	return true;
}

bool Chapter2::setupDungeon(string name) {
	CurrentPrison = Dungeon(name);

	//character setup
	function.Action("CreateItem(Potion of Invincibility, RedPotion)", true);
	function.SetupCharacter("Prisoner", "F", "Bandit", "Spiky", "Blonde", "CurrentPrison.Bed");
	//items

	//icons
	CurrentPrison.icons.push_back(Icon("Talk_To_Prisoner", "talk", "Prisoner", "Talk To Prisoner", "true"));
	CurrentPrison.icons.push_back(Icon("Open Door", "door", "CurrentPrison.Door", "Open Door", "true"));
	function.SetupIcons(CurrentPrison.icons);
	return true;
}

bool Chapter2::setupLeftHallway(string name) {
	LeftHallway = Hallway(name);

	//character setup
	function.SetupCharacter("PrisonGuard", "E", "HeavyArmour", "Spiky", "Black", "LeftHallway.Door");
	//items
	function.Action("CreateItem(Potion of Healing, PurplePotion)", true);
	//icons
	LeftHallway.icons.push_back(Icon("Talk_To_Guard", "talk", "PrisonGuard", "Talk To Guard", "true"));
	function.SetupIcons(LeftHallway.icons);

	return true;
}

bool Chapter2::setupRightHallway(string name) {
	RightHallway = Hallway(name);

	//character setup

	//items

	//icons

	return true;
}

bool Chapter2::setupDiningRoom(string name) {
	CurrentDiningRoom = DiningRoom(name);

	//character setup
	function.SetupCharacter("Chef", "D", "Peasant", "Spiky", "Black", "CurrentDiningRoom.BackDoor");

	//items
	function.Action("CreateItem(DiningChalice, GoldCup)", true);
	function.Action("CreateItem(DiningApple, Apple)", true);
	function.Action("CreateItem(DiningBottle, Bottle)", true);
	function.Action("CreateItem(DiningBread, Bread)", true);
	function.Action("CreateItem(DiningMeat, ChickenLeg)", true);
	function.Action("CreateItem(DiningCup, Cup)", true);
	function.Action("CreateItem(PotionOfPower, BluePotion)", true);

	//icons
	//door interaction
	CurrentDiningRoom.icons.push_back(Icon("Open", "Hand", "CurrentDiningRoom.BackDoor", "Open the Door", "true"));
	CurrentDiningRoom.icons.push_back(Icon("Open", "Hand", "CurrentDiningRoom.Door", "Open the Door", "true"));
	//place items in chairs
	CurrentDiningRoom.icons.push_back(Icon("PlaceInChair", "Hand", "CurrentDiningRoom.LeftChair", "Place an item", "false"));
	CurrentDiningRoom.icons.push_back(Icon("PlaceInChair", "Hand", "CurrentDiningRoom.FrontLeftChair", "Place an item", "false"));
	CurrentDiningRoom.icons.push_back(Icon("PlaceInChair", "Hand", "CurrentDiningRoom.FrontRightChair", "Place an item", "false"));
	CurrentDiningRoom.icons.push_back(Icon("PlaceInChair", "Hand", "CurrentDiningRoom.RightChair", "Place an item", "false"));
	CurrentDiningRoom.icons.push_back(Icon("PlaceInChair", "Hand", "CurrentDiningRoom.BackLeftChair", "Place an item", "false"));
	CurrentDiningRoom.icons.push_back(Icon("PlaceInChair", "Hand", "CurrentDiningRoom.BackRightChair", "Place an item", "false"));
	//check chair notes
	CurrentDiningRoom.icons.push_back(Icon("CheckNote", "OpenScroll", "CurrentDiningRoom.LeftChair", "Check the note", "true"));
	CurrentDiningRoom.icons.push_back(Icon("CheckNote", "OpenScroll", "CurrentDiningRoom.FrontLeftChair", "Check the note", "true"));
	CurrentDiningRoom.icons.push_back(Icon("CheckNote", "OpenScroll", "CurrentDiningRoom.FrontRightChair", "Check the note", "true"));
	CurrentDiningRoom.icons.push_back(Icon("CheckNote", "OpenScroll", "CurrentDiningRoom.RightChair", "Check the note", "true"));
	CurrentDiningRoom.icons.push_back(Icon("CheckNote", "OpenScroll", "CurrentDiningRoom.BackLeftChair", "Check the note", "true"));
	CurrentDiningRoom.icons.push_back(Icon("CheckNote", "OpenScroll", "CurrentDiningRoom.BackRightChair", "Check the note", "true"));
	//drink potion
	CurrentDiningRoom.icons.push_back(Icon("Drink", "Potion", "PotionOfPower", "Drink the potion", "true"));
	
	function.SetupIcons(CurrentDiningRoom.icons);
	
	return true;
}

bool Chapter2::setupStorage(string name) {
	CurrentStorage = Storage(name);

	//character setup

	//items
	function.Action("CreateItem(Potion Of Cleansing, GreenPotion)", true);
	function.Action("CreateItem(Storage Bottle, Bottle)", true);
	function.Action("SetPosition(Storage Bottle, CurrentStorage.Chest)", true);
	function.Action("CreateItem(Storage InkAndQuill, InkAndQuill)", true);
	function.Action("SetPosition(Storage InkAndQuill, CurrentStorage.Chest)", true);
	function.Action("CreateItem(Storage Bread, Bread)", true);
	function.Action("SetPosition(Storage Bread, CurrentStorage.Chest)", true);
	function.Action("CreateItem(Storage Bag, Bag)", true);
	function.Action("SetPosition(Storage Bag, CurrentStorage.Chest)", true);
	function.Action("CreateItem(Storage Helmet, Helmet)", true);
	function.Action("SetPosition(Storage Helmet, CurrentStorage.Chest)", true);
	function.Action("CreateItem(Storage OpenScroll, OpenScroll)", true);
	function.Action("SetPosition(Storage OpenScroll, CurrentStorage.Barrel)", true);

	function.Action("CreateItem(PrisonerOutfit, Helmet)", true);

	//icons
	CurrentStorage.icons.push_back(Icon("Storage Chest", "Hand", "CurrentStorage.Chest", "Take All Storage Items", "true"));
	CurrentStorage.icons.push_back(Icon("Read Storage OpenScroll", "Hand", "Storage OpenScroll", "Read The Scroll", "true"));
	CurrentStorage.icons.push_back(Icon("Interact With Potion Of Cleansing", "Hand", "Potion Of Cleansing", "Take The Potion", "true"));
	CurrentStorage.icons.push_back(Icon("Place Items On Shelf", "Hand", "CurrentStorage.Shelf", "Place An Item On The Shelf", "true"));
	CurrentStorage.icons.push_back(Icon("Leave Storage", "Hand", "CurrentStorage.Door", "Leave", "true"));
	//Placement icons
	/*CurrentLibrary.icons.push_back(Icon("Place Library Apple Left", "Hand", "Library Apple", "Place The Apple Left", "false"));
	CurrentLibrary.icons.push_back(Icon("Place Library Apple Center", "Hand", "Library Apple", "Place The Apple Center", "true"));
	CurrentLibrary.icons.push_back(Icon("Place Library Apple Right", "Hand", "Library Apple", "Place The Apple Right", "false"));
	CurrentLibrary.icons.push_back(Icon("Place Library GoldCup Left", "Hand", "Library GoldCup", "Place The GoldCup Left", "false"));
	CurrentLibrary.icons.push_back(Icon("Place Library GoldCup Center", "Hand", "Library GoldCup", "Place The GoldCup Center", "false"));
	CurrentLibrary.icons.push_back(Icon("Place Library GoldCup Right", "Hand", "Library GoldCup", "Place The GoldCup Right", "true"));
	CurrentLibrary.icons.push_back(Icon("Place Library GreenKey Left", "Hand", "Library GreenKey", "Place The GreenKey Left", "true"));
	CurrentLibrary.icons.push_back(Icon("Place Library GreenKey Center", "Hand", "Library GreenKey", "Place The GreenKey Center", "false"));
	CurrentLibrary.icons.push_back(Icon("Place Library GreenKey Right", "Hand", "Library GreenKey", "Place The GreenKey Right", "false"));*/

	//CurrentLibrary.icons.push_back(Icon("Library Chair", "Hand", "CurrentLibrary.Chair", "Rest", "true"));
	function.SetupIcons(CurrentStorage.icons);

	return true;
}


// location execution functions.
void Chapter2::runCurrentCottage() {
	while (currentLocation == "ArlanCottage") {
		string i;
		getline(cin, i);

		//Gets the first word that isn't "input"
		modified_I = function.splitInput(i, 6, false);

		bool inputWasCommon = function.checkCommonKeywords(i, modified_I, "Arlan", playerInv);

		if (!inputWasCommon) {
			if (modified_I == "Talk_To_Dad") {
				function.SetupDialog("Arlan", "Dad", true);
				function.Action("ClearDialog()", true);
				if (!hasStorybook) {
					function.SetupDialogText("Arlan! Take this book of stories and ask the Town Elder to tell you about them.", "takeBook", "Sure thing Dad!");
				}
				else {
					function.SetupDialogText("Go talk to the Town Elder about the stroybook.", "end", "Will do!");
				}
			}

			else if (modified_I == "Selected") {
				modified_I = function.splitInput(i, 0, true);

				if (modified_I == "takeBook") {
					function.Action("SetNarration(You have taken the Storybook)", true);
					function.Action("ShowNarration()", true);
					playerInv.push_back("Storybook");
					hasStorybook = true;
					function.SetupDialogText("Have fun!", "end", "ok!");
				}
			}

			else if (modified_I == "Open_Door") {
				int test = 6;
				if (hasStorybook) {
					//testing
					if (test == 0) {
						function.Transition("Arlan", "ArlanCottage.Door", "CurrentTown.BlueHouseDoor");
						currentLocation = "CurrentTown";
					}
					else if (test == 1) {
						function.Transition("Arlan", "ArlanCottage.Door", "CurrentLibrary.Door");
						currentLocation = "CurrentLibrary";
					}
					else if (test == 2) {
						function.Transition("Arlan", "ArlanCottage.Door", "CurrentStorage.Door");
						currentLocation = "CurrentStorage";
					}
					else if (test == 3) {
						function.Transition("Arlan", "ArlanCottage.Door", "CurrentDiningRoom.Door");
						currentLocation = "CurrentDiningRoom";
					}
					else if (test == 4) {
						function.Transition("Arlan", "ArlanCottage.Door", "CurrentTown.BlueHouseDoor");
						currentLocation = "CurrentTown";

						//spawn coins in world 
						function.Action("CreateItem(Coin1, Coin)", true);
						function.Action("EnableIcon(TakeCoin1, Hand, CurrentTown.Fountain, Inspect the Fountain, true)", true);

						function.Action("CreateItem(Coin2, Coin)", true);
						canWorkForBlacksmith = true;
						
						function.Action("CreateItem(Coin3, Coin)", true);
						function.Action("EnableIcon(TakeCoin3, Hand, ForestPath2.Well, Inspect the Well, true)", true);

						function.Action("CreateItem(Coin4, Coin)", true);
						function.Action("EnableIcon(TakeCoin4, Hand, CurrentPort.Barrel, Inspect the Barrel, true)", true);

						function.Action("CreateItem(Coin5, Coin)", true);
						function.Action("EnableIcon(TakeCoin5, Hand, Coin5, Take the Coin, true", true);
						function.Action("SetPosition(Coin5, CurrentGreatHall.Table)", true);

						visitedTownElder = true;
						completedErrand = true;

						playerInv.push_back("Coin2");
						playerInv.push_back("Coin5");
						numCoins = 2;
					}
				
					else if (test == 5) {
						function.Transition("Arlan", "ArlanCottage.Door", "CurrentCamp.Exit");
						currentLocation = "CurrentCamp";
					}

					else if (test == 6) {
						function.Transition("Arlan", "ArlanCottage.Door", "CurrentCamp2.Exit");
						currentLocation = "FinalRuins";
					}
				}
				else {
					function.WalkToPlace("Arlan", "ArlanCottage.Door");
					function.Action("ShowDialog()", true);
					function.Action("SetLeft(Arlan)", true);
					function.Action("SetRight(Dad)", true);
					function.Action("ClearDialog()", true);
					function.SetupDialogText("Arlan! Come over here. I have something for you.", "end", "Ok");
				}
			}
		}
	}
}

void Chapter2::runCurrentTown() {
	while (currentLocation == "CurrentTown") {
		string i;
		getline(cin, i);

		//Gets the first word that isn't "input"
		modified_I = function.splitInput(i, 6, false);

		bool inputWasCommon = function.checkCommonKeywords(i, modified_I, "Arlan", playerInv);

		if (!inputWasCommon) {
			//If it's under the "Talk" keyword
			if (modified_I == "Talk") {
				modified_I = function.splitInput(i, 0, true);

				//splitInput needs modifications to allow for spaces
				if (modified_I == "Elder") {
					function.SetupDialog("Arlan", "Town Elder", true);
					if (hasStorybook && !hasBrokenLock && !hasFixedLock && !hasAppleMoney && !hasElderApple) {
						function.SetupDialogText("Thats a cool book Arlan! Can you please help me run some errands and ill tell you about one of the stories?", "helpElder", "Sounds like a deal.");
					}
					else if (hasAppleMoney) {
						function.SetupDialogText("Please go buy me an apple from the Apple Merchant!", "end", "ok.");
					}
					else if (hasBrokenLock) {
						function.SetupDialogText("Please go repair my lock at the Blacksmith Foundry!", "end", "ok.");
					}
					else if (hasElderApple || hasFixedLock) {
						if (visitedFortuneteller) {
							if (hasElderApple) {
								function.RemoveItem("Storybook", playerInv);
								hasStorybook = false;
								function.RemoveItem("Elder Apple", playerInv);
								hasElderApple = false;
								completedErrand = true;
								function.Action("EnableIcon(Look Inside Barrel, Hand, CurrentTown.Barrel, Look Inside, true)", true);
								function.Action("EnableIcon(Look Inside Dirt Pile, Hand, CurrentForestPath.DirtPile, Look Inside, true)", true);

								function.SetupDialogText("You retrieved my apple! Thank you Arlan! Now lets read that book!", "readBook", "Great! What does it say?");
							}
							else if (hasFixedLock) {
								function.RemoveItem("Storybook", playerInv);
								hasStorybook = false;
								function.RemoveItem("Fixed Lock", playerInv);
								hasFixedLock = false;
								completedErrand = true;
								function.Action("EnableIcon(Look Inside Barrel, Hand, CurrentTown.Barrel, Look Inside, true)", true);
								function.Action("EnableIcon(Look Inside Dirt Pile, Hand, CurrentForestPath.DirtPile, Look Inside, true)", true);
								function.SetupDialogText("You fixed my lock! Thank you Arlan! Now lets read that book!", "readBook", "Great! What does it say?");
							}
						}
						else {
							function.SetupDialogText("Go get your fortune from the fortuneteller!", "end", "ok.");
						}
					}
					else if (completedErrand == true) {
						function.SetupDialogText("You should look around for an ancient artifact and take it to the ruins past the forest path.", "end", "Okay! Thanks!");
					}
				}

				else if (modified_I == "Merchant") {
					function.SetupDialog("Arlan", "Apple Merchant", true);
					if (!visitedTownElder) {
						function.SetupDialogText("I am not open quite yet. Come back later!", "end", "ok");
					}
					else if (hasAppleMoney) {
						function.SetupDialogText("Ah! Take this apple for the coin!", "takeApple", "ok!");
					}
					else {
						function.SetupDialogText("Beautiful day isn't it?!", "end", "It is!");
					}
				}
			}

			else if (modified_I == "Selected") {
				modified_I = function.splitInput(i, 0, true);

				if (modified_I == "helpElder") {
					function.SetupDialogText("Great! Would you like to buy my apples or repair my lock?", "selectAppleErrand", "I can buy the apples.", "selectLockErrand", "I would rather fix the lock.");
					visitedTownElder = true;
				}

				else if (modified_I == "selectAppleErrand") {
					function.Action("SetNarration(Apple Money Added To Inventory)", true);
					function.Action("ShowNarration()", true);
					playerInv.push_back("Apple Money");
					hasAppleMoney = true;
					function.SetupDialogText("I would recommend getting your fortune told by the new fortune teller as well! Meet me back here after your errands are done!", "end", "ok!");
				}

				else if (modified_I == "selectLockErrand") {
					function.Action("SetNarration(Broken Lock Added To Inventory)", true);
					function.Action("ShowNarration()", true);
					playerInv.push_back("Broken Lock");
					hasBrokenLock = true;
					function.SetupDialogText("I would recommend getting your fortune told by the new fortune teller as well! Meet me back here after your errands are done!", "end", "ok!");
				}

				else if (modified_I == "takeApple") {
					function.Action("SetNarration(Apple Money Removed From Inventory)", true);
					function.Action("ShowNarration()", true);
					function.RemoveItem("Apple Money", playerInv);
					hasAppleMoney = false;
					function.SetupDialogText("Here you go!", "receiveApple", "Thanks!");
				}

				else if (modified_I == "receiveApple") {
					function.Action("HideDialog()", true);
					playerInv.push_back("Elder Apple");
					hasElderApple = true;
					function.Action("SetNarration(Elder Apple Added To Inventory)", true);
					function.Action("ShowNarration()", true);
				}

				else if (modified_I == "readBook") {
					function.Action("SetNarration(The elder begins flipping through the book and mumbling to himself. He tells you the book is about two influential leaders who have fought for years over a great source of power.)", true);
					function.Action("ShowNarration()", true);
					function.SetupDialogText("The book says the tale is best told by bringing an ancient relic to the ruins and indulging in the reward.", "whatRuins", "What ruins?");
				}

				else if (modified_I == "whatRuins") {
					function.SetupDialogText("Take the eastern forest path just beyond the fortune tellers shop and you will find them.", "completedErrand", "Okay! Thanks!");
				}

				else if (modified_I == "completedErrand") {
					function.Action("ClearDialog()", true);
					function.Action("HideDialog()", true);
					function.Action("SetNarration(The air shifts around you. You feel like you can go somewhere you couldnt before. You wonder where an ancient relic could be.)", true);
					function.Action("ShowNarration()", true);
				}
			}
			else if (modified_I == "Enter_AlchemyShop") {
				function.WalkToPlace("Arlan", "CurrentTown.BrownHouseDoor");
				if (visitedTownElder) {
					function.Transition("Arlan", "CurrentTown.BrownHouseDoor", "AlchemyShop.Door");
					currentLocation = "AlchemyShop";
				}
				else {
					function.Action("SetNarration(The door is locked. This store must be closed.)", true);
					function.Action("ShowNarration()", true);
				}
			}
		}

		if (i == "input arrived Arlan position CurrentTown.EastEnd") {
			if (completedErrand) {
				function.Transition("Arlan", "CurrentTown.EastEnd", "CurrentForestPath.WestEnd");
				currentLocation = "CurrentForestPath";
			}
			else {
				function.Action("SetNarration(A thick mist blocks your path. You can make out a forest path just beyond the fog. Maybe you should return later.)", true);
				function.Action("ShowNarration()", true);
			}
		}

		else if (i == "input arrived Arlan position CurrentTown.NorthEnd") {
			function.Transition("Arlan", "CurrentTown.NorthEnd", "CurrentCourtyard.Exit");
			currentLocation = "CurrentCourtyard";
		}

		else if (i == "input arrived Arlan position CurrentTown.WestEnd") {
			function.Transition("Arlan", "CurrentTown.WestEnd", "ForestPath2.EastEnd");
			currentLocation = "ForestPath2";
		}

		else if (i == "input Enter Blacksmith Foundry CurrentTown.RedHouseDoor") {
			function.WalkToPlace("Arlan", "CurrentTown.RedHouseDoor");
			if (visitedTownElder) {
				function.Transition("Arlan", "CurrentTown.RedHouseDoor", "BlacksmithFoundry.Door");
				currentLocation = "BlacksmithFoundry";
			}
			else {
				function.Action("SetNarration(The door is locked. This store must be closed.)", true);
				function.Action("ShowNarration()", true);
			}
		}

		else if (i == "input Look Inside Barrel CurrentTown.Barrel") {
			function.WalkToPlace("Arlan", "CurrentTown.Barrel");
			function.Action("SetNarration(Theres a sword inside! You take it. It appears ancient and powerful. You wonder if this is the relic the elder mentioned.)", true);
			function.Action("ShowNarration()", true);
			playerInv.push_back("MathiasSword");
			sword_taken = true;
		}

		else if (i == "input TakeCoin1 CurrentTown.Fountain") {
			function.WalkToPlace("Arlan", "CurrentTown.Fountain");
			function.Action("SetNarration(Theres a gold coin in the fountain! You reach in and take it.)", true);
			function.Action("ShowNarration()", true);
			playerInv.push_back("Coin1");
			numCoins++;
			function.Action("DisableIcon(TakeCoin1, CurrentTown.Fountain)", true);
		}

		else if (i == "input Key Inventory") {
			function.Action("ClearList()", true);
			for (string item : playerInv) {
				function.Action("AddToList(" + item + ")", true);
			}
			function.Action("ShowList(Arlan)", true);
		}

		else if (i == "input Close List") {
			function.Action("HideList()", true);
			function.Action("EnableInput()", true);
		}
	}
}

void Chapter2::runBlacksmithFoundry() {
	while (currentLocation == "BlacksmithFoundry") {
		string i;
		getline(cin, i);

		//Gets the first word that isn't "input"
		modified_I = function.splitInput(i, 6, false);

		bool inputWasCommon = function.checkCommonKeywords(i, modified_I, "Arlan", playerInv);

		if (!inputWasCommon) {
			//If it's under the "Talk" keyword
			if (modified_I == "Talk") {
				modified_I = function.splitInput(i, 0, true);

				if (modified_I == "Blacksmith") {
					function.SetupDialog("Arlan", "Blacksmith", true);
					if (canWorkForBlacksmith) {
						function.SetupDialogText("Looking to make some coin? I have a couple tasks around the shop I could use a hand with if youre interested.", "WorkForBlacksmith", "Sure!", "RefuseWork", "No thanks.");
					}
					else if (hasBrokenLock) {
						function.SetupDialogText("Oh! The Town Elder needs his broken lock fixed? No problem! Give me the lock.", "fixTheLock", "Here you go!");
					}
					else if (hasFixedLock) {
						function.SetupDialogText("Return that lock to the Town Elder", "end", "ok.");
					}
					else {
						function.SetupDialogText("Hello. Hope you are having a good day!", "end", "Thank you!");
					}
				}
			}

			else if (modified_I == "Selected") {
				modified_I = function.splitInput(i, 0, true);

				if (modified_I == "WorkForBlacksmith") {
					function.Action("HideDialog()", true);
					function.Action("FadeOut()", true);
					function.Action("FadeIn()", true);
					function.Action("ShowDialog()", true);
					function.SetupDialogText("Great work! Thanks for all your help! Heres a gold coin for your trouble.", "end", "Thanks!");
					playerInv.push_back("Coin2");
					numCoins++;
					canWorkForBlacksmith = false;
				}
				
				else if (modified_I == "RefuseWork") {
					function.SetupDialogText("Another time then.", "end", "Okay.");
				}

				else if (modified_I == "fixTheLock") {
					function.Action("SetNarration(Broken Lock Removed From Inventory)", true);
					function.Action("ShowNarration()", true);
					function.RemoveItem("Broken Lock", playerInv);
					hasBrokenLock = false;
					function.SetupDialogText("Here you go!", "receiveFixedLock", "Thanks!");
				}

				else if (modified_I == "receiveFixedLock") {
					function.Action("HideDialog()", true);
					playerInv.push_back("Fixed Lock");
					hasFixedLock = true;
					function.Action("SetNarration(Fixed Lock Added To Inventory)", true);
					function.Action("ShowNarration()", true);
				}
			}
		}

		if (i == "input Exit Blacksmith Foundry BlacksmithFoundry.Door") {
			function.Transition("Arlan", "BlacksmithFoundry.Door", "CurrentTown.RedHouseDoor");
			currentLocation = "CurrentTown";
		}

		else if (i == "input Key Inventory") {
			function.Action("ClearList()", true);
			for (string item : playerInv) {
				function.Action("AddToList(" + item + ")", true);
			}
			function.Action("ShowList(Arlan)", true);
		}

		else if (i == "input Close List") {
			function.Action("HideList()", true);
			function.Action("EnableInput()", true);
		}
	}
}

void Chapter2::runAlchemyShop() {
	while (currentLocation == "AlchemyShop") {
		string i;
		getline(cin, i);

		//Gets the first word that isn't "input"
		modified_I = function.splitInput(i, 6, false);

		bool inputWasCommon = function.checkCommonKeywords(i, modified_I, "Arlan", playerInv);

		if (!inputWasCommon) {
			if (modified_I == "Talk_To_FortuneTeller") {
				function.SetupDialog("Arlan", "Fortuneteller", true);
				if (!visitedFortuneteller) {
					function.SetupDialogText("Oooh a customer... Arlan is it?", "Answer", "Yes I am Arlan. I have come for a fortune telling.", "Questioning", "I have never met you. How do you know who I am ?");
				}
				else {
					function.SetupDialogText("Thank you for coming to see me. I wish you good fortune in your journey.", "end", "Thank you.");
				}
			}
			else if (modified_I == "Selected") {
				modified_I = function.splitInput(i, 0, true);

				if (modified_I == "Answer") {
					function.Action("ClearDialog()", true);
					function.SetupDialogText("Give me your hand and I will give you your fortune free of charge.", "Accept", "**Put out your hand**", "Deny", "I dont feel like it.");
				}
				if (modified_I == "Questioning") {
					function.Action("ClearDialog()", true);
					function.SetupDialogText("I am a fortune teller. I know many things. Would like your fortune read?", "Answer", "Yes I am Arlan and I would like a fortune telling.", "Deny", "I do not want a fortune telling.");
				}
				if (modified_I == "Deny") {
					function.Action("ClearDialog()", true);
					function.SetupDialogText("Come back when you want your fortune read.", "end", "Leave");
				}
				if (modified_I == "Accept") {
					function.Action("ClearDialog()", true);
					function.SetupDialogText("**She takes your hand and begins to read your palm** You carry the burden of responsibility and hold a promising future.", "end", "Vauge and interesting. Ill be leaving now");
					visitedFortuneteller = true;
				}
				if (modified_I == "end") {
					function.Action("ClearDialog()", true);
					function.Action("HideDialog()", true);
				}
			}
			else if (modified_I == "Exit_Shop") {
				function.Transition("Arlan", "AlchemyShop.Door", "CurrentTown.BrownHouseDoor");
				currentLocation = "CurrentTown";
			}
		}
	}
}

void Chapter2::runCurrentForestPath() {
	while (currentLocation == "CurrentForestPath") {
		string i;
		getline(cin, i);

		//Gets the first word that isn't "input"
		modified_I = function.splitInput(i, 6, false);

		bool inputWasCommon = function.checkCommonKeywords(i, modified_I, "Arlan", playerInv);

		/*if (!inputWasCommon) {
			//If it's under the "Talk" keyword
			if (modified_I == "Talk") {
				modified_I = function.splitInput(i, 0, true);
			}
		}*/

		if (i == "input arrived Arlan position CurrentForestPath.WestEnd") {
			function.Transition("Arlan", "CurrentForestPath.WestEnd", "CurrentTown.EastEnd");
			currentLocation = "CurrentTown";
		}

		else if (i == "input arrived Arlan position CurrentForestPath.EastEnd") {
			function.Transition("Arlan", "CurrentForestPath.EastEnd", "CurrentRuins.Exit");
			currentLocation = "CurrentRuins";
		}

		else if (i == "input Selected end") {
			function.Action("HideDialog()", true);
		}

		else if (i == "input Key Inventory") {
			function.Action("ClearList()", true);
			for (string item : playerInv) {
				function.Action("AddToList(" + item + ")", true);
			}
			function.Action("ShowList(Arlan)", true);
		}

		else if (i == "input Close List") {
			function.Action("HideList()", true);
			function.Action("EnableInput()", true);
		}

		else if (i == "input Look Inside Dirt Pile CurrentForestPath.DirtPile") {
			function.WalkToPlace("Arlan", "CurrentForestPath.DirtPile");
			function.Action("SetNarration(There is a book inside! You take it. It appears ancient and unintelligable. And dirty. You wonder if this is the relic the elder mentioned.)", true);
			function.Action("ShowNarration()", true);
			playerInv.push_back("ArchieSpellbook");
			spellbook_taken = true;
		}
	}
}

void Chapter2::runCurrentRuins() {
	while (currentLocation == "CurrentRuins") {
		string i;
		getline(cin, i);

		//Gets the first word that isn't "input"
		modified_I = function.splitInput(i, 6, false);

		bool inputWasCommon = function.checkCommonKeywords(i, modified_I, "Arlan", playerInv);

		if (!inputWasCommon) {
			//If it's under the "Talk" keyword
			if (modified_I == "Talk") {
				modified_I = function.splitInput(i, 0, true);
			}
			//if the player is in the CurrentRuins
			else if (currentLocation == "CurrentRuins") {
				if (modified_I == "Take") {
					function.Action("Take(Arlan, LeaderFlashPotion)", true);
					flashback1();
				}
			}
		}

		if (i == "input arrived Arlan position CurrentRuins.Exit") {
			function.Transition("Arlan", "CurrentRuins.Exit", "CurrentForestPath.EastEnd");
			currentLocation = "CurrentForestPath";
		}

		else if (i == "input arrived Arlan position CurrentRuins.Altar") {
			if (!item_placed && (sword_taken || spellbook_taken)) {
				function.Action("DisableInput()", true);
				function.Action("ShowDialog()", true);
				function.Action("ClearDialog()", true);
				function.Action("SetLeft(Arlan)", true);
				function.Action("EnableInput()", true);
				if (sword_taken && spellbook_taken) {
					function.Action("SetDialog(You hear a whisper. \"Place the tribute to see the past.\" Place your item? [placeMathiasSword | Place Mathias Sword.] [placeArchieSpellbook | Place Archie Spellbook.])", true);
				}
				else if (sword_taken) {
					function.Action("SetDialog(You hear a whisper. \"Place the tribute to see the past.\" Place your item? [placeMathiasSword | Place Mathias Sword.])", true);
				}
				else if (spellbook_taken) {
					function.Action("SetDialog(You hear a whisper. \"Place the tribute to see the past.\" Place your item? [placeArchieSpellbook | Place Archie Spellbook.])", true);
				}
			}
		}

		else if (i == "input Selected placeMathiasSword") {
			MathiasFlashback = true;
			function.Action("HideDialog()", true);
			if (sword_taken) {
				function.RemoveItem("MathiasSword", playerInv);
				function.Action("SetPosition(MathiasSword, CurrentRuins.Altar.Top)", true);
				ArchieEnemy = true;
				item_placed = true;
				function.Action("CreateEffect(CurrentRuins.Altar, Resurrection)", true);
				function.Action("EnableEffect(CurrentRuins.Altar, Resurrection)", true);
				this_thread::sleep_for(chrono::milliseconds(2000));
				function.Action("SetPosition(MathiasSword)", true);
				function.Action("SetPosition(ArchieSpellbook)", true);
				this_thread::sleep_for(chrono::milliseconds(2000));
				function.Action("SetPosition(LeaderFlashPotion, CurrentRuins.Altar.Top)", true);
				this_thread::sleep_for(chrono::milliseconds(2000));
				function.Action("DisableEffect(CurrentRuins.Altar)", true);
			}
		}

		else if (i == "input Selected placeArchieSpellbook") {
			ArchieFlashback = true;
			function.Action("HideDialog()", true);
			if (spellbook_taken) {
				function.RemoveItem("ArchieSpellbook", playerInv);
				function.Action("SetPosition(ArchieSpellbook, CurrentRuins.Altar.Top)", true);
				ArchieEnemy = false;
				item_placed = true;
				function.Action("CreateEffect(CurrentRuins.Altar, Resurrection)", true);
				function.Action("EnableEffect(CurrentRuins.Altar, Resurrection)", true);
				this_thread::sleep_for(chrono::milliseconds(2000));
				function.Action("SetPosition(MathiasSword)", true);
				function.Action("SetPosition(ArchieSpellbook)", true);
				this_thread::sleep_for(chrono::milliseconds(2000));
				function.Action("SetPosition(LeaderFlashPotion, CurrentRuins.Altar.Top)", true);
				this_thread::sleep_for(chrono::milliseconds(2000));
				function.Action("DisableEffect(CurrentRuins.Altar)", true);
			}
		}

		else if (i == "input Selected end") {
			function.Action("HideDialog()", true);
		}

		else if (i == "input Key Inventory") {
			function.Action("ClearList()", true);
			for (string item : playerInv) {
				function.Action("AddToList(" + item + ")", true);
			}
			function.Action("ShowList(Arlan)", true);
		}

		else if (i == "input Close List") {
			function.Action("HideList()", true);
			function.Action("EnableInput()", true);
		}
	}
}

//Chractercheck is sword_taken
void Chapter2::runPastCottage(bool CharacterCheck) {
	currentLocation = "PastCottage";
	bool LetterCheck = false;
	bool inputWasCommon;
	string CharacterName = "";
	setupPastRuins("PastRuins", CharacterCheck);

	if (CharacterCheck) {
		function.SetupCharacter("Mathias", "F", "HeavyArmour", "Long", "Black", "PastCottage.Bed");
		CharacterName = "Mathias";
	}
	else {
		function.SetupCharacter("Archie", "D", "Warlock", "Mage_Full", "Red", "PastCottage.Bed");
		CharacterName = "Archie";
	}

	function.Action("SetCameraFocus(" + CharacterName + ")", true);
	function.Action("FadeIn()", true);
	function.Action("EnableInput()", true);
	while (currentLocation == "PastCottage") {
		string i;
		getline(cin, i);

		//Gets the first word that isn't "input"
		modified_I = function.splitInput(i, 6, false);

		if (CharacterCheck) {
			inputWasCommon = function.checkCommonKeywords(i, modified_I, CharacterName, mathiasInv);
		}
		else {
			inputWasCommon = function.checkCommonKeywords(i, modified_I, CharacterName, archieInv);
		}


		if (modified_I == "Read") {
			function.Action("WalkTo(" + CharacterName + ", Letter)", true);
			function.Action("SetNarration(" + CharacterName + " we need to discuss what to do about that artifact we found. Meet me by the ruins so we can discuss)", true);
			function.Action("ShowNarration()", true);
			LetterCheck = true;

		}

		if (modified_I == "Close") {
			function.Action("HideNarration()", true);
		}

		if (!inputWasCommon) {

			//If it's under the "Talk" keyword
			if (modified_I == "Talk") {
				modified_I = function.splitInput(i, 0, true);
			}

			if (modified_I == "Open") {
				if (LetterCheck) {
					function.Transition(CharacterName, "PastCottage.Door", "PastCity.GreenHouseDoor");
					currentLocation = "PastCity";
				}
				else {
					function.WalkToPlace(CharacterName, "PastCottage.Door");
					function.Action("SetNarration(I should read that letter I left on the shelf)", true);
					function.Action("ShowNarration()", true);
				}
			}

		}

	}
}
void Chapter2::runPastForestPath(bool CharacterCheck) {
	bool inputWasCommon;
	string CharacterName = "";

	if (CharacterCheck) {
		CharacterName = "Mathias";
	}
	else {
		CharacterName = "Archie";
	}

	while (currentLocation == "PastForestPath") {
		string i;
		getline(cin, i);

		//Gets the first word that isn't "input"
		modified_I = function.splitInput(i, 6, false);

		if (CharacterCheck) {
			inputWasCommon = function.checkCommonKeywords(i, modified_I, CharacterName, mathiasInv);
		}
		else {
			inputWasCommon = function.checkCommonKeywords(i, modified_I, CharacterName, archieInv);
		}

		if (!inputWasCommon) {
			//If it's under the "Talk" keyword
			if (modified_I == "Talk") {
				modified_I = function.splitInput(i, 0, true);
			}
		}

		if (i == "input arrived " + CharacterName + " position PastForestPath.WestEnd") {
			function.Transition(CharacterName, "PastForestPath.WestEnd", "PastCity.EastEnd");
			currentLocation = "PastCity";
		}

		else if (i == "input arrived " + CharacterName + " position PastForestPath.EastEnd") {
			function.Transition(CharacterName, "PastForestPath.EastEnd", "PastRuins.Exit");
			currentLocation = "PastRuins";
			runPastRuins(CharacterCheck);
		}
	}
}

void Chapter2::runPastCity(bool CharacterCheck) {

	string CharacterName = "";
	bool inputWasCommon;

	if (CharacterCheck) {
		CharacterName = "Mathias";
	}
	else {
		CharacterName = "Archie";
	}

	while (currentLocation == "PastCity") {
		string i;
		getline(cin, i);

		//Gets the first word that isn't "input"
		modified_I = function.splitInput(i, 6, false);

		if (CharacterCheck) {
			inputWasCommon = function.checkCommonKeywords(i, modified_I, CharacterName, mathiasInv);
		}
		else {
			inputWasCommon = function.checkCommonKeywords(i, modified_I, CharacterName, archieInv);
		}

		if (!inputWasCommon) {
			//If it's under the "Talk" keyword
			if (modified_I == "Talk") {
				modified_I = function.splitInput(i, 0, true);
			}
		}

		if (i == "input arrived " + CharacterName + " position PastCity.EastEnd") {
			function.Transition(CharacterName, "PastCity.EastEnd", "PastForestPath.WestEnd");
			currentLocation = "PastForestPath";
		}

		if (modified_I == "Open") {
			function.Transition(CharacterName, "PastCity.GreenHouseDoor", "PastCottage.Door");
			currentLocation = "PastCottage";
		}

	}
}

void Chapter2::runPastRuins(bool CharacterCheck) {
	string CharacterName = "";
	string Enemy = "";
	bool inputWasCommon;

	if (CharacterCheck) {
		CharacterName = "Mathias";
		Enemy = "Archie";
	}
	else {
		CharacterName = "Archie";
		Enemy = "Mathias";
	}

	while (currentLocation == "PastRuins") {
		string i;
		getline(cin, i);

		//Gets the first word that isn't "input"
		modified_I = function.splitInput(i, 6, false);

		if (CharacterCheck) {
			inputWasCommon = function.checkCommonKeywords(i, modified_I, CharacterName, mathiasInv);
		}
		else {
			inputWasCommon = function.checkCommonKeywords(i, modified_I, CharacterName, archieInv);
		}

		if (!inputWasCommon) {
			//If it's under the "Talk" keyword
			if (modified_I == "Talk") {
				modified_I = function.splitInput(i, 0, true);

				if (modified_I == Enemy) {
					function.SetupDialog(CharacterName, Enemy, false);
					function.Action("SetDialog(\"(He appears to be mumbling to himself) [getAttention|(Get his attention)]\")", false);
				}
			}

			else if (modified_I == "Selected") {
				modified_I = function.splitInput(i, 0, true);

				if (modified_I == "getAttention") {
					function.Action("ClearDialog()", true);
					function.Action("SetDialog(\"Ah, " + CharacterName + "... you've arrived. I suppose this is inevitable. [question|What are you talking about?]\")", false);
				}

				if (modified_I == "question") {
					function.Action("ClearDialog()", true);
					function.Action("SetDialog(\"I'm afraid this relic is more powerful than either of us could ever have imagined. I cannot let it fall into another's hands. I am sorry, old friend. [wait|" + Enemy + ", wait-]\")", false);
				}

				if (modified_I == "wait") {
					function.Action("ClearDialog()", true);
					function.Action("HideDialog()", true);
					function.Action("DisableInput()", true);
					function.Action("WalkTo(" + Enemy + ", PastRuins.Altar)", true);
					function.Action("Face(" + Enemy + ", " + CharacterName + ")", true);
					function.Action("Cast(" + Enemy + ", " + CharacterName + ")", true); //This works for now, but will need to change Mathias to a sword
					function.Action("Kneel(" + CharacterName + ")", false);
					function.Action("Face(" + Enemy + ", MysteriousSkull)", true);
					function.Action("SetPosition(MysteriousSkull)", true);
					function.Action("Unpocket(" + Enemy + ", MysteriousSkull)", true);
					function.Action("WalkTo(" + Enemy + ", PastRuins.Exit)", true);
					function.Action("SetPosition(" + Enemy + ")", true);
					function.Action("WalkTo(" + CharacterName + ", PastRuins.Altar)", true);
					function.Action("FadeOut()", true);
					currentLocation = "CurrentRuins";
					function.Action("SetPosition(Arlan, CurrentRuins.Altar)", true);
					function.Action("Kneel(Arlan)", true);
					function.Action("SetCameraFocus(Arlan)", true);
					function.Action("FadeIn()", false);
					function.Action("WalkTo(Arlan, CurrentRuins.Altar)", false);
					function.Action("SetNarration(What an odd vision...)", true);
					function.Action("ShowNarration()", true);
				}
			}
		}
	}
}

void Chapter2::runForestPath2() {
	while (currentLocation == "ForestPath2") {
		string i;
		getline(cin, i);

		//Gets the first word that isn't "input"
		modified_I = function.splitInput(i, 6, false);

		bool inputWasCommon = function.checkCommonKeywords(i, modified_I, "Arlan", playerInv);

		if (!inputWasCommon) {
			
		}

		if (i == "input Search Well ForestPath2.Well") {
			function.WalkToPlace("Arlan", "ForestPath2.Well");
			function.Action("SetNarration(There is a sword hidden inside the well! You take it.)", true);
			function.Action("ShowNarration()", true);
			playerInv.push_back("PrisonerSword");
			hasSecondPrisItem = true;
		}

		else if (i == "input arrived Arlan position ForestPath2.WestEnd") {
			function.Transition("Arlan", "ForestPath2.WestEnd", "CurrentCastleCrossroads.EastEnd");
			currentLocation = "CurrentCastleCrossroads";
		}

		if (i == "input TakeCoin3 ForestPath2.Well") {
			function.WalkToPlace("Arlan", "ForestPath2.Well");
			function.Action("SetNarration(Theres a gold coin on the edge of the well! You take it.)", true);
			function.Action("ShowNarration()", true);
			playerInv.push_back("Coin3");
			numCoins++;
			function.Action("DisableIcon(TakeCoin3, ForestPath2.Well)", true);
		}

		else if (i == "input arrived Arlan position ForestPath2.EastEnd") {
			function.Transition("Arlan", "ForestPath2.EastEnd", "CurrentTown.WestEnd");
			currentLocation = "CurrentTown";
		}
	}
}

void Chapter2::runCurrentCastleCrossroads() {
	while (currentLocation == "CurrentCastleCrossroads") {
		string i;
		getline(cin, i);

		//Gets the first word that isn't "input"
		modified_I = function.splitInput(i, 6, false);

		bool inputWasCommon = function.checkCommonKeywords(i, modified_I, "Arlan", playerInv);

		if (!inputWasCommon) {

		}

		//CurrentPort
		if (i == "input arrived Arlan position CurrentCastleCrossroads.WestEnd") {
			function.Transition("Arlan", "CurrentCastleCrossroads.WestEnd", "CurrentPort.Exit");
			currentLocation = "CurrentPort";
		}
		//ForestPath2
		else if (i == "input arrived Arlan position CurrentCastleCrossroads.EastEnd") {
			function.Transition("Arlan", "CurrentCastleCrossroads.EastEnd", "ForestPath2.WestEnd");
			currentLocation = "ForestPath2";
		}
		//CurrentGreatHall
		else if (i == "input arrived Arlan position CurrentCastleCrossroads.Gate") {
			function.Transition("Arlan", "CurrentCastleCrossroads.Gate", "CurrentGreatHall.Gate");
			currentLocation = "CurrentGreatHall";
		}
	}
}

void Chapter2::runCurrentGreatHall() {
	while (currentLocation == "CurrentGreatHall") {
		string i;
		getline(cin, i);

		//Gets the first word that isn't "input"
		modified_I = function.splitInput(i, 6, false);

		bool inputWasCommon = function.checkCommonKeywords(i, modified_I, "Arlan", playerInv);

		if (!inputWasCommon) {

		}

		//CurrentCastleCrossroads
		if (i == "input arrived Arlan position CurrentGreatHall.Gate") {
			function.Transition("Arlan", "CurrentGreatHall.Gate", "CurrentCastleCrossroads.Gate");
			currentLocation = "CurrentCastleCrossroads";
		}
		//LeftHallway
		else if (i == "input Enter Left Door CurrentGreatHall.LeftDoor") {
			function.Transition("Arlan", "CurrentGreatHall.LeftDoor", "LeftHallway.Door");
			currentLocation = "LeftHallway";
		}
		//RightHallway
		else if (i == "input Enter Right Door CurrentGreatHall.RightDoor") {
			function.Transition("Arlan", "CurrentGreatHall.RightDoor", "RightHallway.Door");
			currentLocation = "RightHallway";
		}
		//CurrentStorage
		else if (i == "input Enter Basement Door CurrentGreatHall.BasementDoor") {
			if (!hasGreenPotion /* && mathiasBranch */) {
				function.Transition("Arlan", "CurrentGreatHall.BasementDoor", "CurrentStorage.Door");
				currentLocation = "CurrentStorage";
			}
			else if (hasGreenPotion || hasBlueBook || hasBluePotion) {
				if (hasGreenPotion) {
					function.Action("SetNarration(You have already reaped the rewards of this room. Your Potion Of Cleansing urges you to adventure elsewhere.)", true);
				}
				else if (hasBlueBook || hasBluePotion) {
					function.Action("SetNarration(Your blue artifact repels you from this room.)", true);
				}
				function.Action("ShowNarration()", true);
			}
			/*else if (!mathiasBranch) {
				function.Action("SetNarration(An ominous force repels you from this room.)", true);
				function.Action("ShowNarration()", true);
			}*/
		}

		else if (i == "input TakeCoin5 Coin5") {
			function.WalkToPlace("Arlan", "CurrentGreatHall.Table");
			function.Action("SetNarration(You take the gold coin.)", true);
			function.Action("ShowNarration()", true);
			playerInv.push_back("Coin5");
			numCoins++;
			function.Action("SetPosition(Coin5)", true);
			function.Action("DisableIcon(TakeCoin5, Coin5)", true);
		}
	}
}

void Chapter2::runCurrentPort() {
	while (currentLocation == "CurrentPort") {
		string i;
		getline(cin, i);

		//Gets the first word that isn't "input"
		modified_I = function.splitInput(i, 6, false);

		bool inputWasCommon = function.checkCommonKeywords(i, modified_I, "Arlan", playerInv);

		if (!inputWasCommon) {
			//If it's under the "Talk" keyword
			if (modified_I == "Talk") {
				modified_I = function.splitInput(i, 0, true);

				if (modified_I == "PortMerchant") {
					function.SetupDialog("Arlan", "PortMerchant", true);
					if (hasCompass) {
						function.SetupDialogText("That compass was my last item. Sorry!", "end", "Okay!");
					}
					else {
						function.SetupDialogText("High quality ship wares for sale! Our newest item is a top notch compass! Interested? Only five gold pieces!", "buyCompass", "Ill take it!", "end", "No thanks.");
					}
				}

				else if (modified_I == "Sailor") {
					function.SetupDialog("Arlan", "Sailor", true);
					if (hasCompass) {
						function.SetupDialogText("Ah! That compass! I cannot sail again until I have one just like that. Would you be willing to trade it for a valuable relic I found at sea?", "giveCompass", "Sure!", "end", "No thanks.");
					}
					else {
						function.SetupDialogText("You there! Care to help an old sailor out? I cant sail again until I have a compass. That merchant over there is selling one but he refuses to take sea shells as payment. Could you get it for me? I'll trade you an artifact I found at sea for it!", "end", "Ill see what I can do.");
					}
				}
			}

			else if (modified_I == "Selected") {
				modified_I = function.splitInput(i, 0, true);

				if (modified_I == "buyCompass") {
					if (numCoins >= 5) {
						function.SetupDialogText("Here you are! Watch out for that sailor over there. He has been eyeballing that compass for a while now.", "endPortMerchant", "Okay. Thanks!");
					}
					else if (hasBlueBook) {
						function.SetupDialogText("Thanks again for your help! Ill be heading out again soon thanks to you!", "end", "No worries!");
					}
					else {
						function.SetupDialogText("Ah. My apologies. It seems you dont quite have enough coin. Im sure you could find some scattered about the kingdom if you looked hard enough.", "end", "Okay!");
					}
				}

				else if (modified_I == "endPortMerchant") {
					function.Action("ClearDialog()", true);
					function.Action("HideDialog()", true);
					function.RemoveItem("Coin1", playerInv);
					function.RemoveItem("Coin2", playerInv);
					function.RemoveItem("Coin3", playerInv);
					function.RemoveItem("Coin4", playerInv);
					function.RemoveItem("Coin5", playerInv);
					numCoins = 0;
					playerInv.push_back("Compass");
					hasCompass = true;
					function.Action("SetNarration(A compass has been added to your inventory. 5 coins have been removed.)", true);
					function.Action("ShowNarration()", true);
				}

				else if (modified_I == "giveCompass") {
					function.SetupDialogText("Finally! I can sail again! Here. You can have this old book I found at sea. Seems valuable!", "endSailor", "Thanks!");
					function.RemoveItem("Compass", playerInv);
					hasCompass = false;
					hasBlueBook = true;
				}

				else if (modified_I == "endSailor") {
					function.Action("ClearDialog()", true);
					function.Action("HideDialog()", true);
					function.RemoveItem("Compass", playerInv);
					hasCompass = false;
					playerInv.push_back("BookOfLore");
					hasBlueBook = true;
					function.Action("SetNarration(The Book of Lore has been added to your inventory. The compass has been removed.)", true);
					function.Action("ShowNarration()", true);
				}
			}
		}

		if (i == "input TakeCoin4 CurrentPort.Barrel") {
			function.WalkToPlace("Arlan", "CurrentPort.Barrel");
			function.Action("SetNarration(Theres a gold coin in the barrel! You take it.)", true);
			function.Action("ShowNarration()", true);
			playerInv.push_back("Coin4");
			numCoins++;
			function.Action("DisableIcon(TakeCoin4, CurrentPort.Barrel)", true);
		}

		else if (i == "input ReadBookOfLore BookOfLore") {
			function.Action("HideList()", true);
			function.Action("ClearList()", true);
			function.Action("SetNarration(The book describes an ancient tome that instills its owner with unimaginable power. Those who posess it are said to be destined to rule to world.)", true);
			function.Action("ShowNarration()", true);
		}

		//CurrentCastleCrossroads
		else if (i == "input arrived Arlan position CurrentPort.Exit") {
			function.Transition("Arlan", "CurrentPort.Exit", "CurrentCastleCrossroads.WestEnd");
			currentLocation = "CurrentCastleCrossroads";
		}
	}
}

void Chapter2::runCurrentLibrary() {
	bool libraryLeftOccupied = true;
	bool libraryCenterOccupied = true;
	bool libraryRightOccupied = true;
	libraryApplePositionCorrect = false;
	libraryGoldCupPositionCorrect = false;
	libraryGreenKeyPositionCorrect = false;
	while (currentLocation == "CurrentLibrary") {
		string i;
		getline(cin, i);
		//function.Action("SetLeft(Arlan)", true);

		//Gets the first word that isn't "input"
		modified_I = function.splitInput(i, 6, false);

		bool inputWasCommon = function.checkCommonKeywords(i, modified_I, "Arlan", playerInv);

		if (!inputWasCommon) {

		}

		if (libraryApplePositionCorrect && libraryGoldCupPositionCorrect && libraryGreenKeyPositionCorrect && !hasGreenBook) {
			libraryPuzzleSolved = true;
			function.Action("SetPosition(Book Of Incantations, CurrentLibrary.Table)", true);
			function.Action("CreateEffect(Book Of Incantations, Resurrection)", true);
			function.Action("EnableEffect(Book Of Incantations, Resurrection)", true);
		}

		/*
		CurrentLibrary.icons.push_back(Icon("Library Alchemist Table", "Hand", "CurrentLibrary.AlchemistTable", "Interact With Alchemist Table", "true"));
		CurrentLibrary.icons.push_back(Icon("Library Table", "Hand", "CurrentLibrary.Table", "Interact With Table", "true"));
		CurrentLibrary.icons.push_back(Icon("Library Spellbook", "Hand", "CurrentLibrary.SpellBook", "Read Spellbook", "true"));
		CurrentLibrary.icons.push_back(Icon("Library Chair", "Hand", "CurrentLibrary.Chair", "Rest", "true"));
		*/

		//RightHallway
		if (i == "input arrived Arlan position CurrentLibrary.Door") {
			function.Action("SetNarration(The puzzle resets...)", true);
			function.RemoveItem("Library Apple", playerInv);
			function.RemoveItem("Library GoldCup", playerInv);
			function.RemoveItem("Library GreenKey", playerInv);
			function.Action("SetPosition(Library GoldCup)", true);
			function.Action("SetPosition(Library GreenKey)", true);
			function.Action("SetPosition(Library Apple)", true);
			function.Action("SetPosition(Library GoldCup, CurrentLibrary.AlchemistTable.Right)", true);
			function.Action("SetPosition(Library GreenKey, CurrentLibrary.AlchemistTable.Left)", true);
			function.Action("SetPosition(Library Apple, CurrentLibrary.AlchemistTable.Center)", true);
			hasLibraryApple = false;
			hasLibraryGoldCup = false;
			hasLibraryGreenKey = false;
			function.Transition("Arlan", "CurrentLibrary.Door", "RightHallway.Stairs");
			function.Action("ShowNarration()", true);
			currentLocation = "RightHallway";
		}

		else if (i == "input Library Table CurrentLibrary.Table") {
			function.WalkToPlace("Arlan", "CurrentLibrary.Table");
			if (libraryPuzzleSolved && hasGreenBook) {
				function.Action("SetNarration(You already won.)", true);
				function.Action("ShowNarration()", true);
			}

			else if (!libraryPuzzleSolved && !hasGreenBook) {
				function.SetupDialogText("Restore the order.", "end", "**Walk Away**");
				function.Action("ShowDialog()", true);
			}

			else if (libraryPuzzleSolved && !hasGreenBook) {
				function.Action("SetNarration(This book speaks of a powerful incantation used for removing corrupting spirits from their vessels. Book Of Incantations Added To Inventory.)", true);
				function.Action("ShowNarration()", true);
				//function.Action("DisableEffect(Book Of Incantations, Resurrection)", true);
				function.Action("SetPosition(Book Of Incantations)", true);
				playerInv.push_back("Book Of Incantations");
				hasGreenBook = true;
				function.SetupDialogText("The Book Of Incantations pulls you away.", "leaveLibrary", "Oh...?");
				function.Action("ShowDialog()", true);
			}
		}

		else if (i == "input Selected leaveLibrary") {
			function.Action("HideDialog()", true);
			function.Action("FadeOut()", true);
			function.Action("SetPosition(Arlan, RightHallway.Stairs)", true);
			this_thread::sleep_for(chrono::milliseconds(3000));
			function.Action("FadeIn()", true);
			currentLocation = "RightHallway";
		}

		else if (i == "input Library Spellbook CurrentLibrary.SpellBook") {
			function.WalkToPlace("Arlan", "CurrentLibrary.SpellBook");
			function.SetupDialogText("Restore the order to reveal an Incantation.", "end", "Hmm...");
			function.Action("ShowDialog()", true);
		}

		else if (i == "input Library Alchemist Table CurrentLibrary.AlchemistTable") {
			function.WalkToPlace("Arlan", "CurrentLibrary.AlchemistTable");
			function.Action("ShowDialog()", true);
			if (libraryPuzzleSolved) {
				function.SetupDialogText("The order has been restored.", "end", "**Walk Away**");
			}

			else {
				function.SetupDialogText("What would you like to do?", "placeLibraryItem", "Place An Item.", "pickUpLibraryItem", "Take All Items.");
			}
		}

		else if (i == "input Selected placeLibraryItem") {
			function.SetupDialogText("Which item would you like to place?", "placeLibraryApple", "Apple", "placeLibraryGreenKey", "Green Key", "placeLibraryGoldCup", "Gold Cup");
		}

		else if (i == "input Selected placeLibraryApple") {
			function.SetupDialogText("Where would you like to place the apple?", "placeLibraryAppleLeft", "Left", "placeLibraryAppleCenter", "Center", "placeLibraryAppleRight", "Right");
		}

		else if (i == "input Selected placeLibraryGoldCup") {
			function.SetupDialogText("Where would you like to place the gold cup?", "placeLibraryGoldCupLeft", "Left", "placeLibraryGoldCupCenter", "Center", "placeLibraryGoldCupRight", "Right");
		}

		else if (i == "input Selected placeLibraryGreenKey") {
			function.SetupDialogText("Where would you like to place the green key?", "placeLibraryGreenKeyLeft", "Left", "placeLibraryGreenKeyCenter", "Center", "placeLibraryGreenKeyRight", "Right");
		}

		else if (i == "input Selected placeLibraryAppleLeft") {
			function.LibraryItem("place", "Library Apple", "Left", libraryLeftOccupied, hasLibraryApple, libraryApplePositionCorrect, playerInv);
			//libraryApplePositionCorrect = true;
			//hasLibraryApple = false;
		}

		else if (i == "input Selected placeLibraryAppleCenter") {
			function.LibraryItem("place", "Library Apple", "Center", libraryCenterOccupied, hasLibraryApple, libraryApplePositionCorrect, playerInv);
			//libraryApplePositionCorrect = false;
			//hasLibraryApple = false;
		}

		else if (i == "input Selected placeLibraryAppleRight") {
			function.LibraryItem("place", "Library Apple", "Right", libraryRightOccupied, hasLibraryApple, libraryApplePositionCorrect, playerInv);
			//libraryApplePositionCorrect = false;
			//hasLibraryApple = false;
		}

		else if (i == "input Selected placeLibraryGoldCupLeft") {
			function.LibraryItem("place", "Library GoldCup", "Left", libraryLeftOccupied, hasLibraryGoldCup, libraryGoldCupPositionCorrect, playerInv);
			//libraryGoldCupPositionCorrect = false;
			//hasLibraryGoldCup = false;
		}

		else if (i == "input Selected placeLibraryGoldCupCenter") {
			function.LibraryItem("place", "Library GoldCup", "Center", libraryCenterOccupied, hasLibraryGoldCup, libraryGoldCupPositionCorrect, playerInv);
			//libraryGoldCupPositionCorrect = true;
			//hasLibraryGoldCup = false;
		}

		else if (i == "input Selected placeLibraryGoldCupRight") {
			function.LibraryItem("place", "Library GoldCup", "Right", libraryRightOccupied, hasLibraryGoldCup, libraryGoldCupPositionCorrect, playerInv);
			//libraryGoldCupPositionCorrect = false;
			//hasLibraryGoldCup = false;
		}

		else if (i == "input Selected placeLibraryGreenKeyLeft") {
			function.LibraryItem("place", "Library GreenKey", "Left", libraryLeftOccupied, hasLibraryGreenKey, libraryGreenKeyPositionCorrect, playerInv);
			//libraryGreenKeyPositionCorrect = false;
			//hasLibraryGreenKey = false;
		}

		else if (i == "input Selected placeLibraryGreenKeyCenter") {
			function.LibraryItem("place", "Library GreenKey", "Center", libraryCenterOccupied, hasLibraryGreenKey, libraryGreenKeyPositionCorrect, playerInv);
			//libraryGreenKeyPositionCorrect = false;
			//hasLibraryGreenKey = false;
		}

		else if (i == "input Selected placeLibraryGreenKeyRight") {
			function.LibraryItem("place", "Library GreenKey", "Right", libraryRightOccupied, hasLibraryGreenKey, libraryGreenKeyPositionCorrect, playerInv);
			//libraryGreenKeyPositionCorrect = true;
			//hasLibraryGreenKey = false;
		}

		else if (i == "input Selected pickUpLibraryItem") {
			function.LibraryItem("take", "Library Apple", "onObject", libraryLeftOccupied, hasLibraryApple, libraryApplePositionCorrect, playerInv);
			this_thread::sleep_for(chrono::milliseconds(1000));
			//libraryApplePositionCorrect = false;
			//hasLibraryApple = true;
			function.LibraryItem("take", "Library GoldCup", "onObject", libraryCenterOccupied, hasLibraryGoldCup, libraryGoldCupPositionCorrect, playerInv);
			this_thread::sleep_for(chrono::milliseconds(1000));
			//libraryGoldCupPositionCorrect = false;
			//hasLibraryGoldCup = true;
			function.LibraryItem("take", "Library GreenKey", "onObject", libraryRightOccupied, hasLibraryGreenKey, libraryGreenKeyPositionCorrect, playerInv);
			//libraryGreenKeyPositionCorrect = false;
			//hasLibraryGreenKey = true;
			//function.SetupDialogText("Which item would you like to take?", "pickUpLibraryApple", "Apple", "pickUpLibraryGreenKey", "Green Key", "pickUpLibraryGoldCup", "Gold Cup");
		}

		/*else if (i == "input Selected pickUpLibraryApple") {
			function.LibraryItem("take", "Library Apple", "onObject", hasLibraryApple, playerInv);
			libraryApplePositionCorrect = false;
			hasLibraryApple = true;
		}

		else if (i == "input Selected pickUpLibraryGoldCup") {
			function.LibraryItem("take", "Library GoldCup", "onObject", hasLibraryGoldCup, playerInv);
			libraryGoldCupPositionCorrect = false;
			hasLibraryGoldCup = true;
		}

		else if (i == "input Selected pickUpLibraryGreenKey") {
			function.LibraryItem("take", "Library GreenKey", "onObject", hasLibraryGreenKey, playerInv);
			libraryGreenKeyPositionCorrect = false;
			hasLibraryGreenKey = true;
		}*/

		else if (i == "input Selected end") {
			function.Action("HideDialog()", true);
		}

		else if (i == "input Key Inventory") {
			function.Action("ClearList()", true);
			for (string item : playerInv) {
				function.Action("AddToList(" + item + ")", true);
			}
			function.Action("ShowList(Arlan)", true);
		}

		else if (i == "input Close List") {
			function.Action("HideList()", true);
			function.Action("EnableInput()", true);
		}
	}
}

void Chapter2::runCurrentStorage() {
	bool storageLeftOccupied = false;
	bool storageRightOccupied = false;
	bool potionSpawned = false;
	bool chestOpened = false;
	storageBreadPositionCorrect = false;
	storageBottlePositionCorrect = false;
	string position = "";
	//string itemName = "";
	while (currentLocation == "CurrentStorage") {
		string i;
		getline(cin, i);

		//Gets the first word that isn't "input"
		modified_I = function.splitInput(i, 6, false);

		bool inputWasCommon = function.checkCommonKeywords(i, modified_I, "Arlan", playerInv);

		if (!inputWasCommon) {

		}

		/*
		CurrentStorage.icons.push_back(Icon("Storage Chest", "Hand", "CurrentStorage.Chest", "Take All Storage Items", "true"));
		CurrentStorage.icons.push_back(Icon("Read Storage OpenScroll", "Hand", "Storage OpenScroll", "Read The Scroll", "true"));
		CurrentStorage.icons.push_back(Icon("Interact With Potion Of Cleansing", "Hand", "Potion Of Cleansing", "Take The Potion", "true"));
		CurrentStorage.icons.push_back(Icon("Place Items On Shelf", "Hand", "CurrentStorage.Shelf", "Place An Item On The Shelf", "true"));
		CurrentStorage.icons.push_back(Icon("Leave Storage", "Hand", "CurrentStorage.Door", "Leave", "true"));
		*/

		//CurrentGreatHall
		if (i == "input Leave Storage CurrentStorage.Door") {
			function.Action("SetNarration(The puzzle resets...)", true);
			function.RemoveItem("Storage Bottle", playerInv);
			function.RemoveItem("Storage Bread", playerInv);
			function.RemoveItem("Storage Helmet", playerInv);
			function.RemoveItem("Storage InkAndQuill", playerInv);
			function.RemoveItem("Storage Bag", playerInv);
			function.Action("SetPosition(Storage Bottle, CurrentStorage.Chest)", true);
			function.Action("SetPosition(Storage Bread, CurrentStorage.Chest)", true);
			function.Action("SetPosition(Storage Helmet, CurrentStorage.Chest)", true);
			function.Action("SetPosition(Storage InkAndQuill, CurrentStorage.Chest)", true);
			function.Action("SetPosition(Storage Bag, CurrentStorage.Chest)", true);
			hasStorageBottle = false;
			hasStorageBread = false;
			hasStorageHelmet = false;
			hasStorageInkAndQuill = false;
			hasStorageBag = false;
			function.Transition("Arlan", "CurrentStorage.Door", "CurrentGreatHall.BasementDoor");
			function.Action("ShowNarration()", true);
			currentLocation = "CurrentGreatHall";
		}

		/*
		THIS NEEDS TO BE IMPLEMENTED AS PART OF MY PUZZLE, BUT IT NEEDS TO NOT INTERACT WITH ANY OF THE STUFF AlREADY HERE
		if (i == "input Search Chest CurrentStorage.Chest") {
			function.WalkToPlace("Arlan", "CurrentStorage.Chest");
			function.Action("OpenFurniture(Arlan, CurrentStorage.Chest)", true);
			function.Action("SetNarration(There is a spare guard outfit inside! You take it.)", true);
			function.Action("ShowNarration()", true);
			playerInv.push_back("PrisonerOutfit");
			hasFirstPrisItem = true;
		}*/

		if (storageBreadPositionCorrect && storageBottlePositionCorrect && !hasGreenPotion && !potionSpawned) {
			storagePuzzleSolved = true;
			function.Action("SetPosition(Storage OpenScroll)", true);
			function.Action("SetPosition(Potion Of Cleansing, CurrentStorage.Barrel)", true);
			function.Action("CreateEffect(Potion Of Cleansing, Resurrection)", true);
			function.Action("EnableEffect(Potion Of Cleansing, Resurrection)", true);
			potionSpawned = true;
		}

		else if (i == "input Interact With Potion Of Cleansing Potion Of Cleansing") {
			function.Action("SetNarration(This potion can cleanse the evil spirits from the heart of men. Potion Of Cleansing Added To Inventory.)", true);
			function.Action("ShowNarration()", true);
			function.Action("SetPosition(Potion Of Cleansing)", true);
			playerInv.push_back("Potion Of Cleansing");
			hasGreenPotion = true;
			function.SetupDialogText("The Potion Of Cleansing pulls you away.", "leaveStorage", "Oh...?");
			function.Action("ShowDialog()", true);
		}

		else if (i == "input Selected leaveStorage") {
			function.RemoveItem("Storage Helmet", playerInv);
			function.RemoveItem("Storage InkAndQuill", playerInv);
			function.RemoveItem("Storage Bag", playerInv);
			function.Action("HideDialog()", true);
			function.Action("FadeOut()", true);
			function.Action("SetPosition(Arlan, CurrentGreatHall.BasementDoor)", true);
			this_thread::sleep_for(chrono::milliseconds(3000));
			function.Action("FadeIn()", true);
			currentLocation = "CurrentGreatHall";
		}

		else if (i == "input Storage Chest CurrentStorage.Chest") {
			if (!chestOpened) {
				function.StorageItem("take", "Storage Bread", "onObject", storageLeftOccupied, hasStorageBread, storageBreadPositionCorrect, playerInv);
				this_thread::sleep_for(chrono::milliseconds(1000));
				function.StorageItem("take", "Storage Bottle", "onObject", storageRightOccupied, hasStorageBottle, storageBottlePositionCorrect, playerInv);
				this_thread::sleep_for(chrono::milliseconds(1000));
				function.StorageItem("take", "Storage Bag", "onObject", storageLeftOccupied, hasStorageBag, storageBreadPositionCorrect, playerInv);
				this_thread::sleep_for(chrono::milliseconds(1000));
				function.StorageItem("take", "Storage Helmet", "onObject", storageLeftOccupied, hasStorageHelmet, storageBreadPositionCorrect, playerInv);
				this_thread::sleep_for(chrono::milliseconds(1000));
				function.StorageItem("take", "Storage InkAndQuill", "onObject", storageLeftOccupied, hasStorageInkAndQuill, storageBreadPositionCorrect, playerInv);
				this_thread::sleep_for(chrono::milliseconds(1000));
				chestOpened = true;
			}
			else if (chestOpened) {
				function.Action("SetNarration(The chest is empty.)", true);
				function.Action("ShowNarration()", true);
			}
		}

		else if (i == "input Place Items On Shelf CurrentStorage.Shelf") {
			function.WalkToPlace("Arlan", "CurrentStorage.Shelf");
			function.Action("ShowDialog()", true);
			if (storagePuzzleSolved) {
				function.SetupDialogText("The order has been restored.", "end", "**Walk Away**");
			}

			else {
				function.SetupDialogText("Where would you like to place an item?", "placeStorageLeft", "Left", "placeStorageRight", "Right");
			}
		}

		else if (i == "input Selected placeStorageLeft") {
			position = "Left";
			function.SetupDialogText("What item would you like to place?", "placeStorageBread", "Bread", "placeStorageBottle", "Bottle", "placeStorageBag", "Bag", "placeStorageHelmet", "Helmet", "placeStorageInkAndQuill", "InkAndQuill");
		}

		else if (i == "input Selected placeStorageRight") {
			position = "Right";
			function.SetupDialogText("What item would you like to place?", "placeStorageBread", "Bread", "placeStorageBottle", "Bottle", "placeStorageBag", "Bag", "placeStorageHelmet", "Helmet", "placeStorageInkAndQuill", "InkAndQuill");
		}

		else if (i == "input Selected placeStorageBread") {
			if (position == "Left") {
				function.StorageItem("place", "Storage Bread", position, storageLeftOccupied, hasStorageBread, storageBreadPositionCorrect, playerInv);
			}
			else if (position == "Right") {
				function.StorageItem("place", "Storage Bread", position, storageRightOccupied, hasStorageBread, storageBreadPositionCorrect, playerInv);
			}
		}

		else if (i == "input Selected placeStorageBottle") {
			if (position == "Left") {
				function.StorageItem("place", "Storage Bottle", position, storageLeftOccupied, hasStorageBottle, storageBottlePositionCorrect, playerInv);
			}
			else if (position == "Right") {
				function.StorageItem("place", "Storage Bottle", position, storageRightOccupied, hasStorageBottle, storageBottlePositionCorrect, playerInv);
			}
		}

		else if (i == "input Selected placeStorageBag") {
			if (position == "Left") {
				function.StorageItem("place", "Storage Bag", position, storageLeftOccupied, hasStorageBag, storageBreadPositionCorrect, playerInv);
			}
			else if (position == "Right") {
				function.StorageItem("place", "Storage Bag", position, storageRightOccupied, hasStorageBag, storageBreadPositionCorrect, playerInv);
			}
		}

		else if (i == "input Selected placeStorageHelmet") {
			if (position == "Left") {
				function.StorageItem("place", "Storage Helmet", position, storageLeftOccupied, hasStorageHelmet, storageBreadPositionCorrect, playerInv);
			}
			else if (position == "Right") {
				function.StorageItem("place", "Storage Helmet", position, storageRightOccupied, hasStorageHelmet, storageBreadPositionCorrect, playerInv);
			}
		}

		else if (i == "input Selected placeStorageInkAndQuill") {
			if (position == "Left") {
				function.StorageItem("place", "Storage InkAndQuill", position, storageLeftOccupied, hasStorageInkAndQuill, storageBreadPositionCorrect, playerInv);
			}
			else if (position == "Right") {
				function.StorageItem("place", "Storage InkAndQuill", position, storageRightOccupied, hasStorageInkAndQuill, storageBreadPositionCorrect, playerInv);
			}
		}

		else if (i == "input Read Storage OpenScroll Storage OpenScroll") {
			//function.WalkToPlace("Arlan", "CurrentStorage.Barrel");
			function.SetupDialogText("In this storage some items reside in a chest.\\nSome are useless a red herring at its best.\\nSet a meal on the shelf for this particular test.\\nRemember that thirst is quenched from the right of the perspective of the guest.", "end", "**Walk Away**", "end", "reset");
			function.Action("ShowDialog()", true);
		}

		else if (i == "input Selected end") {
			function.Action("HideDialog()", true);
		}

		else if (i == "input Key Inventory") {
			function.Action("ClearList()", true);
			for (string item : playerInv) {
				function.Action("AddToList(" + item + ")", true);
			}
			function.Action("ShowList(Arlan)", true);
		}

		else if (i == "input Close List") {
			function.Action("HideList()", true);
			function.Action("EnableInput()", true);
		}
	}
}

void Chapter2::runCurrentPrison() {


	while (currentLocation == "CurrentPrison") {
		string i;
		getline(cin, i);

		//Gets the first word that isn't "input"
		modified_I = function.splitInput(i, 6, false);

		bool inputWasCommon = function.checkCommonKeywords(i, modified_I, "Arlan", playerInv);

		if (!inputWasCommon) {
			if (modified_I == "Talk_To_Prisoner") {
				if (firstTalkPris == true) {
					function.SetupDialog("Arlan", "Prisoner", false);
					//function.Action("SetDialog(\"Oh hey nice to see you there! I have a question for you [Question|What is that?]\")", false);
					function.SetupDialogText("Oh hey nice to see you there! I have a question for you", "Question", "What is that?");
				}
				else if (hasFirstPrisItem || hasSecondPrisItem || hasThirdPrisItem) {
					function.SetupDialog("Arlan", "Prisoner", false);
					if (hasFirstPrisItem) {
						function.SetupDialogText("Thank you for finding that outfit for me. Here is the next one", "RiddleTwo", "Hit me with it");

						ForestPath2.icons.push_back(Icon("Search Well", "hand", "ForestPath2.Well", "Search Well", "true"));
						function.SetupIcons(ForestPath2.icons);

						hasFirstPrisItem = false;
						firstPrisRiddle = true;
					}
					if (hasSecondPrisItem) {
						//function.SetupDialogText("We are almost there! This is the last one", "RiddleThree", "I am ready");
						hasSecondPrisItem = false;
						function.SetupDialogText("That seems to be everything! I can finally get out of here. Here take this potion like I promised", "EndQuest", "Sweet!");

						//function.WalkToPlace("Arlan", "ForestPath2.Well");

					}
					//if (hasThirdPrisItem) {

					//}
				}
				else {
					function.SetupDialog("Arlan", "Prisoner", false);
					if (firstPrisRiddle == false) {
						function.SetupDialogText("I see you have not found the previous item yet. Here is what I said again in case you need it", "RiddleOne", "Thanks");
					}
					else if (secondPrisRiddle == false) {
						function.SetupDialogText("I see you have not found the previous item yet. Here is what I said again in case you need it", "RiddleTwo", "Thanks");
					}
					//else {
					//	function.SetupDialogText("I see you have not found the previous item yet. Here is what I said again in case you need it", "RiddleThree", "Thanks");
					//}
				}


			}

			else if (modified_I == "Selected") {
				modified_I = function.splitInput(i, 0, true);

				if (modified_I == "Question") {
					function.Action("ClearDialog()", true);
					function.SetupDialogText("Ah well see. I was wondering if you could help me escape from this place? I definitely did not do the crime and could pay you in some weird potion I found earlier if you help", "StartQuest", "A Potion? I am definitely in!", "DialogEnd", "Uh no you are a criminal");
					//	function.Action("SetDialog(\"Ah well see. I was wondering if you could help me escape from this place? I definitely did not do the crime and could pay you in some weird potion I found earlier if you help [StartQuest|A Potion? I am definitely in!][DenyQuest|Uh no you are a criminal]\")", false);
				}
				else if (modified_I == "DialogEnd") {
					function.Action("ClearDialog()", true);
					function.Action("HideDialog()", true);
				}
				else if (modified_I == "StartQuest") {
					function.SetupDialogText("Great thanks! So I need you to find me three things. A guard outfit and a sword as a disguise. And a key to get me out of this cage. Sound good?", "StartQuestCont", "Yeah so far");
				}
				else if (modified_I == "StartQuestCont") {
					function.SetupDialogText("Alright. Let me cast a location spell to give you a bit of guidance", "RiddleOne", "Wait what?");

					CurrentStorage.icons.push_back(Icon("Search Chest", "hand", "CurrentStorage.Chest", "Search Chest", "true"));
					function.SetupIcons(CurrentStorage.icons);
				}
				else if (modified_I == "RiddleOne") {
					//Run some kind of spell animation here
					function.SetupDialogText("Long and forgotten in a dusty cluttered place. Someone wanted to store this armor for later", "DialogEnd", "Hmmm");
					firstTalkPris = false;
				}
				else if (modified_I == "RiddleThree") {
					function.SetupDialogText("Your final destination is where this awaits. Bullseye! You are right on target", "DialogEnd", "Hmmm");
				}
				else if (modified_I == "RiddleTwo") {
					function.SetupDialogText("Rusting this mighty sword faces the elements day and night. Waiting for the day the metal lifeboat above comes down to help", "DialogEnd", "Hmmm");
				}
				else if (modified_I == "EndQuest") {
					function.Action("SetNarration(Potion of Invincibility added to Inventory!)", true);
					function.Action("ShowNarration()", true);
					playerInv.push_back("RedPotion");
					function.Action("ClearDialog()", true);
					function.Action("HideDialog()", true);

					//function.Action("SetClothing(Prisoner, HeavyArmour)", false);
					//function.Action("WalkTo(Prisoner, CurrentPrison.CellDoor)", true);
					//function.Action("OpenFurniture(Prisoner, CurrentPrison.CellDoor)", true);
					//function.Transition("Prisoner", "CurrentPrison.Door", "LeftHallway.BackDoor");


					hasRedPotion = true;
				}

			}
		}

		//LeftHallway
		if (i == "input Open Door CurrentPrison.Door") {//"input arrived Arlan position CurrentPrison.Door") {
			function.Transition("Arlan", "CurrentPrison.Door", "LeftHallway.BackDoor");
			currentLocation = "LeftHallway";
		}
	}
}

void Chapter2::runLeftHallway() {
	while (currentLocation == "LeftHallway") {
		string i;
		getline(cin, i);

		//Gets the first word that isn't "input"
		modified_I = function.splitInput(i, 6, false);

		bool inputWasCommon = function.checkCommonKeywords(i, modified_I, "Arlan", playerInv);

		if (!inputWasCommon) {
			if (modified_I == "Talk_To_Guard") {
				function.Action("WalkTo(Arlan, PrisonGuard)", true);

				if (firstTalkGuard == true) {
					function.SetupDialog("Arlan", "PrisonGuard", false);
					function.SetupDialogText("Citizen! Do you happen to be any good at puzzles?", "Question", "Yeah I suppose");
				}
				else if (hasBedroomAnswer == false) {
					function.SetupDialog("Arlan", "PrisonGuard", false);
					function.SetupDialogText("You get lost? Go to the hallway in the other wing of the building. The puzzle should be in the bedroom", "DialogEnd", "Oh okay...");
				}
				else if (hasBedroomAnswer == true) {
					function.SetupDialog("Arlan", "PrisonGuard", false);
					function.SetupDialogText("You figured it out! The Kingdom is eternally thankful for your help. Have this weird potion I found laying around as a reward", "DialogEnd", "Accept the Potion");
					playerInv.push_back("Potion of Healing");
				}
			}
		}



		//CurrentPrison
		if (i == "input arrived Arlan position LeftHallway.BackDoor") {
			function.Transition("Arlan", "LeftHallway.BackDoor", "CurrentPrison.Door");
			currentLocation = "CurrentPrison";
		}
		//CurrentDiningRoom
		else if (i == "input arrived Arlan position LeftHallway.Stairs") {
			function.Transition("Arlan", "LeftHallway.Stairs", "CurrentDiningRoom.Door");
			currentLocation = "CurrentDiningRoom";
		}
		else if (i == "input arrived Arlan position LeftHallway.Door") {
			function.Transition("Arlan", "LeftHallway.Door", "CurrentGreatHall.LeftDoor");
			currentLocation = "CurrentGreatHall";
		}

		else if (modified_I == "Selected") {
			modified_I = function.splitInput(i, 0, true);

			if (modified_I == "DialogEnd") {
				function.Action("ClearDialog()", true);
				function.Action("HideDialog()", true);
			}

			if (modified_I == "Question") {
				function.SetupDialogText("Oh great. That prisoner in there hid some valuables from the Kingdom and said they would only return it if we could solve her puzzle. But we can not figure it out! Can you help?", "Accept", "Sounds good to me", "Reject", "I am a little busy");
			}

			if (modified_I == "Reject") {
				function.SetupDialogText("Ah too bad. Come talk to me again if you change your mind", "DialogEnd", "Ok");
			}

			if (modified_I == "Accept") {
				firstTalkGuard = false;
				function.SetupDialogText("Alright well you need to go to the Bedroom across the building. You can find the puzzle there. Come back and tell me once you figure it out. I can give you this weird potion I found as compensation", "DialogEnd", "A potion!");
			}

		}
	}
}

void Chapter2::runRightHallway() {
	while (currentLocation == "RightHallway") {
		string i;
		getline(cin, i);

		//Gets the first word that isn't "input"
		modified_I = function.splitInput(i, 6, false);

		bool inputWasCommon = function.checkCommonKeywords(i, modified_I, "Arlan", playerInv);

		if (!inputWasCommon) {

		}

		//CurrentCastleBedroom
		if (i == "input arrived Arlan position RightHallway.BackDoor") {
			function.Transition("Arlan", "RightHallway.BackDoor", "CurrentCastleBedroom.Door");
			currentLocation = "CurrentCastleBedroom";
		}
		else if (i == "input arrived Arlan position RightHallway.Door") {
			function.Transition("Arlan", "RightHallway.Door", "CurrentGreatHall.RightDoor");
			currentLocation = "CurrentGreatHall";
		}
		//CurrentLibrary
		else if (i == "input arrived Arlan position RightHallway.Stairs") {
			if (!hasGreenBook /* && mathiasBranch */) {
				function.Transition("Arlan", "RightHallway.Stairs", "CurrentLibrary.Door");
				currentLocation = "CurrentLibrary";
			}
			else if (hasGreenBook || hasBlueBook || hasBluePotion) {
				if (hasGreenBook) {
					function.Action("SetNarration(You have already reaped the rewards of this room. Your Book Of Incantations urges you to adventure elsewhere.)", true);
				}
				else if (hasBlueBook || hasBluePotion) {
					function.Action("SetNarration(Your blue artifact repels you from this room.)", true);
				}
				function.Action("ShowNarration()", true);
			}
			/*else if (!mathiasBranch) {
					function.Action("SetNarration(An ominous force repels you from this room.)", true);
					function.Action("ShowNarration()", true);
			}*/
		}

		else if (i == "input Selected end") {
			function.Action("HideDialog()", true);
		}

		else if (i == "input Key Inventory") {
			function.Action("ClearList()", true);
			for (string item : playerInv) {
				function.Action("AddToList(" + item + ")", true);
			}
			function.Action("ShowList(Arlan)", true);
		}

		else if (i == "input Close List") {
			function.Action("HideList()", true);
			function.Action("EnableInput()", true);
		}
	}
}

void Chapter2::runCurrentDiningRoom() {
	if (!visitedDiningRoom) {
		function.Action("DisableInput()", true);
		function.Action("Face(Arlan, Chef)", false);
		function.Action("WalkTo(Chef, Arlan)", true);
		function.SetupDialog("Arlan", "Chef", false);
		function.SetupDialogText("You there! Take these items and set the royal table! I am far too busy to be bothered with such petty tasks.", "chefOkay", "Okay...");
	}

	string currentChair;
	//string leftItem, frontLeftItem, frontRightItem, rightItem, backLeftItem, backRightItem = "";
	string appleLocation, bottleLocation, breadLocation, cupLocation, chaliceLocation, meatLocation = "";
	bool fireDoused = false;

	while (currentLocation == "CurrentDiningRoom") {
		string i;
		getline(cin, i);

		//Gets the first word that isn't "input"
		modified_I = function.splitInput(i, 6, false);

		bool inputWasCommon = function.checkCommonKeywords(i, modified_I, "Arlan", playerInv);

		if (!inputWasCommon) {

			if (modified_I == "Selected") {
				modified_I = function.splitInput(i, 0, true);

				if (modified_I == "chefOkay") {
					function.Action("SetNarration(The chef hands you a number of items.)", true);
					playerInv.push_back("DiningChalice");
					playerInv.push_back("DiningApple");
					playerInv.push_back("DiningBottle");
					playerInv.push_back("DiningBread");
					playerInv.push_back("DiningMeat");
					playerInv.push_back("DiningCup");
					function.Action("ShowNarration()", true);
					function.SetupDialogText("Be sure to check the note on each chair--they will tell you what each patron wants. Dont mess up!", "chefEnd", "Sure...");
				}

				if (modified_I == "chefEnd") {
					function.Action("Exit(Chef, CurrentDiningRoom.BackDoor, false", false);
					function.Action("ClearDialog()", true);
					function.Action("HideDialog()", true);
					function.Action("EnableInput()", true);
				}
			}

			else if (modified_I == "PlaceInChair") {
				// show "Dining" items in inventory, adjust interactions for each
				for (string item : playerInv) {
					if (item.substr(0, 6) == "Dining") {
						function.Action("AddToList(" + item + ")", true);
						function.Action("EnableIcon(Place, Hand, " + item + ", Place, true)", true);
						function.Action("DisableIcon(PickUp, " + item + ")", true);
					}
				}
				function.Action("ShowList(Arlan)", true);

				// set currentChair according to which chair player clicked
				modified_I = function.splitInput(i, 0, true);
				if (modified_I == "CurrentDiningRoom.LeftChair") currentChair = "Left";
				else if (modified_I == "CurrentDiningRoom.FrontLeftChair") currentChair = "FrontLeft";
				else if (modified_I == "CurrentDiningRoom.FrontRightChair") currentChair = "FrontRight";
				else if (modified_I == "CurrentDiningRoom.RightChair") currentChair = "Right";
				else if (modified_I == "CurrentDiningRoom.BackRightChair") currentChair = "BackRight";
				else if (modified_I == "CurrentDiningRoom.BackLeftChair") currentChair = "BackLeft";
			}
			
			else if (modified_I == "Place") {
				modified_I = function.splitInput(i, 0, true);

				for (string item : playerInv) {
					function.Action("DisableIcon(Place, " + item + ")", true);
				}

				function.Action("HideList()", true);
				function.Action("ClearList()", true);
				function.RemoveItem(modified_I, playerInv);
				function.Action("SetPosition(" + modified_I + ", CurrentDiningRoom.DiningTable." + currentChair + ")", true);
				function.Action("EnableIcon(PickUp, Hand, " + modified_I + ", Pick up, true)", true);
				//function.Action("DisableIcon(PlaceInChair, CurrentDiningRoom." + currentChair + "Chair)", true);

				/*if (currentChair == "Left") leftItem = modified_I;
				else if (currentChair == "FrontLeft") frontLeftItem = modified_I;
				else if (currentChair == "FrontRight") frontRightItem = modified_I;
				else if (currentChair == "Right") rightItem = modified_I;
				else if (currentChair == "BackLeft") backLeftItem = modified_I;
				else if (currentChair == "BackRight") backRightItem = modified_I;*/
				if (modified_I == "DiningApple") appleLocation = currentChair;
				else if (modified_I == "DiningBottle") bottleLocation = currentChair;
				else if (modified_I == "DiningBread") breadLocation = currentChair;
				else if (modified_I == "DiningCup") cupLocation = currentChair;
				else if (modified_I == "DiningChalice") chaliceLocation = currentChair;
				else if (modified_I == "DiningMeat") meatLocation = currentChair;

				bool placementCorrect = true;
				if (appleLocation != "BackLeft") placementCorrect = false;
				if (bottleLocation != "FrontLeft") placementCorrect = false;
				if (breadLocation != "Left") placementCorrect = false;
				if (cupLocation != "FrontRight") placementCorrect = false;
				if (chaliceLocation != "Right") placementCorrect = false;
				if (meatLocation != "BackRight") placementCorrect = false;
				if (placementCorrect) {
					function.Action("PlaySound(SecretDoor, CurrentDiningRoom.Fireplace)", false);
					function.Action("SetNarration(You hear a shifting noise near the fireplace.)", true);
					function.Action("ShowNarration()", true);

					function.Action("EnableIcon(Inspect, Hand, CurrentDiningRoom.Fireplace, Inspect the fireplace, true)", true);
				}
			}

			else if (modified_I == "PickUp") {
				modified_I = function.splitInput(i, 0, true);

				function.Action("SetPosition(" + modified_I + ")", true);
				playerInv.push_back(modified_I);
				function.Action("DisableIcon(PickUp, " + modified_I + ")", true);
				function.Action("EnableIcon(Place, Hand, " + modified_I + ", Place, true)", true);
				//function.Action("EnableIcon(PlaceInChair, Hand, CurrentDiningRoom.LeftChair, Place an item, false)", true);
			}

			else if (modified_I == "CheckNote") {
				modified_I = function.splitInput(i, 0, true);
				if (modified_I == "CurrentDiningRoom.LeftChair") {
					function.Action("SetNarration(Here shall sit the Queen. She shall only be satisfied by our bakerys finest.)", true);
					function.Action("ShowNarration()", true);
				}
				else if (modified_I == "CurrentDiningRoom.FrontLeftChair") {
					function.Action("SetNarration(Here shall sit the explorer. He shall need something portable to take on his adventures.)", true);
					function.Action("ShowNarration()", true);
				}
				else if (modified_I == "CurrentDiningRoom.FrontRightChair") {
					function.Action("SetNarration(Here shall sit the servant. He shall need only a modest container for water.)", true);
					function.Action("ShowNarration()", true);
				}
				else if (modified_I == "CurrentDiningRoom.RightChair") {
					function.Action("SetNarration(Here shall sit the King. He requires something suitably ornate.)", true);
					function.Action("ShowNarration()", true);
				}
				else if (modified_I == "CurrentDiningRoom.BackRightChair") {
					function.Action("SetNarration(Here shall sit the huntsman. He shall prefer something that reminds him of the hunt.)", true);
					function.Action("ShowNarration()", true);
				}
				else if (modified_I == "CurrentDiningRoom.BackLeftChair") {
					function.Action("SetNarration(Here shall sit the sailor. He shall prefer something that will help him ward off scurvy.)", true);
					function.Action("ShowNarration()", true);
				}
			}

			else if (modified_I == "Inspect") {
				if (fireDoused) {
					function.Action("SetNarration(You reach back and retrieve a Potion of Power from a hidden compartment in the fireplace.)", true);
					function.Action("ShowNarration()", true);
					playerInv.push_back("PotionOfPower");
				}
				else {
					bool hasCup = false;
					for (string item : playerInv) {
						if (item == "DiningCup") hasCup = true;
					}
					if (hasCup) {
						function.Action("SetNarration(You pour some water out of the servants cup and onto the flames to cool them off a bit.)", true);
						function.Action("ShowNarration()", true);
						fireDoused = true;
					}
					else {
						function.Action("SetNarration(Theres a small opening in the back of the fireplace. You reach for it--but the hot fire burns your hand. If only you had some water to douse it...)", true);
						function.Action("ShowNarration()", true);
					}
				}
			}

			else if (modified_I == "Drink") {
				function.Action("HideList()", true);
				function.Action("ClearList()", true);
				function.Action("Unpocket(Arlan, PotionOfPower)", true);
				function.Action("Drink(Arlan)", true);
				function.Action("SetNarration(You take a sip of the potion. Suddenly, images of a mysterious book adorned with a skull flash before your eyes. You feel stronger as the book calls out to you. You get the feeling should save to the rest of the potion.)", true);
				function.Action("ShowNarration()", true);
				function.Action("DisableIcon(Drink, PotionOfPower)", true);

				function.Action("FadeOut()", true);
				function.Action("SetPosition(Arlan, LeftHallway)", true);
				function.Action("FadeIn()", true);
				currentLocation = "LeftHallway";
			}
		}

		//LeftHallway
		if (i == "input Open CurrentDiningRoom.Door") {
			function.Transition("Arlan", "CurrentDiningRoom.Door", "LeftHallway.BackDoor");
			currentLocation = "LeftHallway";
		}

		/*if (i == "input Place DiningMeat") {
			function.Action("HideList()", true);
			function.Action("ClearList()", true);
			function.RemoveItem("DiningMeat", playerInv);
			function.Action("SetPosition(DiningMeat, CurrentDiningRoom.DiningTable." + currentChair + ")", true);
			function.Action("EnableIcon(Pick Up, Hand, DiningMeat, Pick up the meat, true)", true);
			function.Action("DisableIcon(Place, DiningMeat)", true);
			function.Action("DisableIcon(Place, CurrentDiningRoom." + currentChair + "Chair)", true);
		}
		*/

		/*if (i == "input Pick Up DiningMeat") {
			function.Action("SetPosition(DiningMeat)", true);
			playerInv.push_back("DiningMeat");
			function.Action("DisableIcon(Pick Up, DiningMeat)", true);
			function.Action("EnableIcon(Place, Hand, DiningMeat, Place, true)", true);
			function.Action("EnableIcon(Place, Hand, CurrentDiningRoom.LeftChair, Place an item, false)", true);
		}*/
	}
}

void Chapter2::runCurrentCourtyard() {
	while (currentLocation == "CurrentCourtyard") {
		string i;
		getline(cin, i);

		//Gets the first word that isn't "input"
		modified_I = function.splitInput(i, 6, false);

		bool inputWasCommon = function.checkCommonKeywords(i, modified_I, "Arlan", playerInv);

		if (!inputWasCommon) {

		}

		//CurrentTown
		if (i == "input arrived Arlan position CurrentCourtyard.Exit") {
			function.Transition("Arlan", "CurrentCourtyard.Exit", "CurrentTown.NorthEnd");
			currentLocation = "CurrentTown";
		}

		if (i == "input arrived Arlan position CurrentCourtyard.Gate") {
			if ((hasBlueBook && hasBluePotion) || (hasGreenBook && hasGreenPotion) || (hasRedBook && hasRedPotion) || (hasPurpleBook && hasPurplePotion)) {
				function.Transition("Arlan", "CurrentCourtyard.Gate", "CurrentCamp.Exit");
				currentLocation = "CurrentCamp";
			}
		}

		else if (i == "input Selected end") {
			function.Action("HideDialog()", true);
		}

		else if (i == "input Key Inventory") {
			function.Action("ClearList()", true);
			for (string item : playerInv) {
				function.Action("AddToList(" + item + ")", true);
			}
			function.Action("ShowList(Arlan)", true);
		}

		else if (i == "input Close List") {
			function.Action("HideList()", true);
			function.Action("EnableInput()", true);
		}
	}
}

void Chapter2::runCurrentCastleBedroom() {
	while (currentLocation == "CurrentCastleBedroom") {
		string i;
		getline(cin, i);

		//Gets the first word that isn't "input"
		modified_I = function.splitInput(i, 6, false);

		bool inputWasCommon = function.checkCommonKeywords(i, modified_I, "Arlan", playerInv);

		if (!inputWasCommon) {

		}


		if (modified_I == "Read_Puzzle") {
			function.Action("WalkTo(Arlan, CastleBedroomPuzzle)", true);
			function.Action("SetNarration(1. The Skull is in an even number spot \\n2. The Lock and the Gold Cup are in some order of spot 1 and 5 \\n3. The Ink and Quill are next to the Jewel Keyand the Bag \\n4. The Lock and the Jewel Key are across from each other \\n5. The Jewel Key is in a spot 1 lower than the Gold Cup)", true);
			function.Action("ShowNarration()", true);
			hasReadBedroomNote = true;
		}

		if (modified_I == "Search_Chest") {
			function.Action("WalkTo(Arlan, CastleBedroomPuzzle)", true);
			function.Action("OpenFurniture(Arlan, CurrentCastleBedroom.Chest)", true);
			function.Action("SetNarration(You found the note the Guard was looking for! You take it)", true);
			function.Action("ShowNarration()", true);
			playerInv.push_back("CastleBedroomCrime");
			hasBedroomAnswer = true;
		}

		if (modified_I == "Search_Bedroom_Closet") {
			//	function.Action("WalkTo(Arlan, CurrentCastleBedroom.Closet)", true);
			//	function.Action("OpenFurniture(Arlan, CurrentCastleBedroom.Closet)", true);
			//	function.WalkToPlace("Arlan", "CurrentCastleBedroom.Closet");  Might be a bug here
			function.Action("SetNarration(There are some items hidden in the closet! You take them)", true);
			function.Action("ShowNarration()", true);
			playerInv.push_back("CastleBedroomJewelKey");
			playerInv.push_back("CastleBedroomBag");
			playerInv.push_back("CastleBedroomLock");
			playerInv.push_back("CastleBedroomInkAndQuill");
			playerInv.push_back("CastleBedroomSkull");
			playerInv.push_back("CastleBedroomGoldCup");
			hasSearchedBedroomCloset = true;
		}

		if (modified_I == "Pickup" && hasSearchedBedroomCloset && hasReadBedroomNote) {
			modified_I = function.splitInput(i, 0, true);

			function.Action("WalkTo(Arlan, " + modified_I + ")", true);
			function.Action("Take(Arlan, " + modified_I + ")", true);
			playerInv.push_back(modified_I);
			function.Action("Pocket(Arlan, " + modified_I + ")", true);

			//function.Action("ShowDialog()", true);
			//function.Action("ClearDialog()", true);

			//function.Action("SetLeft(Arlan)", true);
			//function.SetupDialogText("Which item would you like to put in this spot?", "Lock", "Lock", "Bag", "Bag", "Skull", "Skull", "JewelKey", "Jewel Key", "InkAndQuill", "Ink and Quill", "GoldCup", "Gold Cup", "Apple", "Apple");
		}

		if (modified_I == "Pickup" && !(hasSearchedBedroomCloset && hasReadBedroomNote)) {
			function.Action("SetNarration(You feel you should probably fully inspect the room before you go about messing with these apples)", true);
			function.Action("ShowNarration()", true);
		}

		if (modified_I == "Selected") {

			modified_I == function.splitInput(i, 0, true);
			if (modified_I == "Lock" || modified_I == "Bag" || modified_I == "Skull" || modified_I == "JewelKey" || modified_I == "GoldCup" || modified_I == "InkAndQuill" || modified_I == "Apple") {
				//Put(Tom, "Coin", "DiningRoom.Table")
			}

		}

		//CurrentCastleBedroom
		if (i == "input arrived Arlan position CurrentCastleBedroom.Door") {
			function.Transition("Arlan", "CurrentCastleBedroom.Door", "RightHallway.BackDoor");
			currentLocation = "RightHallway";
		}
	}
}

void Chapter2::runCurrentCamp() {
	function.Action("SetPosition(Archie, CurrentCamp.Horse)", true);
	//function.WalkToPlace("Arlan", "Archie");
	function.SetupDialog("Arlan", "Archie", true);
	function.SetupDialogText("Ah... you've found me. The power stemming from my relic told me there would be some to try to come take it from me. No matter. You will be slain just like Mathias", "mathiasEnters", "Please dont do thi--");
	function.Action("ShowDialog()", true);
	while (currentLocation == "CurrentCamp") {
		string i;
		getline(cin, i);

		//Gets the first word that isn't "input"
		modified_I = function.splitInput(i, 6, false);

		bool inputWasCommon = function.checkCommonKeywords(i, modified_I, "Arlan", playerInv);

		if (!inputWasCommon) {

		}

		//CurrentCastleBedroom
		if (i == "input arrived Arlan position CurrentCamp.Exit") {
			function.Transition("Arlan", "CurrentCamp.Exit", "CurrentCourtyard.Gate");
			currentLocation = "CurrentCourtyard";
		}

		else if (i == "input Selected mathiasEnters") {
			function.Action("SetPosition(Mathias, CurrentCamp.RightLog", true);
			function.Action("WalkTo(Mathias, Archie)", true);
			this_thread::sleep_for(chrono::milliseconds(3000));
			function.SetupDialogText("Use the book to remove the corrupting power!", "reciteIncantation", "**Recite the incantation**");
		}

		else if (i == "input Selected reciteIncantation") {
			function.SetupDialogText("Test end", "end", "Done Test");
		}

		else if (i == "input Selected end") {
			function.Action("HideDialog()", true);
		}

		else if (i == "input Key Inventory") {
			function.Action("ClearList()", true);
			for (string item : playerInv) {
				function.Action("AddToList(" + item + ")", true);
			}
			function.Action("ShowList(Arlan)", true);
		}

		else if (i == "input Close List") {
			function.Action("HideList()", true);
			function.Action("EnableInput()", true);
		}
	}
}

void Chapter2::runCurrentCamp2() {
	while (currentLocation == "CurrentCamp2") {
		string i;
		getline(cin, i);

		//Gets the first word that isn't "input"
		modified_I = function.splitInput(i, 6, false);

		bool inputWasCommon = function.checkCommonKeywords(i, modified_I, "Arlan", playerInv);

		if (!inputWasCommon) {

		}

		//CurrentCastleBedroom
		if (i == "input arrived Arlan position CurrentCamp2.Exit") {
			function.Transition("Arlan", "CurrentCamp2.Exit", "CurrentCourtyard.Gate");
			currentLocation = "CurrentCourtyard";
		}

		if (i == "input OpenChest CurrentCamp2.Chest") {
			// walk to and interact with chest
			function.Action("OpenFurniture(Arlan, CurrentCamp2.Chest)", true);
			function.SetupDialog("Arlan", "null", false);
			function.SetupDialogText("A strange book adorned with a skull lies in the chest. You recognize it as the powerful artifact from your visions and the tome described in the book the sailor gave you. Will you take it?", "takeTome", "*Take the artifact.*", "leaveTome", "*Leave it.*");
			//function.Action("ShowDialog()", true);
		}

		else if (i == "input Selected takeTome") {
			function.Action("Take(Arlan, AncientTome, CurrentCamp2.Chest)", true);
			function.SetupDialogText("You take the tome into your hands. You feel a surge of incredible energy flowing through you. The power suddenly takes hold of your body and you begin to lose control.", "giveIn", "*GIVE IN.*");
		}

		else if (i == "input Selected giveIn") {
			function.Action("HideDialog()", true);
			function.Action("ClearDialog()", true);
			function.Action("DisableInput()", true);
			//function.Action("WalkTo(Arlan, CurrentCamp2.LeftLog)", true);
			function.Action("Face(Arlan, CurrentCamp2.Log)", true);
			function.Action("Cast(Arlan)", true);
			function.Action("SetPosition(Archie, CurrentCamp2)", true);
			function.Action("CreateEffect(Archie, Resurrection)", true);
			function.Action("Kneel(Arlan)", false);
			function.Action("WalkTo(Archie, Arlan)", true);
			function.SetupDialog("Arlan", "Archie", false);
			function.SetupDialogText("Finally! My soul has been sealed away for far too long... I have been waiting for some fool to come and free me. You have my thanks... but I will be taking that now.", "obey", "*OBEY.*");
		}

		else if (i == "input Selected obey") {
			function.Action("HideDialog()", true);
			function.Action("ClearDialog()", true);
			function.Action("Take(Archie, AncientTome, Arlan)", true);
			function.Action("Cast(Archie, Arlan)", true);
			function.Action("FadeOut()", true);
			function.Action("WalkTo(Archie, CurrentCamp2.Exit)", true);
			function.Action("SetPosition(Archie)", true);
			function.Action("SetPosition(Mathias, CurrentCamp2.Exit)", true);
			function.Action("FadeIn()", false);
			//function.Action("WalkTo(Mathias, CurrentCamp2.Chest)", true);
			//function.Action("Kneel(Mathias)", true);
			function.Action("WalkTo(Mathias, Arlan)", true);
			function.SetupDialog("Arlan", "Mathias", false);
			function.SetupDialogText("You okay kid?", "arlanOkay", "I think so... what happened?");
		}

		else if (i == "input Selected arlanOkay") {
			function.SetupDialogText("Looks like my old friend outwitted you. This is quite bad... I used that book to seal Archie away years ago. Kept the book a secret hoping that would be the end of it. I should have known it was only a matter of time before the book found someone else...", "arlanFound", "Found someone else?");
		}

		else if (i == "input Selected arlanFound") {
			function.SetupDialogText("Yeah... that book you found instills its wielder with immense power. Archie discovered it many years ago and used it to try and seize control of the kingdom. I got lucky and managed to stop him. Now he is going to attempt it again. He will be more prepared this time.", "stopArchie", "We have to stop him!");
		}

		else if (i == "input Selected stopArchie") {
			function.SetupDialogText("Indeed we must. Im afraid you may not be strong enough to take him on... unless... If you were able to come to this place you must have found the Potion of Power. Do you still have it?", "yesPotion", "You mean the one that gave me the strange visions?");
		}

		else if (i == "input Selected yesPotion") {
			function.SetupDialogText("Thats the one! Looks like you still have some left. Perfect! It will give you great strength. If we are to defeat him you must take the potion when I signal you and then strike him down. Here. Take this sword. You shall need it.", "okaySword", "Okay!");
		}

		else if (i == "input Selected okaySword") {
			function.Action("HideDialog()", true);
			function.Action("ClearDialog()", true);
			function.Action("WalkTo(Arlan, Arlan)", false);
			function.Action("Unpocket(Mathias, MathiasSword)", true);
			function.Action("Take(Arlan, MathiasSword, Mathias)", true);
			function.SetupDialogText("Archie likely fled to the place where this all started. We will confront him in the ruins. Follow me!", "letsGo", "Lets go!");
			function.Action("ShowDialog()", true);
		}

		else if (i == "input Selected letsGo") {
			function.Action("HideDialog()", true);
			function.Action("ClearDialog()", true);
			function.Action("WalkTo(Mathias, CurrentCamp2.Exit)", false);
			function.Action("WalkTo(Arlan, CurrentCamp2.Exit)", false);
			function.Action("FadeOut()", true);
			currentLocation = "FinalRuins";
		}

		else if (i == "input Selected leaveTome") {
			function.Action("HideDialog()", true);
			function.Action("ClearDialog()", true);
			function.Action("CloseFurniture(Arlan, CurrentCamp2.Chest)", true);
			function.Action("SetNarration(You leave the tome alone and close the chest. You feel the tome calling out to you. You have come this far... should you really leave it here?)", true);
			function.Action("ShowNarration()", true);
		}

		else if (i == "input Selected end") {
			function.Action("HideDialog()", true);
		}

		else if (i == "input Key Inventory") {
			function.Action("ClearList()", true);
			for (string item : playerInv) {
				function.Action("AddToList(" + item + ")", true);
			}
			function.Action("ShowList(Arlan)", true);
		}

		else if (i == "input Close List") {
			function.Action("HideList()", true);
			function.Action("EnableInput()", true);
		}
	}
}

void Chapter2::runFinalRuins() {
	function.Action("SetPosition(Archie, FinalRuins.Throne)", true);
	function.Action("Sit(Archie, FinalRuins.Throne)", true);
	function.Action("Enter(Mathias, FinalRuins.Exit, false)", true);
	function.Action("WalkTo(Mathias, FinalRuins.Altar)", false);
	function.Action("Enter(Arlan, FinalRuins.Exit, true)", true);
	function.Action("WalkToSpot(Arlan, 5983.3, 62.2, 98.5)", false);
	function.WaitFor("succeeded WalkTo(Mathias, FinalRuins.Altar)");
	function.Action("Face(Mathias, Archie)", false);
	function.WaitFor("succeeded WalkToSpot(Arlan, 5983.3, 62.2, 98.5)");
	function.Action("Face(Arlan, Archie)", false);
	function.Action("WalkToSpot(Archie, 5984.8, 62.5, 97.6)", true);
	function.SetupDialog("Arlan", "Archie", false);
	function.SetupDialogText("Ah... I see you two have met. You are bold to challenge me boy. But your courage is in vain. Not even my old rival Mathias can help you.", "beginFight", "We shall see. *Attack!*");
	while (currentLocation == "FinalRuins") {
		string i;
		getline(cin, i);

		//Gets the first word that isn't "input"
		modified_I = function.splitInput(i, 6, false);

		bool inputWasCommon = function.checkCommonKeywords(i, modified_I, "Arlan", playerInv);

		if (!inputWasCommon) {

		}


		if (i == "input Selected beginFight") {
			function.Action("HideDialog()", true);
			function.Action("ClearDialog()", false);
			function.Action("Draw(Mathias, MathiasSword2)", true);
			function.Action("Attack(Mathias, Archie, false)", true);
			function.Action("Cast(Archie, Mathias)", true);
			function.Action("Kneel(Mathias)", true);
			function.SetupDialog("Arlan", "Mathias", false);
			function.SetupDialogText("Arlan! Do it now!", "drinkPotion", "*Drink the potion*", "askWhat", "...Do what?");
			function.Action("Face(Archie, Arlan)", false);
		}

		else if (i == "input Selected askWhat") {
			function.SetupDialogText("Drink the potion you fool!", "drinkPotion", "Oh! Right!");
		}

		else if (i == "input Selected drinkPotion") {
			function.Action("HideDialog()", true);
			function.Action("ClearDialog()", false);
			function.Action("Pocket(Arlan, MathiasSword)", true);
			function.Action("Unpocket(Arlan, PotionOfPower)", true);
			function.Action("Drink(Arlan)", true);
			function.SetupDialog("Arlan", "null", false);
			function.SetupDialogText("The power of the potion surges through you. You feel... invincible.", "attackArchie", "*Attack!*");
		}

		else if (i == "input Selected attackArchie") {
			function.Action("HideDialog()", true);
			function.Action("ClearDialog()", false);
			function.Action("Pocket(Arlan, PotionOfPower)", true);
			function.Action("Draw(Arlan, MathiasSword)", true);
			function.Action("Attack(Arlan, Archie, true)", true);
			function.Action("Die(Archie)", true);
			function.Action("Sheathe(Arlan, MathiasSword)", true);
			function.Action("Face(Arlan, Mathias)", false);
			function.SetupDialog("Arlan", "Mathias", false);
			function.SetupDialogText("Finally... it is over. Goodbye old friend... You did well Arlan. If you will excuse me I need a moment to recover.", "ofCourse", "Of course!");
		}

		else if (i == "input Selected ofCourse") {
			function.Action("LookAt(Arlan, AncientTome)", false);
			function.Action("SetRight(null)", true);
			function.SetupDialogText("You hear the ancient tome summoning you once more. Its call is too difficult to resist.", "takeBook", "*TAKE THE BOOK.*");
		}

		else if (i == "input Selected takeBook") {
			function.Action("HideDialog()", true);
			function.Action("ClearDialog()", false);
			function.Action("Face(Arlan, Archie)", false);
			function.Action("Take(Arlan, AncientTome, Archie)", true);
			function.SetupDialogText("Ancient knowledge fills your mind. You feel a sudden sense of total clarity. A new thought creeps into your head... maybe Mathias has ulterior motives. He wants the power for himself. He must. You cannot allow him to take it.", "stopMathias", "*STOP HIM.*");
			function.Action("ShowDialog()", true);
		}

		else if (i == "input Selected stopMathias") {
			function.Action("Face(Arlan, Mathias)", false);
			function.Action("WalkTo(Mathias, FinalRuins.Altar)", false);
			function.Action("SetRight(Mathias)", true);
			function.Action("Face(Mathias, Arlan)", false);
			function.SetupDialogText("Arlan... what are you doing? That tome must be destroyed!", "finish", "HE MUST NOT BE ALLOWED TO TAKE IT.");
		}

		else if (i == "input Selected finish") {
			function.Action("HideDialog()", true);
			function.Action("ClearDialog()", false);
			function.Action("Draw(Arlan, MathiasSword)", true);
			function.Action("Attack(Arlan, Mathias, true)", true);
			function.Action("Die(Mathias)", true);
			function.Action("Sheathe(Arlan, MathiasSword)", true);
			function.Action("WalkTo(Arlan, FinalRuins.Throne)", true);
			function.Action("SetCameraMode(focus)", false);
			function.Action("Sit(Arlan, FinalRuins.Throne)", true);
			function.Action("FadeOut()", true);
			function.Action("SetNarration(THE END.)", true);
			function.Action("ShowNarration()", true);
		}

		else if (i == "input Selected end") {
			function.Action("HideDialog()", true);
		}

		else if (i == "input Key Inventory") {
			function.Action("ClearList()", true);
			for (string item : playerInv) {
				function.Action("AddToList(" + item + ")", true);
			}
			function.Action("ShowList(Arlan)", true);
		}

		else if (i == "input Close List") {
			function.Action("HideList()", true);
			function.Action("EnableInput()", true);
		}
	}
}