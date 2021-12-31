#include <fstream>
#include <vector>
#include<iostream>
#include "Article_device.hpp"
#include <string>
#include "Command_parser.hpp"

using namespace mth;
using namespace std;
using namespace comper;

int main(int argc, char const *argv[]){
    read_emakefile emk;
    run_build_artical rba;
    Command_parser cper;
    Extension exn;
    string line;
    vector <string> after_input;
    read_out = exn.read_conf_expend();
    while (getline(cin,line))
    {
        int bit = 0;
        after_input = emk.Participle(line);
        cper.Lexical_analysis_of_commands(after_input);
        bit = cper.Syntax_analysis_of_commands();
        switch (bit)
        {
        case 1:
            return 1;
            break;
        case 2:
            rba.Article_device_run();
            break;
        case 3:
            cerr<<"do not find"<<" "<<line<<" !!!"<<endl;
            return -1;
        default:
            break;
        }
        cper.state_machine2.clear();
    }
    return 0;
}
