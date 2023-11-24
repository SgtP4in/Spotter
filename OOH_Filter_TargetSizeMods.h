#pragma once
#include <iostream>
#include <stdlib.h>
#include <utility>
#include "OOH_Data.h"
#include "User_Interface.h"
#include "Table_Data.h"

class OOH_Filter_TargetSizeMods
{
public:
	OOH_Filter_TargetSizeMods();

	OOH_Data Filter_TargetSizeMods(OOH_Data data);

private:
	User_Interface x;
	Table_Data table4F;

};

