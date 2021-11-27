#ifndef _Markdown_to_html_h
#define _Markdown_to_html_h
    #include<iostream>
    #include <fstream>
    #include <vector>
    //宏定义
    #define Error -1;
    #define OK 0;
    using namespace std;
    //文件
    ofstream fout;
    ifstream  fin;
    //状态
    int bit_head = 0;
    int bit_img = 0;
    int bit_code_begin = 0;
    int bit_code_end = 0;
    int bit_url = 0;
    int bit_quote = 0;
    int split_line_bit = 0;
    int strong_bit = 0;
    int bit_theme = 0;
    int len = 0;
    int bit_print = 0;
    int head_number = 0;
    int expand_bit = 0;
    //一些函数
    void Welcome();
    void print_file_struct();
    string chose_file_postion(string file);
    int chose_theme(string theme_name);

    class Markdown_to_html{
        private:
            //标签关键词
            char Img[7]={'!','[','i','m','g',']','('};//图像标签
            char code_begin[3] = {'`','`','`'};//代码块开始标签
            char code_end[3] = {'*','*','*'};//代码块结束标签
            char Url[3] = {'u','r','l'};//链接标签
            char Quote[1] = {'>'}; //引用标签
            char split_line[3] = {'-','-','-'};//分割线标签
            char Strong[2] = {'_','_'};//强调标签
            char theme_[6] = {'#','t','h','e','m','e'};
            char expand_[7] = {'#','e','x','p','a','n','d'};
            //暂时存放一行的数组
            vector <char> arr;
        public:
            Markdown_to_html() = default ;
            int Lexical_interpreter(string Md_name,string html_name); //词法分析器
            int Syntax_interpreter(vector <char> Syntax_interpreter_arr);
            //句法分析
            vector <char> head(int number,vector <char> Array);//处理head标签的方法
            vector <char> img(vector <char> img_arr);//处理img标签的方法
            vector <char> url(vector <char> url_arr);//处理url标签的方法
            vector <char> quote(vector <char> quote_arr);//处理引用标签
            vector <char> strong(vector <char> strong_arr);//处理强调语句
            int simple(vector <char> simple_Arr);//处理普通语句
        };
        
    //欢迎界面
    void Welcome(){
        cout<<"Welcome to use e-Conversion html maker!"<<endl;
        cout<<"You can input and enjoy you write!"<<endl;
        cout<<"EASYTHML-V2.1"<<endl;
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
            file = "../About/" + file + h; //目录ABOUT
            return file;
        }
        else if(f==2){
            file = string("../")+file + h;//目录
            return file;
        }
        else if(f==3){
            file = "../Blog/" + file + h;
            return file; //目录BLOG
        }
        else{
            return "1";
        }
    }
    //选择主题
    int chose_theme(vector <char> theme_name){
        fstream theme_conf;
        theme_conf.open("../conf/theme_list.conf");
        string Name;
        vector <string> theme_list ;
        if (theme_conf){
            while ( getline(theme_conf, Name)){
                theme_list.push_back(Name);
            }
        }
        else{
            cout<<"Can not open file!"<<endl;
            return 0;
        }
        int theme_bit = 0;
        //#theme
        string str_theme(theme_name.begin(), theme_name.end());
        //if you are linux user delete "//"
        //string str_name = str_theme;
        //str_theme = str_theme + string("\r"); 
        //if you windows user 
        for (int i = 1; i < theme_list.size(); i++){
            if (theme_list[i] == str_theme){
                theme_bit = 1;
                break;
            }
            else{
                continue;
            }
        }
        //if you are linux delete "//"
        //str_theme = str_name; 
        //if you are windows
        if(theme_bit){
            ifstream file_in;//切换主题
            file_in.open(string("../")+string("theme/")+str_theme+string(".txt"));
                if(file_in){   
                    char t;
                    while ((t = file_in.get()) != EOF){
                        fout<<t;
                    }        
                }
                else    
                    return 1;
                theme_list.clear();
            return 0;
        }
        else{
            return -1;
        }
    }
#endif
