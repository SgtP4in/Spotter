#pragma once
#include "OOH_Data.h"

#include "OOH_Filter_ShooterData.h"
#include "OOH_Filter_SituationMods.h"

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
	//OOH Data object to be constructed by the factor and its filters
	OOH_Data oddsOfHittingData;

	//Filter objects
	OOH_Filter_ShooterData shooterDataFilter;
	OOH_Filter_SituationMods situationDataFilter;

};

