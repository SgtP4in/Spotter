#pragma once
#include <iostream>
#include <stdlib.h>
#include <utility>
#include <string>
#include "OOH_Data.h"
#include "User_Interface.h"
#include "Table_Data.h"


class OOH_Filter_stsM
{
public:
	OOH_Filter_stsM();

	OOH_Data Filter_StandardTargetSize(OOH_Data data);

private:
	class Table_4E_Content {
	public:
		Table_4E_Content(std::string title, int targetSizeMod, int autoElevation) {
			this->title = title;
			this->targetSizeMod = targetSizeMod;
			this->autoElevation = autoElevation;

		}

		std::string title;
		int targetSizeMod;
		int autoElevation;

	};

	//Table 4E, Standard Target Size Modifiers
	const Table_4E_Content TABLE_4E[12] = {
		Table_4E_Content("Look Over / Around", - 4, -3),
		Table_4E_Content("Fire Over / Around", 0, 2),
		Table_4E_Content("Standing Exposed", 7, 14),
		Table_4E_Content("Kneeling Exposed", 6, 11),
		Table_4E_Content("Prone / Crawl", 2, 2),
		Table_4E_Content("Running", 8, 14),
		Table_4E_Content("Low Crouch", 7, 11),
		Table_4E_Content("Hands and Knees", 6, 8),
		Table_4E_Content("Low Prone", 1, 0),
		Table_4E_Content("Head", -3, 0),
		Table_4E_Content("Body", 5, 8),
		Table_4E_Content("Legs", 4, 8)

	};

	User_Interface x;
	std::vector<std::string> options; //Options as outlined in Table 4E
	

};