#include <iostream>
#include <string>
#include <vector>
#include "expand.h"

using namespace std;

int bit_Pi_dashboard = 0;
int bit_weather = 0;
int bit_nextcloud = 0;
int bit_Leanote = 0;

char expand_url[3] = {'u','r','l'};

void print_expand(){
    cout<<"Welcome to use expand"<<endl;
    cout<<"support expand"<<endl;
    cout<<"1.Pi-dashboard"<<endl;
    cout<<"2.Weather.io"<<endl;
    cout<<"3.Nextcloud"<<endl;
    cout<<"4.Leanote"<<endl;
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
        return expand_arr;
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
        return expand_arr;
    }
    for (int i = 0; i < parr.size() - 1; i++){
        if (parr[i] == expand::Next_clond[i]){
            bit_nextcloud = 1;
        }
        else{
            bit_nextcloud = 0;
            break;
        }
    }
    if(bit_nextcloud){
        expand_arr = expand::Nextcloud_function(parr);
        return expand_arr;
    }
    for (int i = 0; i < parr.size() - 1; i++){
        if (parr[i] == expand::LeaNote[i]){
            bit_Leanote = 1;
        }
        else{
            bit_Leanote = 0;
            break;
        }
    }
    if (bit_Leanote){
        expand_arr = expand::Leanote_function(parr);
        return expand_arr;
    }
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

vector <char> expand::Nextcloud_function(vector <char> nextcloud_arr){
    vector <char> nextcloud_parr;
    for (int j = 0; j < 3; j++){
        nextcloud_parr.push_back(expand_url[j]);
    }
    nextcloud_parr.push_back(' ');
    char nextcloud_url[20] = {'h','t','t','p',':','/','/','8','1','.','6','8','.','1','7','5','.','1','8','6'}; 
    for (int j = 0; j < 20; j++){
        nextcloud_parr.push_back(nextcloud_url[j]);
    }
    nextcloud_parr.push_back(' ');
    for (int j = 0; j < nextcloud_arr.size(); j++){
        nextcloud_parr.push_back(nextcloud_arr[j]);
    }
    return nextcloud_parr;
}

vector <char> expand::Leanote_function(vector <char> leanote_arr){
    vector <char> leanote_parr;
    for (int j = 0; j < 3; j++){
        leanote_parr.push_back(expand_url[j]);
    }
    leanote_parr.push_back(' ');
    char leanote_url[25] = {'h','t','t','p',':','/','/','8','1','.','6','8','.','1','7','5','.','1','8','6',
                            ':','9','0','0','0'}; 
    for (int j = 0; j < 25; j++){
        leanote_parr.push_back(leanote_url[j]);
    }
    leanote_parr.push_back(' ');
    for (int j = 0; j < leanote_arr.size(); j++){
        leanote_parr.push_back(leanote_arr[j]);
    }
    return leanote_parr;
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
