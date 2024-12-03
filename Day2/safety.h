#ifndef SAFETY_H
#define SAFETY_H
#include <algorithm>
#include <array>
#include <fstream>
#include <sstream>
#include <memory>
#include <vector>

class Safety
{
private:
    std::vector<std::unique_ptr<std::vector<int>>> store;
    int safeCount;
public:
    Safety(const std::string &fileName): safeCount(0)
    {
        readFile(fileName);
        checkSafety();
    }

    int getSafeCount()
    {
        return safeCount;
    }
private:
    void readFile(const std::string& fileName)
    {
        std::ifstream file(fileName.c_str());
        std::string line;
        while(std::getline(file,line))
        {
            std::istringstream iss(line);
            int val;
            auto vals = std::make_unique<std::vector<int>>();
            while(iss>>val)
            {
                vals->push_back(val);
            }
            store.push_back(std::move(vals));
        }
       file.close();
    }

    void printAll()
    {
        for (const auto& line: store)
        {
            for(int val: *line)
            {
                std::cout<<val<<" ";
            }
            std::cout<<"\n";
        }
    }

    void checkSafety()
    {
        for(const auto& line: store)
        {
            bool safe = true;
            if(line->at(0) > line->at(1))
            {
                //descending
                if(!checkDiff(3, line))
                {
                    safe = false;
                }
            }
            else if (line->at(0)< line->at(1))
            {
                //ascending
                if(!checkDiff(-3,line))
                {
                    safe = false;
                }
            }
            else
            {
                safe = false;
            }


            if(safe)
            {
                ++safeCount;
            }
        }
    }

    bool checkDiff(int max, const std::unique_ptr<std::vector<int>>& line)
    {
        int prev = 0;
        for(auto num: *line)
        {
            if(prev == 0)
            {
                prev = num;
                continue;
            }

            if((prev - num)>max)
            {
                return false;
            }
            prev = num;
        }
        return true;
    }

};

#endif //SAFETY_H
