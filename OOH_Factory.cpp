#include "OOH_Factory.h"

int OOH_Factory::run()
{
	//Clean the data object and filters
	//TODO

	//Shooter data
	//Weapon data
	//Range
	oddsOfHittingData = shooterDataFilter.Filter_ShooterData(oddsOfHittingData);

	//Situation and Stance Modifiers
	oddsOfHittingData = situationDataFilter.Filter_SituationData(oddsOfHittingData);
	std::system("pause"); //TESTING DELETE!!!

	//Visibility Modifiers
	//ToDo

	//Movement Modifiers
	//ToDo

	//Standard Target Size Modifiers
	//ToDo

	//Target Size Modifier
	//ToDo

	//Odds of Hitting
	//ToDo

	return 0;
}
