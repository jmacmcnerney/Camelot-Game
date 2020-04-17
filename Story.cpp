/* Project: Camelot Narrative Story + Experience Manager
-- Project Description: An experience manager for the Camelot Virtual Environment.
-- Authors: John (Mac) McNerney, Zac Foster, John Colfer, Jake Hayden
-- File: Story.cpp
-- File Description: Chapter 2 execution.
*/
#include "Story.h"
#include <chrono>
#include <thread>
#include <vector>
#include <string>
using namespace std;

vector<string> playerInv;

//location boolean
string currentLocation = "ArlanCottage";

//event booleans


//Intro Quest Booleans
//Cottage
bool hasStorybook = false;
//City
bool hasBrokenLock = false;
bool hasFixedLock = false;
bool hasAppleMoney = false;
bool hasElderApple = false;
bool visitedFortuneteller = false;
bool visitedTownElder = false;
bool completedErrand = false;
//Ruins
bool sword_taken = false;
bool spellbook_taken = false;
bool item_placed = false;

//Flashback Booleans
bool ArchieEnemy = false;
bool MathiasFlashback = false;
bool ArchieFlashback = false;

//Green Puzzle Booleans
//Potion
bool hasGreenPotion = true;
bool hasStorageBottle = false;
bool hasStorageBread = false;
bool hasStorageHelmet = false;
bool hasStorageInkAndQuill = false;
bool hasStorageBag = false;
bool storageBreadPositionCorrect = false;
bool storageBottlePositionCorrect = false;
bool storagePuzzleSolved = false;
//Book
bool hasGreenBook = true;
bool hasLibraryGoldCup = false;
bool hasLibraryApple = false;
bool hasLibraryGreenKey = false;
bool libraryApplePositionCorrect = false;
bool libraryGoldCupPositionCorrect = false;
bool libraryGreenKeyPositionCorrect = false;
bool libraryPuzzleSolved = false;

//Blue Puzzle Booleans
//Potion
bool hasBluePotion = false;
//Book
bool hasBlueBook = false;

//Red Puzzle Booleans
//Potion
bool hasRedPotion = false;
//Book
bool hasRedBook = false;

//Purple Puzzle Booleans
//Potion
bool hasPurplePotion = false;
//Book
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

Story::Story() {
	runSetup();
	//function.Action("SetPosition(Arlan, CurrentPrison.Chest)", true);
	run();
}

Story::~Story() {
}

bool Story::runSetup() { // runs initial setup for chapter 2. returns true if setup was successful.
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
	setupDungeon("CurrentPrison");
	setupLeftHallway("LeftHallway");
	setupRightHallway("RightHallway");
	setupDiningRoom("CurrentDiningRoom");
	setupStorage("CurrentStorage");
	function.Action("ShowMenu()", true);

	return true;
}

void Story::run() { // begins chapter 2's execution
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
		else if ((currentLocation == "BlueCamp") || (currentLocation == "GreenCamp") || (currentLocation == "RedCamp") || (currentLocation == "PurpleCamp")) {
			runCurrentCamp();
		}
	}
}

