/*
 * Corner Grocer
 * Date: 06/22/2025
 * Author: Noel Dolores
 */


#include <iostream>
#include <string>

#include "inventory.h"
#include "file_functions.h"

using namespace std;


/*
* Creates a class and takes user input to print financial reports for investment scenarios
*/
int main() {
	initItemFrequencyFile(); // init frequency.dat

	Inventory cornerGrocer; 
	cornerGrocer.printMenu();

	return 0;
}