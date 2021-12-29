#ifndef _tohtml_hpp
#define _tohtml_hpp

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <io.h>
#include <istream>

using namespace std;

class tohtml;
class read_emakefile;
class Extension;

string save_path;
string expand_name;
string expand_State;
string theme_path;
string md_path;

int save_path_state = 0;

ofstream toh;

typedef struct Symbol_table
{
    string name;
    string value;
    Symbol_table *next;
}Symbol_table;

typedef struct strock_int
{
    vector <int> int_arr;
}strock_int;

typedef struct strock_string
{
    vector <string> string_arr;
}strock_string;

vector <Symbol_table> table1;

class read_emakefile
{
private:
    //关键字
    string keyword0 = "#INPUTFILE";
    string keyword1 = "#OUTPUTFILE";
    string keyword2 = "#THEME";
    string keyword3 = "#EXPAND";
    string keyword4 = "var";//定义字符串
    string keyword5 = "int";//定义数字变量
    string keyword6 = "for";
    string keyword7 = "static";
    string keyword8 = "++";
    //栈 存单个变量
    vector <Symbol_table> Variable_stack;
    //栈 存储 字符串或者数字数组
    vector <strock_string> Variable_stack_string_arr;
    vector <strock_int> Variable_stack_int_arr;
    //友类
    friend tohtml;
    friend Extension;
    string finding;
   //按照空格划分语句
   public:
    vector <string> Participle(vector <string> input_file) 
    {
		string space = " ";
		vector <string> Participle_file;
        for (int i = 0; i < input_file.size(); i++)
        {		
            char* s = new char[input_file[i].size() + 1];
            strcpy(s, input_file[i].c_str());
            char* p = strtok(s, " ");
            while(p) 
            {
	            Participle_file.push_back(p);
	            p = strtok(NULL, " ");
            }
        }
		return Participle_file;
    }
    //分词重载
    vector <string> Participle(string input_string) 
    {
		string space = " ";
        char* s = new char[input_string.size() + 1];
        strcpy(s, input_string.c_str());
        char* p = strtok(s, " ");
        vector <string> Participle_file;
        while(p) 
        {
            Participle_file.push_back(p);
	        p = strtok(NULL, " ");
        }
		return Participle_file;
    }
    vector <string> readout_emakefile()
    {
        fstream emakefileout;            
        vector <string> save_data;
        emakefileout.open("../EmakeFile");
        if (emakefileout)
        {
            string line;
            while (getline(emakefileout,line))
            {
                save_data = Participle(line);
                E_make_lexicalandgrammer_analysis(save_data);
                save_data.clear();
            }
        }
        else
        {
            cerr<<"can not open the file!!!"<<endl;
        }
        save_data = Participle(save_data);
        return save_data;
    }

