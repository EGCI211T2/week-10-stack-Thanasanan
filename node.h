#ifndef node_h
#define node_h
#include <iostream>
using namespace std;

class NODE{
    int ord_number, qty; 
    NODE *nextPtr;
public:
    NODE(int, int);
    ~NODE();
    void set_next(NODE*);
    NODE* get_next();
    int get_ord();
    int get_qty();
};
typedef NODE* NodePtr;

NODE::NODE(int o, int q){
    ord_number = o;
    qty = q;
    nextPtr = NULL;
}

NODE* NODE::get_next(){
    return nextPtr;
}

int NODE::get_ord(){
    return ord_number;
}

int NODE::get_qty(){
    return qty;
}

void NODE::set_next(NODE *t){
     nextPtr=t;
}

NODE::~NODE(){
    
}

#endif