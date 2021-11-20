#ifndef _expand_h
#define _expand_h
    #include <iostream>
    #include <vector>

    using namespace std;

    class expand{
    private:
        /* data */
        char expand_[7]= {'e','x','p','a','n','d','/'};
        char index[5] = {'i','n','d','e','x'};
        char Pi_dashboard[12] = {'p','i','-','d','a','s','h','b','o','a','r','d'};
    public:
        expand() = default;  
        vector <char> expand_function(vector <char> expand_arr); //拓展名处理
        vector <char> pi_dashboard_function(vector <char> pi_arr);
    };
    void print_expand();
#endif