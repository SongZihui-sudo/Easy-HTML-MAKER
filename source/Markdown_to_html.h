#ifndef _Markdown_to_html_h
#define _Markdown_to_html_h
    #include<iostream>

    #define Error -1;
    #define OK 0;

    using namespace std;

    void Welcome();
    
    class Markdown_to_html{
        private:
            char tap00 = '#';
            char tap01 = '!';
            char tap02 = '*';
            char tap03 = '`';
            char tap04 = '[';  
        public:
            Markdown_to_html() = default ;
            int Conversion(string str,string file_name);
        };
    
    void Welcome(){
        cout<<"Welcome to use e-Conversion html maker!"<<endl;
        cout<<"You can input and enjoy you write!"<<endl;
    }


#endif
