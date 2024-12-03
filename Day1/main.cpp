#include <iostream>
#include <string>
#include <linux/limits.h>

#include "diff.h"

int main() {
    std::cout << "Starting Day 1" << std::endl;
    std::string data_path = std::getenv("ADVENT_DATA_PATH");
    std::string data_file = data_path + std::string(PATH_SYMBOL) + "day1.txt";

    Diff diff(data_file);
    std::cout<<diff.getSum()<<"\n" ;
    std::cout<<diff.getScore()<<"\n" ;

    return 0;
}
