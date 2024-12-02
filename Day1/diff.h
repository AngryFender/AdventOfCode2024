#ifndef ADVENT_DIFF_H
#define ADVENT_DIFF_H

#include <string>
#include <fstream>
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

class Diff {
private:
    std::vector<int> firstList;
    std::vector<int> secondList;
    std::vector<int> resultList;

public:
    explicit Diff(std::string &filename){
        readFile(filename);
        doSort();
        doDiff();
    }

    int getSum(){
        int sum = 0;
        for(auto i:resultList) {
            sum += i;
        }
        return sum;
    }
private:

    void readFile(std::string &fileName){
        std::ifstream file(fileName.c_str());

        int first,second;
        while(file>>first>>second){
            firstList.push_back(first);
            secondList.push_back(second);
        }

    }

    void doSort(){
        std::sort(firstList.begin(),firstList.end());
        std::sort(secondList.begin(),secondList.end());
    }

    void doDiff(){
        if(firstList.size()!= secondList.size()){
            return;
        }

        for (int i = 0; i < firstList.size(); ++i){
            resultList.push_back(std::abs(firstList[i]-secondList[i]));
        }
    }
};

#endif //ADVENT_DIFF_H
