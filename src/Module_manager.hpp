#ifndef Module_manager_hpp
#define Module_manager_hpp

#include <iostream>
#include <deque>
#include <string>
#include <fstream>

using namespace std;

class Moudule_manager
{
private:
    fstream read_modle;
public:
    Moudule_manager(/* args */) = default;
    ~Moudule_manager() = default;
    deque <string> readout_modellist(){
        deque <string> save_modlelist;
        read_modle.open("../Module_seting.conf");
        if (read_modle){
            string line;
            while (getline(read_modle,line))
            {
                save_modlelist.push_back(line);
            }
        }
        else{
            cerr<<"can not out the file!!!"<<endl;
        }
        return save_modlelist;
    }
};

#endif