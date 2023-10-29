#pragma once
#include <iostream>
#include <stdlib.h>
#include <utility>
#include "OOH_Data.h"
#include "User_Interface.h"
#include "OOH_Filter_ShooterData.h"

class OOH_Filter_ShooterData
{
public:
	//Propogates the Shooter, Weapon, and range data sections of the OOH_Data
	OOH_Data Filter_ShooterData(OOH_Data data);

private:
	User_Interface x;
	//Table 4A, Range
	const std::pair<int, int> TABLE_4A[53] = {
	std::pair<int, int>(1, 33),
	std::pair<int, int>(2, 28),
	std::pair<int, int>(3, 25),
	std::pair<int, int>(4, 23),
	std::pair<int, int>(5, 22),
	std::pair<int, int>(6, 20),
	std::pair<int, int>(7, 19),
	std::pair<int, int>(8, 18),
	std::pair<int, int>(9, 17),
	std::pair<int, int>(11, 16),
	std::pair<int, int>(12, 15),
	std::pair<int, int>(14, 14),
	std::pair<int, int>(16, 13),
	std::pair<int, int>(19, 12),
	std::pair<int, int>(22, 11),
	std::pair<int, int>(25, 10),
	std::pair<int, int>(30, 9),
	std::pair<int, int>(35, 8),
	std::pair<int, int>(40, 7),
	std::pair<int, int>(45, 6),
	std::pair<int, int>(50, 5),
	std::pair<int, int>(55, 4),
	std::pair<int, int>(65, 3),
	std::pair<int, int>(75, 2),
	std::pair<int, int>(85, 1),
	std::pair<int, int>(100, 0),
	std::pair<int, int>(115, -1),
	std::pair<int, int>(130, -2),
	std::pair<int, int>(150, -3),
	std::pair<int, int>(170, -4),
	std::pair<int, int>(200, -5),
	std::pair<int, int>(230, -6),
	std::pair<int, int>(250, -7),
	std::pair<int, int>(300, -8),
	std::pair<int, int>(350, -9),
	std::pair<int, int>(400, -10),
	std::pair<int, int>(450, -11),
	std::pair<int, int>(500, -12),
	std::pair<int, int>(600, -13),
	std::pair<int, int>(700, -14),
	std::pair<int, int>(800, -15),
	std::pair<int, int>(950, -16),
	std::pair<int, int>(1100, -17),
	std::pair<int, int>(1250, -18),
	std::pair<int, int>(1400, -19),
	std::pair<int, int>(1650, -20),
	std::pair<int, int>(1900, -21),
	std::pair<int, int>(2150, -22),
	std::pair<int, int>(2500, -23),
	std::pair<int, int>(2850, -24),
	std::pair<int, int>(3300, -25),
	std::pair<int, int>(3800, -26),
	std::pair<int, int>(4350, -27),
	};
};

