/*
 * Corner Grocer
 * Date: 06/22/2025
 * Author: Noel Dolores
 */


// Inventory class
#pragma once


class Inventory {
public:
    void printMenu();
    int getItemFrequency();
    void printAllItemsAndQuantities();
    void printAllItemsAndQuantitiesWithHistogram();

private:
    std::string getUserSearchInput();
    void menuFunctions(int menuNum);
};
