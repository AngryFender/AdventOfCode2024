#include <iostream>
#include "arranger.h"

int main(){
    std::cout<<"Starting Day5\n";
    std::string dataFile;
    dataFile.append(std::getenv("ADVENT_DATA_PATH")).append(PATH_SYMBOL).append("day5.txt");

    Arranger arranger(dataFile);
    std::cout<<arranger.getMiddleSum();
    return 0;
}