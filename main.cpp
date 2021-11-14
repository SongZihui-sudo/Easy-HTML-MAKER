#include<iostream>
#include "Markdown_to_html.h"
#include <fstream>
#include <vector>
#include <string>

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
        string md_name;
        md_name = str + t;        
        MtH->Lexical_interpreter(md_name,str);//转换
    }
    return 0;
}
//词法解释器
int Markdown_to_html::Lexical_interpreter(string Md_name,string html_name){ 
    Markdown_to_html *p;   
    p = new(Markdown_to_html);
    Md_name = "md/"+Md_name; //md file postion
    fin.open(Md_name); //open md file
    string html_file_name = chose_file_postion(html_name);
    fout.open(html_file_name);
    if(fin){ 
        char c;
        while ((c = fin.get()) != EOF){
            //每次提取一行到数组中
            if( c == '\n' ){
                //标题标签
                for(int i = 0;i < p->arr.size();i++){
                    if(p->arr[i] == '#'){
                        bit_head++;
                        continue;
                    }
                    else if( p->arr[i] == ' ')
                        break;
                    else{
                        bit_head = 0;
                        break;
                    }
                }
                if(bit_head){
                    p->arr = head(bit_head,p->arr);
                    for( int j = 1;j < p->arr.size();j++){
                        fout<<p->arr[j];
                    }
                    fout<<"\n"<<"<br>";
                    p->arr.clear();
                }
                //图像标签
                for (int i = 0; i < 7; i++){
                    if( p->arr[i] == ')'){
                        p->arr[i] = 48;
                        break;
                    }
                    else if(p->arr[i] == p->Img[i]){
                        p->arr[i] = 48;
                        bit_img = 1;
                    }
                    else{
                        bit_img = 0;
                        break;
                    }
                }
                if(bit_img){
                    p->arr =  p->img(p->arr);
                    for( int j = 1;j < p->arr.size();j++){
                        fout<<p->arr[j];
                    }
                    fout<<"\n"<<"<br>";
                    p->arr.clear();
                }
                //代码块开始标签
                for (int i = 0; i < 3; i++){
                    if (p->arr[i] == p->code_begin[i]){
                        bit_code_begin = 1;
                    }
                    else if(p->arr[i] == '\0')
                        break;
                    else{
                        bit_code_begin = 0;
                        break;
                    }
                }
                if(bit_code_begin){
                    fout<<"<pre>";
                    fout<<"\n"<<"<br>";
                    p->arr.clear();
                }
                //代码块结束标签
                for (int i = 0; i < 3; i++){
                    if (p->arr[i] == p->code_end[i]){
                        bit_code_end = 1;
                    }
                    else{
                        bit_code_end = 0;
                        break;
                    }
                }
                if(bit_code_end){
                    fout<<"</pre>";
                    fout<<"\n"<<"<br>";
                    p->arr.clear();
                }
                //链接标签
                for (int i = 0; i < 3; i++){
                    if (p->arr[i] == p->Url[i]){
                        bit_url = 1;
                    }
                    else if( p->arr[i] == '\0' )
                        break;
                    else{
                        bit_url = 0;
                        break;
                    }
                }
                if(bit_url){
                    p->arr = p->url(p->arr);
                    for( int j = 0;j < p->arr.size();j++){
                        fout<<p->arr[j];
                    }
                    fout<<"\n"<<"<br>";
                    p->arr.clear();
                }
                if(bit_head==0&&bit_img==0&&bit_code_begin==0&&bit_code_end==0&&bit_url==0){
                    for(int j = 0;j < p->arr.size();j++){
                        fout<<p->arr[j];
                    }
                    fout<<"\n"<<"<br>";
                    p->arr.clear();
                }
            }
            //存储链接
            else{
                p->arr.push_back(c);
            }
        }
    }
    else{//error
        cout<<"cannot open the file";
        return Error; 
    }   
    return 0;
}
//处理标题标签
vector <char> Markdown_to_html::head(int number,vector <char> Array){     
        vector <char> parr;
        for (int k = number; k < Array.size(); k++){
            parr.push_back(Array[k]);
        }//暂时存储标题内容
        Array = {0};
        Array.push_back('<');Array.push_back('h');
        Array.push_back(number+48);Array.push_back('>');//生成html标题标签
        for (int k = 0; k < parr.size(); k++){
            Array.push_back(parr[k]);//插入标题内容
        }
        Array.push_back('<');Array.push_back('/');//标签结尾
        Array.push_back('h');Array.push_back(number+48);
        Array.push_back('>');
        return Array;
    }
//处理图像标签
//![img]()
vector <char> Markdown_to_html::img(vector <char> img_arr){
    vector <char> parr;//暂时存储url内容
    char html_img[10] = {'<','i','m','g',' ','s','r','c','=','"'};
    for(int k = 7;k < img_arr.size()-1; k++){
        parr.push_back(img_arr[k]);
    }
    img_arr = {48};
    for( int k = 0;k < 10;k++)
        img_arr.push_back(html_img[k]);
    for (int k = 0; k < parr.size(); k++)
        img_arr.push_back(parr[k]);
    img_arr.push_back('"');img_arr.push_back('/');
    img_arr.push_back('>');    
    return img_arr;
}
//处理链接标签
vector <char> Markdown_to_html::url(vector <char> url_arr){
    vector <char> parr_name;
    vector <char> parr_url;
    int len;
    char html_url[9] = {'<','a',' ','h','r','e','f','=','"'};
    for (int k = 4; k < url_arr.size(); k++){
        if(url_arr[k] == ' '){
            len = k;
            break;
        } 
        else
            parr_url.push_back(url_arr[k]);
    }
    for (int h = len; h < url_arr.size(); h++){
        parr_name.push_back(url_arr[h]);
    }
    url_arr.clear();
    for (int k = 0; k < 9; k++){
        url_arr.push_back(html_url[k]);
    }
    for (int k = 0; k < parr_url.size(); k++){
        url_arr.push_back(parr_url[k]);
    }
    url_arr.push_back('"');url_arr.push_back('>');
    for (int k = 0; k < parr_name.size(); k++){
        url_arr.push_back(parr_name[k]);
    }
    url_arr.push_back('<');url_arr.push_back('/');
    url_arr.push_back('a');url_arr.push_back('>');
    return url_arr;
    }