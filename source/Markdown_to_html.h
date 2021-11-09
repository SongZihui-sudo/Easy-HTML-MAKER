#ifndef _Markdown_to_html_h
#define _Markdown_to_html_h
    #include<iostream>
    #include <fstream>

    #define Error -1;
    #define OK 0;

    using namespace std;

    int bit = 0;
    int b = 0;
    int code_bit = 0;
    ofstream fout;
    int v = 0;

    bool tape( char cc );   
    bool img( char Cc);
    bool code(char cC);

    void Welcome();
    void print_file_struct();

    class Markdown_to_html{
        private:
            char tap00 = '#';
            char tap01 = '!';
            char tap02 = '*';
            char tap03 = '`';//符号
            char tap04 = '[';  
        public:
            Markdown_to_html() = default ;
            int Conversion(string str,string file_name);
        };
    //欢迎界面
    void Welcome(){
        cout<<"Welcome to use e-Conversion html maker!"<<endl;
        cout<<"You can input and enjoy you write!"<<endl;
    }
    //输出目录结构
    void print_file_struct(){
        cout<<"e-htmlmaker"<<endl;
        cout<<"|"<<endl;
        cout<<"————"<<"Blog:"<<"you content"<<endl;
        cout<<"|"<<endl;
        cout<<"————"<<"About: about youself "<<endl;
        cout<<"|"<<endl;
        cout<<"————"<<"index: wensite's index html"<<endl;
        cout<<"|"<<endl;
        cout<<"————"<<": wensite's "<<endl;
    }

#endif