//Flashback execution function
void Story::flashback1() {
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
bool Story::setupCurrentCottage(string name) {
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

bool Story::setupCurrentTown(string name) {
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

bool Story::setupBlacksmithFoundry(string name) {
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

bool Story::setupAlchemyShop(string name) {
	Alchemy = AlchemyShop(name);

	//character setup
	function.SetupCharacter("Fortuneteller", "G", "Witch", "Ponytail", "Gray", "AlchemyShop.AlchemistTable");

	//icon setup
	Alchemy.icons.push_back(Icon("Talk_To_FortuneTeller", "Talk", "Fortuneteller", "Talk to Fortune Teller", "true"));
	Alchemy.icons.push_back(Icon("Exit_Shop", "Open", "AlchemyShop.Door", "Exit Alchemy Shop", "true"));
	function.SetupIcons(Alchemy.icons);

	return true;
}

bool Story::setupCurrentForestPath(string name) {
	currentForestPath = ForestPath(name);

	//character setup

	//items and their placement
	function.Action("CreateItem(ArchieSpellbook, SpellBook)", true);

	//icons
	currentForestPath.icons.push_back(Icon("Take_ArchieSpellbook", "Hand", "ArchieSpellbook", "Take the spellbook", "true"));
	function.SetupIcons(currentForestPath.icons);

	return true;
}

bool Story::setupCurrentRuins(string name) {
	currentRuins = Ruins(name);

	//character setup

	//items and their placement
	function.Action("CreateItem(LeaderFlashPotion, GreenPotion)", true);//potion to activate flashback 1

	//icons
	currentRuins.icons.push_back(Icon("Take", "Hand", "LeaderFlashPotion", "Take the Potion", "true"));
	function.SetupIcons(currentRuins.icons);


	return true;
}

bool Story::setupPastCottage(string name) {
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

bool Story::setupPastForestPath(string name) {
	pastForestPath = ForestPath(name);

	//character setup

	//icons

	return true;
}

bool Story::setupPastCity(string name) {
	pastCity = City(name);

	//character setup

	//icons
	pastCottage.icons.push_back(Icon("Open", "Exit", "PastCity.GreenHouseDoor", "Go Inside", "true"));
	function.SetupIcons(pastCity.icons);

	return true;
}

bool Story::setupPastRuins(string name, bool Enemy) {
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

bool Story::setupForestPath2(string name) {
	ForestPath2 = ForestPath(name);

	//character setup

	//items
	function.Action("CreateItem(PrisonerSword, Sword)", true);
	//icons

	return true;
}

bool Story::setupCourtyard(string name) {
	CurrentCourtyard = Courtyard(name);

	//character setup

	//items

	//icons

	return true;
}

bool Story::setupCastleBedroom(string name) {
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

bool Story::setupPort(string name) {
	CurrentPort = Port(name);

	//character setup

	//items

	//icons

	return true;
}

bool Story::setupGreatHall(string name) {
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

bool Story::setupCastleCrossroads(string name) {
	CurrentCastleCrossroads = CastleCrossroads(name);

	//character setup

	//items

	//icons

	return true;
}

bool Story::setupLibrary(string name) {
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

bool Story::setupCamp(string name) {
	CurrentCamp = Camp(name);

	if (name == "GreenCamp") {
		//character setup

		//items

		//icons
		function.Action("SetPosition(Archie, GreenCamp.Horse)", true);
		function.Action("Draw(Archie, LeaderFlashPotion)", true);
		function.Action("EnableEffect(Archie, Force)", true);
	}
	if (name == "BlueCamp") {
		//character setup

		//items

		//icons
	}
	if (name == "RedCamp") {
		//character setup

		//items

		//icons
	}
	if (name == "PurpleCamp") {
		//character setup

		//items

		//icons
	}
	
	return true;
}

bool Story::setupDungeon(string name) {
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

bool Story::setupLeftHallway(string name) {
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

bool Story::setupRightHallway(string name) {
	RightHallway = Hallway(name);

	//character setup

	//items

	//icons

	return true;
}

bool Story::setupDiningRoom(string name) {
	CurrentDiningRoom = DiningRoom(name);

	//character setup

	//items

	//icons

	return true;
}

bool Story::setupStorage(string name) {
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
void Story::runCurrentCottage() {
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
				int test = 3;
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
						function.Transition("Arlan", "ArlanCottage.Door", "CurrentCourtyard.Exit");
						currentLocation = "CurrentCourtyard";
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

void Story::runCurrentTown() {
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

void Story::runBlacksmithFoundry() {
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
					if (hasBrokenLock) {
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

				if (modified_I == "fixTheLock") {
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

void Story::runAlchemyShop() {
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

void Story::runCurrentForestPath() {
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

void Story::runCurrentRuins() {
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
void Story::runPastCottage(bool CharacterCheck) {
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
void Story::runPastForestPath(bool CharacterCheck) {
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

void Story::runPastCity(bool CharacterCheck) {

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

void Story::runPastRuins(bool CharacterCheck) {
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

void Story::runForestPath2() {
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

		else if (i == "input arrived Arlan position ForestPath2.EastEnd") {
			function.Transition("Arlan", "ForestPath2.EastEnd", "CurrentTown.WestEnd");
			currentLocation = "CurrentTown";
		}
	}
}

void Story::runCurrentCastleCrossroads() {
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

void Story::runCurrentGreatHall() {
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
	}
}

void Story::runCurrentPort() {
	while (currentLocation == "CurrentPort") {
		string i;
		getline(cin, i);

		//Gets the first word that isn't "input"
		modified_I = function.splitInput(i, 6, false);

		bool inputWasCommon = function.checkCommonKeywords(i, modified_I, "Arlan", playerInv);

		if (!inputWasCommon) {

		}

		//CurrentCastleCrossroads
		if (i == "input arrived Arlan position CurrentPort.Exit") {
			function.Transition("Arlan", "CurrentPort.Exit", "CurrentCastleCrossroads.WestEnd");
			currentLocation = "CurrentCastleCrossroads";
		}
	}
}

void Story::runCurrentLibrary() {
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

void Story::runCurrentStorage() {
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

void Story::runCurrentPrison() {


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

void Story::runLeftHallway() {
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

void Story::runRightHallway() {
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

void Story::runCurrentDiningRoom() {
	while (currentLocation == "CurrentDiningRoom") {
		string i;
		getline(cin, i);

		//Gets the first word that isn't "input"
		modified_I = function.splitInput(i, 6, false);

		bool inputWasCommon = function.checkCommonKeywords(i, modified_I, "Arlan", playerInv);

		if (!inputWasCommon) {

		}

		//LeftHallway
		if (i == "input arrived Arlan position CurrentDiningRoom.Door") {
			function.Transition("Arlan", "CurrentDiningRoom.Door", "LeftHallway.BackDoor");
			currentLocation = "LeftHallway";
		}
	}
}

void Story::runCurrentCourtyard() {
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
				if (hasBlueBook && hasBluePotion) {
					setupCamp("BlueCamp");
					currentLocation = "BlueCamp";
					function.Transition("Arlan", "CurrentCourtyard.Gate", "BlueCamp.Exit");
				}
				else if (hasGreenBook && hasGreenPotion) {
					setupCamp("GreenCamp");
					currentLocation = "GreenCamp";
					function.Transition("Arlan", "CurrentCourtyard.Gate", "GreenCamp.Exit");
				}
				else if (hasRedBook && hasRedPotion) {
					setupCamp("RedCamp");
					currentLocation = "RedCamp";
					function.Transition("Arlan", "CurrentCourtyard.Gate", "RedCamp.Exit");
				}
				else if (hasPurpleBook && hasPurplePotion) {
					setupCamp("PurpleCamp");
					currentLocation = "PurpleCamp";
					function.Transition("Arlan", "CurrentCourtyard.Gate", "PurpleCamp.Exit");
				}
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

void Story::runCurrentCastleBedroom() {
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

void Story::runCurrentCamp() {
	if (currentLocation == "BlueCamp") {
		while (currentLocation == "BlueCamp") {

		}
	}
	if (currentLocation == "RedCamp") {
		while (currentLocation == "RedCamp") {

		}
	}
	if (currentLocation == "PurpleCamp") {
		while (currentLocation == "PurpleCamp") {

		}
	}
	if (currentLocation == "GreenCamp") {
		//function.Action("SetPosition(Archie, CurrentCamp.Horse)", true);
		//function.Action("Draw(Archie, LeaderFlashPotion)", true);
		//function.Action("EnableEffect(Archie, Force)", true);
		function.WalkToPlace("Arlan", "Archie");
		//function.Action("Face(Archie, Arlan)", true);
		this_thread::sleep_for(chrono::milliseconds(200));
		function.Action("Face(Arlan, Archie)", true);
		this_thread::sleep_for(chrono::milliseconds(200));
		function.Action("SetLeft(Arlan)", true);
		function.Action("SetRight(Archie)", true);
		function.SetupDialogText("Ah... you've found me. The power stemming from my relic told me there would be some to try to come take it from me. No matter. You will be slain just like Mathias", "mathiasEnters", "Please dont do thi--");
		function.Action("ShowDialog()", true);
		while (currentLocation == "GreenCamp") {
			string i;
			getline(cin, i);

			//Gets the first word that isn't "input"
			modified_I = function.splitInput(i, 6, false);

			bool inputWasCommon = function.checkCommonKeywords(i, modified_I, "Arlan", playerInv);

			if (!inputWasCommon) {

			}

			//CurrentCastleBedroom
			if (i == "input arrived Arlan position GreenCamp.Exit") {
				function.Transition("Arlan", "GreenCamp.Exit", "CurrentCourtyard.Gate");
				currentLocation = "CurrentCourtyard";
			}

			else if (i == "input Selected mathiasEnters") {
				function.Action("HideDialog()", true);
				function.Action("SetPosition(Mathias, GreenCamp.Exit)", true);
				function.Action("SetCameraFocus(Mathias)", true);
				function.Action("SetCameraMode(Focus)", true);
				this_thread::sleep_for(chrono::milliseconds(500));
				function.Action("Draw(Mathias, MathiasSword)", true);
				this_thread::sleep_for(chrono::milliseconds(500));
				function.Action("SetCameraMode(Follow)", true);
				function.Action("Face(Archie, Mathias)", true);
				function.Action("Face(Arlan, Mathias)", true);
				function.Action("WalkTo(Mathias, Archie)", true);
				//this_thread::sleep_for(chrono::milliseconds(3000));
				function.Action("SetCameraFocus(Arlan)", true);
				function.SetupDialogText("Quickly Arlan! Use the book to remove the corrupting power!", "reciteIncantation", "**Recite the incantation**");
				function.Action("SetRight(Mathias)", true);
				function.Action("ShowDialog()", true);
			}

			else if (i == "input Selected reciteIncantation") {
				function.Action("HideDialog()", true);
				function.Action("Face(Arlan, Archie)", true);
				function.Action("Draw(Arlan, Book Of Incantations)", true);
				function.Action("Cast(Arlan, Archie)", true);
				function.Action("Kneel(Archie)", true);
				function.Action("DisableEffect(Archie)", true);
				function.Action("Sheathe(Arlan, Book Of Incantations)", true);
				function.Action("SetRight(Archie)", true);
				function.SetupDialogText("Wha.. what is going on..? Where am I..?", "askMathias", "What should we do Mathias?");
				function.Action("ShowDialog()", true);
			}

			else if (i == "input Selected askMathias") {
				function.Action("SetRight(Mathias)", true);
				function.SetupDialogText("Use your potion to cleanse the corruption or he will die!", "usePotion", "**Use The Potion**");
			}

			else if (i == "input Selected usePotion") {
				function.Action("HideDialog()", true);
				//function.Action("Draw(Arlan, Potion Of Cleansing)", true);
				function.Action("Give(Arlan, Potion Of Cleansing, Archie)", true);
				this_thread::sleep_for(chrono::milliseconds(1000));
				function.Action("Face(Archie, Arlan)", true);
				function.Action("SetRight(Archie)", true);
				function.SetupDialogText("Thank you hero... you have saved me from the corruption that consumed me.", "apologizeToMathias", "Of course.");
				function.Action("ShowDialog()", true);
			}

			else if (i == "input Selected apologizeToMathias") {
				function.Action("HideDialog()", true);
				function.Action("Face(Archie, Mathias", true);
				function.Action("SetLeft(Archie)", true);
				function.Action("SetRight(Mathias)", true);
				function.SetupDialogText("Mathias... I am so sorry for everything I have done.", "apologyAccepted", "...");
				function.Action("ShowDialog()", true);
			}

			else if (i == "input Selected apologyAccepted") {
				function.Action("SetLeft(Mathias)", true);
				function.Action("SetRight(Archie)", true);
				function.SetupDialogText("It is ok my friend. Let us return to the kingdom. Arlan... thank you for everything.", "endGame", "...");
			}

			else if (i == "input Selected endGame") {
				function.Action("HideDialog()", true);
				function.Action("WalkTo(Mathias, GreenCamp.Exit)", true);
				function.Action("SetPosition(Mathias)", true);
				function.Action("WalkTo(Archie, GreenCamp.Exit)", true);
				function.Action("SetPosition(Archie)", true);
				function.Action("FadeOut()", true);
				this_thread::sleep_for(chrono::milliseconds(2000));
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
}