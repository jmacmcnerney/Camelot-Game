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
#include <fstream>
using namespace std;

vector<string> playerInv;

//location boolean
string currentLocation = "ArlanCottage";

bool cheatsEnabled = true;
bool musicPlaying = false;

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
bool finishedTalkingToElder = false;
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
bool hasGreenPotion = false;
bool hasStorageBottle = false;
bool hasStorageBread = false;
bool hasStorageHelmet = false;
bool hasStorageInkAndQuill = false;
bool hasStorageBag = false;
bool storageBreadPositionCorrect = false;
bool storageBottlePositionCorrect = false;
bool storagePuzzleSolved = false;
//Book
bool hasGreenBook = false;
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
bool visitedDiningRoom = false;
bool isPlacingItem = false;
bool drankBluePotion = false;
//Book
bool hasBlueBook = false;
bool spokenWithMerchant = false;
bool hasStrangeElixir = false;
bool drankStangeElixir = false;
//bool spokenWithSailor = false;
bool canWorkForBlacksmith = false;
bool hasCompass = false;
bool boughtCompass = false;

//Red Puzzle Booleans
//Potion
bool hasRedPotion = false;
//Book
bool hasRedBook = false;
bool hasLitTorch = false;
bool torchUnpocketed = false;
bool boatOnFire = false;
bool merchantDistracted = false;
bool hasTranslatingGlass = false;
bool iconEnabled = false;
bool isChestOpened = false;

//Purple Puzzle Booleans
//Potion
bool hasPurplePotion = false;
//Book
bool hasPurpleBook = false;
bool hasLegofTwo = false;
bool hasCloth = false;
bool givenRiddle = false;

bool camptest = false;

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

bool BedroomSpot1Full = false;
bool BedroomSpot2Full = false;
bool BedroomSpot3Full = false;
bool BedroomSpot4Full = false;
bool BedroomSpot5Full = false;
bool BedroomSpot6Full = false;

bool BedroomSpot1Correct = false;
bool BedroomSpot2Correct = false;
bool BedroomSpot3Correct = false;
bool BedroomSpot4Correct = false;
bool BedroomSpot5Correct = false;
bool BedroomSpot6Correct = false;

bool BedroomGoldCupUsed = false;
bool BedroomBagUsed = false;
bool BedroomJewelKeyUsed = false;
bool BedroomSkullUsed = false;
bool BedroomLockUsed = false;
bool BedroomInkAndQuillUsed = false;

bool BedroomPuzzleFin = false;

int numCoins = 0;

Story::Story() {
	runSetup();
	function.Action("SetTitle(Relics Of The Kingdom)", true);
	run();
}

Story::~Story() {
}

bool Story::runSetup() { // runs initial setup for chapter 2. returns true if setup was successful.
	//CHEATS
	if (cheatsEnabled) {
		function.Action("CreateItem(Cheating Menu, EvilBook)", true);
		playerInv.push_back("Cheating Menu");
		function.Action("EnableIcon(accessCheatMenu, unlock, Cheating Menu, Open Cheat Menu, true)", true);
	}

	//location setup calls
	setupCurrentCottage("ArlanCottage");
	setupCurrentTown("CurrentTown");
	setupBlacksmithFoundry("BlacksmithFoundry");
	setupCurrentForestPath("CurrentForestPath");
	setupForestPath2("ForestPath2");
	setupCurrentRuins("CurrentRuins");
	setupPastCottage("PastCottage");
	setupPastForestPath("PastForestPath");
	setupPastCity("PastCity");
	setupAlchemyShop("AlchemyShop");
	setupCourtyard("CurrentCourtyard");
	setupCastleBedroom("CurrentCastleBedroom");
	setupCastleCrossroads("CurrentCastleCrossroads");
	setupLibrary("CurrentLibrary");
	setupFinalRuins("FinalRuins");
	setupDungeon("CurrentPrison");
	setupRightHallway("RightHallway");

	//Areas where interactions are different based on Archie or Mathis Path for TESTING
	//setupPort("CurrentPort");	// need to disable this again. hopefully i don't forget -zac
	//setupGreatHall("CurrentGreatHall");
	//setupLeftHallway("LeftHallway");
	//setupDiningRoom("CurrentDiningRoom");	// need to disable this again. hopefully i don't forget -zac
	//setupStorage("CurrentStorage");

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
		else if (currentLocation == "FinalRuins") {
			runFinalRuins();
		}
	}
}

//Flashback execution function
void Story::flashback1() {
	//flashback transistion
	function.WalkToPlace("Arlan", "CurrentRuins.Altar");
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

	//Furniture
	function.Action("HideFurniture(ArlanCottage.Chest)", true);

	return true;
}

bool Story::setupCurrentTown(string name) {
	currentCity = City(name);

	//character setup
	function.SetupCharacter("Apple Merchant", "C", "Merchant", "Long", "Blonde", "CurrentTown.Horse");
	function.SetupCharacter("Town Elder", "H", "Noble", "Musketeer_Full", "Gray", "CurrentTown.Plant");

	//items
	function.Action("CreateItem(ArchieSpellbook, SpellBook)", true);
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
	currentCity.icons.push_back(Icon("Take_ArchieSpellbook", "Hand", "ArchieSpellbook", "Take the spellbook", "true"));
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

	//Furniture
	function.Action("HideFurniture(BlacksmithFoundry.Chest)", true);

	return true;
}

bool Story::setupAlchemyShop(string name) {
	Alchemy = AlchemyShop(name);

	//character setup
	function.SetupCharacter("Fortuneteller", "G", "Witch", "Ponytail", "Gray", "AlchemyShop.AlchemistTable");

	//item setup 
	function.Action("CreateItem(Book of Tactics, PurpleBook)", true);

	//icon setup
	Alchemy.icons.push_back(Icon("Talk_To_FortuneTeller", "Talk", "Fortuneteller", "Talk to Fortune Teller", "true"));
	Alchemy.icons.push_back(Icon("Exit_Shop", "Open", "AlchemyShop.Door", "Exit Alchemy Shop", "true"));
	function.SetupIcons(Alchemy.icons);

	//Furniture
	function.Action("HideFurniture(AlchemyShop.Chest)", true);

	return true;
}

bool Story::setupCurrentForestPath(string name) {
	currentForestPath = ForestPath(name);

	//character setup

	//items and their placement
	function.Action("CreateItem(MathiasSword, Sword)", true);


	//icons
	currentForestPath.icons.push_back(Icon("Take_MathiasSword", "Hand", "MathiasSword", "Take the sword", "true"));
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
	currentRuins.icons.push_back(Icon("Examine_Altar", "Magnifyingglass", "CurrentRuins.Altar", "Examine the Altar", "true"));
	function.SetupIcons(currentRuins.icons);

	//Furniture
	function.Action("HideFurniture(CurrentRuins.Chest)", true);


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

	//Furniture
	function.Action("HideFurniture(PastCottage.Chest)", true);


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

	//Furniture
	function.Action("HideFurniture(PastRuins.Chest)", true);

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
	function.Action("CreateItem(PrisonerHammer, Hammer)", true);
	//icons
	CurrentCourtyard.icons.push_back(Icon("Exit Courtyard", "Hand", "CurrentCourtyard.Gate", "Exit", "true"));
	function.SetupIcons(CurrentCourtyard.icons);

	return true;
}

bool Story::setupCastleBedroom(string name) {
	CurrentCastleBedroom = CastleBedroom(name);

	//character setup
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

	function.Action("SetPosition(CastleBedroomPuzzle, CurrentCastleBedroom.SmallTable)", true);


	//icons
	CurrentCastleBedroom.icons.push_back(Icon("Read_Puzzle", "research", "CastleBedroomPuzzle", "Read Puzzle", "true"));
	CurrentCastleBedroom.icons.push_back(Icon("Search_Bedroom_Closet", "hand", "CurrentCastleBedroom.Closet", "Search Closet", "true"));

	CurrentCastleBedroom.icons.push_back(Icon("Pickup Lock", "hand", "CastleBedroomLock", "Pickup Lock", "true"));
	CurrentCastleBedroom.icons.push_back(Icon("Pickup Skull", "hand", "CastleBedroomSkull", "Pickup Skull", "true"));
	CurrentCastleBedroom.icons.push_back(Icon("Pickup Bag", "hand", "CastleBedroomBag", "Pickup Bag", "true"));
	CurrentCastleBedroom.icons.push_back(Icon("Pickup InkAndQuill", "hand", "CastleBedroomInkAndQuill", "Pickup Ink and Quill", "true"));
	CurrentCastleBedroom.icons.push_back(Icon("Pickup JewelKey", "hand", "CastleBedroomJewelKey", "Pickup Jewel Key", "true"));
	CurrentCastleBedroom.icons.push_back(Icon("Pickup GoldCup", "hand", "CastleBedroomGoldCup", "Pickup Gold Cup", "true"));


	CurrentCastleBedroom.icons.push_back(Icon("Swap Spot1", "hand", "CurrentCastleBedroom.Table", "Interact with Spot 1", "true"));
	CurrentCastleBedroom.icons.push_back(Icon("Swap Spot2", "hand", "CurrentCastleBedroom.Table", "Interact with Spot 2", "true"));
	CurrentCastleBedroom.icons.push_back(Icon("Swap Spot3", "hand", "CurrentCastleBedroom.Table", "Interact with Spot 3", "true"));
	CurrentCastleBedroom.icons.push_back(Icon("Swap Spot4", "hand", "CurrentCastleBedroom.Table", "Interact with Spot 4", "true"));
	CurrentCastleBedroom.icons.push_back(Icon("Swap Spot5", "hand", "CurrentCastleBedroom.Table", "Interact with Spot 5", "true"));
	CurrentCastleBedroom.icons.push_back(Icon("Swap Spot6", "hand", "CurrentCastleBedroom.Table", "Interact with Spot 6", "true"));

	function.SetupIcons(CurrentCastleBedroom.icons);

	return true;
}

bool Story::setupPort(string name) {
	CurrentPort = Port(name);
	if (MathiasFlashback) {

		//character setup
		function.SetupCharacter("PortMerchant", "H", "Merchant", "Short", "Gray", "CurrentPort.SmallStall");
		function.SetupCharacter("Sailor", "D", "Peasant", "Musketeer", "Gray", "CurrentPort.BigShip");

		//items
		function.Action("CreateItem(Compass, Compass)", true);
		function.Action("CreateItem(BookOfLore, BlueBook)", true);
		function.Action("CreateItem(StrangeElixir, Bottle)", true);

		//icons
		CurrentPort.icons.push_back(Icon("Talk to PortMerchant", "Talk", "PortMerchant", "Talk To Port Merchant", "true"));
		CurrentPort.icons.push_back(Icon("Talk to Sailor", "Talk", "Sailor", "Talk To Sailor", "true"));
		CurrentPort.icons.push_back(Icon("ReadBookOfLore", "Research", "BookOfLore", "Read the Book", "true"));
		CurrentPort.icons.push_back(Icon("DrinkStrangeElixir", "potion", "StrangeElixir", "Drink the Elixir", "true"));
		function.SetupIcons(CurrentPort.icons);
	}
	else if (ArchieFlashback) {
		//character setup
		function.SetupCharacter("ShipTrader", "F", "Merchant", "Musketeer", "blonde", "CurrentPort.BigStall");

		//items
		function.Action("CreateItem(Translating Glass, MagnifyingGlass)", true);
		function.Action("CreateItem(StrangeElixir, Bottle)", true);
		function.Action("SetPosition(Translating Glass, CurrentPort.BigStall.Left)", true);


		//icons
		CurrentPort.icons.push_back(Icon("Talk_To_Trader", "Talk", "ShipTrader", "Talk to Ship Merchant", "true"));
		CurrentPort.icons.push_back(Icon("Take_Glass", "Hand", "Translating Glass", "Take Translaing Glass", "true"));
		CurrentPort.icons.push_back(Icon("Intract_Ship", "Torch", "CurrentPort.SmallShip", "Interact with Ship", "true"));
		CurrentPort.icons.push_back(Icon("DrinkStrangeElixir", "potion", "StrangeElixir", "Drink the Elixir", "true"));
		function.SetupIcons(CurrentPort.icons);

		//visual effect
		//function.Action("EnableEffect(Translating Glass, Diamond)", true);
		//function.Action("EnableEffect(CurrentPort.SmallShip, Diamond)", true);
	}

	return true;
}

bool Story::setupGreatHall(string name) {
	CurrentGreatHall = GreatHall(name);

	//character setup

	//items
	if (ArchieFlashback) {
		function.Action("CreateItem(Translated Book, RedBook)", true);
		function.Action("SetPosition(Translated Book, CurrentGreatHall.Table)", true);
		CurrentGreatHall.icons.push_back(Icon("Read_Book", "Research", "Translated Book", "Read Book", "true"));
	}

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
	CurrentLibrary.icons.push_back(Icon("Library Table", "Hand", "CurrentLibrary.Table", "Interact With Table", "true"));
	CurrentLibrary.icons.push_back(Icon("Library Spellbook", "Hand", "CurrentLibrary.SpellBook", "Read Spellbook", "true"));
	CurrentLibrary.icons.push_back(Icon("PlaceLibraryItemCenter", "Hand", "CurrentLibrary.AlchemistTable", "Place An Item Center", "false"));
	CurrentLibrary.icons.push_back(Icon("PlaceLibraryItemRight", "Hand", "CurrentLibrary.AlchemistTable", "Place An Item Right", "false"));
	CurrentLibrary.icons.push_back(Icon("PlaceLibraryItemLeft", "Hand", "CurrentLibrary.AlchemistTable", "Place An Item Left", "false"));
	CurrentLibrary.icons.push_back(Icon("PickUp", "Hand", "Library Apple", "Pick Up", "true"));
	CurrentLibrary.icons.push_back(Icon("PickUp", "Hand", "Library GoldCup", "Pick Up", "true"));
	CurrentLibrary.icons.push_back(Icon("PickUp", "Hand", "Library GreenKey", "Pick Up", "true"));
	CurrentLibrary.icons.push_back(Icon("Leave Library", "Hand", "CurrentLibrary.Door", "Leave", "true"));

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
		//function.Action("Draw(Archie, LeaderFlashPotion)", true);
		function.Action("EnableEffect(Archie, Force)", true);
	}
	if (name == "BlueCamp") {
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
		CurrentCamp.icons.push_back(Icon("OpenChest", "chest, ", name + ".Chest", "Open the Chest", "true"));
		function.SetupIcons(CurrentCamp.icons);
	}
	if (name == "RedCamp") {
		//character setup
		function.Action("SetPosition(Archie, RedCamp.Stall)", true);
		//function.SetupCharacter("Archie", "D", "Warlock", "Mage_Full", "Red", name + ".Stall");
		//function.SetupCharacter("MathiasR", "F", "HeavyArmour", "Short_Full", "Brown", name + ".Log");
		//items
		function.Action("CreateItem(Mathias_Sword, Sword)", true);
		function.Action("CreateItem(Artifact, Skull)", true);
		function.Action("CreateItem(TempPotion, RedPotion)", true);
		//icons
	}
	if (name == "PurpleCamp") {
		//character setup

		//items
		function.Action("HideFurniture(PurpleCamp.Cauldron)", true);
		function.Action("HideFurniture(PurpleCamp.Roast)", true);
		function.Action("HideFurniture(PurpleCamp.Firepit)", true);
		function.Action("HideFurniture(PurpleCamp.Stall)", true);
		function.Action("HideFurniture(PurpleCamp.LeftLog)", true);
		function.Action("HideFurniture(PurpleCamp.Chest)", true);
		function.Action("CreateItem(SpareSword, Sword)", true);
		function.Action("CreateItem(SpareSword2, Sword)", true);

		//icons
		//CurrentCamp.icons.push_back(Icon("Talk_Archie", "Talk", "Archie", "Talk to Archie", "true"));
		//function.SetupIcons(CurrentCamp.icons);
	}
	
	return true;
}

