#include "Markdown_to_html.h"
#include <fstream>
#include <vector>
#include "expand.h"
#include<iostream>

using namespace std;
//主函数
int main(){
    Welcome();
    ofstream fout;
    Markdown_to_html *MtH; //类
    MtH = new(Markdown_to_html);
    cout<<"input file name,like xxxx."<<endl;
    string str;
    cout<<"filename:"; //文件名    
    cin>>str;//名称无后缀
    if(str == "ps"){
        print_file_struct();//输出目录结构
    }       
    string t = ".md"; 
    string md_name; //md文件名称   
    md_name = str + t;        
    MtH->Lexical_interpreter(md_name,str);//转换
    //if you are windows user delete //
    //if you are linux user stay //
    //system("pause");
    return 0;
}
//词法解释器
int Markdown_to_html::Lexical_interpreter(string Md_name,string html_name){ 
    Markdown_to_html *p;   
    p = new(Markdown_to_html);
    Md_name = string("../")+"md/"+Md_name; //md file postion
    fin.open(Md_name); //open md file
    string html_file_name = chose_file_postion(html_name);
    fout.open(html_file_name);
    if(fin){     
        char c;
        while ((c = fin.get()) != EOF){
            //每次提取一行到数组中
            if( c == '\n' ){
                Syntax_interpreter(p->arr);
                p->arr.clear();
                fout<<"<br>"<<"\n";
            }
            else{
                p->arr.push_back(c);
            }
        }
        fout<<"</div>"<<"</body>"<<"</html>";
    }
    else{//error
        cout<<"cannot open the file"<<endl;
        return Error; 
    }   
    free(p);
    return 0;
}
//文法分析器
int Markdown_to_html::Syntax_interpreter(vector <char> Syntax_interpreter_arr){
    expand *e;
    Markdown_to_html *m;
    e = new(expand);
    m = new(Markdown_to_html); 
    vector <char> syntax_Arr;
    if(Syntax_interpreter_arr.empty())
        return 0;
    //标题标签
    for(int i = 0;i < Syntax_interpreter_arr.size();i++){
        if(Syntax_interpreter_arr[i] == '#'){
            bit_head++;
            continue;
        }
        else if( Syntax_interpreter_arr[i] == ' ')
            break;
        else{
            bit_head = 0;
            break;
        }
    }
    if(bit_head){
        fout<<"<h"<<bit_head<<">";
        head_number = bit_head;
        Syntax_interpreter_arr = head(bit_head,Syntax_interpreter_arr);
        for (int j = 0; j < Syntax_interpreter_arr.size(); j++){
            if(Syntax_interpreter_arr[j] == 32){
                len = j + 1;
                break;
            }
        }
        for ( int j = len; j < Syntax_interpreter_arr.size() - 5; j++){
            syntax_Arr.push_back(Syntax_interpreter_arr[j]);
        }
        Syntax_interpreter(syntax_Arr);
        fout<<"</h"<<head_number<<">";
        bit_print = 0;
        bit_head = 0;
        Syntax_interpreter_arr.clear();
        return 0;
    }
    //图像标签
    for (int i = 0; i < 7; i++){ 
        if(Syntax_interpreter_arr[i] == m->Img[i]){
            Syntax_interpreter_arr[i] = 48;
            bit_img = 1;
        }
        else{
            bit_img = 0;
            break;
        }
    }
    if(bit_img){
        Syntax_interpreter_arr =  m->img(Syntax_interpreter_arr);
        for( int j = 1;j < Syntax_interpreter_arr.size();j++){
        fout<<Syntax_interpreter_arr[j];
    }
        bit_img = 0;
        Syntax_interpreter_arr.clear();
        return 0;
    }
    //代码块开始标签
    for (int i = 0; i < 3; i++){
        if (Syntax_interpreter_arr[i] == m->code_begin[i]){
            bit_code_begin = 1;
        }
        else if(Syntax_interpreter_arr[i] == '\0')
            break;
        else{
            bit_code_begin = 0;
            break;
        }
    }
    if(bit_code_begin){
        fout<<"<pre>";
        Syntax_interpreter_arr.clear();
        bit_code_begin = 0;
        return 0;
    }
    //代码块结束标签
    for (int i = 0; i < 3; i++){
        if (Syntax_interpreter_arr[i] == m->code_end[i]){
            bit_code_end = 1;
        }
        else{
            bit_code_end = 0;
            break;
        }
    }
        if(bit_code_end){
            fout<<"</pre>";
            bit_code_end = 0;
            Syntax_interpreter_arr.clear();
            return 0; 
        }
        //链接标签
    for (int i = 0; i < 3; i++){
        if (Syntax_interpreter_arr[i] == m->Url[i]){
            bit_url = 1;
        }
        else if( Syntax_interpreter_arr[i] == '\0' )
            break;
        else{
            bit_url = 0;
            break;
        }
    }
    if(bit_url){
        Syntax_interpreter_arr = m->url(Syntax_interpreter_arr);
        for( int j = 0;j < Syntax_interpreter_arr.size();j++){
            fout<<Syntax_interpreter_arr[j];
        }
        bit_url = 0;
        Syntax_interpreter_arr.clear();
        return 0;
    }
        //处理引用语句
    for (int i = 0; i < 1; i++){
        if( Syntax_interpreter_arr[i] == m->Quote[i]){
            bit_quote = 1;
        }
        else{
            bit_quote = 0;
            break;
        }
    }
    if(bit_quote){
        Syntax_interpreter_arr = m->quote(Syntax_interpreter_arr);
        for (int j = 0; j < Syntax_interpreter_arr.size(); j++){
            fout<<Syntax_interpreter_arr[j];
        }
        bit_quote = 0;
        Syntax_interpreter_arr.clear();
        return 0;
    }
    //处理分割线语句
    for (int i = 0; i < 3; i++){
        if(Syntax_interpreter_arr[i] == m->split_line[i]){
            split_line_bit = 1;
        }
        else{
            split_line_bit = 0;
            break;
        }
    }
    if( split_line_bit ){
        fout<<"<hr>";
        Syntax_interpreter_arr.clear();
        split_line_bit = 0;
        return 0;
    }
    //处理强调语句
    for (int i = 0; i < 2; i++){
        if( Syntax_interpreter_arr[i] == m->Strong[i]){
            strong_bit = 1;
            }
        else{
            strong_bit = 0;
            break;
            }
    }
    if(strong_bit){
        Syntax_interpreter_arr = m->strong(Syntax_interpreter_arr);
        for (int j = 0; j < Syntax_interpreter_arr.size(); j++){
            fout<<Syntax_interpreter_arr[j];
        }
        strong_bit = 0;
        Syntax_interpreter_arr.clear();
        return 0;
    }
    //主题标签
    for (int i = 0; i < 5; i++){
        if(Syntax_interpreter_arr[i] == m->theme_[i])
            bit_theme = 1;
        else{
            bit_theme = 0;
            break;
        }
    }
    if(bit_theme){
        vector <char> Theme_Name;
        for (int j = 7; j < Syntax_interpreter_arr.size(); j++){
            Theme_Name.push_back(Syntax_interpreter_arr[j]);
        }
        chose_theme(Theme_Name);
        bit_theme = 0;
        Syntax_interpreter_arr.clear();
        Theme_Name.clear();
        return 0;
    }
    //拓展标签
    for (int i = 0; i < 7; i++){
        if (Syntax_interpreter_arr[i] == m->expand_[i]){
            expand_bit = 1;
        }
        else{
            expand_bit = 0;
            break;
        }
    }
    if ( expand_bit ){
        Syntax_interpreter_arr = e->expand_function(Syntax_interpreter_arr);
        Syntax_interpreter(Syntax_interpreter_arr);
        return 0;
    }
    //处理普通语句
    if(bit_head==0&&bit_img==0&&bit_code_begin==0&&bit_code_end==0&&bit_url==0){
        m->simple(Syntax_interpreter_arr);
    }
    free(e);
    free(m);
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
        parr.clear();
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
    parr.clear();
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
    parr_name.clear();
    parr_url.clear();
    return url_arr;
    }
