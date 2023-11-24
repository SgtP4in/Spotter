# Spotter - The Unofficial Pheonix Command Combat System Companion Calculator
Current Version: 0.1
## Spotter Build Instructions
Spotter is a C++ application which will require a C++ compiler to build

## Usage Instructions
The "Tables" Folder must be within the same directory as the Spotter application when Spotter is run. If you recieve a warning on the main menu, Spotter was not able to find the folder

## Supported Features
* An odds of hitting calculation using Tables 4A-4G

## Known Bugs and Issues
* If a target is moving, Spotter will initially assume they are moving 0.5 HPI. This can be corrected by inputting N/"No, this data is not correct and I do not want to continue", and the correct value can then be input.

The following issues do not seriously effect end user functionality, but must be refactored before additional system development can continue.
* Screen titles will dissapear on multiple selection screens once input is passed. 
* The User Interface is tightly coupled to the Windows Operating System. 
* Control logic is tightly coupled to the user interface.
  * Various UI element styles, consistent in presentation across the system, are manually incorporated into several menues in parallel, and should be incorporated into the UI class.
* Filters currently do not conform to a common parent interface, despite using identical control processes.
