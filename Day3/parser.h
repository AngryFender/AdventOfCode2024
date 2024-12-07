#ifndef PARSER_H
#define PARSER_H
#include <string>
#include <fstream>
#include <vector>
#include <string_view>
#include <charconv>
class Parser{

    enum State{
      start = 0,
      middle,
      end
    };

    enum Status
    {
      doo = 0,
      dont
    };

    std::string data;
    std::vector<std::pair<int,int>> pairs;

  public:
    explicit Parser(std::string& fileName){
      readFile(fileName);
      parseData();
    }

    long long getSumMult()
    {
        long long sum = 0;
        for(auto& pair: pairs)
        {
            sum += static_cast<long long>(pair.first) * static_cast<long long>(pair.second);
        }
        return sum;
    }
  private:
    void readFile(std::string& fileName){
        std::ifstream file(fileName.c_str());
        std::string line;
        while(file>>line)
        {
            data = data+line;
        };
    }

    void parseData(){
        State state = State::start;
        Status status = Status::doo;
        int win_start = 0;
        int num1_start = 0, num1_end=0;
        int num2_start = 0, num2_end=0;

        std::string_view view(data);

        while(win_start<data.length()){
            switch(state){
                case start: {
                    if((win_start+4) < data.length() && view.substr(win_start, 4)=="do()")
                    {
                        status = Status::doo;
                        win_start+=4;
                    }
                    if((win_start+7) < data.length() && view.substr(win_start, 7)=="don't()")
                    {
                        status = Status::dont;
                        win_start+=7;
                    }
                    if((win_start+4) < data.length() && view.substr(win_start, 4)=="mul("){
                        state = middle;
                        num1_start = win_start + 4;
                        win_start+=5;
                        continue;
                    }break;
                }
                case middle:{
                    if((win_start-num1_start) > 3)
                    {
                        state = start;
                        continue;
                    }
                    if(view.substr(win_start, 1)==","){
                        state = end;
                        num1_end = win_start;
                        num2_start = win_start+1;
                    }break;
                }
                case end:{
                    if((win_start-num2_start) > 3){
                        state = start;
                        continue;
                    }
                    if(view.substr(win_start, 1)==")"){
                        state = start;
                        num2_end = win_start;

                        if(status == Status::doo)
                        {
                            std::string_view first_view = view.substr(num1_start,num1_end-num1_start);
                            std::string_view second_view = view.substr(num2_start,num2_end-num2_start);
                            int first, second;
                            auto result1 = std::from_chars(first_view.data(), first_view.data()+ first_view.size(),first, 10);
                            auto result2 = std::from_chars(second_view.data(), second_view.data()+ second_view.size(),second, 10);

                            if(result1.ec == std::errc() && result2.ec == std::errc())
                            {
                                pairs.push_back(std::pair<int,int>(first,second));
                            }
                        }
                    }break;
                }
            }
            ++win_start;
        }
    }
};



#endif //PARSER_H
