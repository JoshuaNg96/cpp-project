#include "CSVLine.h"

//Define constructor
CSVLine::CSVLine(std::string line) {
    std::string value;
    std::vector<std::string> entry;
    std::stringstream ss(line);

    //Split csv row and push to vector
    while (getline(ss, value, ',')) {
        entry.push_back(value);
    }

    date = entry.at(0);
    name = entry.at(1);
    //If entry is credit set debit to 0
    amount = entry.at(3).size() ? std::stof(entry.at(3).substr(1, -1)) : 0;
}
