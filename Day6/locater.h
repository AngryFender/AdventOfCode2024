#ifndef LOCATER_H
#define LOCATER_H

#include <fstream>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>

class Locater
{

    std::vector<std::vector<char>> _store;
    std::set<std::pair<int,int>> _distinct;
    std::pair<int,int> _pos;
    std::pair<int,int> _firstPos;
    std::vector<std::pair<int,int>> _direct;
    std::map<std::pair<int,int>,int> _nodes;
    int _loopSum;

public:
    explicit Locater(const std::string& fileName):
    _pos({0,0}),
    _direct({{-1,0},{0,1},{1,0},{0,-1}}),
    _loopSum(0)
    {
        readFile(fileName);
        locateEnding();
        findLoop();
    }

    int getDistinctCount()
    {
        return _distinct.size()+1;
    }

    int getLoopSum()const
    {
        return _loopSum;
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
        _firstPos = _pos;
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

    void findLoop()
    {
        _distinct.erase({_firstPos.first-1, _firstPos.second});

        for(const auto& prob: _distinct)
        {
            _store[prob.first][prob.second] = '#';

            int go = 0;
            _pos = _firstPos;
            _nodes.clear() ;

            while(1)
            {
                _pos = {_pos.first +_direct[go].first,_pos.second + _direct[go].second};
                if(_pos.first > (_store.size()-1) || _pos.first < 0 || _pos.second < 0 || _pos.second > (_store[0].size()-1))
                {
                    _store[prob.first][prob.second] = '.';
                    break;
                }

                if(_store[_pos.first][_pos.second] == '#')
                {
                    if(++_nodes[{_pos.first,_pos.second}]>3)
                    {
                        ++_loopSum;
                        _store[prob.first][prob.second] = '.';
                        break;
                    }
                    _pos = {_pos.first -_direct[go].first,_pos.second - _direct[go].second};
                    go = (go<3)? ++go : 0;
                }
            }
        }
    }
};

#endif //LOCATER_H
