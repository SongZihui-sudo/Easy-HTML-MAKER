#include<iostream>
#include "Markdown_to_html.h"
#include <fstream>

using namespace std;

int main(){
    Welcome();
    ofstream fout;
    Markdown_to_html *MtH;
    MtH = new(Markdown_to_html);
    string str;
    cout<<"input file name,like xxxx."<<endl;
    int n;    
    cout<<"page number:";
    cin>>n;
    while( n -- ){
         cout<<"filename:";
        cin>>str;
        string t = ".md";
        string Str;
        Str = str + t;        
        MtH->Conversion(Str,str);
    }
    return 0;
}

int Markdown_to_html::Conversion(string s,string file_name){    
    ifstream  fin;
    ofstream fout;
    string h = ".html";
    file_name = file_name + h;
    fout.open(file_name);
    fin.open(s);
    if(fin){ //防止出错
        int bit = 0;
        int b = 0;
        char c;
        int code_bit = 0;
        fout<<"<!DOCTYPE html>"<<endl;
        fout<<"<html lang=\"en\">"<<endl;
        fout<<"<head>"<<endl;
        fout<<"<meta charset=\"UTF-8\">"<<endl;
        fout<<"<meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\">"<<endl;
        fout<<"<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">"<<endl;
        fout<<" <title>S-zh.space</title>"<<endl;
        fout<<"<style>body {background-color: #dea829;}</style>";
        fout<<"</head>"<<endl;
        fout<<"<body>"<<endl;
        int v = 0;
        while ((c = fin.get()) != EOF){
            if( c == tap00){
                bit++;
                b = 1;
            }
            else if ( bit && c == 32){
                fout<<"<"<<"h"<<bit<<">";
                v = 1;
            }
            else if (b && c == '\n' && v){
                fout<<"</h"<<bit<<">";
                b = 0;
                bit = 0;
                fout<<"\n";
            }
            else if( c == '!' && b == 0){
                bit++;
                b++;
            }
            else if( c == '[' && code_bit == 0){
                fout<<"<";
            }
            else if( bit && c == '(')
                continue;
            else if( bit && c == ')'){
                bit = 0;
                fout<<"\" />";
            }
            else if( bit && c == ']'){
                fout<<" src=\"";
                b = 0;
            }
            else if( c == '\n'){
                fout<<"\n";
                fout<<"<br>";
            }
            else if( bit == 0 && c == '[' && code_bit == 0 ){
                fout<<"<a href=\"";
                bit++;
            } 
            else if( code_bit == 2 && c == '`'){
                fout<<"<pre>";
                code_bit++;
            }  
            else if( code_bit == 3 && c== '<')
                    fout<<"&#60";
            else if( code_bit == 3 && c == '>')
                    fout<<"&#62";
            else if( code_bit == 3  && c == '`'){
                fout<<"</pre>";
                code_bit++;
            }
            else if( code_bit == 6)
                code_bit = 0;
            else if ( c == '`'){
                code_bit++;
            }    
           
            else{
                fout << c;
            }            
                
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
