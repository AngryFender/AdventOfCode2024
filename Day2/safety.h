#ifndef SAFETY_H
#define SAFETY_H
#include <algorithm>
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

    void checkSafety()
    {
        for(const auto& line: store)
        {
            if(checkLine(*line)){
                ++safeCount;
            }
            else
            {
                 if(tolerateLine(*line))
                 {
                     ++safeCount;
                 }
            }

        }
    }

    bool checkLine(const std::vector<int>& line)
    {
        bool ascending = line.at(0) < line.at(1);
        int prev = 0,curr = 0,diff = 0;

        for(int i=1; i < line.size(); ++i )
        {
            prev = line.at(i-1);
            curr = line.at(i);
            diff = (ascending)?(curr-prev):(prev-curr);
            if(!(1 <= diff && diff <=3))
            {
                return false;
            }
        }
        return true;
    }

    bool tolerateLine(const std::vector<int>& line)
    {
        for(int i = 0; i < line.size(); ++ i )
        {
            std::vector<int> badLine = line;
            badLine.erase(badLine.begin()+i);
            if(checkLine(badLine))
            {
                return true;
            }
        }
        return false;
    }
};

#endif //SAFETY_H
