#ifndef _Markdown_to_html_h
#define _Markdown_to_html_h
    #include<iostream>
    #include <fstream>
    #include <vector>
    
    #define Error -1;
    #define OK 0;

    using namespace std;

    ofstream fout;
    ifstream  fin;

    int bit_head = 0;
    int bit_img = 0;
    int bit_code_begin = 0;
    int bit_code_end = 0;
    int bit_url = 0;
    
    void Welcome();
    void print_file_struct();
    string chose_file_postion(string file);
    int chose_theme();

    class Markdown_to_html{
        private:
            char Img[7]={'!','[','i','m','g',']','('};
            char code_begin[3] = {'`','`','`'};
            char code_end[3] = {'*','*','*'};
            char Url[3] = {'u','r','l'};               
            vector <char> arr;
        public:
            Markdown_to_html() = default ;
            int Lexical_interpreter(string Md_name,string html_name); 
            vector <char> head(int number,vector <char> Array);//处理head标签的方法
            vector <char> img(vector <char> img_arr);//处理img标签的方法
            vector <char> url(vector <char> url_arr);//处理url标签的方法
            int simple_Statement();//处理普通语句
        };
    int Markdown_to_html::simple_Statement(){
        return 0;
    }
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
        cout<<"————"<<"theme: wensite's theme"<<endl;
        cout<<"|"<<endl;
        cout<<"————"<<"md: markdown file "<<endl;
    }
    //选择存储目录
    string chose_file_postion(string file){
        string h = ".html";
        cout<<"chose the file postion,About---1,index----2,Blog----3:";
        int f;
        cin>>f;
        if (f==1){
            file = "About/" + file + h;
            return file;
        }
        else if(f==2){
            file = file + h;
            return file;
        }
        else if(f==3){
            file = "Blog/" + file + h;
            return file;
        }
    else{

        return "1";
    }
    }
    //选择主题
    int chose_theme(){
        cout<<"chose the theme you like:";
        string theme_name;
        cin>>theme_name;
        theme_name = "theme/"+theme_name+".txt";
        ifstream file_in;//切换主题
        file_in.open(theme_name);
            if(file_in){   
                char t;
                while ((t = file_in.get()) != EOF){
                    fout<<t;
                }
            }
            else    
                return 1;
        return 0;
    }
#endif
