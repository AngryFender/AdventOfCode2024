#include <iostream>
#include <string>
#include "safety.h"
int main()
{
    std::cout<<"Starting Day2 \n";
    std::string dataFile;
    dataFile.append(std::getenv("ADVENT_DATA_PATH")).append(PATH_SYMBOL).append("day2.txt");

    Safety safety(dataFile);
    std::cout << safety.getSafeCount();

    return 0;
}


