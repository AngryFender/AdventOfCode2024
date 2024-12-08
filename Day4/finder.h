#ifndef FINDER_H
#define FINDER_H
#include <string>
#include <fstream>
#include <vector>

class Finder
{
    std::vector<std::vector<char>> store;
    int count;
    int countAgain;
public:

    explicit Finder(std::string& fileName): count(0), countAgain(0)
    {
        readFile(fileName);
        scan();
    }

    int getXmasCount()
    {
        return count;
    }
    int getMasCount()
    {
        return countAgain;
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


    void scan()
    {
        for(int y = 0; y < store.size(); ++y)
        {
            for( int x = 0; x < store[x].size(); ++x)
            {
                if(store[y][x] == 'X')
                {
                    scanXmas(y,x);
                }

                if(store[y][x] == 'A')
                {
                    scanMas(y,x);
                }
            }
        }
    }

    void scanXmas(int y, int x)
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
    void scanMas(int y, int x)
    {
        bool isX1 = false, isX2 = false;
        //upleft  & downright
        if((y-1)>=0 && (x-1)>=0 && (y+1)<store.size() && (x+1)<store[y+1].size())
        {
            if ((store[y-1][x-1] == 'M' && store[y+1][x+1] == 'S')||(store[y-1][x-1] == 'S' && store[y+1][x+1] == 'M'))
                isX1 = true;
        }

        //downleft & upright
        if((y+1)<store.size() && (x-1)>=0 && (y-1)>=0 && (x+1)<store[y+1].size())
        {
            if ((store[y+1][x-1] == 'M' && store[y-1][x+1] == 'S')||(store[y+1][x-1] == 'S' && store[y-1][x+1] == 'M'))
                isX2 = true;
        }

        if(isX1 && isX2)
        {
            ++countAgain;
        }
    }
};
#endif //FINDER_H