bool Story::setupFinalRuins(string name) {
	finalRuins = Ruins(name);

	//character setup

	//items
	function.Action("CreateItem(MathiasSword2, Sword)", true);

	//icons

	return true;
}

bool Story::setupDungeon(string name) {
	CurrentPrison = Dungeon(name);

	//character setup
	function.Action("CreateItem(Potion of Invincibility, RedPotion)", true);
	function.SetupCharacter("Prisoner", "F", "Bandit", "Spiky", "Blonde", "CurrentPrison.Bed");
	//items
	function.Action("CreateItem(PrisonerOutfit, Helmet)", true);
	function.Action("CreateItem(GuardSword, Sword)", true);
	//icons
	CurrentPrison.icons.push_back(Icon("Talk_To_Prisoner", "talk", "Prisoner", "Talk To Prisoner", "true"));
	CurrentPrison.icons.push_back(Icon("Open Door", "door", "CurrentPrison.Door", "Open Door", "true"));
	function.SetupIcons(CurrentPrison.icons);
	return true;
}

bool Story::setupLeftHallway(string name) {
	LeftHallway = Hallway(name);

	//character setup
	if (ArchieFlashback) {
		function.SetupCharacter("PrisonGuard", "E", "HeavyArmour", "Spiky", "Black", "LeftHallway.Door");
		LeftHallway.icons.push_back(Icon("Talk_To_Guard", "talk", "PrisonGuard", "Talk To Guard", "true"));
	}
	//items
	function.Action("CreateItem(Potion of Healing, PurplePotion)", true);
	//icons
	
	LeftHallway.icons.push_back(Icon("Enter LeftHallway Door", "Hand", "LeftHallway.Door", "Enter", "true"));
	LeftHallway.icons.push_back(Icon("Enter LeftHallway BackDoor", "Hand", "LeftHallway.BackDoor", "Enter", "true"));
	function.SetupIcons(LeftHallway.icons);

	return true;
}

bool Story::setupRightHallway(string name) {
	RightHallway = Hallway(name);

	//character setup

	//items

	//icons
	RightHallway.icons.push_back(Icon("Enter RightHallway Door", "Hand", "RightHallway.Door", "Enter", "true"));
	RightHallway.icons.push_back(Icon("Enter RightHallway BackDoor", "Hand", "RightHallway.BackDoor", "Enter", "true"));
	function.SetupIcons(RightHallway.icons);

	return true;
}

bool Story::setupDiningRoom(string name) {
	CurrentDiningRoom = DiningRoom(name);

	if (MathiasFlashback) {
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

		function.Action("EnableEffect(CurrentDiningRoom.Fireplace, Campfire)", true);
		function.Action("PlaySound(Fireplace, CurrentDiningRoom.Fireplace, true)", true);
	}
	else if (ArchieFlashback) {
		//character setup
		function.SetupCharacter("Chef", "D", "Peasant", "Spiky", "Black", "CurrentDiningRoom.Fireplace");
		function.Action("Face(Chef, CurrentDiningRoom.Fireplace)", true);

		//items
		function.Action("CreateItem(Leg of Two, ChickenLeg)", true);

		//icons
		CurrentDiningRoom.icons.push_back(Icon("Talk_Chef", "Talk", "Chef", "Talk to Chef", "true"));
		function.SetupIcons(CurrentDiningRoom.icons);
	}
	
	return true;
}

bool Story::setupStorage(string name) {
	CurrentStorage = Storage(name);
	if (MathiasFlashback) {
		//character setup

		//items
		function.Action("CreateItem(Potion Of Cleansing, GreenPotion)", true);
		function.Action("CreateItem(Storage Bottle, Bottle)", true);
		CurrentStorage.chestInv.push_back("Storage Bottle");
		function.Action("CreateItem(Storage InkAndQuill, InkAndQuill)", true);
		CurrentStorage.chestInv.push_back("Storage InkAndQuill");
		function.Action("CreateItem(Storage Bread, Bread)", true);
		CurrentStorage.chestInv.push_back("Storage Bread");
		function.Action("CreateItem(Storage Bag, Bag)", true);
		CurrentStorage.chestInv.push_back("Storage Bag");
		function.Action("CreateItem(Storage Helmet, Helmet)", true);
		CurrentStorage.chestInv.push_back("Storage Helmet");
		function.Action("CreateItem(Storage OpenScroll, OpenScroll)", true);
		function.Action("SetPosition(Storage OpenScroll, CurrentStorage.Barrel)", true);

		//icons
		CurrentStorage.icons.push_back(Icon("Open Storage Chest", "Hand", "CurrentStorage.Chest", "Open Chest", "true"));
		CurrentStorage.icons.push_back(Icon("TakeStorageItemFromChest", "Hand", "Storage Bottle", "Take Storage Bottle", "true"));
		CurrentStorage.icons.push_back(Icon("TakeStorageItemFromChest", "Hand", "Storage InkAndQuill", "Take Storage InkAndQuill", "true"));
		CurrentStorage.icons.push_back(Icon("TakeStorageItemFromChest", "Hand", "Storage Bread", "Take Storage Bread", "true"));
		CurrentStorage.icons.push_back(Icon("TakeStorageItemFromChest", "Hand", "Storage Bag", "Take Storage Bag", "true"));
		CurrentStorage.icons.push_back(Icon("TakeStorageItemFromChest", "Hand", "Storage Helmet", "Take Storage Helmet", "true"));
		CurrentStorage.icons.push_back(Icon("Read Storage OpenScroll", "Hand", "Storage OpenScroll", "Read The Scroll", "true"));
		CurrentStorage.icons.push_back(Icon("Interact With Potion Of Cleansing", "Hand", "Potion Of Cleansing", "Take The Potion", "true"));
		CurrentStorage.icons.push_back(Icon("PlaceStorageItemLeft", "Hand", "CurrentStorage.Shelf", "Place Item Left", "false"));
		CurrentStorage.icons.push_back(Icon("PlaceStorageItemRight", "Hand", "CurrentStorage.Shelf", "Place Item Right", "false"));
		CurrentStorage.icons.push_back(Icon("Leave Storage", "Hand", "CurrentStorage.Door", "Leave", "true"));

		function.SetupIcons(CurrentStorage.icons);
	}
	else if (ArchieFlashback) {
		//character setup

		//items
		function.Action("CreateItem(Torch, LitTorch)", true);
		CurrentStorage.chestInv.push_back("Torch");
		function.Action("CreateItem(Purple Cloth, PurpleCloth)", true);
		CurrentStorage.chestInv.push_back("Purple Cloth");

		//icons
		CurrentStorage.icons.push_back(Icon("Open_Chest", "Hand", "CurrentStorage.Chest", "Open Chest", "true"));
		CurrentStorage.icons.push_back(Icon("Take_Torch", "Hand", "Torch", "Take LitTorch", "true"));
		CurrentStorage.icons.push_back(Icon("Take_Cloth", "Open", "Purple Cloth", "Take Cloth", "true"));
		CurrentStorage.icons.push_back(Icon("Leave_Storage", "Hand", "CurrentStorage.Door", "Leave", "true"));
		function.SetupIcons(CurrentStorage.icons);
	}

	return true;
}


// location execution functions.
void Story::runCurrentCottage() {
	function.MusicHandler("Explorer", currentLocation, musicPlaying);
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
				if (hasStorybook) {
					function.Transition("Arlan", "ArlanCottage.Door", "CurrentTown.BlueHouseDoor");
					currentLocation = "CurrentTown";
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
	function.MusicHandler("Town_Day", currentLocation, musicPlaying);
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
					else if (completedErrand == true && !ArchieFlashback && !MathiasFlashback) {
						function.SetupDialogText("You should look around for an ancient artifact and take it to the ruins past the forest path.", "end", "Okay! Thanks!");
					}
					else if (ArchieFlashback || MathiasFlashback) {
						if (finishedTalkingToElder) {
							if (MathiasFlashback) {
								function.SetupDialogText("Hello again Arlan! Need something?", "askCoins", "Know where I can find any coins?", "askReminder", "What am I doing again?");
							}
							else if (ArchieFlashback) {
								function.SetupDialogText("Hello again Arlan! Need something?", "askReminder", "What am I doing again?");
							}
						}
						else {
							function.SetupDialogText("You saw what? Oh my... the storybook did have some additional information. It said to stop the corruption you must locate 2 ancient artifacts and bring them to the region beyond the courtyard at the north end of the town.", "end", "Okay! Thanks!");

							if (MathiasFlashback) {
								//spawn coins in world 
								function.Action("CreateItem(Coin1, Coin)", true);
								function.Action("EnableIcon(TakeCoin1, Hand, CurrentTown.Fountain, Inspect the Fountain, true)", true);

								function.Action("CreateItem(Coin2, Coin)", true);
								canWorkForBlacksmith = true;

								function.Action("CreateItem(Coin3, Coin)", true);
								function.Action("EnableIcon(TakeCoin3, Hand, ForestPath2.Well, Inspect the Well, true)", true);

								function.Action("CreateItem(Coin4, Coin)", true);
								function.Action("EnableIcon(TakeCoin4, Hand, CurrentPort.Barrel, Inspect the Barrel, true)", true);

								/*function.Action("CreateItem(Coin5, Coin)", true);
								function.Action("EnableIcon(TakeCoin5, Hand, Coin5, Take the Coin, true", true);
								function.Action("SetPosition(Coin5, AlchemyShop.Table)", true);*/
							}

							finishedTalkingToElder = true;
						}
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
					function.SetupDialogText("Take the eastern forest path just beyond the fortune tellers shop and you will find them.", "completedErrand", "Okay. Thanks.");
				}

				else if (modified_I == "completedErrand") {
					function.Action("ClearDialog()", true);
					function.Action("HideDialog()", true);
					function.Action("SetNarration(The air shifts around you. You feel like you can go somewhere you couldnt before. You wonder where an ancient relic could be.)", true);
					function.Action("ShowNarration()", true);
				}

				else if (modified_I == "askCoins") {
					int coinHint = rand() % 3;
					if (coinHint == 0) {
						function.SetupDialogText("Coins? Hmm... perhaps try looking around a place of business such as the blacksmith.", "end", "Okay! Thanks!");
					}
					else if (coinHint == 1) {
						function.SetupDialogText("Coins? Hmm... Many people toss coins into fountains or wells. Perhaps try looking there.", "end", "Okay! Thanks!");
					}
					else if (coinHint == 2) {
						function.SetupDialogText("Coins? Hmm... There is much coin exhanged in the royal port. Perhaps try looking near the vendors there.", "end", "Okay! Thanks!");
					}
				}

				else if (modified_I == "askReminder") {
					function.SetupDialogText("That storybook of yours said that to stop the corruption you must locate 2 ancient artifacts and bring them to the region beyond the courtyard at the north end of the town. Perhaps you should seek those artifacts?", "end", "Okay! Thanks!");
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
			if (MathiasFlashback || ArchieFlashback) {
				function.Transition("Arlan", "CurrentTown.NorthEnd", "CurrentCourtyard.Exit");
				currentLocation = "CurrentCourtyard";
			}
			else {
				function.Action("SetNarration(A thick mist blocks your path. You can make out a forest path just beyond the fog. Maybe you should return later.)", true);
				function.Action("ShowNarration()", true);
			}
		}

		else if (i == "input arrived Arlan position CurrentTown.WestEnd") {
			if (MathiasFlashback || ArchieFlashback) {
				function.Transition("Arlan", "CurrentTown.WestEnd", "ForestPath2.EastEnd");
				currentLocation = "ForestPath2";
			}
			else {
				function.Action("SetNarration(A thick mist blocks your path. You can make out a forest path just beyond the fog. Maybe you should return later.)", true);
				function.Action("ShowNarration()", true);
			}
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
			function.Action("SetNarration(Theres a spellbook inside! You take it. It appears ancient and powerful. You wonder if this is the relic the elder mentioned.)", true);
			function.Action("ShowNarration()", true);
			playerInv.push_back("ArchieSpellbook");
			spellbook_taken = true;
			function.Action("DisableIcon(Look Inside Barrel, CurrentTown.Barrel)", true);
		}

		else if (i == "input TakeCoin1 CurrentTown.Fountain") {
			function.WalkToPlace("Arlan", "CurrentTown.Fountain");
			function.Action("SetNarration(Theres a gold coin in the fountain! You reach in and take it.)", true);
			function.Action("ShowNarration()", true);
			function.Action("PlaySound(Pocket)", true);
			playerInv.push_back("Coin1");
			numCoins++;
			function.Action("DisableIcon(TakeCoin1, CurrentTown.Fountain)", true);
		}
	}
}

void Story::runBlacksmithFoundry() {
	function.MusicHandler("Tavern", currentLocation, musicPlaying);
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
					function.Action("PlaySound(Pocket)", true);
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
	}
}

