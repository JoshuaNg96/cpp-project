#include "CSVLine.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <ctime>


int main()
{
    float total = 0;
    std::vector<std::string> name_list = { 
        "ELECTRIC", "GROCERY", "INTERNET" }; //whitelist entries

    //generate output file
    std::stringstream outNameStream;
    outNameStream << std::time(nullptr) << "_OUTPUT.csv";
    std::ofstream ofile(outNameStream.str());

    //Read each line of input file then append to output file
    std::ifstream ifile("DUMMY_INPUT.csv");
    std::string file_entry;
    while (getline(ifile, file_entry)) {
        CSVLine line(file_entry);
        std::stringstream ss;

        for (auto name : name_list) {
            if (line.get_name().find(name) != std::string::npos) {
                ss << line.get_date() << "," << line.get_name() << ",$" << line.get_amount() << std::endl;
                ofile << ss.str(); //append entry to output file
                total += line.get_amount();
            }
        }
    }
    ifile.close();

    //append total expenses
    ofile << total << std::endl;
    ofile.close();

    return 0;
}
