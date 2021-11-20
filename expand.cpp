#include <iostream>
#include <string>
#include <vector>
#include "expand.h"

using namespace std;

int bit_Pi_dashboard = 0;

void print_expand(){
    cout<<"Welcome to use expand"<<endl;
    cout<<"support expand"<<endl;
    cout<<"1.Pi-dashboard"<<endl;
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
    expand_arr.clear();
    if(bit_Pi_dashboard){
        expand_arr = expand::pi_dashboard_function(parr);
    }
    return expand_arr;
}
vector <char> expand::pi_dashboard_function(vector <char> pi_arr){
    vector <char> pi_parr;
    char expand_url[3] = {'u','r','l'};
    for (int j = 0; j < 3; j++){
        pi_parr.push_back(expand_url[j]);
    }
    pi_parr.push_back(' ');
    for (size_t j = 0; j < 7; j++){
        pi_parr.push_back(expand::expand_[j]);
    }
    for (int j = 0; j < pi_arr.size()-1; j++){
        pi_parr.push_back(pi_arr[j]);
    }
    pi_parr.push_back('/');
    for (int j = 0; j < 5; j++){
        pi_parr.push_back(expand::index[j]);
    }
    pi_parr.push_back('.');pi_parr.push_back('p');
    pi_parr.push_back('h');pi_parr.push_back('p');
    pi_parr.push_back(' ');
    for (int j = 0; j < pi_arr.size() ; j++){
        pi_parr.push_back(pi_arr[j]);
    }
    return pi_parr;
}
