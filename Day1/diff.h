#ifndef ADVENT_DIFF_H
#define ADVENT_DIFF_H

#include <string>
#include <fstream>
#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <map>

class Diff {
private:
    std::vector<int> firstList;
    std::vector<int> secondList;
    std::vector<int> resultList;
    std::map<int,int> secondMap;

public:
    explicit Diff(std::string &filename){
        readFile(filename);
        doSort();
        doDiff();
        censusRight();
    }

    int getSum(){
        int sum = 0;
        for(auto i:resultList) {
            sum += i;
        }
        return sum;
    }

    int getScore(){
        int score = 0;
        for(auto i: firstList){
            score = score + secondMap[i]*i;
        }
        return score;
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

    void censusRight(){
        int holder;
        for(int val: secondList){
            holder = secondMap[val];
            secondMap[val] = holder + 1;
        }
    }
};

#endif //ADVENT_DIFF_H
