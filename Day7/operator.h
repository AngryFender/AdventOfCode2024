#ifndef OPERATOR_H
#define OPERATOR_H
#include <string>
#include <fstream>
#include <vector>
class Operator{

std::vector<long long> _values;
std::vector<std::vector<int>> _lines;
long long _safeSum;

public:
    explicit Operator(std::string& fileName):_safeSum(0){
        readFile(fileName);
        checkAll();
    }

    long long getSafeSum(){
        return _safeSum;
    }

private:
    void readFile(std::string& fileName){
        std::ifstream file(fileName.c_str());
        std::string rawLine;
        while(std::getline(file,rawLine))
        {
            std::vector<int> intLine;
            std::string str;
            for(auto& ch: rawLine)
            {
                switch (ch)
                {
                case ':':
                    _values.push_back(std::stoll(str));
                    str = "";
                    break;
                case ' ':
                    if (!str.empty())
                    {
                        intLine.push_back(std::stoi(str));
                        str = "";
                    }
                    break;
                default: str += ch;
                }
            }
            intLine.push_back(std::stoi(str));
            _lines.emplace_back(intLine);
        }
    }

    void checkAll()
    {
        for(int i = 0; i < _lines.size(); ++i )
        {
            _safeSum = checkLine(_values[i], (long long)_lines[i][0],1,_lines[i])? _safeSum+_values[i]: _safeSum;
        }
    }

    bool checkLine(const long long& value, long long result, int index, const std::vector<int>& line)
    {
        if(result > value)
        {
            return false;
        }

        if(index >= (line.size()))
        {
            return value == result;
        }

        if(checkLine(value, result + (long long) line[index], index+1, line))
        {
            return true;
        }

        if(checkLine(value, result * (long long) line[index], index+1, line))
        {
            return true;
        }

        return false;
    }

};

#endif //OPERATOR_H
