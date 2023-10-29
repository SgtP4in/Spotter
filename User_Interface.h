#pragma once

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>

class User_Interface
{
public:
	//Display the Hello World testing interface
	void HelloWorld();

	/*
	* Display a simple(y / n) confirmation prompt
	*/
	bool Confirm(std::string prompt = "continue");

	/*
	* Offer the user a chance to select multiple options at once
	* Will return one true false value for each option selected
	* CANNOT EXCEED 14 OPTIONS!!!
	*/
	std::vector<bool> FilterSelection(std::vector<std::string> options);

	/*
	* Offer the user a chance to select multiple options at once
	* Will return one true false value for each option selected
	* CANNOT EXCEED 14 OPTIONS!!!
	* Recurrent version
	*/
	std::vector<bool> FilterSelection_r(std::vector<std::string> options, std::vector<bool> recurrentData);

	/*
	* Print a line of text
	*/
	void PrintLine(std::string text, bool noNewline = false);

	/*
	* Print a horizontal line
	*/
	void PrintHorzLine();

private:

};

