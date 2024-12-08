#include <iostream>
#include "finder.h"

int main(){
    std::cout<<"Starting Day4\n";
    std::string dataFile;
    dataFile.append(std::getenv("ADVENT_DATA_PATH")).append(PATH_SYMBOL).append("day4.txt");

    Finder finder(dataFile);
    std::cout<<finder.getCount()<<"\n";
    return 0;
}