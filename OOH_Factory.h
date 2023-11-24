#pragma once
#include "OOH_Data.h"

#include "User_Interface.h"
#include <utility>

#include "OOH_Filter_ShooterData.h"
#include "OOH_Filter_SituationMods.h"
#include "OOH_Filter_VisualMods.h"
#include "OOH_Filter_MoveM.h"
#include "OOH_Filter_STSmods.h"
#include "OOH_Filter_TargetSizeMods.h"

/*
* A factory class whose function is to administrate an Odds of Hitting Calculation using filters
*/
class OOH_Factory
{
public:
	//OOH_Factory();

	//Run a calculation, and construct the oddsOfHittingData object
	int run();

private:
	//Finally "assembly" function of the factory
	OOH_Data finalOddsAssembly(OOH_Data data);

	//OOH Data object to be constructed by the factor and its filters
	OOH_Data oddsOfHittingData;

	//Filter objects
	OOH_Filter_ShooterData shooterDataFilter;
	OOH_Filter_SituationMods situationDataFilter;
	OOH_Filter_VisualMods visibilityDataFilter;
	OOH_Filter_MoveM movementDataFilter;
	OOH_Filter_stsM standardTatgetSizeFilter;
	OOH_Filter_TargetSizeMods targetSizeFilter;

	//User interface
	User_Interface x;

};

