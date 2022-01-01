#include <fstream>
#include <vector>
#include<iostream>
#include "Article_device.hpp"
#include <string>
#include "Command_parser.hpp"
#include "Module_manager.hpp"
#include <deque>
#include "easyhtmleditor.hpp"

using namespace mth;
using namespace std;
using namespace comper;

int main(int argc, char const *argv[]){
    deque <string> module;
    read_emakefile emk;
    run_build_artical rba;
    Command_parser cper;
    Extension exn;
    Moudule_manager moumer;
    string line;
    vector <string> after_input;
    read_out = exn.read_conf_expend();
    module = moumer.readout_modellist();
    for (int i = 1; i < module.size(); i++){
        if (module[i] == "switch"){
            if (module[i+1] == "ON"){
                continue;
            }
            else{
                return 1;
            }
        }
        else if (module[i] == "Editor" && module[i+1] == "ON"){
            cout<<"Easy Html Editor"<<endl;
        }
        else if(module[i] == "Command_parser" && module[i+1] == "ON"){
            while (getline(cin,line)){
                int bit = 0;
                after_input = emk.Participle(line);
                cper.Lexical_analysis_of_commands(after_input);
                bit = cper.Syntax_analysis_of_commands();
                switch (bit)
                {
                    case 1:
                        return 1;
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
        }
        else
        {
            cerr<<"ERROR!!!"<<endl;
            return -1;
        }   
    }
    
    
    return 0;
}
