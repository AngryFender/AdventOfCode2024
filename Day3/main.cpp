#include <iostream>
#include <string>
#include "parser.h"

int main(){
    std::cout<<"Starting Day3\n";
    std::string dataFile;
    dataFile.append(std::getenv("ADVENT_DATA_PATH")).append(PATH_SYMBOL).append("day3.txt");

    Parser parser(dataFile);
    std::cout<<parser.getSumMult();

    return 0;
}