void Story::runAlchemyShop() {
	function.MusicHandler("Tavern", currentLocation, musicPlaying);
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
				else if (ArchieFlashback && !hasPurpleBook) {
					function.SetupDialogText("You have visited me again my child. You seek artifacts yes?", "Answer2", "I do. Can you help me?", "end", "Nope.");
				}
				else {
					function.SetupDialogText("Thank you for coming to see me. I wish you good fortune in your journey.", "end", "Thank you.");
				}
			}
			else if (modified_I == "Selected") {
				modified_I = function.splitInput(i, 0, true);
				//fortune teller errand dialogue
				if (modified_I == "Answer") {
					function.SetupDialogText("Give me your hand and I will give you your fortune free of charge.", "Accept", "**Put out your hand**", "Deny", "I dont feel like it.");
				}
				else if (modified_I == "Questioning") {
					function.SetupDialogText("I am a fortune teller. I know many things. Would like your fortune read?", "Answer", "Yes I am Arlan and I would like a fortune telling.", "Deny", "I do not want a fortune telling.");
				}
				else if (modified_I == "Deny") {
					function.SetupDialogText("Come back when you want your fortune read.", "end", "Leave");
				}
				else if (modified_I == "Accept") {
					function.SetupDialogText("**She takes your hand and begins to read your palm** You carry the burden of responsibility and hold a promising future.", "end", "Vague and interesting. I will be leaving now");
					visitedFortuneteller = true;
				}
				//dialogue concerning artifact
				else if (modified_I == "Answer2") {
					if (!hasRedBook && !hasRedPotion) {
						if (!hasPurplePotion || !hasCloth || !hasLegofTwo) {
							function.SetupDialogText("I can help you create an artifact of which you search.", "Riddle", "How so?");
						}
						else {
							function.SetupDialogText("It looks like you brought me everything. Now watch and see.", "PurpleBook", "Okay.");
						}
					}
					else {
						function.SetupDialogText("You already have what I could possibly give you.", "end", "I see. **Leave**)");
					}
				}
				else if (modified_I == "Riddle") {
					function.SetupDialogText("You must bring me a Cloth as Royal as the Kings. A leg of a creature that walks on two and some Purple Liquid.", "end", "I will go find these things.");
					givenRiddle = true;
				}
				else if (modified_I == "PurpleBook") {
					function.Action("DisableInput()", true);
					function.Action("HideDialog()", true);
					function.RemoveItem("Leg of Two", playerInv);
					function.RemoveItem("Purple Cloth", playerInv);
					hasLegofTwo = false;
					hasCloth = false;
					//function.Action("SetCameraFocus(Fortuneteller)", true);
					function.WalkToPlace("Fortuneteller", "AlchemyShop.Cauldron");
					function.Action("Face(Fortuneteller, AlchemyShop.Cauldron)", false);
					function.Action("Face(Arlan, Fortuneteller)", true);
					function.Action("EnableEffect(AlchemyShop.Fireplace, Campfire)", true);
					function.Action("PlaySound(Brew, AlchemyShop.Cauldron)", false);
					function.Action("Unpocket(Fortuneteller, Leg of Two)", true);
					function.Action("PutDown(Fortuneteller, Leg of Two)", true);
					function.Action("Unpocket(Fortuneteller, Purple Cloth)", true);
					function.Action("PutDown(Fortuneteller, Purple Cloth)", true);
					function.Action("Unpocket(Fortuneteller, Potion of Healing)", true);
					function.Action("PutDown(Fortuneteller, Potion of Healing)", true);
					function.Action("CreateEffect(AlchemyShop.Cauldron, Brew)", false);
					function.Action("StopSound(Brew, AlchemyShop.Cauldron)", false);
					function.Action("PlaySound(Spell, AlchemyShop.Cauldron)", true);
					function.Action("DisableEffect(AlchemyShop.Fireplace)", true);
					this_thread::sleep_for(chrono::milliseconds(1500));
					function.WalkToPlace("Fortuneteller", "AlchemyShop.AlchemistTable");
					function.Action("Face(Fortuneteller, Arlan)", false);
					function.Action("Face(Arlan, Fortuneteller)", true);
					function.SetupDialog("Arlan", "Fortuneteller", false);
					function.Action("EnableInput()", true);
					function.SetupDialogText("It seems that this book was created instead of a potion. This book once read will give you an intuitive mind.", "Awe", "Awesome!");
				}
				else if (modified_I == "Awe") {
					function.Action("SetNarration(You recive a Book of Tactics and half a bottle of a Potion of Healing)", true);
					function.Action("ShowNarration()", true);
					playerInv.push_back("Book of Tactics");
					function.SetupDialogText("Go ahead and read it.", "ReadBook", "Alright.");
					hasPurpleBook = true;
				}
				else if (modified_I == "ReadBook") {
					function.Action("SetNarration(You read the book and it tells you about how to outsmart your enemy. While reading it you feel a magical force flow into you.)", true);
					function.Action("ShowNarration()", true);
					function.SetupDialogText("Enjoy your journey!", "end", "Thanks!");
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
	function.MusicHandler("Forest_Day", currentLocation, musicPlaying);
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

		else if (i == "input Look Inside Dirt Pile CurrentForestPath.DirtPile") {
			function.WalkToPlace("Arlan", "CurrentForestPath.DirtPile");
			function.Action("SetNarration(There is a sword inside! You take it. It appears ancient and dirty. You wonder if this is the relic the elder mentioned.)", true);
			function.Action("ShowNarration()", true);
			playerInv.push_back("MathiasSword");
			sword_taken = true;
			function.Action("DisableIcon(Look Inside Dirt Pile, CurrentForestPath.DirtPile)", true);
		}
	}
}

void Story::runCurrentRuins() {
	function.MusicHandler("Spooky", currentLocation, musicPlaying);
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
					function.Action("Take(Arlan, LeaderFlashPotion, CurrentRuins.Altar)", true);
					flashback1();
				}
			}
		}

		if (i == "input arrived Arlan position CurrentRuins.Exit") {
			function.Transition("Arlan", "CurrentRuins.Exit", "CurrentForestPath.EastEnd");
			currentLocation = "CurrentForestPath";
		}

		else if (i == "input Examine_Altar CurrentRuins.Altar") {
			function.WalkToPlace("Arlan", "CurrentRuins.Altar");
			function.Action("SetRight(null)", true);
			if (!item_placed && (sword_taken || spellbook_taken)) {
				function.Action("DisableInput()", true);
				function.Action("ShowDialog()", true);
				function.Action("ClearDialog()", true);
				function.Action("SetLeft(Arlan)", true);
				function.Action("EnableInput()", true);
				if (sword_taken && spellbook_taken) {
					function.Action("SetDialog(You hear a whisper. \"Place the tribute to see the past.\" Place your item?\\n[placeMathiasSword|Place Mathias Sword.]\\n[placeArchieSpellbook|Place Archie Spellbook.])", true);
				}
				else if (sword_taken) {
					function.Action("SetDialog(You hear a whisper. \"Place the tribute to see the past.\" Place your item?\\n[placeMathiasSword|Place Mathias Sword.])", true);
				}
				else if (spellbook_taken) {
					function.Action("SetDialog(You hear a whisper. \"Place the tribute to see the past.\" Place your item?\\n[placeArchieSpellbook|Place Archie Spellbook.])", true);
				}
			}
		}

		else if (i == "input Selected placeMathiasSword") {
			if (!spellbook_taken) {
				function.Action("DisableIcon(Look Inside Barrel, CurrentTown.Barrel)", true);
			}
			function.Action("DisableIcon(Examine_Altar, CurrentRuins.Altar)", true);
			MathiasFlashback = true;
			//function.Action("DisableIcon(Talk_To_Guard, PrisonGuard)", true);
			function.Action("HideDialog()", true);
			if (sword_taken) {
				function.RemoveItem("MathiasSword", playerInv);
				if (spellbook_taken) { function.RemoveItem("ArchieSpellbook", playerInv); }
				//function.Action("SetPosition(MathiasSword, CurrentRuins.Altar.Top)", true);
				function.Action("Unpocket(Arlan, MathiasSword)", true);
				function.Action("Put(Arlan, MathiasSword, CurrentRuins.Altar)", true);
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
			if (!sword_taken) {
				function.Action("DisableIcon(Look Inside Dirt Pile, CurrentForestPath.DirtPile)", true);
			}
			function.Action("DisableIcon(Examine_Altar, CurrentRuins.Altar)", true);
			ArchieFlashback = true;
			function.Action("HideDialog()", true);
			if (spellbook_taken) {
				function.RemoveItem("ArchieSpellbook", playerInv);
				if (sword_taken) { function.RemoveItem("MathiasSword", playerInv); }
				//function.Action("SetPosition(ArchieSpellbook, CurrentRuins.Altar.Top)", true);
				function.Action("Unpocket(Arlan, ArchieSpellbook)", true);
				function.Action("Put(Arlan, ArchieSpellbook, CurrentRuins.Altar)", true);
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
	}
}

//Chractercheck is sword_taken
void Story::runPastCottage(bool CharacterCheck) {
	function.MusicHandler("Explorer", currentLocation, musicPlaying);
	function.Action("SetPosition(LeaderFlashPotion)", true);
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
			function.WalkToPlace(CharacterName, "Letter");
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
	function.MusicHandler("Forest_Day", currentLocation, musicPlaying);
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
	function.MusicHandler("Town_Day", currentLocation, musicPlaying);
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
	function.MusicHandler("Danger1", currentLocation, musicPlaying);
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
					function.WalkToPlace(Enemy, "PastRuins.Altar");
					function.Action("Face(" + Enemy + ", " + CharacterName + ")", true);
					function.Action("Cast(" + Enemy + ", " + CharacterName + ")", true); //This works for now, but will need to change Mathias to a sword
					function.Action("Kneel(" + CharacterName + ")", false);
					function.Action("Face(" + Enemy + ", MysteriousSkull)", true);
					function.Action("SetPosition(MysteriousSkull)", true);
					function.Action("Unpocket(" + Enemy + ", MysteriousSkull)", true);
					function.WalkToPlace(Enemy, "PastRuins.Exit");
					function.Action("SetPosition(" + Enemy + ")", true);
					function.WalkToPlace(CharacterName, "PastRuins.Altar");
					function.Action("FadeOut()", true);
					setupLeftHallway("LeftHallway");
					setupGreatHall("CurrentGreatHall");
					setupDiningRoom("CurrentDiningRoom");
					setupPort("CurrentPort");
					setupStorage("CurrentStorage");
					currentLocation = "CurrentRuins";
					function.Action("SetPosition(Arlan, CurrentRuins.Altar)", true);
					function.Action("Kneel(Arlan)", true);
					function.Action("SetCameraFocus(Arlan)", true);
					function.Action("SetExpression(Arlan, Neutral)", true);
					function.Action("FadeIn()", false);
					function.WalkToPlace("Arlan", "CurrentRuins.Altar");
					function.Action("SetNarration(What an odd vision...)", true);
					function.Action("ShowNarration()", true);
					function.Action("EnableInput()", true);
				}
			}
		}
	}
}

