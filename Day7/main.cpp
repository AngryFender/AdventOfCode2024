#include <iostream>
#include "operator.h"
int main(){
    std::cout<<"Starting Day7\n";
    std::string dataFile;
    dataFile.append(std::getenv("ADVENT_DATA_PATH")).append(PATH_SYMBOL).append("day7.txt");

    Operator operate(dataFile);
    std::cout<<operate.getSafeSum()<<"\n";

    return 0;
}
