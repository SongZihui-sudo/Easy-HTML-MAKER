#include <fstream>
#include <vector>
#include<iostream>
#include "tohtml.hpp"
#include <string>

using namespace std;
//主函数
int main(){
    read_emakefile *r;
    r = new read_emakefile();
    tohtml *t;
    t = new tohtml();
    r->make_symboltable1(r->readout_emakefile());
    t->open_mdfile();
    delete(r);
    return 0;
}
