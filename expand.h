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
        char Pi_dashboard[13] = {'p','i','-','d','a','s','h','b','o','a','r','d',' '};
        char weather[10] = {'W','e','a','t','h','e','r','.','i','o'};
        char Next_clond[10] = {'n','e','x','t','c','l','o','u','n','d'}; 
        char LeaNote[7] = {'l','e','a','n','o','t','e'};
    public:
        vector <char> make_file(vector <char> make);
        expand() = default;  
        vector <char> expand_function(vector <char> expand_arr); //拓展名处理
        vector <char> pi_dashboard_function(vector <char> pi_arr);
        vector <char> Weather_function(vector <char> wea_arr);
        vector <char> Leanote_function(vector <char> leanote_arr);
        vector <char> Nextcloud_function(vector <char> nextcloud_arr);
    };
    void print_expand();
#endif
