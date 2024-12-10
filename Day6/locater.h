#ifndef LOCATER_H
#define LOCATER_H

#include <fstream>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>

class Locater
{

    std::vector<std::vector<char>> _store;
    std::set<std::pair<int,int>> _distinct;
    std::pair<int,int> _pos;
    std::vector<std::pair<int,int>> _direct;

public:
    explicit Locater(const std::string& fileName):_pos({0,0}), _direct({{-1,0},{0,1},{1,0},{0,-1}})
    {
        readFile(fileName);
        locateEnding();
    }

    int getDistinctCount()const
    {
        return _distinct.size();
    }

private:
    void readFile(const std::string& fileName)
    {
        std::ifstream file(fileName.c_str());
        std::string rawLine;
        int y=0, x=0;
        while(file>>rawLine)
        {
            std::vector<char> line;
            for(auto& pixel: rawLine)
            {
                if(pixel == '^')
                    _pos = {y,x};

                line.push_back(pixel);
                ++x;
            }
            _store.emplace_back(std::move(line));
            ++y; x = 0;
        }
    }

    void locateEnding()
    {
        int go = 0;
        _distinct.insert(_pos);
        while(1)
        {
            _pos = {_pos.first +_direct[go].first,_pos.second + _direct[go].second};
            if(_pos.first > (_store.size()-1) || _pos.first < 0 || _pos.second < 0 || _pos.second > (_store[0].size()-1))
            {
                break;
            }

            if(_store[_pos.first][_pos.second] == '#')
            {
                _pos = {_pos.first -_direct[go].first,_pos.second - _direct[go].second};
                go = (go<3)? ++go : 0;
            }
            else
            {
                _distinct.insert(_pos);
            }
        }
    }
};

#endif //LOCATER_H