    //Emakefile文件的词法分析
    int E_make_lexicalandgrammer_analysis(vector <string> ready_to_make){
        string name;
        Symbol_table *next;
        Symbol_table *head;
        Symbol_table *node;
        for (int i = 0; i < ready_to_make.size(); i+=2)
        {
            //先去掉注释语句
            if (ready_to_make[i] == "//")
            {
                continue; 
            }
            else if(ready_to_make[i] == keyword0||ready_to_make[i] == keyword1||ready_to_make[i]==keyword2||ready_to_make[i]==keyword3||ready_to_make[i]==keyword4||ready_to_make[i]==keyword5||ready_to_make[i]==keyword6||ready_to_make[i]==keyword7)
            {        
                head = new Symbol_table();
                head->name = ready_to_make[i];
                head->value = ready_to_make[i+1];  
                head->next = next;
                next = head;            
            }
            else
            {
                break;
            }
        }
        for (int i = 0; i < ready_to_make.size(); i++)
        {
            if (ready_to_make[0] == keyword0)
            {
                for (int i = 0; i < Variable_stack.size(); i++)
                {
                    if (finding == Variable_stack[i].name)
                    {
                        md_path = Variable_stack[i].value;
                        break;
                    }
                    else;
                }
            }
            else if (ready_to_make[0] == keyword1)
            {
                for (int i = 0; i < Variable_stack.size(); i++)
                {
                    if (finding == Variable_stack[i].name)
                    {
                        save_path = Variable_stack[i].value;    
                        break;
                    }
                    else
                        save_path = ready_to_make[1];
                }
            }
            else if(ready_to_make[0] == keyword2)
            {
                for (int i = 0; i < Variable_stack.size(); i++)
                {
                    if(finding == Variable_stack[i].name){
                        theme_path = Variable_stack[i].value;
                        break;
                    }
                    else;
                }
            }
            else if(ready_to_make[0] == keyword3)
            {
                expand_State = ready_to_make[1];
            }
            else if(ready_to_make[0] == keyword4)
            {
                Symbol_table svar;
                svar.name = ready_to_make[1];
                svar.value="1";
                Variable_stack.push_back(svar);
            }
            else if(ready_to_make[0] == keyword5)
            {
                Symbol_table svar;
                svar.name = ready_to_make[1];
                svar.value = "0";
                Variable_stack.push_back(svar);
            }
            else if(ready_to_make[0] == keyword6)
            {
                strock_int parr_int;
                int size;
                for (int i = 0; i < Variable_stack.size(); i++)
                {
                    if (finding == Variable_stack[i].name)
                    {
                        size = stoi(Variable_stack[i].value);
                    }
                    else;
                }
                for (int i = 1; i < size; i++)
                {
                    parr_int.int_arr.push_back(i);                    
                }
                Variable_stack_int_arr.push_back(parr_int);
            }
            else if(ready_to_make[0] == keyword7)
            {
                finding = ready_to_make[1];
            }
            else if(ready_to_make[0] == keyword8)
            {
                int num;
                for (int i = 0; i < Variable_stack.size(); i++)
                {
                    if (ready_to_make[1] == Variable_stack[i].name)
                    {
                        num = stoi(Variable_stack[i].value);
                    }
                }
                save_path_state = num;
            }
            else{
                for (int i = 0; i < Variable_stack.size(); i++)
                {
                    if (Variable_stack[i].name == ready_to_make[0])
                    {
                        if (Variable_stack[i].value == "1")
                        {
                            Variable_stack[i].value = ready_to_make[1];
                        }
                        else if(Variable_stack[i].value == "0")
                        {
                            Variable_stack[i].value = ready_to_make[1];
                        }
                        else;
                        if (Variable_stack[i].value == "++")
                        {
                            Variable_stack[i].value.clear();
                        }
                        else;
                    }
                    else;
                }
            }
            //head = head->next;
        }
        return 0;
    }
};
    
class Extension{
private:
    vector <Symbol_table> table3;
    string extension_key = "#EXPAND";
public:
    //拓展管理
    read_emakefile *re3;
    // 拓展一 增加功能性页面
    vector <string> add_new_page(){
        Symbol_table s3;    
        fstream conf_expan_out;
        conf_expan_out.open("../conf/expand_list.conf");
        vector <string> save_conffile;
        vector <string> gotogrammer;
        if (conf_expan_out)
        {
            string line;
            while (getline(conf_expan_out,line))
            {
                save_conffile.push_back(line);
            }
        }
        else
        {
            cerr<<"can not open the file!!!"<<endl;
        }
        save_conffile = re3->Participle(save_conffile);
        for (int i = 2; i < save_conffile.size(); i+=2)
        {
            s3.name = save_conffile[i];
            s3.value = save_conffile[i+1];
            if (s3.name == expand_name)
            {
                gotogrammer.push_back(s3.value+string(" "));
                gotogrammer.push_back(s3.name);
                return gotogrammer;
            }
            else;
            table3.push_back(s3);
        }
        gotogrammer.clear();
        return gotogrammer;
    }

    Extension(){
        re3 = new read_emakefile();
    }
    ~Extension(){
        delete(re3);
    }
};


