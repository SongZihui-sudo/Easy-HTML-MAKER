#include <iostream>
#include "expand.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <vector>

using namespace std;

vector <char> expand::expand_function(vector <char> expand_arr){
    int expand_bit = 0;
    vector <string> expand_list;
    int expand_conf;
    expand_conf = open("../conf/expand_list.conf",O_RDONLY|O_CREAT);
    string Name;
    if (expand_conf == -1 ){ 
        cout<<"can not open the expand file!!!"<<endl;
        expand_arr.clear();
        return expand_arr;
    }
    else{
        vector <char> buffer;
        char buf[1];
        while (read(expand_conf,buf,1)){ //read the file
            if (buf[0] == '\n'){
                string str_expand_name(buffer.begin(),buffer.end());
                expand_list.push_back(str_expand_name);
                buffer.clear();
                continue;
            }
            else{
                buffer.push_back(buf[0]);
            }
        }           
    }
    int space_pation;
    vector <string> expand_name;
    vector <string> expand_url;
    for (int i = 1; i < expand_list.size(); i++){
        for (int j = 0; j < expand_list[i].size(); j++){
            if (expand_list[i][j] == ' '){
                space_pation = j;
                break; 
            }
            else{
                continue;
            }
        }
        expand_name.push_back(expand_list[i].substr(0,space_pation));
        int n = space_pation + 1;
        expand_url.push_back(expand_list[i].substr(n,expand_list[i].size()));
        space_pation = 0;
    }
    vector <char> parr;
    for (int i = 0; i < expand_arr.size(); i++){
        if (expand_arr[i] == ' '){
            space_pation = i;
            break;
        }
        else{
            continue;
        }
    }
    for (int i = space_pation+1; i < expand_arr.size(); i++){
        parr.push_back(expand_arr[i]);
    }
    space_pation = 0;
    int expand_name_postion;
    string str_expand(parr.begin(), parr.end());
    for (int i = 0; i < expand_name.size(); i++){
        if (expand_name[i] == str_expand){
            expand_bit = 1;
            expand_name_postion = i;
            break;
        }
        else{
            continue;
            expand_bit = 0;
        }
    }    
    expand_arr.clear();
    string Expand;
    if (expand_bit){
        Expand = string("url ") + expand_url[expand_name_postion] + string(" ")+ expand_name[expand_name_postion];
        for (int i = 0; i < Expand.size(); i++){
            expand_arr.push_back(Expand[i]);
        }
    }
    return expand_arr;
}

