#pragma once
#include <iostream>
#include <stdlib.h>
#include <utility>
#include <string>
#include "OOH_Data.h"
#include "User_Interface.h"

class OOH_Filter_SituationMods
{
public:
	OOH_Filter_SituationMods();

	//Propogates the Situation Modifier Section of the OOH_Data
	OOH_Data Filter_SituationData(OOH_Data data);

private:
	//Table 4B, Situational Stance Modifiers
	const std::pair<std::string, int> TABLE_4B[14] = {
	std::pair<std::string, int>("Standing", 0),
	std::pair<std::string, int>("Kneeling", 3),
	std::pair<std::string, int>("Prone", 6),
	std::pair<std::string, int>("Using Sling for Support (Aim Time > 7)", 1),
	std::pair<std::string, int>("Firing from the Hip", -6),
	std::pair<std::string, int>("Firing Rifle with One Hand", -7),
	std::pair<std::string, int>("Firing Pistol with One Hand", -4),
	std::pair<std::string, int>("Folding Stock Not Used", -4),
	std::pair<std::string, int>("Firing Pistol Double Action", -3),
	std::pair<std::string, int>("Deployed Bipod Not Braced", -2),
	std::pair<std::string, int>("Bipod Mounted Weapon", 3),
	std::pair<std::string, int>("Tripod Mounted Weapon", 5),
	std::pair<std::string, int>("Turret Mounted Weapon", 11),
	std::pair<std::string, int>("Pistol with Shoulder Stock", 3),
	};

	User_Interface x;
	std::vector<std::string> options; //Options as outlined in Table 4B

};

