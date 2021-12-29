#include <fstream>
#include <vector>
#include<iostream>
#include "tohtml.hpp"
#include <string>

using namespace std;
//主函数
int main(){
    Extension *e2;
    e2 = new Extension();
    read_emakefile *r;
    r = new read_emakefile();
    tohtml *t;
    t = new tohtml();
    r->make_symboltable1(r->readout_emakefile());
    Preprocessor *p;
    p = new Preprocessor();
    p->read_themefile();
    t->open_mdfile();
    delete(r);
    delete(t);
    delete(p);
    delete(e2);
    return 0;
}

