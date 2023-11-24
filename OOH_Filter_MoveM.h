#pragma once
#include <iostream>
#include <stdlib.h>
#include <utility>
#include "OOH_Data.h"
#include "User_Interface.h"
#include "Table_Data.h"

class OOH_Filter_MoveM
{
public:
	OOH_Filter_MoveM();

	OOH_Data Filter_MovementData(OOH_Data data);

private:
	User_Interface x;
	Table_Data table4D;

};

