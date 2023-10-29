#include "OOH_Filter_SituationMods.h"

OOH_Filter_SituationMods::OOH_Filter_SituationMods()
{
    //Propogate Options as defined in table 4B
    for (auto i : TABLE_4B) {
        options.push_back(i.first);

    }

}

OOH_Data OOH_Filter_SituationMods::Filter_SituationData(OOH_Data data)
{
    std::system("cls");

    OOH_Data returnVal;
    int answer;
    int workingALM = 0;
    std::string dataSummary;
RETRY:
    try {
        //Present situational options to the user
        x.PrintLine("Please select any applicable situational stance modifiers regarding the shooter: ");
        returnVal.ss_m = x.FilterSelection(options);
        x.PrintHorzLine();

        //Ask if the shooter is braced
        x.PrintLine("Is the shooter's weapon braced? (y/n)");
        answer = std::system("choice /c yn /n");
        x.PrintHorzLine();

        //Calculate the composite sum of Situational modifiers
            //Add additional modifiers based on if the shooter is braced, to reflect table 4B
        workingALM = 0;
        if (answer == 1) {
            if (returnVal.ss_m.at(0) == true) { workingALM = workingALM + 4; }
            if (returnVal.ss_m.at(1) == true) { workingALM = workingALM + 2; }
            if (returnVal.ss_m.at(2) == true) { workingALM = workingALM + 1; }
            dataSummary.append("The shooter is firing from a braced position\n");

        }
            //sum the modifiers selected
        for (int i = 0; i < options.size(); i++) {
            if (returnVal.ss_m.at(i) == true) {
                workingALM = workingALM + TABLE_4B[i].second;
                dataSummary.append(TABLE_4B[i].first + "\n");

            }

        }
        returnVal.ssmAlm = workingALM;

    }
    catch (...) {
        x.PrintLine("ERROR Invalid Input!");
        std::cin.clear();
        goto RETRY;
    }

    //Present data to user for confirmation
    x.PrintLine("Your data is as follows:\n" + dataSummary);
    x.PrintLine("Your situational stance modifier is " + std::to_string(returnVal.ssmAlm) + " ALMs, calculated using Table 4B");

    if (x.Confirm("leave this stage") == false) {
        std::system("cls"); //clear the console
        return Filter_SituationData(returnVal);

    }

    return returnVal;
}
