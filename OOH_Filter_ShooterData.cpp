#include "OOH_Filter_ShooterData.h"

OOH_Data OOH_Filter_ShooterData::Filter_ShooterData(OOH_Data data) {
	OOH_Data returnVal = data;

	//Print title
	x.PrintLine("SHOOTER, WEAPON, and RANGE DATA");
	x.PrintHorzLine();

	//Prompt the user for the SAL, ATM, and BA
RETRY:
	try {
		//SAL
		x.PrintLine("\"The character's Skill Accuracy level (SAL) is now determined. This measures his\n skillwith weapons, and obviously has a significanteffect on how accurate his shots will be.\n The greater the SAL, the greater his expertise.It is found opposite the Gun Combat Skill\n l evel on Table 1C, and should be recorded on the Status Sheet.Note that there is a rapid\n increase in the SAL as a character moves through the low levels.This is because of the\n very rapid improvement in ability which comes from even a little training or practice.\n Skill Accuracy level found on Table 1C opposite the Gun Combat Skill l evel\n (Step 2)\"", 1);
		x.PrintLine(" ~Phoenix Command - Small Arms Combat System, Page 5");
		std::cout << std::endl;
		x.PrintLine("What is the Skill Accuracy Level (SAL) of the shooter?");
		std::cin >> returnVal.sal;
		std::cin.clear();
		x.PrintHorzLine();

		//ATM
		x.PrintLine("\"A wide-ranging list of weapons is found in the Weapon Data Tables located at the back\n of this book.The appropriate data for the weapon used by a character should be\n transferred from the Weapon Data Tables to the Status Sheet.For those just starting out, \n this is certainly not necessary during character generation.It is, however, a good idea to\n copy the numbers at some point.as the information will be used in combat.\"", 1);
		x.PrintLine(" ~Phoenix Command - Small Arms Combat System, Page 6");
		std::cout << std::endl;
		x.PrintLine("\"Aim Time Modifiers(Alm Time Mod): The combined measure of the weapon's accuracy\n and speed of aim.There are severalAim Time Modifiers, one foreach Aim Time listed\n inthe third column.How accurate a shot is obviously has a lot to do with how much time\n has been spent aiming.The Aim Time Modifiers measure this.As a character devotes\n more Actions to his Aim Time on a given shot, his accuracy improves.The greater the\n Aim Time Mod, the greater the accuracy.\n Each weapo n's listing contains Aim Time Mods for several Aim Times. These Aim\n Times typically range from 1 to 12 Actions.The Aim Time Mod to the right of each Aim\n Time measures the weapon's inherent accuracy and speed of aim.\n A close look at these numbers will show that small weapons, such as pistols, are\n more accurate for brief aim times, but do not improve much with long aim, while longer\n rifle - type weapons are the opposite.This is obviously because light, short pistols can\n be aimed quickly, but have short barrelsand lack real accuracy.Rifles, on the other\n hand, take longer to move around, but if aimed carefully can be extremely accurate.\n The Aim Time Mods are important factors in shot accuracy, of course, and affect the\n Odds of Hitting of every shot fired.\n These Aim Time Mods should be added to the character's Skill Accuracy level,\n which measures the shooter's accuracy, to determine the overallShot Accuracy(SA).\n Just add the Skill Accuracy level(SAL) to each of the weapon 's Aim Time Mods, and\n record the totals under Shot Accuracy on the Status Sheet.The Weapon Data section\n of Figure 1 shows both sets of data, the AimTime Mods from theWeapon Data Tables, \n and the Shot Accuracy values after the SAL has been added in.\"", 1);
		x.PrintLine(" ~Phoenix Command - Small Arms Combat System, Page 7");
		std::cout << std::endl;
		x.PrintLine("What is the Aim Time Modifier (ATM) of the shooter?");
		std::cin >> returnVal.atm;
		std::cin.clear();
		x.PrintHorzLine();

		//BA
		x.PrintLine("\"Ballistic Accuracy (BA): The measure of weapon/ammunition accuracy potential. The\n larger the BA, the greater this potential.This value is used in the Advanced Phoenix\n Command Combat Supplement.\"", 1);
		x.PrintLine(" ~Phoenix Command - Small Arms Combat System, Page 8");
		std::cout << std::endl;
		x.PrintLine("What is the Ballistic Accuracy (BA) of the weapon at the current range to target?");
		std::cin >> returnVal.ba;
		std::cin.clear();
		x.PrintHorzLine();

		//Range
		x.PrintLine("Please input the currnet range to target in hexes, where each hex is 2 yards in diameter.");
		std::cin >> returnVal.range;
		std::cin.clear();

			//Determine the Range ALM using Table 4A
		auto prev = TABLE_4A[0];
		if (prev.first == returnVal.range) {
			returnVal.rangeAlm = prev.second;
		}
		else {
			for (auto i : TABLE_4A) {
				if (i.first > returnVal.range) {
					returnVal.rangeAlm = prev.second;
					break;

				}
				else {
					prev = i;
				}

			}
		}
		
		x.PrintHorzLine();

	}
	catch (...) {
		x.PrintLine("ERROR Invalid Input!");
		std::cin.clear();
		goto RETRY;

	}

	x.PrintLine("Your data is as follows:");
	x.PrintLine("SAL: " + std::to_string(returnVal.sal));
	x.PrintLine("ATM: " + std::to_string(returnVal.atm));
	x.PrintLine("Weapon BA given range: " + std::to_string(returnVal.ba));
	x.PrintLine("Current Range in 2 yard hexes: " + std::to_string(returnVal.range));
	x.PrintLine("Calculated Range ALM using table 4A: " + std::to_string(returnVal.rangeAlm) + "\n");
	
	if (x.Confirm("leave this stage") == false) {
		std::system("cls"); //clear the console
		return Filter_ShooterData(returnVal);

	}
	
	return returnVal;

}