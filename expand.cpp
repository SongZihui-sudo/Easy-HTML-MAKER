#include <iostream>
#include <string>
#include <vector>
#include "expand.h"

using namespace std;

int bit_Pi_dashboard = 0;
int bit_weather = 0;

char expand_url[3] = {'u','r','l'};

void print_expand(){
    cout<<"Welcome to use expand"<<endl;
    cout<<"support expand"<<endl;
    cout<<"1.Pi-dashboard"<<endl;
    cout<<"2.Weather.io"<<endl;
}

vector <char> expand::expand_function(vector <char> expand_arr){
    vector <char> parr;
    for (int j = 8; j < expand_arr.size(); j++){
        parr.push_back(expand_arr[j]);
    }
    for (int i = 0; i < parr.size(); i++){
        if(parr[i] == expand::Pi_dashboard[i]){
            bit_Pi_dashboard = 1;
        }
        else{
            bit_Pi_dashboard = 0;
            break;
        }
    }
    if(bit_Pi_dashboard){
        expand_arr = expand::pi_dashboard_function(parr);
    }
    for (int i = 0; i < parr.size() - 1; i++){
        if (parr[i] == expand::weather[i]){
            bit_weather = 1;
        }
        else{
            bit_weather = 0;
            break;
        }
    }
    if (bit_weather){
        expand_arr = expand::Weather_function(parr);
    }
    return expand_arr;
}
vector <char> expand::pi_dashboard_function(vector <char> pi_arr){
    vector <char> pi_parr;
    pi_parr = expand::make_file(pi_arr);
    pi_parr.push_back('.');pi_parr.push_back('p');
    pi_parr.push_back('h');pi_parr.push_back('p');
    pi_parr.push_back(' ');
    for (int j = 0; j < pi_arr.size() ; j++){
        pi_parr.push_back(pi_arr[j]);
    }
    return pi_parr;
}

vector <char> expand::Weather_function(vector <char> wea_arr){
    vector <char> wea_parr;
    wea_parr = expand::make_file(wea_arr);
    wea_parr.push_back('.');wea_parr.push_back('h');
    wea_parr.push_back('t');wea_parr.push_back('m');
    wea_parr.push_back('l');
    wea_parr.push_back(' ');
    for (int j = 0; j < wea_arr.size() ; j++){
        wea_parr.push_back(wea_arr[j]);
    }
    return wea_parr;
}

vector <char> expand::make_file(vector <char> make){
    vector <char> make_parr;
     for (int j = 0; j < 3; j++){
        make_parr.push_back(expand_url[j]);
    }
    make_parr.push_back(' ');
    for (int j = 0; j < 7; j++){
        make_parr.push_back(expand::expand_[j]);
    }
    for (int j = 0; j < make.size(); j++){
        make_parr.push_back(make[j]);
    }
    make_parr.push_back('/');
    for (int j = 0; j < 5; j++){
        make_parr.push_back(expand::index[j]);
    }
    return make_parr;
}
