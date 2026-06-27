#pragma once

#include <string>
#include <map>

using namespace std;

class ItemTracker {
private:
    map<string, int> itemFrequency;

public:
    ItemTracker();

    void LoadDataFromFile(string filename);

    void CreateBackupFile(string filename);

    int GetItemFrequency(string item);

    void PrintAllFrequencies();

    void PrintHistogram();
};