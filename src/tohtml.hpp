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

string save_path;

ofstream toh;

typedef struct Symbol_table
{
    string name;
    string next;
}Symbol_table;

vector <Symbol_table> table1;

class read_emakefile
{
private:
    string keyword0 = "#INPUTFILE";
    string keyword1 = "#OUTPUTFILE";
    string keyword2 = "#THEME";
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
                if(s1.name == keyword1)
                    save_path = s1.next;
                else;
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
    vector <Symbol_table> table2;
    vector <int> state_machine;
    vector <int> end_state_machine;
    vector <string> data_share;
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
}

tohtml::~tohtml()
{
    delete(re);
}

class Preprocessor
{
private:
    string theme_key = "#THEME";
    fstream theme_out;
public:
    Preprocessor();
    int read_themefile()
    {                       
        toh.open(save_path+string(".html"));        
        for (int i = 0; i < table1.size(); i++)
        {
            if (table1[i].name == theme_key)
            {
                theme_out.open(table1[i].next+string(".txt"));
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
            else
            {
                continue;
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