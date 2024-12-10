#include <iostream>
#include "locater.h"
int main()
{
    std::cout<<"Starting Day6\n";
    std::string dataFile;
    dataFile.append(std::getenv("ADVENT_DATA_PATH")).append(PATH_SYMBOL).append("day6.txt");

    Locater locater(dataFile);
    std::cout<<locater.getDistinctCount()<<"\n";
    std::cout<<locater.getLoopSum();
    return 0;
}
