#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "CSVLine.h"


int main()
{
    float total = 0;
    std::vector<std::string> name_list = { 
        "ELECTRIC", "GROCERY", "INTERNET" }; //whitelist entries
    std::string file_entry, close;
    std::ifstream file ( "DUMMY_INPUT.csv");

    while (getline(file, file_entry)) {
        CSVLine line(file_entry);
        std::stringstream ss;

        for (auto name : name_list) {
            if (line.get_name().find(name) != std::string::npos) {
                ss << line.get_date() << "," << line.get_name() << ",$" << line.get_amount() << std::endl;
                std::cout << ss.str(); //TODO: Append to CSV
                total += line.get_amount();
            }
        }
    }

    std::cout << total << std::endl; //TODO: Append to CSV
    std::cout << "enter text to close console" << std::endl;
    std::cin >> close;

    return 0;
}
