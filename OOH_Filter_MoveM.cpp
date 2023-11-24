#include "OOH_Filter_MoveM.h"

OOH_Filter_MoveM::OOH_Filter_MoveM()
{
	if (table4D.LoadTable("Tables/Table4D.csv") == -1) {
		x.PrintLine("ERROR OOH_Filter_MoveM(): Failed to load table!!!");

	}

}

OOH_Data OOH_Filter_MoveM::Filter_MovementData(OOH_Data data)
{
	OOH_Data returnVal = data;
	int answer;

	std::system("cls");

RETRY:
	try {
		//Print title
		x.PrintLine("MOVEMENT DATA");
		x.PrintHorzLine();

		//Prompt user for information
		x.PrintLine("\"Movement ALM\n Corrections for targetand shooter motion are found on Table 40.The Moving Target\n ALM is found on Table 40 by crcss - lndexlnq the target speed(in hexes per Impulse) and\n target range(in 2 yard hexes).li the entry is in the shaded portion altha table, then there\n is no restriction on Aim Time.If the entry is in the unshaded portion of the table, the shot's\n Aim Time is restricted to a maximum of 2 Impulses.\n\n For shooters moving under their own power, the Moving Shooter ALM is found in the\n same manner as for a Moving Target.The Shooter's speed is cross-indexed with the\n target range on Table 4D to find the Mo ving Shooter ALM.A moving shooter has an Aim\n Time restriction of 1 Impulse.Note that the shooter's speed is the number of hexes moved\n the Impulse the shot was fired, and that a moving sh ooter must Hip Fire.\"");
		x.PrintLine(" ~Phoenix Command - Small Arms Combat System, Page 22");
		std::cout << std::endl;
		x.PrintLine("What is the speed of the shooter in Hexes per impulse? (yds/0.25 sec)");
		std::cin >> returnVal.move_speedHPI;
		std::cin.clear();
		x.PrintHorzLine();

		//Cross reference table 4D to find the correct data
		returnVal.moveAlm = table4D.CrossReference(returnVal.move_speedHPI, returnVal.range);

	}
	catch (...) {
		x.PrintLine("ERROR filter_MovementData(OOH_Data data)");
		goto RETRY;

	}

	//Present data to user for confirmation
	x.PrintLine("Your data is as follows:\n");
	x.PrintLine("The shooter's speed in Hexes Per Impulse (HPI) is " + std::to_string(returnVal.move_speedHPI));
	x.PrintLine("The range to target in 2 yd hexes is " + std::to_string(returnVal.range));

	if (returnVal.moveAlm == 777) {
		returnVal.moveAlm = -5;
		x.PrintLine("Your movement ALM modifier is -5 (No Maximim Aim), calculated using Table 4D");
	}
	else if (returnVal.moveAlm == 666) {
		returnVal.moveAlm = -10;
		x.PrintLine("Your movement ALM modifier is -10 (Maximum 2 Impulse Aim), calculated using Table 4D");

	}
	else {
		x.PrintLine("Your movement ALM modifier is " + std::to_string(returnVal.moveAlm) + ", calculated using Table 4D");

	}

	if (x.Confirm("leave this stage") == false) {
		std::system("cls"); //clear the console
		return Filter_MovementData(returnVal);

	}

	return returnVal;
}
