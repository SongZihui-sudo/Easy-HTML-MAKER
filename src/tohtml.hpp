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

ofstream toh;

typedef struct Symbol_table
{
    string name;
    string next;
    Symbol_table* NextandNext;
}Symbol_table;

vector <Symbol_table> table1;

class read_emakefile
{
private:
    string keyword0 = "#INPUTFILE";
    string keyword1 = "#OUTPUTFILE";
    string keyword2 = "THEME";
public:
    friend tohtml;
   //按照空格划分语句
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
                save_data.push_back(line);
            }
        }
        else
        {
            cerr<<"can not open the file!!!"<<endl;
        }
        save_data = Participle(save_data);
        return save_data;
    }
    int make_symboltable1(vector <string> input_src1){
        Symbol_table s1;
        for (int i = 0; i < input_src1.size(); i++){
            if (input_src1[i] == keyword0 || input_src1[i] == keyword1 || input_src1[i] == keyword2){
                s1.name = input_src1[i];
                s1.next = input_src1[i+1];
                table1.push_back(s1);
            }
            else;
        }
        return 0;
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
    string save_path;
    vector <Symbol_table> table2;
    vector <int> state_machine;
    vector <int> end_state_machine;
    int num = 0;
public:
    friend read_emakefile;
    read_emakefile *re;
    tohtml();
    ~tohtml();
    int open_mdfile()
    {                
        vector<string> files;
        for (int i = 0; i < table1.size(); i++)
        {
            if ( table1[i].name == re->keyword0)
            {
                char * filePath = (char*)table1[i].next.c_str();
                ////获取该路径下的所有文件
                getFiles(filePath, files );
                char str[30];
                int size = files.size();
                
            }
            else if(table1[i].name == re->keyword1)
            {
                save_path = table1[i].next;
            }
            else
            {
                continue;
            }
        }  
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
                if ( run_task(save_mdfile[0],save_mdfile))
                {
                    save_mdfile.pop_back();
                }
                else;
            }
        }
        else
        {
            cout<<"can not open the file!!!"<<endl;
        }
        return 0;
    }
    int run_task(string inputfile,vector <string> inputarr)
    {
        toh.open(save_path+string(".html"));
        //词法检查
        if (Lexical_analyzer(inputfile))
        {
            //OK          
        }
        else
        {
            toh<<inputfile;//直接输出
            return 1;
        }
        //词法分析
        Grammatical_analyer(inputarr);
        return 0;
    }
    //词法分析器
    bool Lexical_analyzer(string analyer1)
    {
        if (analyer1 == md_keyword0|| analyer1 == md_keyword1||analyer1 == md_keyword2||analyer1 == md_keyword3||analyer1 == md_keyword4||analyer1 == md_keyword5||analyer1 == md_keyword6||analyer1 == md_keyword7)
        {
            return true;
        }
        else {
            return false;
        }
        return true;
    }
    //文法分析器
    int Grammatical_analyer(vector <string> analyer2)
    {
        int bit = 0;
        if (analyer2[0][0] == '#')
        {
            for (int i = 0; i < analyer2.size(); i++)
            {
                if (analyer2[0][i] == '#')
                {
                    num++;
                }
            }
            bit = 1;
            analyer2.erase(analyer2.begin());
            state_machine.push_back(bit);
            Grammatical_analyer(analyer2);
        }
        else if(analyer2[0] == md_keyword0)
        {
            bit = 2;
            analyer2.erase(analyer2.begin());
            state_machine.push_back(bit);
            Grammatical_analyer(analyer2);
        }
        else if (analyer2[0] == md_keyword2)
        {
            bit = 3;
            analyer2.erase(analyer2.begin());
            state_machine.push_back(bit);
            Grammatical_analyer(analyer2);
        }
        else if (analyer2[0] == md_keyword3)
        {
            bit = 4;
            analyer2.erase(analyer2.begin());
            state_machine.push_back(bit);
            Grammatical_analyer(analyer2);
        }
        else if (analyer2[0] == md_keyword4)
        {
            bit = 5;
            analyer2.erase(analyer2.begin());
            state_machine.push_back(bit);
            Grammatical_analyer(analyer2);
        }
        else if (analyer2[1] == md_keyword5)
        {
            bit = 6;
            analyer2.erase(analyer2.begin());
            state_machine.push_back(bit);
            Grammatical_analyer(analyer2);
        }
        else if (analyer2[0] == md_keyword6){
            bit = 7;
            analyer2.erase(analyer2.begin());
            state_machine.push_back(bit);
            Grammatical_analyer(analyer2);
        }
        else if (analyer2[0] == md_keyword7)
        {
            bit = 8;
            analyer2.erase(analyer2.begin());
            state_machine.push_back(bit);
            Grammatical_analyer(analyer2);
        }
        else{
            //state_machine
            State_Machine(state_machine,num,analyer2);
        }
        return 0;
    }
    int State_Machine(vector <int> State,int number,vector <string> arr)
    {   
        for (int i = 0; i < State.size(); i++)
        {
            int pattern = 0;
            int bit1 = State[i];
            switch (bit1)
            {
                case 1:
                    toh<<"<h"<<number<<">";     
                    State.erase(State.begin());
                    pattern = 1;
                    for (int i = 0; i < arr.size(); i++)
                    {
                        toh<<arr[i]<<" ";
                    }
                    end_state_machine.push_back(pattern);                  
                    State_Machine(State,number,arr);
                    break;
                case 2:                     
                    toh<<"< img src=";
                    for (int i = 0; i < arr.size(); i++)
                    {
                        toh<<arr[i];
                    }
                    toh<<">";
                    State_Machine(State,number,arr);
                case 3:
                    toh<<"<q>";
                    pattern = 3;
                    end_state_machine.push_back(pattern);                    
                    State_Machine(State,number,arr);
                    break;
                case 4:
                    toh<<"<a href=\"";
                    toh<<arr[0]<<">";
                    arr.erase(arr.begin());
                    toh<<arr[1]<<"</a>";
                    arr.erase(arr.begin());
                    State.erase(State.begin());
                    pattern = 4;
                    end_state_machine.push_back(pattern);                    
                    State_Machine(State,number,arr);
                    break;
                case 5:
                    toh<<"<strong>";
                    for (int i = 0; i < arr.size(); i++)
                    {
                        toh<<arr[i];
                    }
                    toh<<"</strong>";                    
                    break;
                case 6:
                    toh<<"<code>";
                    break;
                case 7:
                    break;
                    toh<<"</code>";
                case 8:
                    toh<<"<hr>";
                    break;
                default:
                    break;
            }
        }            
        State.clear();  
        for (int i = 0; i < end_state_machine.size(); i++)
        {
            int bit2 = end_state_machine[i];
            switch (bit2)
            {
            case 1:
                toh<<"<"<<"/"<<"h"<<number<<">";
                break;
            case 3:
                toh<<"</q>";
                break;
            case 4:
                toh<<"</a>";
                break;
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
}

tohtml::~tohtml()
{
    delete(re);
}

#endif