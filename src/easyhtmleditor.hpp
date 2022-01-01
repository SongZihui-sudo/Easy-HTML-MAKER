#ifndef _easyhtmleditor_h
#define _easyhtmleditor_h
    #include <iostream>
    #include <vector>
    #include "estack.hpp"
    #include "Article_device.hpp"

    using namespace std;
    using namespace mth;

    string File_Name;
    vector <string> buf;
    
    class easyhtmleditor
    {
    private:
        int num = 0;
    public:
        read_emakefile re5;
        tohtml toh2;
        easyhtmleditor();
        ~easyhtmleditor();
        int run_eim(){
            estack <string> save_input;
            save_input = input_str(save_input);
            return 0;
        }
        estack <string> input_str(estack <string> input){
            string line;
            while (getline(cin,line)){
                if (line == "wq")
                {
                    save_file(line,input);
                }
                else if (line == "q")
                {
                    cout<<"wearning!!!You input will not be save!!!"<<endl;
                    return input;
                }
                else
                {
                    line = convert(line);
                    input.Push(line);
                }
            }
            return input;
        }
        string convert(string readytoconvert){
            vector <string> arr_input;
            arr_input = re5.Participle(readytoconvert);
            int bit = toh2.Lexical_analyzer(arr_input);
            toh2.Grammatical_analyer(bit,toh2.num,arr_input,1); 
            return readytoconvert;
        }
        int save_file(string save_path1,estack <string> arr_str){
            cout<<"Saving file"<<endl;
            ofstream output;
            output.open(save_path1);
            if (output)
            {
                int i = 0;
                for (int i = 0; i < arr_str.Size(); i++)
                {
                    output<<arr_str.data[i];
                }
            }
            else
            {
                cerr<<"can not open the file!!!"<<endl;
            }
            return 0;
        }
    };
    
    easyhtmleditor::easyhtmleditor(/* args */)
    {
    }
    
    easyhtmleditor::~easyhtmleditor()
    {
    }
    

#endif 