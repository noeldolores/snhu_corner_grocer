/*
 * Corner Grocer
 * Date: 06/22/2025
 * Author: Noel Dolores
 */


#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <iomanip>

#include "inventory.h"
#include "file_functions.h"

using namespace std;


/*
* Prints the main navigation menu to screen and accepts input.
*/
void Inventory::printMenu() {
    int menuNum = 0;

    cout << "********************************************************************" << endl;
    cout << "**************************  Inventory  *****************************" << endl;

    while (menuNum != 1 && menuNum != 2 && menuNum != 3 && menuNum != 4 && menuNum != 5) {
        cout << "Enter 1 to Item Search" << endl;
        cout << "Enter 2 to Show All Items" << endl;
        cout << "Enter 3 to Show All with Histogram" << endl;
        cout << "Enter 4 to Exit" << endl;
        cout << "Enter 5 to Process Daily Item Data" << endl;

        cin >> menuNum;
        menuFunctions(menuNum);
    }
}


/*
* Takes action based on user input on the main navigation menu
*/
void Inventory::menuFunctions(int menuNum) {
    string continueValidation;

    switch (menuNum) {
    case 1:
        cout << "--------------------------------------------------------------------" << endl; // Style line
        getItemFrequency();


        cout << "--------------------------------------------------------------------" << endl; // Style line
        cout << endl;
        printMenu();
        break;
    case 2:
        cout << "--------------------------------------------------------------------" << endl; // Style line
        printAllItemsAndQuantities();

        cout << "--------------------------------------------------------------------" << endl; // Style line
        cout << endl;
        printMenu();
        break;
    case 3:
        cout << "--------------------------------------------------------------------" << endl; // Style line
        printAllItemsAndQuantitiesWithHistogram();

        cout << "--------------------------------------------------------------------" << endl; // Style line
        cout << endl;
        printMenu();
        break;
    case 4:
        break;
    case 5:
        cout << "--------------------------------------------------------------------" << endl; // Style line
        saveItemPurchasesToDatFile("CS210_Project_Three_Input_File.txt");

        cout << "--------------------------------------------------------------------" << endl; // Style line
        cout << endl;
        printMenu();
        break;
    default:
        break;
    }
}


/**
* Takes a string input from user for item search
* Return itemSearch - string
*/
string Inventory::getUserSearchInput() {
    string itemSearch;

    cout << "Enter an item name..." << endl;
    cin >> itemSearch;
    itemSearch = toLowercase(itemSearch);

    return itemSearch;
}


/**
* Searches frequency.dat for an item name and returns the matching quantity
* Return itemQuantity - integer
*/
int Inventory::getItemFrequency() {
    string itemName = getUserSearchInput();

    ifstream currentQuantities;
    string item;
    int itemQuantity = 0;

    currentQuantities.open("frequency.dat");
    
    while (currentQuantities >> item >> itemQuantity) {
        if (item == itemName) {
            break;
        }
    }

    if (itemQuantity > 0) {
        cout << itemName << ": " << itemQuantity << endl;
    }
    else {
        cout << itemName << " not found." << endl;
    }
    
    return itemQuantity; 
}


/**
* Reads frequency.dat and prints all lines from the file
*/
void Inventory::printAllItemsAndQuantities() {
    ifstream currentQuantities;
    string line;

    currentQuantities.open("frequency.dat");
    if (!currentQuantities.is_open()) {
        cout << "Could not open file frequency.dat." << endl;
    }
    else {
        while (getline(currentQuantities, line)) {
            cout << line << endl;
        }

        currentQuantities.close();
    }
}


/**
* Reads frequency.dat and prints all lines from the file formatted with a histogram
*/
void Inventory::printAllItemsAndQuantitiesWithHistogram() {
    ifstream inputCurrentQuantities;
    string inputFileName = "frequency.dat";

    map<string, int> itemFrequency;

    // Load existing frequency.dat if it already exists
    inputCurrentQuantities.open(inputFileName);
    if (inputCurrentQuantities) {
        string item;
        int count;
        while (inputCurrentQuantities >> item >> count) {
            itemFrequency[item] = count;
        }
        inputCurrentQuantities.close();
    }

    // Display histogram
    for (const auto& [item, count] : itemFrequency) {
        cout << left << setw(12) << item      // Item name padded to 12 characters
            << setw(4) << count              // Count padded to 4 spaces
            << " | ";
        cout << string(count, '*') << endl;   // Asterisk bar
    }
}