void Story::runForestPath2() {
	function.MusicHandler("Forest_Day", currentLocation, musicPlaying);
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
			function.Action("DisableIcon(Search Well, ForestPath2.Well)", true);
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
			function.Action("PlaySound(Pocket)", true);
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

void Story::runCurrentCastleCrossroads() {
	function.MusicHandler("River", currentLocation, musicPlaying);
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
			if (ArchieFlashback) {
				if (!hasTranslatingGlass && !hasPurpleBook && !hasPurplePotion) {
					function.Transition("Arlan", "CurrentCastleCrossroads.WestEnd", "CurrentPort.Exit");
					currentLocation = "CurrentPort";
				}
				else {
					if (hasPurpleBook || hasPurplePotion) {
						function.Action("SetNarration(The artifact is repelling you from this place)", true);
						function.Action("ShowNarration()", true);
					}
					else {
						function.Action("SetNarration(There is no reason to go back.)", true);
						function.Action("ShowNarration()", true);
					}
				}
			}
			else {
				function.Transition("Arlan", "CurrentCastleCrossroads.WestEnd", "CurrentPort.Exit");
				currentLocation = "CurrentPort";
			}
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
	function.MusicHandler("LivelyMusic", currentLocation, musicPlaying);
	if (MathiasFlashback) {
		while (currentLocation == "CurrentGreatHall") {
			string i;
			getline(cin, i);

			//Gets the first word that isn't "input"
			modified_I = function.splitInput(i, 6, false);

			bool inputWasCommon = function.checkCommonKeywords(i, modified_I, "Arlan", playerInv);

			if (!inputWasCommon) {

			}

			//CurrentCastleCrossroads
			if (i == "input Enter Gate CurrentGreatHall.Gate") {
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
				if (!hasGreenPotion && MathiasFlashback) {
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
				else if (!MathiasFlashback) {
					function.Action("SetNarration(An ominous force repels you from this room.)", true);
					function.Action("ShowNarration()", true);
				}
			}
		}
	}
	else if (ArchieFlashback) {
		//Visual Effects
		if (!hasRedBook && !hasPurpleBook && !hasPurplePotion) {
			function.Action("EnableEffect(Translated Book, Diamond)", true);
		}

		while (currentLocation == "CurrentGreatHall") {
			string i;
			getline(cin, i);

			//Gets the first word that isn't "input"
			modified_I = function.splitInput(i, 6, false);

			bool inputWasCommon = function.checkCommonKeywords(i, modified_I, "Arlan", playerInv);

			if (!inputWasCommon) {
				if (modified_I == "Read_Book") {
					function.Action("PlaySound(Book, Translated Book)", true);
					function.WalkToPlace("Arlan", "CurrentGreatHall.Table");
					if (hasPurplePotion || hasPurpleBook) {
						function.Action("SetNarration(The pages are blank. I guess this book is of no use to me.)", true);
						function.Action("ShowNarration()", true);
					}
					else if (hasLitTorch) {
						function.Action("Unpocket(Arlan, Torch)", true);
						torchUnpocketed = true;
						this_thread::sleep_for(chrono::milliseconds(500));
						if (hasTranslatingGlass) {
							function.Action("SetNarration(Using the Translating Glass you begin to translate the book. The books contains a way to nullify the power of magical items... or does it mean amplify? You should probably take this.)", true);
							function.Action("ShowNarration()", true);
							if (!iconEnabled) {
								function.Action("EnableIcon(Take_Book, Take, Translated Book, Take Book, true)", true);
								iconEnabled = true;
							}
						}
						else {
							function.Action("SetNarration(With the light words start to form on pages but you don't know what they mean. You have heard rumors of a Translating Glass but they are rare and said to be found by the sea.)", true);
							function.Action("ShowNarration()", true);
						}
					}
					else {
						function.Action("SetNarration(It's too dark to read. I better get some light)", true);
						function.Action("ShowNarration()", true);

					}
				}
				else if (modified_I == "Take_Book") {
					//function.Action("Pocket(Arlan, Torch)", true);
					function.Action("DisableEffect(Translated Book)", true);
					function.Action("Take(Arlan, Translated Book, CurrentGreatHall.Table)", true);
					function.Action("Pocket(Arlan, Translated Book)", true);
					playerInv.push_back("Translated Book");
					function.Action("DisableIcon(Take_Book, Translated Book)", true);
					function.Action("DisableIcon(Read_Book, Translated Book)", true);
					hasRedBook = true;
				}
			}

			//CurrentCastleCrossroads
			if (i == "input Enter Gate CurrentGreatHall.Gate") {
				if (!hasRedBook && !hasPurpleBook && !hasPurplePotion) {
					function.Action("DisableEffect(Translated Book)", false);
				}
				function.Transition("Arlan", "CurrentGreatHall.Gate", "CurrentCastleCrossroads.Gate");
				currentLocation = "CurrentCastleCrossroads";

			}
			else if (i == "input arrived Arlan position CurrentGreatHall.Gate") {
				if (!hasRedBook && !hasPurpleBook && !hasPurplePotion) {
					function.Action("DisableEffect(Translated Book)", false);
				}
				function.Transition("Arlan", "CurrentGreatHall.Gate", "CurrentCastleCrossroads.Gate");
				currentLocation = "CurrentCastleCrossroads";

			}
			//LeftHallway
			else if (i == "input Enter Left Door CurrentGreatHall.LeftDoor") {
				if (!hasRedBook && !hasPurpleBook && !hasPurplePotion) {
					function.Action("DisableEffect(Translated Book)", false);
				}
				function.Transition("Arlan", "CurrentGreatHall.LeftDoor", "LeftHallway.Door");
				currentLocation = "LeftHallway";

			}
			//RightHallway
			else if (i == "input Enter Right Door CurrentGreatHall.RightDoor") {
				if (!hasRedBook && !hasPurpleBook && !hasPurplePotion) {
					function.Action("DisableEffect(Translated Book)", false);
				}
				function.Transition("Arlan", "CurrentGreatHall.RightDoor", "RightHallway.Door");
				currentLocation = "RightHallway";

			}
			//CurrentStorage
			else if (i == "input Enter Basement Door CurrentGreatHall.BasementDoor") {
				if (!hasRedBook && !hasPurpleBook && !hasPurplePotion) {
					function.Action("DisableEffect(Translated Book)", false);
				}
				function.Transition("Arlan", "CurrentGreatHall.BasementDoor", "CurrentStorage.Door");
				currentLocation = "CurrentStorage";

			}
			//action with closing narration
			else if (modified_I == "Close" && torchUnpocketed) {
				function.Action("Pocket(Arlan, Torch)", true);
				torchUnpocketed = false;
			}

		}
	}
}

void Story::runCurrentPort() {
	function.MusicHandler("Port", currentLocation, musicPlaying);
	if (MathiasFlashback) {
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
						if (hasStrangeElixir) {
							if (drankStangeElixir) {
								function.SetupDialogText("That was my last item, sorry!", "askElixir", "That elixir didnt do anything!");
							}
							else {
								function.SetupDialogText("That was my last item, sorry!", "end", "*Leave.*");
							}
						}
						else if (!MathiasFlashback) {
							function.SetupDialogText("Hello there! Unfortunately I just sold my last seafaring item to that sailor gentlemen over there. Sorry!", "askCoins", "Any idea where I could spend some coin?", "end", "*Leave.*");
						}
						else if (hasGreenBook || hasGreenPotion)
						{
							if (!spokenWithMerchant) {
								function.SetupDialogText("Hello there! Unfortunately I just sold my last seafaring item to that sailor gentlemen over there. Sorry!", "askCoins", "Any idea where I could spend some coin?", "end", "*Leave.*");
							}
							else {
								function.SetupDialogText("Hello again! Unfortunately that sailor gentleman gathered enough coin to purchase the compass. I can no longer sell it to you. Sorry!", "askCoins", "Is there anything else I can purchase?", "end", "*Leave.*");
							}
						}
						else if (boughtCompass) {
							function.SetupDialogText("That compass was my last item. Sorry!", "end", "Okay!");
						}
						else {
							function.SetupDialogText("High quality ship wares for sale! Our newest item is a top notch compass! Interested? Only four gold pieces!", "buyCompass", "Ill take it!", "end", "No thanks.");
							spokenWithMerchant = true;
						}
					}

					else if (modified_I == "Sailor") {
						function.SetupDialog("Arlan", "Sailor", true);
						if (!MathiasFlashback || hasGreenBook || hasGreenPotion) {
							function.SetupDialogText("*The sailor appears enthralled by a compass and isnt responding.*", "end", "*Leave.*");
						}
						else if (hasCompass) {
							function.SetupDialogText("Ah! That compass! I cannot sail again until I have one just like that. Would you be willing to trade it for a valuable relic I found at sea?", "giveCompass", "Sure!", "end", "No thanks.");
						}
						else if (hasBlueBook) {
							function.SetupDialogText("Thanks again for your help! Hope that book is useful for ya.", "end", "*Leave.*");
						}
						else {
							function.SetupDialogText("You there! Care to help an old sailor out? I cant sail again until I have a compass. That merchant over there is selling one but he refuses to take sea shells as payment. Could you get it for me? I'll trade you an artifact I found at sea for it!", "end", "Ill see what I can do.");
						}
					}
				}

				else if (modified_I == "Selected") {
					modified_I = function.splitInput(i, 0, true);

					if (modified_I == "buyCompass") {
						if (numCoins >= 4) {
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
						//function.RemoveItem("Coin5", playerInv);
						numCoins = 0;
						playerInv.push_back("Compass");
						hasCompass = true;
						boughtCompass = true;
						function.Action("SetNarration(A compass has been added to your inventory. 4 coins have been removed.)", true);
						function.Action("ShowNarration()", true);
						function.Action("PlaySound(Unpocket)", true);
						function.Action("PlaySound(Pocket)", true);
					}

					else if (modified_I == "askCoins") {
						function.SetupDialogText("Well... I do have an imported elixir from overseas... It is said to induce strange visions and abilities. I could part with it for say... 4 coins?", "buyElixir", "Sure.", "end", "*No thanks.");
					}

					else if (modified_I == "buyElixir") {
						if (numCoins >= 5) {
							function.SetupDialogText("Here you are! Enjoy!", "endPortMerchantElixir", "Thanks!");
						}
						else {
							function.SetupDialogText("Ah. My apologies. It seems you dont quite have enough coin. Im sure you could find some scattered about the kingdom if you looked hard enough.", "end", "Okay!");
						}
					}

					else if (modified_I == "endPortMerchantElixir") {
						function.Action("ClearDialog()", true);
						function.Action("HideDialog()", true);
						function.RemoveItem("Coin1", playerInv);
						function.RemoveItem("Coin2", playerInv);
						function.RemoveItem("Coin3", playerInv);
						function.RemoveItem("Coin4", playerInv);
						//function.RemoveItem("Coin5", playerInv);
						numCoins = 0;
						playerInv.push_back("StrangeElixir");
						hasStrangeElixir = true;
						function.Action("SetNarration(A strange elixir has been added to your inventory. 4 coins have been removed.)", true);
						function.Action("ShowNarration()", true);
						function.Action("PlaySound(Unpocket)", true);
						function.Action("PlaySound(Pocket)", true);
					}

					else if (modified_I == "askElixir") {
						function.SetupDialogText("*He shrugs.* Sorry! No refunds.", "end", "Fine. *Leave*");
					}

					else if (modified_I == "giveCompass") {
						function.SetupDialogText("Finally! I can sail again! Here. You can have this old book I found at sea. Seems valuable!", "endSailor", "Thanks!");
						function.Action("PlaySound(Unpocket)", true);
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
						function.Action("PlaySound(Pocket)", true);
					}
				}
			}

			if (i == "input TakeCoin4 CurrentPort.Barrel") {
				function.WalkToPlace("Arlan", "CurrentPort.Barrel");
				function.Action("SetNarration(Theres a gold coin in the barrel! You take it.)", true);
				function.Action("ShowNarration()", true);
				function.Action("PlaySound(Pocket)", true);
				playerInv.push_back("Coin4");
				numCoins++;
				function.Action("DisableIcon(TakeCoin4, CurrentPort.Barrel)", true);
			}

			/*else if (i == "input ReadBookOfLore BookOfLore") {
				function.Action("HideList()", true);
				function.Action("ClearList()", true);
				function.Action("SetNarration(The book describes an ancient tome that instills its owner with unimaginable power. Those who posess it are said to be destined to rule to world.)", true);
				function.Action("ShowNarration()", true);
			}*/

			else if (i == "input DrinkStrangeElixir StrangeElixir") {
				function.Action("Unpocket(Arlan, StrangeElixir)", true);
				function.Action("Drink(Arlan)", true);
				function.Action("SetNarration(The elixir tastes terrible. It doesnt seem to do much else.)", true);
				function.Action("ShowNarration()", true);
				function.RemoveItem("StrangeElixir", playerInv);
				drankStangeElixir = true;
			}

			//CurrentCastleCrossroads
			else if (i == "input arrived Arlan position CurrentPort.Exit") {
				function.Transition("Arlan", "CurrentPort.Exit", "CurrentCastleCrossroads.WestEnd");
				currentLocation = "CurrentCastleCrossroads";
			}
		}
	}
	else if (ArchieFlashback) {
		//visual effect
		if (!boatOnFire) {
			function.Action("EnableEffect(CurrentPort.SmallShip, Diamond)", true);
		}
		else {
			function.Action("EnableEffect(CurrentPort.SmallShip, WildFire)", true);
			function.Action("PlaySound(Fireplace, CurrentPort.SmallShip, true)", true);
		}
		function.Action("EnableEffect(Translating Glass, Diamond)", true);

		while (currentLocation == "CurrentPort") {
			string i;
			getline(cin, i);

			//Gets the first word that isn't "input"
			modified_I = function.splitInput(i, 6, false);

			bool inputWasCommon = function.checkCommonKeywords(i, modified_I, "Arlan", playerInv);

			if (!inputWasCommon) {
				if (modified_I == "Talk_To_Trader") {
					function.SetupDialog("Arlan", "ShipTrader", true);
					if (boatOnFire) {
						function.SetupDialogText("What do you want?", "Fire", "Is that your boat on fire?", "end", "Leave");
					}
					else {
						function.SetupDialogText("What do you want?", "Ask", "What is you are selling?", "end", "Leave");
					}
				}
				else if (modified_I == "Selected") {
					modified_I = function.splitInput(i, 0, true);

					if (modified_I == "Fire") {
						function.Action("SetExpression(ShipTrader, Scared)", true);
						function.SetupDialogText("What!...How?", "Distraction", "You should probably go get help.");
					}
					else if (modified_I == "Ask") {
						function.SetupDialogText("That right there is a rare item called a Translating Glass.", "Question", "How much for it?", "end", "Leave");
					}
					else if (modified_I == "Question") {
						function.SetupDialogText("By the looks of you I'd say that you would never be able to afford this. Now don't waste my time.", "end", "Leave");
					}
					else if (modified_I == "Distraction") {
						function.Action("HideDialog()", true);
						function.Action("DisableInput()", true);
						function.Action("SetCameraFocus(ShipTrader)", false);
						function.WalkToPlace("ShipTrader", "CurrentPort.Exit");
						function.Action("FadeOut()", true);
						function.Action("SetCameraFocus(Arlan)", true);
						function.Action("DisableIcon(Talk_To_Trader, ShipTrader)", true);
						function.Action("SetPosition(ShipTrader, ArlanCottage.Bed)", true);
						this_thread::sleep_for(chrono::milliseconds(500));
						function.Action("FadeIn()", true);
						function.Action("EnableInput()", true);
						merchantDistracted = true;
					}
					else if (modified_I == "Steal") {
						function.Action("DisableEffect(Translating Glass)", false);
						function.Action("HideDialog()", true);
						function.Action("SetExpression(ShipTrader, Angry)", true);
						//function.Action("Attack(Arlan, ShipTrader, true)", true);
						function.Action("Take(Arlan, Translating Glass, CurrentPort.BigStall.Left)", true);
						function.Action("Pocket(Arlan, Translating Glass)", true);
						function.Action("DisableIcon(Take_Glass, Translating Glass)", true);
						playerInv.push_back("Translating Glass");
						hasTranslatingGlass = true;
						function.SetupDialog("Arlan", "ShipTrader", true);
						function.SetupDialogText("Hey! GET BACK HERE!", "end", "RUN");
					}
				}
				else if (modified_I == "Take_Glass") {
					if (merchantDistracted) {
						function.Action("DisableEffect(Translating Glass)", false);
						function.Action("Take(Arlan, Translating Glass, CurrentPort.BigStall.Left)", true);
						function.Action("Pocket(Arlan, Translating Glass)", true);
						function.Action("DisableIcon(Take_Glass, Translating Glass)", true);
						playerInv.push_back("Translating Glass");
						hasTranslatingGlass = true;
					}
					else {
						function.SetupDialog("Arlan", "ShipTrader", true);
						function.SetupDialogText("What do think you are doing?", "Ask", "I was looking at this. What is it?", "Steal", "Taking this.", "end", "Leave");

					}
				}
				else if (modified_I == "Intract_Ship") {
					if (hasLitTorch) {
						function.Action("DisableEffect(CurrentPort.SmallShip)", false);
						function.Action("DisableInput()", true);
						//function.WalkToPlace("Arlan", "CurrentPort.SmallShip");
						function.Action("Unpocket(Arlan, Torch)", true);
						function.Action("PutDown(Arlan, Torch)", true);
						function.Action("EnableEffect(CurrentPort.SmallShip, WildFire)", false);
						function.Action("PlaySound(Fireplace, CurrentPort.SmallShip, true)", false);
						function.Action("DisableIcon(Intract_Ship, CurrentPort.SmallShip)", true);
						boatOnFire = true;
						function.Action("EnableInput()", true);

					}
					else {
						function.Action("SetNarration(The boat looks quite flamable.)", true);
						function.Action("ShowNarration()", true);
					}
				}
			}

			//CurrentCastleCrossroads
			if (i == "input arrived Arlan position CurrentPort.Exit") {
				function.Action("DisableEffect(CurrentPort.SmallShip)", false);
				function.Action("DisableEffect(Translating Glass)", false);
				if (boatOnFire){ function.Action("StopSound(Fireplace, CurrentPort.SmallShip)", false); }
				function.Transition("Arlan", "CurrentPort.Exit", "CurrentCastleCrossroads.WestEnd");
				currentLocation = "CurrentCastleCrossroads";
			}
			else if (i == "input Selected end" && hasTranslatingGlass) {
				function.Action("DisableEffect(CurrentPort.SmallShip)", false);
				if (boatOnFire) { function.Action("StopSound(Fireplace, CurrentPort.SmallShip)", false); }
				function.Transition("Arlan", "CurrentPort.Exit", "CurrentCastleCrossroads.WestEnd");
				currentLocation = "CurrentCastleCrossroads";
			}
		}
	}
}

