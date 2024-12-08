#ifndef FINDER_H
#define FINDER_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

class Finder
{
    std::vector<std::vector<char>> store;
    int count;
public:
    explicit Finder(std::string& fileName): count(0)
    {
        readFile(fileName);
        scanXmas();
    }

    int getCount()
    {
        return count;
    }

private:
    void readFile(std::string& fileName)
    {
        std::ifstream file(fileName.c_str());
        char ch;
        std::vector<char> line;
        while(file.get(ch))
        {
            if(ch == '\n')
            {
                store.push_back(line);
                line.clear();
            }
            else
            {
                line.push_back(ch);
            }
        }
        store.push_back(line);
    }


    void scanXmas()
    {
        for(int y = 0; y < store.size(); ++y)
        {
            for( int x = 0; x < store[x].size(); ++x)
            {
                if(store[y][x] == 'X')
                {
                    scanNeighours(y,x);
                }
            }
        }
    }

    void scanNeighours(int y, int x)
    {
        //back
        if((x-3)>=0 && (store[y][x-1] == 'M') && store[y][x-2] == 'A' && store[y][x-3] == 'S')
        {
            ++count;
        }

        //front
        if((x+3)<store[y].size() && store[y][x+1] == 'M' && store[y][x+2] == 'A' && store[y][x+3] == 'S')
        {
            ++count;
        }

        //up
        if((y-3)>=0 && store[y-1][x] == 'M' && store[y-2][x] == 'A' && store[y-3][x] == 'S')
        {
            ++count;
        }

        //down
        if((y+3)<store.size() && store[y+1][x] == 'M' && store[y+2][x] == 'A' && store[y+3][x] == 'S')
        {
            ++count;
        }

        //upleft
        if((y-3)>=0 && (x-3)>=0 && store[y-1][x-1] == 'M' && store[y-2][x-2] == 'A' && store[y-3][x-3] == 'S')
        {
            ++count;
        }

        //upright
        if((y-3)>=0 && (x+3)<store[y].size() && store[y-1][x+1] == 'M' && store[y-2][x+2] == 'A' && store[y-3][x+3] == 'S')
        {
            ++count;
        }

        //downright
        if((y+3)<store.size() && (x+3)<store[y].size() && store[y+1][x+1] == 'M' && store[y+2][x+2] == 'A' && store[y+3][x+3] == 'S')
        {
            ++count;
        }

        //downleft
        if((y+3)<store.size() && (x-3)>=0 && store[y+1][x-1] == 'M' && store[y+2][x-2] == 'A' && store[y+3][x-3] == 'S')
        {
            ++count;
        }

    }
};
#endif //FINDER_H
