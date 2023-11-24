#include "OOH_Filter_STSmods.h"

OOH_Filter_stsM::OOH_Filter_stsM()
{
    //Propogate Options as defined in table 4E
    for (auto i : TABLE_4E) {
        options.push_back(i.title);

    }

}

OOH_Data OOH_Filter_stsM::Filter_StandardTargetSize(OOH_Data data)
{
    OOH_Data returnVal = data;
    int answer;
    int workingALM = 0;
    std::string dataSummary;
RETRY:
    try {
        //Present situational options to the user
        x.PrintLine("Please select any applicable target size modifiers regarding the target: ");
        returnVal.sts_m = x.FilterSelection(options);
        x.PrintHorzLine();

        //Calculate the composite sum of Situational modifiers
        //sum the modifiers selected for a single shot target size
        for (int i = 0; i < options.size(); i++) {
            if (returnVal.sts_m.at(i) == true) {
                workingALM = workingALM + TABLE_4E[i].targetSizeMod;
                dataSummary.append(TABLE_4E[i].title + "\n");

            }

        }
        returnVal.stsAlm = workingALM;

        //sum the modifiers selected for a burst elevation
        workingALM = 0;
        for (int i = 0; i < options.size(); i++) {
            if (returnVal.sts_m.at(i) == true) {
                workingALM = workingALM + TABLE_4E[i].autoElevation;

            }

        }
        returnVal.stsAutoElevAlm = workingALM;

    }
    catch (...) {
        x.PrintLine("ERROR Invalid Input!");
        std::cin.clear();
        goto RETRY;
    }

    //Present data to user for confirmation
    x.PrintLine("Your data is as follows:\n" + dataSummary);
    x.PrintLine("Calculated using Table 4E...\n Your Target Size modifier is " + std::to_string(returnVal.stsAlm) + " ALMs\n Your Burst Elevation modifier is " + std::to_string(returnVal.stsAutoElevAlm));

    if (x.Confirm("leave this stage") == false) {
        std::system("cls"); //clear the console
        return Filter_StandardTargetSize(returnVal);

    }

    return returnVal;
}
