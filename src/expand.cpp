#include <iostream>
#include <string>
#include <vector>
#include "expand.h"
#include <fstream>

using namespace std;

vector <char> expand::expand_function(vector <char> expand_arr){
    int expand_bit = 0;
    vector <string> expand_list;
    fstream expand_conf;
    expand_conf.open("../expand_list.conf");
    string Name;
    if (expand_conf){
        char e;
        while (getline(expand_conf,Name)){
            expand_list.push_back(Name);
        }
    }
    else{
        cout<<"can not open the file!!!"<<endl;
        expand_arr.clear();
        return expand_arr;
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