void Story::runCurrentLibrary() {
	string position = "";
	string onLeft = "Library GreenKey";
	string onCenter = "Library Apple";
	string onRight = "Library GoldCup";
	bool correctLeft = false; 
	bool correctCenter = false;
	bool correctRight = false;
	bool inventoryErrorCheck = true;
	function.Action("SetLeft(Arlan)", true);
	function.Action("SetRight(null)", true);
	function.MusicHandler("Serenity", currentLocation, musicPlaying);
	while (currentLocation == "CurrentLibrary") {
		string i;
		getline(cin, i);
		//Gets the first word that isn't "input"
		modified_I = function.splitInput(i, 6, false);

		bool inputWasCommon = function.checkCommonKeywords(i, modified_I, "Arlan", playerInv);

		if (!inputWasCommon) {

		}

		if (correctLeft && correctCenter && correctRight && !hasGreenBook && !libraryPuzzleSolved) {
			libraryPuzzleSolved = true;
			function.Action("SetPosition(Book Of Incantations, CurrentLibrary.Table)", true);
			function.Action("CreateEffect(Book Of Incantations, Resurrection)", true);
			function.Action("EnableEffect(Book Of Incantations, Resurrection)", true);
			function.Action("DisableIcon(PickUp, Library Apple)", true);
			function.Action("DisableIcon(PickUp, Library GoldCup)", true);
			function.Action("DisableIcon(PickUp, Library GreenKey)", true);
		}

		//RightHallway
		if (i == "input Leave Library CurrentLibrary.Door") {
			if (!libraryPuzzleSolved) {
				function.Action("SetNarration(The puzzle resets...)", true);
				vector<string> tempInv;
				for (string item : playerInv) {
					if (item.substr(0, 7) == "Library") {
						if (!inventoryErrorCheck) {
							function.Action("DisableIcon(PlaceItem, " + item + ")", true);
						}
						function.Action("EnableIcon(PickUp, Hand, " + item + ", Pick Up, true)", true);
					}
					else {
						tempInv.push_back(item);
					}
				}
				playerInv = tempInv;
				function.Action("SetPosition(Library GoldCup)", true);
				function.Action("SetPosition(Library GreenKey)", true);
				function.Action("SetPosition(Library Apple)", true);
				function.Action("SetPosition(Library GoldCup, CurrentLibrary.AlchemistTable.Right)", true);
				function.Action("SetPosition(Library GreenKey, CurrentLibrary.AlchemistTable.Left)", true);
				function.Action("SetPosition(Library Apple, CurrentLibrary.AlchemistTable.Center)", true);
				function.Transition("Arlan", "CurrentLibrary.Door", "RightHallway.Stairs");
				function.Action("ShowNarration()", true);
				currentLocation = "RightHallway";
			}
			else {
				function.Transition("Arlan", "CurrentLibrary.Door", "RightHallway.Stairs");
				currentLocation = "RightHallway";
			}
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
				function.Action("DisableEffect(Book Of Incantations)", true);
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

		else if ((modified_I == "PlaceLibraryItemLeft") || (modified_I == "PlaceLibraryItemCenter") || (modified_I == "PlaceLibraryItemRight")) {
			position = modified_I.substr(16);
			function.WalkToPlace("Arlan", "CurrentLibrary.AlchemistTable");
			if (libraryPuzzleSolved) {
				function.SetupDialogText("The order has been restored.", "end", "**Walk Away**");
				function.Action("ShowDialog()", true);
			}
			else {
				function.ItemHandler("none", "ShowPlaceInventory", position, "CurrentLibrary", playerInv, inventoryErrorCheck, onLeft, onRight, onCenter, correctLeft, correctRight, correctCenter);
			}
		}

		else if (modified_I == "PlaceItem") {
			modified_I = function.splitInput(i, 0, true);
			function.ItemHandler("Library " + modified_I, "PlaceItem", position, "CurrentLibrary", playerInv, inventoryErrorCheck, onLeft, onRight, onCenter, correctLeft, correctRight, correctCenter);
		}

		else if (modified_I == "PickUp") {
			modified_I = function.splitInput(i, 0, true);
			if (onLeft == "Library " + modified_I) { position = "Left"; }
			if (onCenter == "Library " + modified_I) { position = "Center"; }
			if (onRight == "Library " + modified_I) { position = "Right"; }
			function.ItemHandler("Library " + modified_I, "PickUp", position, "CurrentLibrary", playerInv, inventoryErrorCheck, onLeft, onRight, onCenter, correctLeft, correctRight, correctCenter);
		}
	}
}

void Story::runCurrentStorage() {
	function.MusicHandler("Tavern", currentLocation, musicPlaying);
	if (MathiasFlashback) {
		string position = "";
		string onLeft = "", onCenter = "", onRight = "";
		bool correctLeft = false, correctRight = false, correctCenter = false;
		bool inventoryErrorCheck = true;
		string chestItem = "";
		function.Action("SetLeft(Arlan)", true);
		function.Action("SetRight(null)", true);
		while (currentLocation == "CurrentStorage") {
			string i;
			getline(cin, i);

			//Gets the first word that isn't "input"
			modified_I = function.splitInput(i, 6, false);

			bool inputWasCommon = function.checkCommonKeywords(i, modified_I, "Arlan", playerInv);

			if (!inputWasCommon) {

			}

			//CurrentGreatHall
			if (i == "input Leave Storage CurrentStorage.Door") {
				if (!storagePuzzleSolved && (onLeft == "") && (onRight == "")) {
					function.Action("SetNarration(The puzzle resets...)", true);
					vector<string> tempInv;
					for (string item : playerInv) {
						if (item.substr(0, 7) == "Storage") {
							if (!inventoryErrorCheck) {
								function.Action("DisableIcon(PlaceItem, " + item + ")", true);
							}
							function.Action("EnableIcon(TakeStorageItemFromChest, Hand, " + item + ", Pick Up, true)", true);
							CurrentStorage.chestInv.push_back(item);
						}
						else {
							tempInv.push_back(item);
						}
					}
					playerInv = tempInv;
					function.Action("SetPosition(Storage Bottle)", true);
					function.Action("SetPosition(Storage Bread)", true);
					function.Action("SetPosition(Storage Helmet)", true);
					function.Action("SetPosition(Storage InkAndQuill)", true);
					function.Action("SetPosition(Storage Bag)", true);
					function.Transition("Arlan", "CurrentStorage.Door", "CurrentGreatHall.BasementDoor");
					function.Action("ShowNarration()", true);
					currentLocation = "CurrentGreatHall";
				}
				else if ((onLeft != "") || (onRight != "")) {
					function.Action("SetNarration(You can't leave while items lay on the shelf...)", true);
					function.Action("ShowNarration()", true);
				}
				else {
					function.Transition("Arlan", "CurrentStorage.Door", "CurrentGreatHall.BasementDoor");
					currentLocation = "CurrentGreatHall";
				}
			}

			if (correctLeft && correctRight && !hasGreenPotion && !storagePuzzleSolved) {
				storagePuzzleSolved = true;
				function.Action("SetPosition(Storage OpenScroll)", true);
				function.Action("SetPosition(Potion Of Cleansing, CurrentStorage.Barrel)", true);
				function.Action("CreateEffect(Potion Of Cleansing, Resurrection)", true);
				function.Action("EnableEffect(Potion Of Cleansing, Resurrection)", true);
				function.Action("DisableIcon(PickUp, Storage Bread)", true);
				function.Action("DisableIcon(PickUp, Storage Bottle)", true);
				function.RemoveItem("Storage InkAndQuill", playerInv);
				function.RemoveItem("Storage InkAndQuill", CurrentStorage.chestInv);
				function.RemoveItem("Storage Helmet", playerInv);
				function.RemoveItem("Storage Helmet", CurrentStorage.chestInv);
				function.RemoveItem("Storage Bag", playerInv);
				function.RemoveItem("Storage Bag", CurrentStorage.chestInv);
			}

			else if (i == "input Interact With Potion Of Cleansing Potion Of Cleansing") {
				function.Action("SetRight(null)", true);
				function.Action("SetNarration(This potion can cleanse the evil spirits from the heart of men. Potion Of Cleansing Added To Inventory.)", true);
				function.Action("ShowNarration()", true);
				function.Action("DisableEffect(Potion Of Cleansing)", true);
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

			else if (i == "input Open Storage Chest CurrentStorage.Chest") {
				function.Action("ClearList()", true);
				function.WalkToPlace("Arlan", "CurrentStorage.Chest");
				function.Action("DisableInput()", true);
				function.Action("OpenFurniture(Arlan, CurrentStorage.Chest)", true);
				function.Action("EnableInput()", true);
				function.ShowInv("CurrentStorage.Chest", CurrentStorage.chestInv);
				isChestOpened = true;
			}

			else if (modified_I == "TakeStorageItemFromChest") {
				chestItem = i.substr(39);
				function.RemoveItem("Storage " + chestItem, CurrentStorage.chestInv);
				function.Action("RemoveFromList(Storage " + chestItem + ")", true);
				playerInv.push_back("Storage " + chestItem);
				function.Action("DisableIcon(TakeStorageItemFromChest, Storage " + chestItem + ")", true);
			}

			else if ((modified_I == "PlaceStorageItemLeft") || (modified_I == "PlaceStorageItemRight")) {
				position = modified_I.substr(16);
				function.WalkToPlace("Arlan", "CurrentStorage.Shelf");
				if (storagePuzzleSolved) {
					function.SetupDialogText("The order has been restored.", "end", "**Walk Away**");
					function.Action("ShowDialog()", true);
				}
				else {
					function.ItemHandler("none", "ShowPlaceInventory", position, "CurrentStorage", playerInv, inventoryErrorCheck, onLeft, onRight, onCenter, correctLeft, correctRight, correctCenter);
				}
			}

			else if (modified_I == "PlaceItem") {
				modified_I = function.splitInput(i, 0, true);
				function.ItemHandler("Storage " + modified_I, "PlaceItem", position, "CurrentStorage", playerInv, inventoryErrorCheck, onLeft, onRight, onCenter, correctLeft, correctRight, correctCenter);
			}

			else if (modified_I == "PickUp") {
				modified_I = function.splitInput(i, 0, true);
				if (onLeft == "Storage " + modified_I) { position = "Left"; }
				if (onRight == "Storage " + modified_I) { position = "Right"; }
				function.ItemHandler("Storage " + modified_I, "PickUp", position, "CurrentStorage", playerInv, inventoryErrorCheck, onLeft, onRight, onCenter, correctLeft, correctRight, correctCenter);
			}

			else if (i == "input Read Storage OpenScroll Storage OpenScroll") {
				function.Action("SetRight(null)", true);
				function.SetupDialogText("In this storage some items reside in a chest.\\nSome are useless a red herring at its best.\\nSet a meal on the shelf for this particular test.\\nRemember that thirst is quenched from the right of the perspective of the guest.", "end", "**Walk Away**");
				function.Action("ShowDialog()", true);
			}

			if (isChestOpened && modified_I == "Close") {
				function.Action("DisableInput()", true);
				function.Action("CloseFurniture(Arlan, CurrentStorage.Chest)", true);
				function.Action("EnableInput()", true);
				isChestOpened = false;
			}
		}
	}
	else if (ArchieFlashback) {
		while (currentLocation == "CurrentStorage") {
			string i;
			getline(cin, i);

			//Gets the first word that isn't "input"
			modified_I = function.splitInput(i, 6, false);

			bool inputWasCommon = function.checkCommonKeywords(i, modified_I, "Arlan", playerInv);

			if (!inputWasCommon) {
				if (modified_I == "Open_Chest") {
					function.Action("DisableInput()", true);
					function.Action("OpenFurniture(Arlan, CurrentStorage.Chest)", true);
					function.Action("EnableInput()", true);
					function.ShowInv("CurrentStorage.Chest", CurrentStorage.chestInv);
					isChestOpened = true;
				}
				else if (modified_I == "Take_Torch") {
					function.RemoveItem("Torch", CurrentStorage.chestInv);
					function.Action("RemoveFromList(Torch)", true);
					function.Action("DisableIcon(Take_Torch, Torch)", true);
					playerInv.push_back("Torch");
					hasLitTorch = true;
				}
				else if (modified_I == "Take_Cloth") {
					function.RemoveItem("Purple Cloth", CurrentStorage.chestInv);
					function.Action("RemoveFromList(Purple Cloth)", true);
					function.Action("DisableIcon(Take_Cloth, Purple Cloth)", true);
					playerInv.push_back("Purple Cloth");
					hasCloth = true;
				}
				else if (modified_I == "Leave_Storage"){
					function.Transition("Arlan", "CurrentStorage.Door", "CurrentGreatHall.BasementDoor");
					currentLocation = "CurrentGreatHall";
				}
			}

			//closing chest animation when exiting chestInv
			if (isChestOpened && modified_I == "Close") {
				function.Action("DisableInput()", true);
				function.Action("CloseFurniture(Arlan, CurrentStorage.Chest)", true);
				function.Action("EnableInput()", true);
				isChestOpened = false;
			}
		}
	}
}

void Story::runCurrentPrison() {
	function.MusicHandler("LivelyMusic", currentLocation, musicPlaying);
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
					function.SetupDialogText("Oh hey nice to finally see someone that's not a guard! I have a question for you.", "Question", "What is it?");
				}
				else if (hasFirstPrisItem || hasSecondPrisItem || hasThirdPrisItem) {
					function.SetupDialog("Arlan", "Prisoner", false);
					if (hasFirstPrisItem) {
						function.SetupDialogText("Thank you for finding that disguise for me. Here's the next vision", "RiddleTwo", "Hit me with it");
						
						function.RemoveItem("PrisonerOutfit", playerInv);
						ForestPath2.icons.push_back(Icon("Search Well", "hand", "ForestPath2.Well", "Search Well", "true"));
						function.SetupIcons(ForestPath2.icons);

						function.Action("SetClothing(Prisoner, HeavyArmour)", true);

						hasFirstPrisItem = false;
						firstPrisRiddle = true;
					}
					if (hasSecondPrisItem) {
						function.SetupDialogText("We're almost there! This is the last one", "RiddleThree", "I'm ready");

						function.RemoveItem("PrisonerSword", playerInv);
						function.Action("EnableIcon(Search Target, hand, CurrentCourtyard.Target, Search Target, true)", true);

						function.Action("Draw(Prisoner, GuardSword)", true);

						hasSecondPrisItem = false;
						secondPrisRiddle = true;
						//thirdPrisRiddle = true;
						//function.SetupDialogText("That seems to be everything! I can finally get out of here. Here take this potion like I promised", "EndQuest", "Sweet!");

						//function.WalkToPlace("Arlan", "ForestPath2.Well");

					}
					if (hasThirdPrisItem) {
						hasThirdPrisItem = false;

						function.RemoveItem("PrisonerHammer", playerInv);

						function.SetupDialogText("That seems to be everything! Thanks for helping me get out of here. You can take this potion like I promised.", "EndQuest", "Sweet!");
					}
				}
				else {
					function.SetupDialog("Arlan", "Prisoner", false);
					if (firstPrisRiddle == false) {
						function.SetupDialogText("I see you have not found the previous item yet. Here's what I said again in case you need it", "RiddleOne", "Thanks");
					}
					else if (secondPrisRiddle == false) {
						function.SetupDialogText("I see you have not found the previous item yet. Here's what I said again in case you need it", "RiddleTwo", "Thanks");
					}
					else if (thirdPrisRiddle == false) {
						function.SetupDialogText("I see you have not found the previous item yet. Here's what I said again in case you need it", "RiddleThree", "Thanks");
					}
				}


			}

			else if (modified_I == "Selected") {
				modified_I = function.splitInput(i, 0, true);

				if (modified_I == "Question") {
					function.Action("ClearDialog()", true);
					function.SetupDialogText("Ah well see. I was wondering if you could help me escape from this place? I definitely didn't do whatever those guards are accusing me of and I could pay you back with this potion of invincibility if you'll help", "StartQuest", "A Potion? I'm definitely in!", "DialogEnd", "Uh no you're a criminal");
					//	function.Action("SetDialog(\"Ah well see. I was wondering if you could help me escape from this place? I definitely did not do the crime and could pay you in some weird potion I found earlier if you help [StartQuest|A Potion? I am definitely in!][DenyQuest|Uh no you are a criminal]\")", false);
				}
				else if (modified_I == "DialogEnd") {
					function.Action("ClearDialog()", true);
					function.Action("HideDialog()", true);
				}
				else if (modified_I == "StartQuest") {
					function.SetupDialogText("Great thanks! So I need you to find me three things. A guard outfit and a sword as a disguise. And something to get me out of this cage. Sound good?", "StartQuestCont", "Yeah so far");
				}
				else if (modified_I == "StartQuestCont") {
					function.SetupDialogText("Alright. Let me cast a location spell to give you a bit of guidance", "RiddleOne", "Wait what?");

					//CurrentGreatHall.icons.push_back(Icon("Search Chest", "hand", "CurrentStorage.Chest", "Search Chest", "true"));
					//function.SetupIcons(CurrentStorage.icons);
					function.Action("EnableIcon(Search Chest, hand, CurrentPrison.Chest, Search Chest, true)", true);
				}
				else if (modified_I == "RiddleOne") {
					//Run some kind of spell animation here
					function.Action("ClearDialog()", true);
					function.Action("HideDialog()", true);

					function.Action("SetCameraFocus(Prisoner)", true);
					function.Action("SetCameraMode(follow)", true);

					function.Action("CreateEffect(Prisoner, Force)", true);
					this_thread::sleep_for(chrono::milliseconds(2500));

					function.Action("SetCameraFocus(Arlan)", true);
					function.Action("SetCameraMode(follow)", true);

					function.SetupDialog("Arlan", "Prisoner", false);
					function.SetupDialogText("This first one is hidden in a sarcophagus of wood. You won't have to look far to find this suit of armor.", "DialogEnd", "Hmmm");
					firstTalkPris = false;
				}
				else if (modified_I == "RiddleThree") {
					function.SetupDialogText("Your final destination is where this awaits. Bullseye! You're right on target.", "DialogEnd", "Hmmm");
				}
				else if (modified_I == "RiddleTwo") {
					function.SetupDialogText("Slowly rusting. This mighty sword faces the elements day and night. Waiting for the day the metal lifeboat above comes down to help.", "DialogEnd", "Hmmm");
				}
				else if (modified_I == "EndQuest") {

					function.Action("DisableInput()", true);

					function.Action("SetNarration(Potion of Invincibility added to Inventory!)", true);
					function.Action("ShowNarration()", true);
					this_thread::sleep_for(chrono::milliseconds(2500));
					playerInv.push_back("Potion of Invincibility");
					function.Action("HideNarration()", true);
					function.Action("ClearDialog()", true);
					function.Action("HideDialog()", true);

					function.Action("SetCameraFocus(Prisoner)", true);

					function.Action("OpenFurniture(Prisoner, CurrentPrison.CellDoor)", true);
					function.Action("OpenFurniture(Prisoner, CurrentPrison.Door)", true);

					function.Action("SetCameraFocus(Arlan)", true);

					function.Action("Exit(Prisoner, CurrentPrison.Door, false)", true);
					function.Action("SetPosition(Prisoner, PastCottage)", true);

					function.Action("EnableInput()", true);


					//function.Action("WalkTo(Prisoner, CurrentPrison.CellDoor)", true);
					//function.Action("OpenFurniture(Prisoner, CurrentPrison.CellDoor)", true);
					//function.Transition("Prisoner", "CurrentPrison.Door", "LeftHallway.BackDoor");


					hasRedPotion = true;
				}

			}
			
			else if (i == "input Search Chest CurrentPrison.Chest") {
				//function.WalkToPlace("Arlan", "CurrentPrison.Chest");
				function.Action("OpenFurniture(Arlan, CurrentPrison.Chest)", true);
				function.Action("SetNarration(There is some armor hidden in the chest! You take it.)", true);
				function.Action("ShowNarration()", true);
				playerInv.push_back("PrisonerOutfit");
				function.Action("DisableIcon(Search Chest, CurrentPrison.Chest)", true);
				hasFirstPrisItem = true;
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
	function.MusicHandler("LivelyMusic", currentLocation, musicPlaying);
	while (currentLocation == "LeftHallway") {
		string i;
		getline(cin, i);

		//Gets the first word that isn't "input"
		modified_I = function.splitInput(i, 6, false);

		bool inputWasCommon = function.checkCommonKeywords(i, modified_I, "Arlan", playerInv);

		if (!inputWasCommon) {
			if (modified_I == "Talk_To_Guard" && !(hasRedBook || hasRedPotion) ) {
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
					hasPurplePotion = true;
					function.RemoveItem("CastleBedroomCrime", playerInv);
				}
			}
			else if (modified_I == "Talk_To_Guard" && (hasRedBook || hasRedPotion)) {
				function.Action("WalkTo(Arlan, PrisonGuard)", true);
				function.SetupDialog("Arlan", "PrisonGuard", false);
				function.SetupDialogText("Sorry I don't have anything for you to do", "DialogEnd", "Oh...");
			}
		}



		//CurrentPrison
		if (i == "input Enter LeftHallway BackDoor LeftHallway.BackDoor") {
			if (!ArchieFlashback) {
				function.Action("SetNarration(You may not enter)", true);
				function.Action("ShowNarration()", true);
			}
			else if (hasRedPotion || hasPurpleBook || hasPurplePotion) {
				if (hasRedPotion) {
					function.Action("SetNarration(You have already reaped the rewards of this room)", true);
				}
				else if (hasPurpleBook || hasPurplePotion) {
					function.Action("SetNarration(Your purple artifact repels you from this room)", true);
				}
				function.Action("ShowNarration()", true);
			}
			else if (ArchieFlashback && !hasRedPotion && !hasPurpleBook && !hasPurplePotion) {
				function.Transition("Arlan", "LeftHallway.BackDoor", "CurrentPrison.Door");
				currentLocation = "CurrentPrison";
			}
		}
		//CurrentDiningRoom
		else if (i == "input arrived Arlan position LeftHallway.Stairs") {
			if (ArchieFlashback && !hasRedPotion && !hasRedBook && !hasPurpleBook) {
				function.Transition("Arlan", "LeftHallway.Stairs", "CurrentDiningRoom.Door");
				currentLocation = "CurrentDiningRoom";
			}
			else if (ArchieFlashback && (hasRedBook || hasRedPotion || hasPurpleBook)) {
				function.Action("SetNarration(A mysterious force prevents you from entering. You should adventure elsewhere.)", true);
				function.Action("ShowNarration()", true);
			}

			else if (hasGreenBook || hasGreenPotion) {
				function.Action("SetNarration(A mysterious force prevents you from entering. You should adventure elsewhere.)", true);
				function.Action("ShowNarration()", true);
			}
			else if (hasBluePotion) {
				function.Action("SetNarration(A mysterious force prevents you from entering. You feel your work here is complete. You should adventure elsewhere.)", true);
				function.Action("ShowNarration()", true);
			}
			else if (MathiasFlashback && !hasGreenBook && !hasGreenPotion && !hasBluePotion) {
				function.Transition("Arlan", "LeftHallway.Stairs", "CurrentDiningRoom.Door");
				currentLocation = "CurrentDiningRoom";
			}
		}
		//else if (i == "input Enter LeftHallway Door LeftHallway.Door") {
		else if (i == "input Enter LeftHallway Door LeftHallway.Door") {
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
				function.SetupDialogText("Oh thank goodness. That prisoner in there hid some valuables from the Kingdom and said they would only return them if we could solve her puzzle. But for the life of us we can't figure it out! Can you help?", "Accept", "Sure why not?", "Reject", "I'm a little busy");
			}

			if (modified_I == "Reject") {
				function.SetupDialogText("Ah too bad. Come talk to me again if you change your mind", "DialogEnd", "Ok");
			}

			if (modified_I == "Accept") {
				firstTalkGuard = false;
				function.SetupDialogText("Alright well you need to go to the Bedroom in the other wing of the castle. You can find the puzzle there. Come back and tell me once you figure it out. I can give you this weird potion I found as compensation", "DialogEnd", "A potion!");
			}

		}
	}
}

