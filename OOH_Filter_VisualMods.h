#pragma once
#include <iostream>
#include <stdlib.h>
#include <utility>
#include <string>
#include "OOH_Data.h"
#include "User_Interface.h"

class OOH_Filter_VisualMods
{
public:
	OOH_Filter_VisualMods();

	//Propogates the Visibility Modifier Section of the OOH_Data
	OOH_Data Filter_VisibilityData(OOH_Data data);

private:
	//Table 4C, Visibility Modifiers
	const std::pair<std::string, int> TABLE_4C[14] = {
	std::pair<std::string, int>("Good Visibility", 0),
	std::pair<std::string, int>("Dusk", -2),
	std::pair<std::string, int>("Night Full Moon", -4),
	std::pair<std::string, int>("Night 1 / 2 Moon", -6),
	std::pair<std::string, int>("Night No Moon", -12),
	std::pair<std::string, int>("Firing at Muzzle Flash", -10),
	std::pair<std::string, int>("Smoke, Haze.Fog", -6),
	std::pair<std::string, int>("Looking into a Light", -8),
	std::pair<std::string, int>("Optical Scope under 8 hexes", -6),
	std::pair<std::string, int>("Optical Scope Broken", -4),
	std::pair<std::string, int>("Advanced Aiming System Broken", -8),
	std::pair<std::string, int>("Weapon Sights Broken", -4),
	std::pair<std::string, int>("Firing from Teargas.No Mask", -8),
	std::pair<std::string, int>("Shooter Not Looking", -14),
	};

	User_Interface x;
	std::vector<std::string> options; //Options as outlined in Table 4C
};

