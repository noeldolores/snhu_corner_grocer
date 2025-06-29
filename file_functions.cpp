/*
 * Corner Grocer
 * Date: 06/22/2025
 * Author: Noel Dolores
 */


#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include "file_functions.h"

using namespace std;


/*
* Returns an input string as lowercase
* @param input - string
* Return lowerCase - string
*/
string toLowercase(string input) {
    string lowerCase = input;
    transform(lowerCase.begin(), lowerCase.end(), lowerCase.begin(),
        [](unsigned char c) { return tolower(c); });
    return lowerCase;
}


/*
* Creates the frequency.dat file if it does not already exist.
*/
void initItemFrequencyFile() {
    string frequencyFile = "frequency.dat";

    cout << "--------------------------------------------------------------------" << endl; // Style line
    // Create the frequency.dat file if it doesn't
    //   exist. Prints the file status.
    ifstream file(frequencyFile);
    if (!file) {
        ofstream file(frequencyFile);
        if (file) {
            cout << "ATTENTION: New frequency.dat file created successfully." << endl;
            file.close();
        }
        else {
            cout << "ATTENTION: Failed to create frequency.dat file."<< endl;
        }
    }
    else {
        cout << "ATTENTION: Using existing frequency.dat file." << endl;
    }
    cout << "--------------------------------------------------------------------" << endl; // Style line
}


/**
* Takes a file containing a list of items, and stores updates quantity information in the frequency.dat file
* @param fileName - string
*/
int saveItemPurchasesToDatFile(string fileName) {
    ifstream inputDailySales;
    ifstream inputCurrentQuantities;
    ofstream outputUpdatedQuantities;

    string inputFileName = "CS210_Project_Three_Input_File.txt";
    string outputFileName = "frequency.dat";

    int totalNewItems = 0;
    map<string, int> itemFrequency;

    // Load existing frequency.dat if it already exists
    inputCurrentQuantities.open(outputFileName);
    if (inputCurrentQuantities) {
        cout << "Loading items and quantities from frequency.dat..." << endl;
        string item;
        int count;
        while (inputCurrentQuantities >> item >> count) {
            itemFrequency[item] = count;
        }
        inputCurrentQuantities.close();
    }

    // Read new items and update frequency
    inputDailySales.open(inputFileName);
    if (!inputDailySales) {
        cerr << "Failed to open " << inputFileName << endl;
        return 1;
    }

    cout << "Reading items and quantities from CS210_Project_Three_Input_File.txt..." << endl;
    string newItem;
    while (getline(inputDailySales, newItem)) {
        if (!newItem.empty())
            newItem = toLowercase(newItem);
            ++itemFrequency[newItem];
            ++totalNewItems;
    }
    inputDailySales.close();

    // Write updated frequencies
    outputUpdatedQuantities.open(outputFileName);
    if (!outputUpdatedQuantities) {
        cout << "Failed to open " << outputFileName << " for writing." << endl;
        return 1;
    }

    cout << "Writing new items and quantities to frequency.dat..." << endl;
    for (const auto& [item, count] : itemFrequency) {
        outputUpdatedQuantities << item << " " << count << endl;
    }
    outputUpdatedQuantities.close();

    cout << totalNewItems << " items processed successfully." << endl;

    return 0;
}