void Story::runRightHallway() {
	function.MusicHandler("LivelyMusic", currentLocation, musicPlaying);
	while (currentLocation == "RightHallway") {
		string i;
		getline(cin, i);

		//Gets the first word that isn't "input"
		modified_I = function.splitInput(i, 6, false);

		bool inputWasCommon = function.checkCommonKeywords(i, modified_I, "Arlan", playerInv);

		if (!inputWasCommon) {

		}

		//CurrentCastleBedroom
		if (i == "input Enter RightHallway BackDoor RightHallway.BackDoor") {
			if (!ArchieFlashback) {
				function.Action("SetNarration(You may not enter)", true);
				function.Action("ShowNarration()", true);
			}
			else if (hasRedPotion || hasRedBook || hasPurplePotion) {
				if (hasPurplePotion) {
					function.Action("SetNarration(You have already reaped the rewards of this room)", true);
				}
				else if (hasRedBook || hasRedPotion) {
					function.Action("SetNarration(Your red artifact repels you from this room)", true);
				}
				function.Action("ShowNarration()", true);
			}
			else if (firstTalkGuard == true) {
				function.Action("SetNarration(You feel as if you need to talk to someone before coming in here)", true);
				function.Action("ShowNarration()", true);
			}
			else if (ArchieFlashback && !hasRedPotion && !hasPurplePotion && !hasRedBook) {
				function.Transition("Arlan", "RightHallway.BackDoor", "CurrentCastleBedroom.Door");
				currentLocation = "CurrentCastleBedroom";
			}
		}
		//CurrentGreatHall
		//else if (i == "input Enter RightHallway Door RightHallway.Door") {
		//RightHallway.icons.push_back(Icon("Enter RightHallway Door", "Hand", "RightHallway.Door", "Enter", "true"));
		//(i == "input Open Door CurrentPrison.Door")
		else if (i == "input Enter RightHallway Door RightHallway.Door") {
			function.Transition("Arlan", "RightHallway.Door", "CurrentGreatHall.RightDoor");
			currentLocation = "CurrentGreatHall";
		}
		//CurrentLibrary
		else if (i == "input arrived Arlan position RightHallway.Stairs") {
			if (!hasGreenBook && MathiasFlashback) {
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
			else if (!MathiasFlashback) {
					function.Action("SetNarration(An ominous force repels you from this room.)", true);
					function.Action("ShowNarration()", true);
			}
		}
	}
}

void Story::runCurrentDiningRoom() {
	function.MusicHandler("LivelyMusic", currentLocation, musicPlaying);
	if (MathiasFlashback) {
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
						function.Action("PlaySound(Pocket)", true);
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
					// get name of selected chair
					modified_I = function.splitInput(i, 0, true);

					// walk to selected chair
					//function.Action("WalkTo(Arlan, " + modified_I + ")", true);

					// show "Dining" items in inventory, adjust interactions for each
					for (string item : playerInv) {
						if (item.substr(0, 6) == "Dining") {
							function.Action("AddToList(" + item + ")", true);
							function.Action("EnableIcon(Place, Hand, " + item + ", Place, true)", true);
							//function.Action("DisableIcon(PickUp, " + item + ")", true);
						}
					}
					function.Action("ShowList(Arlan)", true);

					// set currentChair according to which chair player clicked
					if (modified_I == "CurrentDiningRoom.LeftChair") currentChair = "Left";
					else if (modified_I == "CurrentDiningRoom.FrontLeftChair") currentChair = "FrontLeft";
					else if (modified_I == "CurrentDiningRoom.FrontRightChair") currentChair = "FrontRight";
					else if (modified_I == "CurrentDiningRoom.RightChair") currentChair = "Right";
					else if (modified_I == "CurrentDiningRoom.BackRightChair") currentChair = "BackRight";
					else if (modified_I == "CurrentDiningRoom.BackLeftChair") currentChair = "BackLeft";

					// true while dining item placement list is open
					isPlacingItem = true;
				}

				else if (modified_I == "Place") {
					modified_I = function.splitInput(i, 0, true);

					for (string item : playerInv) {
						if (item.substr(0, 6) == "Dining") {
							function.Action("DisableIcon(Place, " + item + ")", true);
						}
					}

					function.Action("HideList()", true);
					function.Action("ClearList()", true);
					function.RemoveItem(modified_I, playerInv);
					function.Action("PlaySound(Unpocket)", true);
					//function.Action("Unpocket(Arlan, " + modified_I + ")", true);
					//function.Action("Put(Arlan, " + modified_I + ", CurrentDiningRoom.DiningTable." + currentChair + ")", true);
					function.Action("SetPosition(" + modified_I + ", CurrentDiningRoom.DiningTable." + currentChair + ")", true);
					function.Action("EnableIcon(PickUp, Hand, " + modified_I + ", Pick up, true)", true);
					function.Action("DisableIcon(PlaceInChair, CurrentDiningRoom." + currentChair + "Chair)", true);

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

					isPlacingItem = false;
				}

				else if (modified_I == "PickUp") {
					modified_I = function.splitInput(i, 0, true);

					if (modified_I == "DiningApple") currentChair = appleLocation;
					else if (modified_I == "DiningBottle") currentChair = bottleLocation;
					else if (modified_I == "DiningBread") currentChair = breadLocation;
					else if (modified_I == "DiningCup") currentChair = cupLocation;
					else if (modified_I == "DiningChalice") currentChair = chaliceLocation;
					else if (modified_I == "DiningMeat") currentChair = meatLocation;


					//function.Action("Take(Arlan, " + modified_I + ", CurrentDiningRoom." + currentChair + "Chair)", true);
					//function.Action("Pocket(Arlan, " + modified_I + ")", true);
					function.Action("SetPosition(" + modified_I + ")", true);
					playerInv.push_back(modified_I);
					function.Action("PlaySound(Pocket)", true);
					function.Action("DisableIcon(PickUp, " + modified_I + ")", true);
					//function.Action("EnableIcon(Place, Hand, " + modified_I + ", Place, true)", true);

					function.Action("EnableIcon(PlaceInChair, Hand, CurrentDiningRoom." + currentChair + "Chair, Place an item, false)", true);
				}

				else if (modified_I == "CheckNote") {
					modified_I = function.splitInput(i, 0, true);
					//function.Action("WalkTo(Arlan, " + modified_I + ")", true);
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
					//function.Action("WalkTo(Arlan, CurrentDiningRoom.Fireplace)", true);
					if (hasBluePotion) {
						function.Action("SetNarration(The hidden compartment is empty. You think you should check out that potion.)", true);
						function.Action("ShowNarration()", true);
					}
					else if (fireDoused) {
						function.Action("SetNarration(You reach back and retrieve a Potion of Power from a hidden compartment in the fireplace.)", true);
						function.Action("ShowNarration()", true);
						function.Action("PlaySound(Pocket)", true);
						playerInv.push_back("PotionOfPower");
						hasBluePotion = true;
					}
					else {
						bool hasCup = false;
						for (string item : playerInv) {
							if (item == "DiningCup") hasCup = true;
						}
						if (hasCup) {
							function.Action("SetNarration(You pour some water out of the servants cup and onto the flames to cool them off a bit.)", true);
							function.Action("DisableEffect(CurrentDiningRoom.Fireplace)", true);
							function.Action("StopSound(Fireplace, CurrentDiningRoom.Fireplace)", true);
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
					function.Action("SetNarration(You take a sip of the potion. Sudden images of a mysterious book adorned with a skull flash before your eyes. You feel stronger as the book calls out to you. You get the feeling should save the rest of the potion.)", true);
					function.Action("ShowNarration()", true);
					function.Action("DisableIcon(Drink, PotionOfPower)", true);
					function.Action("EnableIcon(Inspect, Potion, PotionOfPower, Inspect the Potion, true)", true);
					drankBluePotion = true;

					function.Action("FadeOut()", true);
					function.Action("SetPosition(Arlan, LeftHallway)", true);
					function.Action("Pocket(Arlan, PotionOfPower)", true);
					function.Action("FadeIn()", true);
					currentLocation = "LeftHallway";
				}
			}

			//LeftHallway
			if (i == "input Open CurrentDiningRoom.Door") {
				if (hasBluePotion && !drankBluePotion) {
					function.Action("SetNarration(You feel like you should probably check out that potion before you leave.)", true);
					function.Action("ShowNarration()", true);
				}
				else {
					function.Transition("Arlan", "CurrentDiningRoom.Door", "LeftHallway.BackDoor");
					currentLocation = "LeftHallway";
				}
			}

			if (i == "input Open CurrentDiningRoom.BackDoor") {
				function.Action("SetNarration(You can hear the Chef rummaging around behind the door. He seems to have locked it behind him.)", true);
				function.Action("ShowNarration()", true);
			}

			// disable Place icon if player closes list before placing puzzle item
			if (i == "input Close List") {

				if (isPlacingItem) {
					for (string item : playerInv) {
						if (item.substr(0, 6) == "Dining") {
							function.Action("DisableIcon(Place, " + item + ")", true);
						}
					}
					isPlacingItem = false;
				}
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
	else if (ArchieFlashback) {
		while (currentLocation == "CurrentDiningRoom") {
			string i;
			getline(cin, i);

			//Gets the first word that isn't "input"
			modified_I = function.splitInput(i, 6, false);

			bool inputWasCommon = function.checkCommonKeywords(i, modified_I, "Arlan", playerInv);

			if (!inputWasCommon) {
				if (modified_I == "Talk_Chef") {
					function.SetupDialog("Arlan", "Chef", true);
					if (!hasLegofTwo && givenRiddle) {
						function.SetupDialogText("I am bit busy at the moment. Do you need anything?", "Question1", "Do you have any food you can spare?", "end", "Nope");
					}
					else {
						if (!givenRiddle) {
							function.SetupDialogText("I am bit busy at the moment. I do not wish to be disturbed.", "end", "Okay");
						}
						else {
							function.SetupDialogText("I gave you food. Now leave me to my duties", "end", "Okay");
						}
					}
				}
				else if (modified_I == "Selected") {
					modified_I = function.splitInput(i, 0, true);
					if (modified_I == "Question1") {
						function.SetupDialogText("Uh... sure. I have some spare meat if that is what you want.", "Question2", "Any legs?", "Question3", "Any leg of two?");
					}
					else if (modified_I == "Question2") {
						function.SetupDialogText("I do have some chicken legs I can spare if thats what you mean...Here.", "Thanks", "Thanks!");

					}
					else if (modified_I == "Question3") {
						function.SetupDialogText("Leg of what? ", "Answer", "It was part of riddle.");
					}
					else if (modified_I == "Answer") {
						function.SetupDialogText("Don't throw me riddles. Just tell me what you want.", "Question2", "Do you have meat of a creature that walks on two legs");
					}
					else if (modified_I == "Thanks") {
						function.Action("HideDialog()", true);
						function.Action("SetNarration(The Chef gives you a chicken leg)", true);
						function.Action("ShowNarration()", true);
						hasLegofTwo = true;
						playerInv.push_back("Leg of Two");
					}
				}
			}

			//LeftHallway
			if (i == "input arrived Arlan position CurrentDiningRoom.Door") {
				function.Transition("Arlan", "CurrentDiningRoom.Door", "LeftHallway.Stairs");
				currentLocation = "LeftHallway";
			}
		}
	}
}

void Story::runCurrentCourtyard() {
	function.MusicHandler("Town_Day", currentLocation, musicPlaying);
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

		if (i == "input Exit Courtyard CurrentCourtyard.Gate") {
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
			else {
				function.Action("SetNarration(You do not possess the strength to proceed.)", true);
				function.Action("ShowNarration()", true);
			}
		}

		else if (i == "input Search Target CurrentCourtyard.Target") {
			function.WalkToPlace("Arlan", "CurrentCourtyard.Target");
			function.Action("SetNarration(There is a hammer hidden behind the target! You take it.)", true);
			function.Action("ShowNarration()", true);
			playerInv.push_back("PrisonerHammer");
			function.Action("DisableIcon(Search Target, CurrentCourtyard.Target)", true);
			hasThirdPrisItem = true;
		}
	}
}

void Story::runCurrentCastleBedroom() {
	function.MusicHandler("LivelyMusic", currentLocation, musicPlaying);
	string currentPosition = "";
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
			function.Action("DisableInput()", true);
			function.Action("OpenFurniture(Arlan, CurrentCastleBedroom.Chest)", true);
			function.Action("SetNarration(You found the note the Guard was looking for! You take it)", true);
			function.Action("ShowNarration()", true);
			this_thread::sleep_for(chrono::milliseconds(2500));
			playerInv.push_back("CastleBedroomCrime");
			function.Action("DisableEffect(CurrentCastleBedroom.Chest)", true);
			function.Action("DisableIcon(Search_Chest, CurrentCastleBedroom.Chest)", true);
			function.Action("HideNarration()", true);
			function.Action("EnableInput()", true);
			hasBedroomAnswer = true;
		}

		if (modified_I == "Search_Bedroom_Closet") {
			function.Action("SetNarration(There are some items hidden in the closet! You take them)", true);
			function.Action("ShowNarration()", true);
			playerInv.push_back("CastleBedroomJewelKey");
			playerInv.push_back("CastleBedroomBag");
			playerInv.push_back("CastleBedroomLock");
			playerInv.push_back("CastleBedroomInkAndQuill");
			playerInv.push_back("CastleBedroomSkull");
			playerInv.push_back("CastleBedroomGoldCup");
			hasSearchedBedroomCloset = true;
			function.Action("DisableIcon(Search_Bedroom_Closet, CurrentCastleBedroom.Closet)", true);
		}

		if (modified_I == "Swap" && hasSearchedBedroomCloset && hasReadBedroomNote) {

			modified_I = function.splitInput(i, 11, false);

			if (modified_I == "Spot1" && !BedroomSpot1Full) {
				currentPosition = "CurrentCastleBedroom.Table.FrontLeft";
			}
			else if (modified_I == "Spot2" && !BedroomSpot2Full) {
				currentPosition = "CurrentCastleBedroom.Table.FrontRight";
			}
			else if (modified_I == "Spot3" && !BedroomSpot3Full) {
				currentPosition = "CurrentCastleBedroom.Table.Right";
			}
			else if (modified_I == "Spot4" && !BedroomSpot4Full) {
				currentPosition = "CurrentCastleBedroom.Table.BackRight";
			}
			else if (modified_I == "Spot5" && !BedroomSpot5Full) {
				currentPosition = "CurrentCastleBedroom.Table.BackLeft";
			}
			else if (modified_I == "Spot6" && !BedroomSpot6Full) {
				currentPosition = "CurrentCastleBedroom.Table.Left";
			}

			if (currentPosition != "") {
				function.SetupDialog("Arlan", "Arlan", false);
				function.SetupDialogText("Which item would you like to put in this spot?", "CastleBedroomLock", "Lock", "CastleBedroomBag", "Bag", "CastleBedroomSkull", "Skull", "CastleBedroomJewelKey", "Jewel Key", "CastleBedroomInkAndQuill", "Ink and Quill", "CastleBedroomGoldCup", "Gold Cup");
			}

		}

		if (modified_I == "Swap" && !(hasSearchedBedroomCloset && hasReadBedroomNote)) {
			function.Action("SetNarration(You feel you should probably fully inspect the room before you go about messing with this)", true);
			function.Action("ShowNarration()", true);
		}

		if (modified_I == "Selected") {
			modified_I = function.splitInput(i, 0, true);

			if (modified_I == "CastleBedroomLock" || modified_I == "CastleBedroomBag" || modified_I == "CastleBedroomSkull" || modified_I == "CastleBedroomJewelKey" || modified_I == "CastleBedroomGoldCup" || modified_I == "CastleBedroomInkAndQuill") {
				function.Action("ClearDialog()", true);
				function.Action("HideDialog()", true);

				if ((modified_I == "CastleBedroomLock" && BedroomLockUsed == false) || (modified_I == "CastleBedroomBag" && BedroomBagUsed == false) || (modified_I == "CastleBedroomSkull" && BedroomSkullUsed == false) || (modified_I == "CastleBedroomJewelKey" && BedroomJewelKeyUsed == false) || (modified_I == "CastleBedroomGoldCup" && BedroomGoldCupUsed == false) || (modified_I == "CastleBedroomInkAndQuill" && BedroomInkAndQuillUsed == false)) {
					function.Action("Put(Arlan, " + modified_I + ", " + currentPosition + ")", true);

					if (modified_I == "CastleBedroomLock") {
						BedroomLockUsed = true;
					}
					else if (modified_I == "CastleBedroomBag") {
						BedroomBagUsed = true;
					}
					else if (modified_I == "CastleBedroomSkull") {
						BedroomSkullUsed = true;
					}
					else if (modified_I == "CastleBedroomJewelKey") {
						BedroomJewelKeyUsed = true;
					}
					else if (modified_I == "CastleBedroomGoldCup") {
						BedroomGoldCupUsed = true;
					}
					else if (modified_I == "CastleBedroomInkAndQuill") {
						BedroomInkAndQuillUsed = true;
					}


					if (currentPosition == "CurrentCastleBedroom.Table.FrontLeft") {
						BedroomSpot1Full = true;

						if (modified_I == "CastleBedroomLock") {
							BedroomSpot1Correct = true;
						}
					}
					else if (currentPosition == "CurrentCastleBedroom.Table.FrontRight") {
						BedroomSpot2Full = true;

						if (modified_I == "CastleBedroomBag") {
							BedroomSpot2Correct = true;
						}
					}
					else if (currentPosition == "CurrentCastleBedroom.Table.Left") {
						BedroomSpot6Full = true;

						if (modified_I == "CastleBedroomSkull") {
							BedroomSpot6Correct = true;
						}
					}
					else if (currentPosition == "CurrentCastleBedroom.Table.BackRight") {
						BedroomSpot4Full = true;

						if (modified_I == "CastleBedroomJewelKey") {
							BedroomSpot4Correct = true;
						}
					}
					else if (currentPosition == "CurrentCastleBedroom.Table.BackLeft") {
						BedroomSpot5Full = true;

						if (modified_I == "CastleBedroomGoldCup") {
							BedroomSpot5Correct = true;
						}
					}
					else if (currentPosition == "CurrentCastleBedroom.Table.Right") {
						BedroomSpot3Full = true;

						if (modified_I == "CastleBedroomInkAndQuill") {
							BedroomSpot3Correct = true;
						}
					}

					function.RemoveItem(modified_I, playerInv);
					currentPosition = "";
					//Put(Tom, "Coin", "DiningRoom.Table")
				}
			}

		}

		if (BedroomSpot1Full && BedroomSpot2Full && BedroomSpot3Full && BedroomSpot4Full && BedroomSpot5Full && BedroomSpot6Full && !BedroomPuzzleFin) {
			if (BedroomSpot1Correct && BedroomSpot2Correct && BedroomSpot3Correct && BedroomSpot4Correct && BedroomSpot5Correct && BedroomSpot6Correct) {

				function.Action("DisableInput()", true);
				function.Action("EnableIcon(Search_Chest, magnifyingglass, CurrentCastleBedroom.Chest, Search Chest, true)", true);
				function.Action("SetNarration(You hear something unlock...)", true);
				function.Action("ShowNarration()", true);
				function.Action("PlaySound(Unlock, CurrentCastleBedroom.Chest, false)", false);
				this_thread::sleep_for(chrono::milliseconds(2500));
				function.Action("EnableEffect(CurrentCastleBedroom.Chest, Diamond)", true);
				function.Action("HideNarration()", true);
				function.Action("EnableInput()", true);

				BedroomPuzzleFin = true;
			}
			else {
				BedroomSpot1Correct = false;
				BedroomSpot2Correct = false;
				BedroomSpot3Correct = false;
				BedroomSpot4Correct = false;
				BedroomSpot5Correct = false;
				BedroomSpot6Correct = false;

				BedroomSpot1Full = false;
				BedroomSpot2Full = false;
				BedroomSpot3Full = false;
				BedroomSpot4Full = false;
				BedroomSpot5Full = false;
				BedroomSpot6Full = false;

				BedroomGoldCupUsed = false;
				BedroomBagUsed = false;
				BedroomJewelKeyUsed = false;
				BedroomSkullUsed = false;
				BedroomLockUsed = false;
				BedroomInkAndQuillUsed = false;

				function.Action("Take(Arlan, CastleBedroomLock)", true);
				playerInv.push_back("CastleBedroomLock");

				function.Action("Take(Arlan, CastleBedroomBag)", true);
				playerInv.push_back("CastleBedroomBag");

				function.Action("Take(Arlan, CastleBedroomSkull)", true);
				playerInv.push_back("CastleBedroomSkull");

				function.Action("Take(Arlan, CastleBedroomJewelKey)", true);
				playerInv.push_back("CastleBedroomJewelKey");

				function.Action("Take(Arlan, CastleBedroomGoldCup)", true);
				playerInv.push_back("CastleBedroomGoldCup");

				function.Action("Take(Arlan, CastleBedroomInkAndQuill)", true);
				playerInv.push_back("CastleBedroomInkAndQuill");
				function.Action("Pocket(Arlan, CastleBedroomInkAndQuill)", true);
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
	function.MusicHandler("Danger3", currentLocation, musicPlaying);
	if (currentLocation == "BlueCamp") {
		while (currentLocation == "BlueCamp") {
			string i;
			getline(cin, i);

			//Gets the first word that isn't "input"
			modified_I = function.splitInput(i, 6, false);

			bool inputWasCommon = function.checkCommonKeywords(i, modified_I, "Arlan", playerInv);

			if (!inputWasCommon) {

			}

			//CurrentCastleBedroom
			if (i == "input arrived Arlan position BlueCamp.Exit") {
				function.Transition("Arlan", "BlueCamp.Exit", "CurrentCourtyard.Gate");
				currentLocation = "CurrentCourtyard";
			}

			if (i == "input OpenChest BlueCamp.Chest") {
				// walk to and interact with chest
				//function.Action("OpenFurniture(Arlan, BlueCamp.Chest)", true); (camelot bug)
				function.SetupDialog("Arlan", "null", false);
				function.SetupDialogText("A strange book adorned with a skull lies in the chest. You recognize it as the powerful artifact from your visions and the tome described in the book the sailor gave you. Will you take it?", "takeTome", "*Take the artifact.*", "leaveTome", "*Leave it.*");
				//function.Action("ShowDialog()", true);
			}

			else if (i == "input Selected takeTome") {
				function.Action("Take(Arlan, AncientTome, BlueCamp.Chest)", true);
				function.SetupDialogText("You take the tome into your hands. You feel a surge of incredible energy flowing through you. The power suddenly takes hold of your body and you begin to lose control.", "giveIn", "*GIVE IN.*");
			}

			else if (i == "input Selected giveIn") {
				function.Action("HideDialog()", true);
				function.Action("ClearDialog()", true);
				function.Action("DisableInput()", true);
				//function.Action("WalkTo(Arlan, BlueCamp.LeftLog)", true);
				function.Action("Face(Arlan, BlueCamp.Log)", true);
				function.Action("Cast(Arlan)", true);
				function.Action("SetPosition(Archie, BlueCamp)", true);
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
				function.Action("WalkTo(Archie, BlueCamp.Exit)", true);
				function.Action("SetPosition(Archie)", true);
				function.Action("SetPosition(Mathias, BlueCamp.Exit)", true);
				function.Action("FadeIn()", false);
				//function.Action("WalkTo(Mathias, BlueCamp.Chest)", true);
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
				function.Action("WalkTo(Mathias, BlueCamp.Exit)", false);
				function.Action("WalkTo(Arlan, BlueCamp.Exit)", false); // does not need to be WalkToPlace since input is disabled here
				function.Action("FadeOut()", true);
				currentLocation = "FinalRuins";
			}

			else if (i == "input Selected leaveTome") {
				function.Action("HideDialog()", true);
				function.Action("ClearDialog()", true);
				function.Action("CloseFurniture(Arlan, BlueCamp.Chest)", true);
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
	if (currentLocation == "RedCamp") {

		bool ActionSequence = true;

		//		function.Action("WalkTo(Arlan, ArchieR, true)", true);
		//		function.SetupDialog("Arlan", "ArchieR", true);
		//		function.SetupDialogText("Ah you found me and brought along company I see. Guess it it time to deal with you once and for all Mathias", "Battle", "Don't fight!");

		while (currentLocation == "RedCamp") {

			string i;
			getline(cin, i);

			//Gets the first word that isn't "input"
			modified_I = function.splitInput(i, 6, false);

			bool inputWasCommon = function.checkCommonKeywords(i, modified_I, "Arlan", playerInv);

			if (!inputWasCommon) {
				if (ActionSequence == true) {

					ActionSequence = false;

					function.Action("DisableInput()", true);
					//function.Action("PlaySound(Danger1, RedCamp, true)", true);
					function.Action("WalkTo(Arlan, Archie, true)", true);

					function.SetupDialog("Arlan", "Archie", true);
					function.SetupDialogText("Ah I see you finally found me. Quickly let me explain what we'll have to do-", "Entrance", "*CLANK*");

					// Then have dialog setting up scene more
	//				if (i == "input Selected Battle") {
	//				}
				}
				else if (modified_I == "Selected") {

					modified_I = function.splitInput(i, 0, true);

					if (modified_I == "Entrance") {
						function.SetupDialogText("Oh no he's here already. Guess we have no choice but to fight. Wish me luck.", "Battle", "No wait!");
					}

					else if (modified_I == "ReadBook") {
						function.SetupDialogText("Wait a minute who else is here?", "Continue", "**Continue Reading**");
					}

					else if (modified_I == "Continue") {
						function.SetupDialogText("No! Don't say that! You don't know what you're doing!", "FinishSpell", "**Finish Spell**");
					}

					else if (modified_I == "Battle") {
						function.Action("ClearDialog()", true);
						function.Action("HideDialog()", true);
						function.Action("SetPosition(Mathias, RedCamp.Exit)", true);
						function.Action("SetCameraFocus(Mathias)", true);

						function.Action("DisableInput()", true);
						function.Action("Draw(Mathias, Mathias_Sword)", true);
						function.Action("WalkTo(Mathias, Archie)", false);
						function.Action("WalkTo(Archie, Mathias)", true);
						function.Action("Face(Arlan, Mathias)", true);
						function.Action("Attack(Mathias, Archie, true)", true);
						function.Action("Die(Archie)", true);
						function.Action("Sheathe(Mathias, Mathias_Sword)", true);
						function.Action("Draw(Mathias, Artifact)", true);
						function.Action("EnableInput()", true);

						function.SetupDialog("Arlan", "Mathias", false);
						function.SetupDialogText("Finally! Now that I don't have to worry about Archie anymore I can finally harness the full power of this artifact.", "ReadBook", "**I can't let that happen! Read Translated Book**");
					}

					else if (modified_I == "FinishSpell") {
						function.Action("ClearDialog()", true);
						function.Action("HideDialog()", true);
						function.Action("SetCameraFocus(Artifact)", true);
						function.Action("SetCameraMode(focus)", true);
						function.Action("CreateEffect(Artifact, Spiralflame)", false);
						this_thread::sleep_for(chrono::milliseconds(2500));

						function.SetupDialog("Arlan", "Mathias", false);
						function.SetupDialogText("Oh no this isn't good... we're all doomed", "Drink", "**Drink Potion of Invincibility**");
					}

					else if (modified_I == "Drink") {
						function.Action("DisableEffect(Artifact)", true);
						function.Action("ClearDialog()", true);
						function.Action("HideDialog()", true);

						function.Action("SetCameraFocus(Arlan)", true);
						function.Action("SetCameraMode(focus)", true);
						function.Action("Unpocket(Arlan, TempPotion)", true);
						function.Action("Drink(Arlan)", true);
						this_thread::sleep_for(chrono::milliseconds(300));

						function.Action("SetNarration(This tastes strangely like water... You've been tricked!)", true);
						function.Action("ShowNarration()", true);
						this_thread::sleep_for(chrono::milliseconds(2000));
						function.Action("HideNarration()", true);

						function.Action("SetCameraFocus(Mathias)", true);
						function.Action("SetCameraMode(focus)", true);
						this_thread::sleep_for(chrono::milliseconds(1000));
						function.Action("CreateEffect(Artifact, Explosion)", false);
						function.Action("PlaySound(Fireball, Artifact, false)", true);
						this_thread::sleep_for(chrono::milliseconds(1000));

						function.Action("SetCameraFocus(Mathias)", true);
						function.Action("SetCameraMode(track)", true);
						function.Action("CreateEffect(Mathias, Death)", true);
						function.Action("Die(Mathias)", true);
						function.Action("SetCameraFocus(Arlan)", true);
						function.Action("SetCameraMode(track)", true);
						function.Action("CreateEffect(Arlan, Death)", true);
						function.Action("Die(Arlan)", true);
						function.Action("FadeOut()", true);
						function.Action("StopSound(RedCamp)", true);
					}

				}
			}

		}
	}
	if (currentLocation == "PurpleCamp") {
		function.Action("SetPosition(Archie, PurpleCamp.Log)", true);
		function.Action("Face(Archie, PurpleCamp.Horse)", true);
		function.Action("HideFurniture(PurpleCamp.Log)", true);
		function.Action("Face(Archie, Arlan)", true);
		function.SetupDialog("Arlan", "Archie", true);
		function.Action("Face(Arlan, Archie)", true);
		function.SetupDialogText("Who are you? What are you doing here? Nevermind. There is no time. You must hide and here take this sword.", "hide", "**Take sword and hide by the barrel**");

		while (currentLocation == "PurpleCamp") {
			string i;
			getline(cin, i);

			//Gets the first word that isn't "input"
			modified_I = function.splitInput(i, 6, false);

			bool inputWasCommon = function.checkCommonKeywords(i, modified_I, "Arlan", playerInv);

			if (!inputWasCommon) {
				if (modified_I == "Selected") {
					modified_I = function.splitInput(i, 0, true);

					if (modified_I == "hide") {
						function.Action("HideDialog()", true);
						function.Action("Draw(Arlan, SpareSword)", true);
						function.WalkToPlace("Arlan", "PurpleCamp.Barrel");
						this_thread::sleep_for(chrono::milliseconds(1000));
						function.Action("Face(Arlan, Archie)", true);
						this_thread::sleep_for(chrono::milliseconds(500));
						function.Action("SetPosition(Mathias, PurpleCamp.Horse)", true);
						function.Action("Draw(Mathias, SpareSword2)", true);
						function.Action("Face(Archie, Mathias)", true);
						function.SetupDialog("Mathias", "Archie", true);
						function.SetupDialogText("Mathias! This artifact has corrupted you. You need to be stopped.\\n**You feel the book call for you to wait.**", "Wait", "**Wait to strike**", "Confront", "**Confront Mathias**");
					}
					else if (modified_I == "Wait") {
						function.Action("HideDialog()", true);
						function.Action("Attack(Mathias, Archie, true)", true);
						function.Action("Kneel(Archie)", true);
						function.SetupDialog("Arlan", "Mathias", false);
						function.SetupDialogText("**You feel the book telling you to strike now while Mathias is distracted**", "Strike1", "**Strike down Mathias**");
					}
					else if (modified_I == "Confront") {
						function.Action("HideDialog()", true);
						function.Action("DisableInput()", true);
						function.Action("WalkToSpot(Arlan, 5999, 0, 4)", true);
						function.Action("Face(Mathias, Arlan)", true);
						function.SetupDialog("Arlan", "Mathias", false);
						function.Action("EnableInput()", true);
						function.SetupDialogText("Who's this? No matter both of you will die here.", "Strike2", "**Strike down Mathias**");
					}
					else if (modified_I == "Strike1") {
						function.Action("HideDialog()", true);
						function.Action("Face(Mathias, Arlan)", true);
						function.WalkToPlace("Arlan", "Mathias");
						function.Action("Attack(Arlan, Mathias, true)", true);
						function.Action("Die(Mathias)", true);
						function.SetupDialog("Arlan", "Archie", true);
						function.SetupDialogText("Thank you for your help stranger. I cannot offer you anything in return but maybe a warrior like you would have use for Mathias' armor. Now I must heal my wounds", "Potion", "I have a potion of healing you can use. **Give Potion of Healing**", "Armor2", "*Take Mathias' Armor**");
					}
					else if (modified_I == "Strike2") {
						function.Action("HideDialog()", true);
						function.Action("Attack(Mathias, Arlan, true)", true);
						function.Action("Cast(Archie, Mathias)", true);
						function.Action("Attack(Arlan, Mathias, true)", true);
						function.Action("Die(Mathias)", true);
						function.SetupDialog("Arlan", "Archie", false);
						function.SetupDialogText("Thank you for your help stranger. I cannot offer you anything in return but maybe a warrior like you would have use for Mathias' armor.", "Armor1", "**Drink Potion of Healing and take Mathias' armor**");
					}
					else if (modified_I == "Armor1") {
						function.Action("HideDialog()", true);
						function.Action("DisableInput()", true);
						function.Action("Unpocket(Arlan, Potion of Healing)", true);
						function.Action("SetCameraMode(Focus)", true);
						function.Action("Drink(Arlan)", true);
						function.Action("Pocket(Arlan, Potion of Healing)", true);
						this_thread::sleep_for(chrono::milliseconds(500));
						function.Action("SetCameraMode(Follow)", true);
						function.Action("FadeOut()", true);
						function.Action("SetClothing(Arlan, HeavyArmour)", true);
						function.Action("SetClothing(Mathias, LightArmour)", true);
						function.Action("SetCameraMode(Focus)", true);
						function.Action("FadeIn()", true);
						this_thread::sleep_for(chrono::milliseconds(2000));
						function.Action("FadeOut()", true);
					}
					else if (modified_I == "Armor2") {
						function.Action("HideDialog()", true);
						function.Action("DisableInput()", true);
						function.Action("FadeOut()", true);
						function.Action("SetClothing(Arlan, HeavyArmour)", true);
						function.Action("SetClothing(Mathias, LightArmour)", true);
						function.Action("SetCameraMode(Focus)", true);
						function.Action("Face(Arlan, PurpleCamp.Barrel)", true);
						function.Action("FadeIn()", true);
						this_thread::sleep_for(chrono::milliseconds(2000));
						function.Action("FadeOut()", true);
					}
					else if (modified_I == "Potion") {
						function.Action("HideDialog()", true);
						function.Action("Face(Arlan, Archie)", true);
						function.Action("Give(Arlan, Potion of Healing, Archie)", true);
						function.Action("ShowDialog()", true);
						function.SetupDialogText("Thank you kind stranger", "Armor2", "**Take Mathias' Armor**");
					}
				}
			}
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
				//function.Action("WalkTo(Mathias, Archie)", true);
				function.WalkToPlace("Mathias", "Archie");
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
				function.MusicHandler("Serenity", currentLocation, musicPlaying);
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
				function.Action("DisableInput()", true);
				function.Action("SetPosition(Potion Of Cleansing)", true);
				function.Action("SetPosition(MysteriousSkull)", true);
				function.Action("WalkTo(Mathias, GreenCamp.Exit)", false);
				function.Action("WalkTo(Archie, GreenCamp.Exit)", true);
				function.Action("SetPosition(Mathias)", true);
				function.Action("SetPosition(Archie)", true);
				function.Action("FadeOut()", true);
				this_thread::sleep_for(chrono::milliseconds(2000));
			}
		}
	}
}

void Story::runFinalRuins() {
	function.MusicHandler("Danger3", currentLocation, musicPlaying);
	function.Action("SetPosition(Archie, FinalRuins.Altar)", true);
	//function.Action("Sit(Archie, FinalRuins.Throne)", true);
	function.Action("Enter(Mathias, FinalRuins.Exit, false)", true);
	function.Action("WalkTo(Mathias, Archie)", false);
	function.Action("Enter(Arlan, FinalRuins.Exit, true)", true);
	function.Action("WalkTo(Arlan, FinalRuins.Plant)", false); // can't use WalkToPlace here because WaitFor needs to be used differently & input is already disabled
	function.WaitFor("succeeded WalkTo(Mathias, Archie)");
	function.Action("Face(Mathias, Archie)", false);
	function.WaitFor("succeeded WalkTo(Arlan, FinalRuins.Plant)");
	function.Action("Face(Arlan, Archie)", false);
	function.Action("Face(Archie, Mathias)", true);
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
			function.Action("Attack(Mathias, Archie, false)", true); //camelot bug
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
			function.Action("WalkTo(Archie, Arlan)", false);
			function.Action("Attack(Arlan, Archie, true)", true);
			function.Action("Die(Archie)", true);
			function.Action("Sheathe(Arlan, MathiasSword)", true);
			function.Action("WalkTo(Arlan, Mathias)", false);
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
			function.Action("ShowDialog()", true);
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