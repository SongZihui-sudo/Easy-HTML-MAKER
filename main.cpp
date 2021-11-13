#include<iostream>
#include "Markdown_to_html.h"
#include <fstream>

using namespace std;
//主函数
int main(){
    Welcome();
    ofstream fout;
    Markdown_to_html *MtH; //类
    MtH = new(Markdown_to_html);
    string str;
    cout<<"input file name,like xxxx."<<endl;
    int n;    //页数
    cout<<"page number:";
    cin>>n;
    while( n -- ){
        cout<<"filename:"; //文件名    
        cin>>str;
        if(str == "ps"){
            print_file_struct();//输出目录结构
            continue;
        }       
        string t = ".md";
        string Str;
        Str = str + t;        
        MtH->Conversion(Str,str);//转换
    }
    return 0;
}
//转换函数
int Markdown_to_html::Conversion(string s,string file_name){    
    ifstream  fin;
    ofstream fout;
    s = "md/"+s;
    file_name = chose_file_postion(file_name);
    fout.open(file_name);
    fin.open(s);
    if(fin){ //防止出错
        //对符号的判断
        //进行转换
        char c;
        while ((c = fin.get()) != EOF){
           
       
        } 
        fout<<"</body>"<<endl;
        fout<<"</html>"<<endl;
    }
    else{
        cout<<"cannot open the file";
        return Error; 
    }   
    return 0;
}