//引用标签
vector <char> Markdown_to_html::quote(vector <char> quote_arr){
    vector <char> parr;
    for( int k = 2;k < quote_arr.size() ; k++){
        parr.push_back(quote_arr[k]);
    }
    quote_arr.clear();
    char html_quote_begin[12] = {'<','b','l','o','c','k','q','u','o','t','e','>'};
    char html_quote_end[13] = {'<','/','b','l','o','c','k','q','u','o','t','e','>'};
    for( int g = 0;g < 12;g++)
        quote_arr.push_back(html_quote_begin[g]);
    for (int g = 0; g < parr.size(); g++){
        quote_arr.push_back(parr[g]);
    }
    for (int g = 0; g < 13; g++){
        quote_arr.push_back(html_quote_end[g]);
    }
    parr.clear();
    return quote_arr;
}
//处理强调语句
vector <char> Markdown_to_html::strong(vector <char> strong_arr){
    vector <char> parr;
    for (int k = 3; k < strong_arr.size(); k++){
        parr.push_back(strong_arr[k]);
    }
    strong_arr.clear();
    char html_strong_begin[8] = {'<','s','t','r','o','n','g','>'};
    char html_string_end[9] = {'<','/','s','t','r','o','n','g','>'};
    for (int k = 0; k < 8; k++){
        strong_arr.push_back(html_strong_begin[k]);
    }
    for (int k = 0; k < parr.size(); k++){
        strong_arr.push_back(parr[k]);
    }
    for (int k = 0; k < 9; k++){
        strong_arr.push_back(html_string_end[k]);
    }
    return strong_arr;
}
//处理普通语句
int Markdown_to_html::simple(vector <char> simple_Arr){
    int num_space = 0;
    int not_found = 0;
    long long num = 0;
    char html_Url[3] = {'u','r','l'}; 
    vector <char> parr;
    for(int j = 0;j < 3;){
        if( simple_Arr[num] != html_Url[j] ){
            num +=3;
            if (num > simple_Arr.size()){
                not_found = 0;
                break;
            }
        } 
        else if( simple_Arr[num] == html_Url[j]){
            j++;
            num++;
            not_found = 1;
        }
    }
    if(not_found){
        long long length = 0;
        for ( int k = num - 3; k < simple_Arr.size(); k++){
            if(simple_Arr[k] == ' '){
                parr.push_back(simple_Arr[k]);
                num_space++;
            }
            else if(num_space == 3){
                length = k;
                break;
            }
            else{
                parr.push_back(simple_Arr[k]);
            }
        }
        for (int j = 0; j < num - 4; j++){
            fout<<simple_Arr[j];
        }
        Markdown_to_html::Syntax_interpreter(parr);
        for ( int j = length; j < simple_Arr.size(); j++){
            fout<<simple_Arr[j];
        }
    }
    else{
        for (int j = 0; j < simple_Arr.size(); j++){
            if(simple_Arr[j] == '<'){
                fout<<"&lt";
            }
            else if(simple_Arr[j] == '>'){
                fout<<"&gt";
            }
            else{
                fout<<simple_Arr[j];
            }
        }
    }
    return 0;
}
