#include "OOH_Filter_VisualMods.h"

OOH_Filter_VisualMods::OOH_Filter_VisualMods()
{
    //Propogate Options as defined in table 4B
    for (auto i : TABLE_4C) {
        options.push_back(i.first);

    }

}

OOH_Data OOH_Filter_VisualMods::Filter_VisibilityData(OOH_Data data)
{
    std::system("cls");

    OOH_Data returnVal = data;
    int answer;
    int workingALM = 0;
    std::string dataSummary;
RETRY:
    try {
        //Present visbility options to the user
        x.PrintLine("Please select any applicable visibility modifiers regarding the shooter: ");
        returnVal.v_m = x.FilterSelection(options);
        x.PrintHorzLine();

        //Calculate the composite sum of visibility modifiers
            //Add additional modifiers based on if the shooter is braced, to reflect table 4B
        workingALM = 0;
        //sum the modifiers selected
        for (int i = 0; i < options.size(); i++) {
            if (returnVal.v_m.at(i) == true) {
                workingALM = workingALM + TABLE_4C[i].second;
                dataSummary.append(TABLE_4C[i].first + "\n");

            }

        }
        returnVal.vmAlm = workingALM;

    }
    catch (...) {
        x.PrintLine("ERROR Invalid Input!");
        std::cin.clear();
        goto RETRY;
    }

    //Present data to user for confirmation
    x.PrintLine("Your data is as follows:\n" + dataSummary);
    x.PrintLine("Your visibility modifier is " + std::to_string(returnVal.vmAlm) + " ALMs, calculated using Table 4C");

    if (x.Confirm("leave this stage") == false) {
        std::system("cls"); //clear the console
        return Filter_VisibilityData(returnVal);

    }

    return returnVal;
}
