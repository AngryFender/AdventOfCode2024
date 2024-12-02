#include <iostream>
#include <string>
#include "diff.h"

int main() {
    std::cout << "Starting Day 1" << std::endl;
    std::string data_path = std::getenv("ADVENT_DATA_PATH");
    std::string data_file = data_path + "\\day1.txt";

    Diff diff(data_file);
    std::cout<<diff.getSum()<<"\n" ;
    std::cout<<diff.getScore()<<"\n" ;

    return 0;
}
