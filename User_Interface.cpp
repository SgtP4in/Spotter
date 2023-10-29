#include "User_Interface.h"


void User_Interface::HelloWorld()
{
	std::cout << "[ ] Hello World!" << std::endl;
	Confirm();
	std::system("pause");

	std::system("cls");

	std::vector<std::string> testOpts;
	testOpts.push_back("Option 0");
	testOpts.push_back("Option 1");
	testOpts.push_back("Option 2");
	testOpts.push_back("Option 3");
	testOpts.push_back("Option 4");

	FilterSelection(testOpts);

	std::system("pause");
	std::system("cls");

	//std::cout << "[X] Hello World!" << std::endl;
	PrintLine("[X] Hello World!");
	std::system("pause");

}

bool User_Interface::Confirm(std::string prompt)
{
	int answer;

	//Attempt to recieve input
	std::cout << "You are about to " + prompt + ", are you sure you wish to continue? (y/n)";
	answer = ( std::system("choice /c ny /n") - 1 ); //system will return true as 1, and false as 2, so it needs to be converted with the -1
	std::cout << answer << std::endl;
	
	return (bool)answer;

}

std::vector<bool> User_Interface::FilterSelection(std::vector<std::string> options)
{
	//Out of Bounds error check
	if (options.size() <= 0 || options.size() > 14) {
		std::cout << "ERROR User_Interface::FilterSelection: number of options out of acceptable range" << std::endl;
		std::system("pause");

	}

	//Configure the return data structure, and create one entry corresponding to each option
	std::vector<bool> returnData;
	for (auto i : options) {
		returnData.push_back(false);

	}

	//Call the recurrent version of the function, to begin the selection process
	returnData = FilterSelection_r(options, returnData);

	//Refesh the terminal
	std::system("cls");
	return returnData;

}

void User_Interface::PrintLine(std::string text, bool noNewline)
{
	std::cout << text;
	if (noNewline == false) std::cout << std::endl;

}

void User_Interface::PrintHorzLine()
{
	std::cout << "--------------------------------------------------------------------------------" << std::endl;

}

std::vector<bool> User_Interface::FilterSelection_r(std::vector<std::string> options, std::vector<bool> recurrentData)
{
	std::vector<bool> returnData = recurrentData;

	//Configure the choice setting for the windows choice command further in
	std::string choiceOpts;
	if (options.size() == 1) { choiceOpts = "c0"; }
	else if (options.size() == 2) { choiceOpts = "c01"; }
	else if (options.size() == 3) { choiceOpts = "c012"; }
	else if (options.size() == 4) { choiceOpts = "c0123"; }
	else if (options.size() == 5) { choiceOpts = "c01234"; }
	else if (options.size() == 6) { choiceOpts = "c012345"; }
	else if (options.size() == 7) { choiceOpts = "c0123456"; }
	else if (options.size() == 8) { choiceOpts = "c01234567"; }
	else if (options.size() == 9) { choiceOpts = "c012345678"; }
	else if (options.size() == 10) { choiceOpts = "c0123456789q"; }
	else if (options.size() == 11) { choiceOpts = "c0123456789qw"; }
	else if (options.size() == 12) { choiceOpts = "c0123456789qwe"; }
	else if (options.size() == 13) { choiceOpts = "c0123456789qwer"; }
	else { choiceOpts = "c0123456789qwert"; }

	int answer; //holder for user input
	int j; //used in the for loop to track the current index
	std::string prefix; //Prefix text printed at the start of each option
	char ddoption; //Used if an option is between and including 10 and 14
	// Prompt the user for input until they enter "C", indicating they wish to continue
	//Display the options
	j = 0;
	for (auto i : options) {
		//Change the option prefix if it is selected
		if (returnData.at(j) == false) { prefix = "[ ]"; }
		else { prefix = "[X]"; }
		if (j <= 9) std::cout << prefix + " " + std::to_string(j) + ") " + i << std::endl;
		else {
			//Convert the index to the correct letter option
			switch (j)
			{
			case 10:
				ddoption = 'q';
				break;

			case 11:
				ddoption = 'w';
				break;

			case 12:
				ddoption = 'e';
				break;

			case 13:
				ddoption = 'r';
				break;

			default:
				ddoption = 't';
				break;

			}

			//print the option
			PrintLine(prefix + " " + ddoption + ") " + i);

		}

		j++;

	}

	PrintLine("Please toggle your selections, then press 'c' to Continue...");

	//Recieve input
	choiceOpts = "choice /c " + choiceOpts + " /n";
	answer = std::system(choiceOpts.c_str());

	//If the input is not 1 ('C'ontinue), adjust the settings accordingly, then call the recurrent version of the function
	if (answer != 1) {
		returnData.at(answer - 2) = (returnData.at(answer - 2) == false); //Flip false to true, and the reverse

		//Refesh the terminal
		std::system("cls");

		returnData = FilterSelection_r(options, returnData);

	}

	//Once the user is finished, clean the terminal and return the data
	return returnData;

}


