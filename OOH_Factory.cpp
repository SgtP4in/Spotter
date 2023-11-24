#include "OOH_Factory.h"

int OOH_Factory::run()
{
	//Clean the data object and filters
	oddsOfHittingData.atm = 0;
	oddsOfHittingData.ba = 0;
	oddsOfHittingData.burstElevationOOH = 0;
	oddsOfHittingData.burst_eal = 0;
	oddsOfHittingData.eal = 0;
	oddsOfHittingData.moveAlm = 0;
	oddsOfHittingData.move_speedHPI = 0;
	oddsOfHittingData.range = 0;
	oddsOfHittingData.rangeAlm = 0;
	oddsOfHittingData.sal = 0;
	oddsOfHittingData.singleShotOOH = 0;
	oddsOfHittingData.ssmAlm = 0;
	oddsOfHittingData.ss_m = std::vector<bool>();
	oddsOfHittingData.stsAlm = 0;
	oddsOfHittingData.stsAutoElevAlm = 0;
	oddsOfHittingData.sts_m = std::vector<bool>();
	oddsOfHittingData.vmAlm = 0;
	oddsOfHittingData.v_m = std::vector<bool>();

	//Shooter data
	//Weapon data
	//Range
	oddsOfHittingData = shooterDataFilter.Filter_ShooterData(oddsOfHittingData);

	//Situation and Stance Modifiers
	oddsOfHittingData = situationDataFilter.Filter_SituationData(oddsOfHittingData);

	//Visibility Modifiers
	oddsOfHittingData = visibilityDataFilter.Filter_VisibilityData(oddsOfHittingData);

	//Movement Modifiers
		//Ask if the shooter is moving
	int answer;
	std::system("cls");
	x.PrintLine("Is the shooter moving? (y/n)");
	answer = std::system("choice /c yn /n");
	if (answer == 1) {
		oddsOfHittingData = movementDataFilter.Filter_MovementData(oddsOfHittingData);
	}
	else {
		oddsOfHittingData.move_speedHPI = 0;
		oddsOfHittingData.moveAlm = 0;

	}

	//Decide whether to use Table 4E or 4F, because they are mutually exclusive to one another
	std::system("cls");

	x.PrintLine("TARGET SIZE MODIFIERS");
	x.PrintHorzLine();
	x.PrintLine("\"Target Size ALM\n Target Size ALM for common targets are given on Table 4E.If the target cannot be\n found in the common listings, its Target Size ALM can be found opposite its diameter, in\n feet, on the Target Size ALM Table(4F).\"");
	x.PrintLine(" ~Phoenix Command - Small Arms Combat System, Page 22");
	std::cout << std::endl;

	x.PrintLine("Would you like to use the Standard Target Size Modifiers within Table 4E for a 6' tall human target,\n Or the alternative Target Size Modifiers within Table 4F?");
	x.PrintLine("1) Table 4E Standard Target Size Modifiers");
	x.PrintLine("2) Table 4F (alternative) Target Size Modifiers");
	answer = std::system("choice /c 12 /n");

	switch (answer)
	{
	case 1:
		//Standard Target Size Modifiers
		oddsOfHittingData = standardTatgetSizeFilter.Filter_StandardTargetSize(oddsOfHittingData);
		break;

	case 2:
		//Target Size Modifier
		oddsOfHittingData = targetSizeFilter.Filter_TargetSizeMods(oddsOfHittingData);
		break;

	default:
		x.PrintLine("TARGET SIZE MODIFIERS ERROR!!!");
		break;
	}

	//Odds of Hitting
	oddsOfHittingData = finalOddsAssembly(oddsOfHittingData);

	return 0;

}

OOH_Data OOH_Factory::finalOddsAssembly(OOH_Data data)
{
	OOH_Data returnVal = data;
	Table_Data Table_4G;

	//Calculate the single shot Odds of Hitting
	returnVal.eal = returnVal.sal + returnVal.atm + returnVal.rangeAlm + returnVal.ssmAlm + returnVal.vmAlm + returnVal.moveAlm + returnVal.stsAlm;
	if (returnVal.eal > returnVal.ba) { returnVal.eal = returnVal.ba; } //Adjust the EAL if it is greater than the Base Accuracy of the weapon for the given range
	Table_4G.LoadTable("Tables/Table4G.csv");
	returnVal.singleShotOOH = Table_4G.CrossReference((double)returnVal.eal, 1);

	//Calculate the full auto burst Odds of Hitting
	returnVal.burst_eal = returnVal.sal + returnVal.atm + returnVal.rangeAlm + returnVal.ssmAlm + returnVal.vmAlm + returnVal.moveAlm + returnVal.stsAutoElevAlm;
	if (returnVal.burst_eal > returnVal.ba) { returnVal.burst_eal = returnVal.ba; } //Adjust the EAL if it is greater than the Base Accuracy of the weapon for the given range
	Table_4G.LoadTable("Tables/Table4G_b.csv");
	returnVal.burstElevationOOH = Table_4G.CrossReference((double)returnVal.burst_eal, 1);

	//Print the final results
	x.PrintLine("ODDS OF HITTING");
	x.PrintHorzLine();
	x.PrintLine("The Effective Accuracy Level (EAL) is the sum of aliapplicable ALM's and determines the Odds of Hitting.");
	x.PrintLine("Your Odds of Hitting have been determined by cross referencing the appropriate EAL with Table 4G\n");
	x.PrintLine("For a single shot, your EAL is " + std::to_string(returnVal.eal));
	x.PrintLine("For a single shot, your chance to hit is " + std::to_string(returnVal.singleShotOOH) + "%\n");

	x.PrintLine("For an automatic burst, your EAL is " + std::to_string(returnVal.burst_eal));
	x.PrintLine("For an automatic burst, your Burst Elevation is " + std::to_string(returnVal.burstElevationOOH) + "%\n");

	//Confirm end of calculation
	x.PrintLine("You are at the end of the calculation, and may press any key to return to the main menu\n You will not be able to return to this screen once you leave.\n");
	std::system("pause");

	std::system("cls");

	return returnVal;
}