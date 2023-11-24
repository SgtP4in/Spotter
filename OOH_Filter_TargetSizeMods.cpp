#include "OOH_Filter_TargetSizeMods.h"

OOH_Filter_TargetSizeMods::OOH_Filter_TargetSizeMods()
{
	if (table4F.LoadTable("Tables/Table4F.csv") == -1) {
		x.PrintLine("ERROR OOH_Filter_TargetSizeMods(): Failed to load table!!!");

	}
}

OOH_Data OOH_Filter_TargetSizeMods::Filter_TargetSizeMods(OOH_Data data)
{
	OOH_Data returnVal = data;
	int answer;
	double answer2;

RETRY:
	try {
		//Print title

		//Prompt user for information
		x.PrintLine("What is the diameter of target in feet? (Use a decimal value for targets below 1' in width)");
		std::cin >> answer2;
		std::cin.clear();
		x.PrintHorzLine();

		//Cross reference table 4F to find the correct data
		returnVal.stsAlm = table4F.CrossReference(answer2, 1);
		returnVal.stsAutoElevAlm = table4F.CrossReference(answer2, 1);

	}
	catch (...) {
		x.PrintLine("ERROR Filter_TargetSizeMods()");
		goto RETRY;

	}

	//Present data to user for confirmation
	x.PrintLine("Your data is as follows:\n");
	x.PrintLine("The Target's size in feet is " + std::to_string(answer2));
	x.PrintLine("Your Target Size and Burst Elevation ALM is " + std::to_string(returnVal.stsAlm) + ", calculated using Table 4F");
	

	if (x.Confirm("leave this stage") == false) {
		std::system("cls"); //clear the console
		return Filter_TargetSizeMods(returnVal);

	}

	return returnVal;

}
