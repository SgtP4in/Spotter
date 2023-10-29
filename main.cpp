/*
* Spotter, the unofficial Pheonix Command Companion Calculator
* Version 0.1
* Supported Features:
* > Odds of Hitting Tables, 4A-4G
*/

/*
* Current Issues:
* > Needs to be converted from a Visual Studio 2019 Solution project structure to CMake
* > The User interface is VERY tightly coupled to windows, and should be made platform agnostic
* > The user interface class was made with many shortcuts, and needs to be adjusted
* > QoL features that need to be added:
*	> Ability to return to the main menue at any time
*	> The ability to "back up" to prior filters without starting over the calculation
* > The following Features should be added next:
*	> Automatic Weapon Odds of Hitting Support
*	> Explosive Weapon Odds of Hitting Support
*	> Character Sheet Generator
*	> Basic Injury Table Support
*/

#include "User_Interface.h"
#include <stdlib.h>

#include "OOH_Factory.h"

const double VERSION = 0.1;

//Activity Factory Objects
OOH_Factory oddsOfHittingActivity;

int main() {
	//Initialize user interface
	User_Interface x;

	//Display main menu and prompt user
	int answer;
	do {
		//Display Opening information
		x.PrintLine("Spotter, the unofficial Pheonix Command Companion Calculator");
		x.PrintLine("Version: " + std::to_string(VERSION));
		x.PrintHorzLine();

		//Display prompts
		x.PrintLine("MAIN MENU\n What would you like to do?");
		x.PrintLine("1) Perform a new Odds of Hitting Calculation, using tables 4A - 4G from the core rules");
		x.PrintLine("q) Quit Application");
		answer = NULL;
		answer = std::system("choice /c 1q /n");

		std::system("cls"); //clear the console

		switch (answer)
		{
		case 1:
			oddsOfHittingActivity.run();
			break;

		default:
			answer = 666;
			break;
		}

	} while (answer != 666);

}