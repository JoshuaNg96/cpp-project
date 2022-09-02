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
    amount = std::stof(entry.at(2).substr(1, -1));
}
