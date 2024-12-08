#ifndef ARRANGER_H
#define ARRANGER_H
#include <string>
#include <fstream>
#include <memory>
#include <unordered_map>
#include <vector>


class Arranger{
    std::unordered_map<std::string,std::string> store;
    std::vector<std::vector<std::string>> lines;
    std::vector<std::vector<std::string>> passed;
    int middleSum;
public:
    explicit Arranger(std::string& fileName):middleSum(0)
    {
        readFile(fileName);
        validateLines();
    }

    int getMiddleSum()
    {
       return middleSum;
    }

private:


    void readFile(std::string& fileName){
        std::ifstream file(fileName.c_str());
        std::string line = "not a test", first, second, value, digit;
        while(file>>line)
        {
            first.clear();
            second.clear();

            if(line[2]=='|')
            {
                first.append({line[0], line[1]});
                second.append({line[3], line[4]});
                value = store[first] + ',' + second;
                store[first] = value;
            }
            else
            {
                std::vector<std::string> testLine;
                digit.clear();

                for(auto& ch: line)
                {
                    if(ch == ',')
                    {
                        testLine.push_back(digit);
                        digit.clear();
                    }
                    else
                    {
                        digit+=ch;
                    }
                }

                testLine.push_back(digit);
                lines.emplace_back(std::move(testLine));
            }
        }
    }

    void validateLines()
    {
        bool valid = true;

        for(auto& line: lines)
        {
            valid = true;
            for(int i = 1; i<line.size(); ++i)
            {
                for(int j = 0; j<i; ++j)
                {
                    std::string& key = line[i];
                    std::string& value = line[j];
                    std::string& rules = store[key];

                    if( rules.find(value) != std::string::npos)
                    {
                        valid = false;
                        break;
                    }
                }
            }
            if(valid)
            {
                passed.push_back(line);
                middleSum += std::stoi(line[(line.size()-1)/2]);
            }
        }
    }
};

#endif //ARRANGER_H
