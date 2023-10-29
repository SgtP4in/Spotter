#include "OOH_Factory.h"

int OOH_Factory::run()
{
	//Clean the data object and filters
	//TODO

	//Shooter data
	oddsOfHittingData = shooterDataFilter.Filter_ShooterData(oddsOfHittingData);
	std::system("pause"); //TESTING DELETE!!!

	//Weapon data
	//ToDo

	//Range
	//ToDo

	//Situation and Stance Modifiers
	//ToDo

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
