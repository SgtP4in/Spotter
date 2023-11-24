#include "Table_Data.h"

int Table_Data::LoadTable(std::string file)
{
    //open the file
    std::ifstream fin(file);

    //check if the file opened
    if (!fin) {
        std::cout << "ERROR: Could not read " + file << std::endl;
        return -1;

    }

    //read the file and load the data
    double row, column;
    int content;
    std::string line = "";
    std::string tempString = "";
    while (std::getline(fin, line)) {
        std::stringstream inputString(line);

        std::getline(inputString, tempString, ',');
        row = std::atof(tempString.c_str());

        tempString = "";
        std::getline(inputString, tempString, ',');
        column = std::atof(tempString.c_str());

        tempString = "";
        std::getline(inputString, tempString);
        content = std::atoi(tempString.c_str());

        tableContent.push_back(tableEntry(row, column, content));

        std::string line = "";

    }

    /*
    std::cout << "contents of " + file << std::endl;
    for (auto j : tableContent) {
        std::cout << std::to_string(j.rowKey) + " " + std::to_string(j.colKey) + " " + std::to_string(j.content) << std::endl;
    }
    */

    //close the file
    fin.close();
    return 0;

}

int Table_Data::CrossReference(double rowK, double columnK)
{
    bool checkRow = true;
    bool checkCol = true;
    double corrRow = 1;
    double corrCol = 1;
    double lowestRow = FLT_MAX;
    double lowestCol = FLT_MAX;
    double highestRow = FLT_MIN;
    double highestCol = FLT_MIN;

    //Round down any tabke input values
    for (int i = 0; i < (tableContent.size() - 1); i++) {
        //if the right row key is found, save it and stop checking
        if (tableContent.at(i).rowKey <= rowK && tableContent.at(i + 1).rowKey > rowK && checkRow == true ) {
            corrRow = tableContent.at(i).rowKey;
            checkRow = false;

        }

        //if the right col key is found, save it and stop checking
        if (tableContent.at(i).colKey <= columnK && tableContent.at(i + 1).colKey > columnK && checkCol == true) {
            corrCol = tableContent.at(i).colKey;
            checkCol = false;

        }

        //Determine the lower and outermost bounds of the table
        if (tableContent.at(i).rowKey < lowestRow) {
            lowestRow = tableContent.at(i).rowKey;

        }
        if (tableContent.at(i).colKey < lowestCol) {
            lowestCol = tableContent.at(i).colKey;

        }
        if (tableContent.at(i).rowKey > highestRow) {
            highestRow = tableContent.at(i).rowKey;

        }
        if (tableContent.at(i).colKey > highestCol) {
            highestCol = tableContent.at(i).colKey;

        }

    }

    //Out of Bounds check
    if (rowK <= lowestRow) {
        corrRow = lowestRow;
    }
    if (columnK <= lowestCol) {
        corrCol = lowestCol;
    }
    if (rowK >= highestRow) {
        corrRow = highestRow;
    }
    if (columnK >= highestCol) {
        corrCol = highestCol;
    }

    //Cross reference the table
    for (auto i : tableContent) {
        if (i.rowKey == corrRow && i.colKey == corrCol) {

            return i.content;

        }

    }

    return 666;

}
