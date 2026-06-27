/*
 * Project Three
 * CS-210
 * Chijioke Nwaogbe
 */

#include <iostream>
#include <limits>
#include "ItemTracker.h"

using namespace std;

int main() {

    ItemTracker tracker;

    tracker.LoadDataFromFile("CS210_Project_Three_Input_File.txt");
    tracker.CreateBackupFile("frequency.dat");

    int choice = 0;
    string itemName;

    while (choice != 4) {

        cout << endl;
        cout << "==================================" << endl;
        cout << "        Corner Grocer Menu        " << endl;
        cout << "==================================" << endl;
        cout << "1. Search for an item" << endl;
        cout << "2. Display all item frequencies" << endl;
        cout << "3. Display histogram" << endl;
        cout << "4. Exit" << endl;
        cout << "==================================" << endl;
        cout << "Enter your choice: ";

        cin >> choice;

        // Input validation
        while (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input. Enter a number from 1 to 4: ";
            cin >> choice;
        }

        switch (choice) {

        case 1:

            cout << endl;
            cout << "Enter item name: ";
            cin >> itemName;

            cout << itemName << " was purchased "
                << tracker.GetItemFrequency(itemName)
                << " time(s)." << endl;

            break;

        case 2:

            cout << endl;
            cout << "Item Frequencies" << endl;
            cout << "----------------" << endl;

            tracker.PrintAllFrequencies();

            break;

        case 3:

            cout << endl;
            cout << "Histogram" << endl;
            cout << "---------" << endl;

            tracker.PrintHistogram();

            break;

        case 4:

            cout << endl;
            cout << "Program terminated." << endl;

            break;

        default:

            cout << endl;
            cout << "Please enter a number from 1 to 4." << endl;
        }
    }

    return 0;
}