class tohtml
{
private:
    string md_keyword0 = "img";
    string md_keyword1 = "#";
    string md_keyword2 = ">";
    string md_keyword3 = "url";
    string md_keyword4 = "___";
    string md_keyword5 = "```";
    string md_keyword6 = "***";
    string md_keyword7 = "---"; 
    string md_keyword8 = "::";
    void getFiles( string path, vector<string>& files )
    {
        //文件句柄
        long   hFile   =   0;
        //文件信息
        struct _finddata_t fileinfo;
        string p;
        if((hFile = _findfirst(p.assign(path).append("\\*").c_str(),&fileinfo)) !=  -1)
        {
            do
            {
                //如果是目录,迭代之
                //如果不是,加入列表
                if((fileinfo.attrib &  _A_SUBDIR))
                {
                    if(strcmp(fileinfo.name,".") != 0  &&  strcmp(fileinfo.name,"..") != 0)
                        getFiles( p.assign(path).append("\\").append(fileinfo.name), files );
                }
                else
                {
                    files.push_back(p.assign(path).append("\\").append(fileinfo.name) );
                }
            }
            while(_findnext(hFile, &fileinfo)  == 0);
            _findclose(hFile);
        }
    }         
    vector <Symbol_table> table2;
    vector <int> state_machine;
    vector <int> end_state_machine;
    vector <string> data_share;
    int num = 0;
public:
    friend read_emakefile;
    read_emakefile *re;
    Extension *e2;
    tohtml();
    ~tohtml();
    int open_mdfile()
    {                
        vector<string> files;
        char * filePath = (char*)md_path.c_str();
        ////获取该路径下的所有文件
        getFiles(filePath, files );
        char str[30];
        int size = files.size();
        for (int i = 0; i < files.size(); i++)
        {
            trans_tohtml(files[i]);
        }
        return 0;   
    }
   
