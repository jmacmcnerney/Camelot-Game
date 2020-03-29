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
bool hasGreenPotion = false;
bool hasGreenBook = false;
bool hasLibraryGoldCup = false;
bool hasLibraryApple = false;
bool hasLibraryGreenKey = false;
bool libraryApplePositionCorrect = false;
bool libraryGoldCupPositionCorrect = false;
bool libraryGreenKeyPositionCorrect = false;
//bool libraryLeftOccupied = false;
//bool libraryCenterOccupied = true;
//bool libraryRightOccupied = true;
bool libraryPuzzleSolved = false;
bool hasBluePotion = false;
bool hasBlueBook = false;
bool hasRedPotion = false;
bool hasRedBook = false;
bool hasPurplePotion = false;
bool hasPurpleBook = false;

Chapter2::Chapter2() {
	runSetup();
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

	//items

	//icons

	return true;
}

bool Chapter2::setupPort(string name) {
	CurrentPort = Port(name);

	//character setup

	//items

	//icons

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

bool Chapter2::setupDungeon(string name) {
	CurrentPrison = Dungeon(name);

	//character setup

	//items

	//icons

	return true;
}

bool Chapter2::setupLeftHallway(string name) {
	LeftHallway = Hallway(name);

	//character setup

	//items

	//icons

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

	//items

	//icons

	return true;
}

bool Chapter2::setupStorage(string name) {
	CurrentStorage = Storage(name);

	//character setup

	//items

	//icons

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
				int test = 0;
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
			function.Transition("Arlan", "CurrenTown.NorthEnd", "CurrentCourtyard.Exit");
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

		if (i == "input arrived Arlan position ForestPath2.WestEnd") {
			function.Transition("Arlan", "ForestPath2.WestEnd", "CurrentCastleCrossroads.EastEnd");
			currentLocation = "CurrentCastleCrossroads";
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
			function.Transition("Arlan", "CurrentGreatHall.BasementDoor", "CurrentStorage.Door");
			currentLocation = "CurrentStorage";
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

		}

		//CurrentCastleCrossroads
		if (i == "input arrived Arlan position CurrentPort.Exit") {
			function.Transition("Arlan", "CurrentPort.Exit", "CurrentCastleCrossroads.WestEnd");
			currentLocation = "CurrentCastleCrossroads";
		}
	}
}

void Chapter2::runCurrentLibrary() {
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
			function.Transition("Arlan", "CurrentLibrary.Door", "RightHallway.Stairs");
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
				function.Action("SetNarration(Book Of Incantations Added To Inventory)", true);
				function.Action("ShowNarration()", true);
				//function.Action("DisableEffect(Book Of Incantations, Resurrection)", true);
				function.Action("SetPosition(Book Of Incantations)", true);
				playerInv.push_back("Book Of Incantations");
				hasGreenBook = true;
			}
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
				function.SetupDialogText("What would you like to do?", "placeLibraryItem", "Place Item.", "pickUpLibraryItem", "Take Item.");
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
			function.LibraryItem("place", "Library Apple", "Left", hasLibraryApple, playerInv);
			libraryApplePositionCorrect = true;
			hasLibraryApple = false;
		}

		else if (i == "input Selected placeLibraryAppleCenter") {
			function.LibraryItem("place", "Library Apple", "Center", hasLibraryApple, playerInv);
			libraryApplePositionCorrect = false;
			hasLibraryApple = false;
		}

		else if (i == "input Selected placeLibraryAppleRight") {
			function.LibraryItem("place", "Library Apple", "Right", hasLibraryApple, playerInv);
			libraryApplePositionCorrect = false;
			hasLibraryApple = false;
		}

		else if (i == "input Selected placeLibraryGoldCupLeft") {
			function.LibraryItem("place", "Library GoldCup", "Left", hasLibraryGoldCup, playerInv);
			libraryGoldCupPositionCorrect = false;
			hasLibraryGoldCup = false;
		}

		else if (i == "input Selected placeLibraryGoldCupCenter") {
			function.LibraryItem("place", "Library GoldCup", "Center", hasLibraryGoldCup, playerInv);
			libraryGoldCupPositionCorrect = true;
			hasLibraryGoldCup = false;
		}

		else if (i == "input Selected placeLibraryGoldCupRight") {
			function.LibraryItem("place", "Library GoldCup", "Right", hasLibraryGoldCup, playerInv);
			libraryGoldCupPositionCorrect = false;
			hasLibraryGoldCup = false;
		}

		else if (i == "input Selected placeLibraryGreenKeyLeft") {
			function.LibraryItem("place", "Library GreenKey", "Left", hasLibraryGreenKey, playerInv);
			libraryGreenKeyPositionCorrect = false;
			hasLibraryGreenKey = false;
		}

		else if (i == "input Selected placeLibraryGreenKeyCenter") {
			function.LibraryItem("place", "Library GreenKey", "Center", hasLibraryGreenKey, playerInv);
			libraryGreenKeyPositionCorrect = false;
			hasLibraryGreenKey = false;
		}

		else if (i == "input Selected placeLibraryGreenKeyRight") {
			function.LibraryItem("place", "Library GreenKey", "Right", hasLibraryGreenKey, playerInv);
			libraryGreenKeyPositionCorrect = true;
			hasLibraryGreenKey = false;
		}

		else if (i == "input Selected pickUpLibraryItem") {
			function.SetupDialogText("Which item would you like to take?", "pickUpLibraryApple", "Apple", "pickUpLibraryGreenKey", "Green Key", "pickUpLibraryGoldCup", "Gold Cup");
		}

		else if (i == "input Selected pickUpLibraryApple") {
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

void Chapter2::runCurrentStorage() {
	while (currentLocation == "CurrentStorage") {
		string i;
		getline(cin, i);

		//Gets the first word that isn't "input"
		modified_I = function.splitInput(i, 6, false);

		bool inputWasCommon = function.checkCommonKeywords(i, modified_I, "Arlan", playerInv);

		if (!inputWasCommon) {

		}

		//CurrentGreatHall
		if (i == "input arrived Arlan position CurrentStorage.Door") {
			function.Transition("Arlan", "CurrentStorage.Door", "CurrentGreatHall.BasementDoor");
			currentLocation = "CurrentGreatHall";
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

		}

		//LeftHallway
		if (i == "input arrived Arlan position CurrentPrison.Door") {
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
			function.Transition("Arlan", "RightHallway.BackDoor", "CastleBedroom.Door");
			currentLocation = "CurrentCastleBedroom";
		}
		//CurrentLibrary
		else if (i == "input arrived Arlan position RightHallway.Stairs") {
			function.Transition("Arlan", "RightHallway.Stairs", "CurrentLibrary.Door");
			currentLocation = "CurrentLibrary";
		}
	}
}

void Chapter2::runCurrentDiningRoom() {
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

		//CurrentCastleBedroom
		if (i == "input arrived Arlan position CurrentCastleBedroom.Door") {
			function.Transition("Arlan", "CurrentCastleBedroom.Door", "RightHallway.BackDoor");
			currentLocation = "RightHallway";
		}
	}
}