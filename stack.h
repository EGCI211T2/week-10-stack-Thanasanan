#ifndef stack_h
#define stack_h
#include "node.h"

class Stack {
    NodePtr top;
    int size;
public:
    void push(char);
    char pop();
    Stack();
    ~Stack();
    int getSize();
};

Stack::Stack(){
    top = NULL;
    size = 0;
}

void Stack::push(char x){
    NodePtr new_node = new NODE(x);
    if(new_node){
        new_node->set_next(top);
        top = new_node;
        size++;
    }
}

char Stack::pop(){
    NodePtr t = top;
    char value;
    if(t == NULL) return 0;
    
    value = t->get_value();
    top = t->get_next();
    delete t;
    size--;
    return value;
}

int Stack::getSize(){
    return size;
}

Stack::~Stack(){
    while(top != NULL){
        NodePtr t = top;
        top = top->get_next();
        delete t;
    }
}

#endif