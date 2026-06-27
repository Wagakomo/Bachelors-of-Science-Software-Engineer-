#include "ItemTracker.h"

#include <iostream>
#include <fstream>

using namespace std;

// Default constructor
ItemTracker::ItemTracker() {
}

// Reads the grocery items from the input file
void ItemTracker::LoadDataFromFile(string filename) {
    ifstream inputFile;
    string item;

    inputFile.open(filename);

    while (inputFile >> item) {
        itemFrequency[item]++;
    }

    inputFile.close();
}

// Creates frequency.dat backup file
void ItemTracker::CreateBackupFile(string filename) {
    ofstream outputFile;

    outputFile.open(filename);

    for (auto const& pair : itemFrequency) {
        outputFile << pair.first << " " << pair.second << endl;
    }

    outputFile.close();
}

// Returns the frequency of a specific item
int ItemTracker::GetItemFrequency(string item) {
    if (itemFrequency.find(item) != itemFrequency.end()) {
        return itemFrequency[item];
    }

    return 0;
}

// Prints all item frequencies
void ItemTracker::PrintAllFrequencies() {
    for (auto const& pair : itemFrequency) {
        cout << pair.first << " " << pair.second << endl;
    }
}

// Prints histogram using asterisks
void ItemTracker::PrintHistogram() {
    for (auto const& pair : itemFrequency) {

        cout << pair.first << " ";

        for (int i = 0; i < pair.second; i++) {
            cout << "*";
        }

        cout << endl;
    }
}