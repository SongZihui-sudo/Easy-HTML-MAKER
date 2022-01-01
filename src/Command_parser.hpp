#ifndef _Command_parser_hpp
#define _Command_parser_hpp

#include <fstream>
#include <deque>
#include<iostream>
#include <string>

using namespace std;

namespace comper{

class Command_parser
{

private:
    int bit = 0;
    string keyword[3] = {"quit","emake","eim"};
public:        
    deque <int> state_machine2;
    int Lexical_analysis_of_commands(vector <string> ready_todo){
        for (int i = 0; i < sizeof(keyword)/sizeof(keyword[0]); i++){
            if (keyword[i] == ready_todo[0])
            {
                state_machine2.push_back(i);
            }
        }
        ready_todo.erase(ready_todo.begin());
        if (ready_todo.begin() == ready_todo.end())
        {
            return -2;   
        }
        else
            Lexical_analysis_of_commands(ready_todo);
        return 2;
    }
    int Syntax_analysis_of_commands(){
        int bit = state_machine2[0];
        bit++;
        switch (bit)
        {
        case 1:
            return 1;
        case 2:
            return 2;
        case 3:
            return 3;
        default:
            return -1;
            break;
        }
        state_machine2.erase(state_machine2.begin());
        if (state_machine2.begin() == state_machine2.end())
        {
            return 0;
        }
        Syntax_analysis_of_commands();
        return 0;
    } 
    Command_parser();
    ~Command_parser();
};

Command_parser::Command_parser()
{
}

Command_parser::~Command_parser()
{
}

};

#endif
