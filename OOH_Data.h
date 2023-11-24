#pragma once
#include <vector>

/*
* A data class for Odds. Of. Hitting. calculations, meant to be passed through filters for propagation and modification
*/
class OOH_Data
{
public:
	//Shooter data
	int sal; //Skill Accuracy Level
	
	//Weapon data
	int atm; //Aim Time Mod
	int ba; //Base Accuracy for the current range

	//Range
	int range; //current range in hexes
	int rangeAlm; //range ALMs

	//Situation and Stance Modifiers
	std::vector<bool> ss_m; //Situational Stance Modifiers
	int ssmAlm; //Situational Stance ALMs

	//Visibility Modifiers
	std::vector<bool> v_m;
	int vmAlm;

	//Movement Modifiers
	double move_speedHPI;
	int moveAlm;

	//Standard Target Size Modifiers
	//Target Size Modifier
	std::vector<bool> sts_m;
	int stsAlm;
	int stsAutoElevAlm;

	//Odds of Hitting
	int eal; //Effective Accuracy Level
	int burst_eal; //Effective Accuracy Level
	int singleShotOOH; //Single Shot Odds of Hitting
	int burstElevationOOH; //Burst Elevation

};

