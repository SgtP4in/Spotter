#pragma once
#include <vector>

/*
* A data class for Odds. Of. Hitting. calculations, meant to be passed through filters for propagation and modification
*/
class OOH_Data
{
	//Shooter data
	double sal; //Skill Accuracy Level
	
	//Weapon data
	double atm; //Aim Time Mod
	double ba; //Base Accuracy for the current range

	//Range
	double rangeAlm;

	//Situation and Stance Modifiers
	std::vector<bool> ss_m;
	double ssmAlm;

	//Visibility Modifiers
	std::vector<bool> v_m;
	double vmAlm;

	//Movement Modifiers
	std::vector<bool> move_m;
	double moveAlm;

	//Standard Target Size Modifiers
	std::vector<bool> sts_m;
	double stsAlm;

	//Target Size Modifier
	std::vector<bool> ts_m;
	double tsAlm;

	//Odds of Hitting
	double eal; //Effective Accuracy Level
	double singleShotOOH; //Single Shot Odds of Hitting
	double burstElevation; //Burst Elevation

};

