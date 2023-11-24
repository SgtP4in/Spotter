#pragma once
#include <iostream>
#include <stdlib.h>
#include <utility>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "tableEntry.h"

class Table_Data
{
public:
	/*
	* Load the contents of a csv data table
	*/
	int LoadTable(std::string file);

	/*
	* Cross reference a table given a row key and a column key to find the appropriate value
	*/
	int CrossReference(double rowK, double columnK);

	//Table Data container
	//Stored as Row Key, Column Key, and content
	std::vector<tableEntry> tableContent;

};