    int trans_tohtml(string file_path)
    {
        fstream fout;
        fout.open(file_path);
        vector <string> save_mdfile;                
        if (fout)
        {
            string line;
            while (getline(fout,line)){
                save_mdfile = re->Participle(line);
                if ( run_task(save_mdfile))
                {
                    save_mdfile.pop_back();
                }
                else{
                    toh<<"<br>"<<endl;
                }
            }
        }
        else
        {
            cout<<"can not open the file!!!"<<endl;
            return -1;
        }
        toh<<"</body>"<<"</html>";
        return 0;
    }
    int run_task(vector <string> inputarr)
    {
        int bit = 0;
        while(inputarr.begin()!=inputarr.end())
        {
            bit = Lexical_analyzer(inputarr);
            Grammatical_analyer(bit,num,data_share);
            inputarr = data_share;
        }
        return 0;
    }
    //词法分析器
    int Lexical_analyzer(vector <string> analyer1)
    {
        int bit = 0;
        if (analyer1[0][0] == '#')
        {
            for (int i = 0; i < analyer1[0].size(); i++)
            {
                if (analyer1[0][i] == '#') //确定几级标题
                {
                    num++;
                }
            }
            bit = 1;
            analyer1.erase(analyer1.begin());
            state_machine.push_back(bit);
            data_share = analyer1;
            return bit;
        }
        else if(analyer1[0] == md_keyword0)
        {
            bit = 2;
            analyer1.erase(analyer1.begin());
            state_machine.push_back(bit);
            data_share = analyer1;
            return bit;
        }
        else if (analyer1[0] == md_keyword2)
        {
            bit = 3;
            analyer1.erase(analyer1.begin());
            state_machine.push_back(bit);
            data_share = analyer1;
            return bit;
        }
        else if (analyer1[0] == md_keyword3)
        {
            bit = 4;
            analyer1.erase(analyer1.begin());
            state_machine.push_back(bit);
            data_share = analyer1;
            return bit;
        }
        else if (analyer1[0] == md_keyword4)
        {
            bit = 5;
            analyer1.erase(analyer1.begin());
            state_machine.push_back(bit);
            data_share = analyer1;
            return bit;
        }
        else if (analyer1[0] == md_keyword5)
        {
            bit = 6;
            analyer1.erase(analyer1.begin());
            state_machine.push_back(bit);
            data_share = analyer1;
            return bit;
        }
        else if (analyer1[0] == md_keyword6){
            bit = 7;
            analyer1.erase(analyer1.begin());
            state_machine.push_back(bit);
            data_share = analyer1;
            return bit;
        }
        else if (analyer1[0] == md_keyword7)
        {
            bit = 8;
            analyer1.erase(analyer1.begin());
            state_machine.push_back(bit);
            data_share = analyer1;
            return bit;
        }
        else if(analyer1[0] == md_keyword8)
        {
            bit = 9;
            analyer1.erase(analyer1.begin());
            state_machine.push_back(bit);
            data_share = analyer1;
            return bit;
        }
        else
        {
            bit = 0;
            state_machine.push_back(bit);
            data_share = analyer1;
            return bit;
        }
        return 10;
    }
    //文法分析器
    int Grammatical_analyer(int State,int number,vector <string> arr)
    {   
        int pattern = 0;
        int bit1 = State;
        switch (bit1)
        {
            case 1:
                toh<<"<h"<<number<<">";     
                pattern = 1;
                end_state_machine.push_back(pattern);    
                bit1 = 0;
                Grammatical_analyer(bit1,number,arr);              
                break;
            case 2:                     
                toh<<"< img src=";
                pattern = 2;
                end_state_machine.push_back(pattern);
                bit1 = 0;
                Grammatical_analyer(bit1,number,arr);              
            case 3:
                toh<<"<q>";
                pattern = 3;
                end_state_machine.push_back(pattern);
                bit1 = 0;
                Grammatical_analyer(bit1,number,arr);                                  
                break;
            case 4:
                toh<<"<a href=\"";
                toh<<arr[0]<<"\">";
                arr.erase(arr.begin());
                for (int i = 0; i < arr.size(); i++)
                {
                    toh<<arr[i]<<" ";
                }
                toh<<"</a>";
                end_state_machine.push_back(pattern);                    
                bit1 = 0;                
                arr.clear();
                Grammatical_analyer(bit1,number,arr);              
                break;
            case 5:
                toh<<"<strong>";
                pattern = 5;
                end_state_machine.push_back(pattern);
                bit1 = 0;
                Grammatical_analyer(bit1,number,arr);              
                break;
            case 6:
                toh<<"<code>";
                Grammatical_analyer(bit1,number,arr);              
                bit1 = 0;
                break;
            case 7:                    
                toh<<"</code>";
                bit1 = 0;
                Grammatical_analyer(bit1,number,arr);              
                break;
            case 8:
                toh<<"<hr>";
                bit1 = 0;
                Grammatical_analyer(bit1,number,arr);              
                break;
            case 9:
                expand_name = arr[0];
                if (expand_State == "ON")
                {
                    vector <string> in_grammer;
                    in_grammer = e2->add_new_page();
                    Grammatical_analyer(4,0,in_grammer);
                }
                else;
                break;
            default: 
                for (int i = 0; i < arr.size(); i++)
                {
                    int bit2 = 0;
                    if (bit2 = Lexical_analyzer(arr))
                    {
                        arr.erase(arr.begin());
                        Grammatical_analyer(bit2,number,arr);
                        arr.clear();
                    }
                    else
                    {
                        toh<<arr[i]<<" ";
                        arr.erase(arr.begin());
                        i--;
                    }
                }
                arr.clear();
                data_share = arr;
                break;
        } 
        //输出结尾部分  
        for (int i = 0; i < end_state_machine.size(); i++)
        {
            int bit2 = end_state_machine[i];
            switch (bit2)
            {
                case 1:
                    toh<<"<"<<"/"<<"h"<<number<<">";
                    end_state_machine.erase(end_state_machine.begin());
                    break;
                case 2:
                    toh<<">";
                    break;
                case 3:
                    toh<<"</q>";
                    end_state_machine.erase(end_state_machine.begin());
                    break;
                case 5:
                    toh<<"</strong>";
                default:
                    break;
            }
        }
        return 0;
    }
};
tohtml::tohtml()
{
    re = new read_emakefile();
    e2 = new Extension();
}

tohtml::~tohtml()
{
    delete(re);
    delete(e2);
}

class Preprocessor
{
private:
    fstream theme_out;
public:
    Preprocessor();
    int read_themefile()
    {                  
        for (int j = 0; j < save_path_state; j++)
        {
            toh.open(save_path+to_string(j)+string(".html"));        
            theme_out.open(theme_path+string(".txt"));
            if (theme_out)
            {
                string line;
                while (getline(theme_out,line))
                {
                    toh<<line<<"\n";
                }
                break;
            }
            else
            {
                cerr<<"can not open the file!!!"<<endl;
                return -1;
            }
        } 
        return 0;
    }
    ~Preprocessor();
};

Preprocessor::Preprocessor(/* args */)
{
}

Preprocessor::~Preprocessor()
{
}

#endif