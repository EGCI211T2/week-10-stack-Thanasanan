#ifndef queue_h
#define queue_h
#include "node.h"
#include <iostream>
using namespace std;

class Queue {
    NodePtr headPtr;
    NodePtr tailPtr;
    int size;
    int customer_no; 
public:
    void enqueue(int, int);
    void dequeue(); 
    int get_size(); 
    Queue();
    ~Queue();
};

Queue::Queue(){
    headPtr = NULL;
    tailPtr = NULL;
    size = 0;
    customer_no = 1;
}

int Queue::get_size(){
    return size;
}

void Queue::enqueue(int x, int y){
    NodePtr new_node = new NODE(x, y); 
    if(new_node){
       
        cout << "My order is " << x << endl;

        if(size == 0){
            headPtr = new_node;
        } else {
            tailPtr->set_next(new_node);
        }
        tailPtr = new_node;
        size++;
    }
}

void Queue::dequeue(){
    if(headPtr == NULL){
        
        cout << "The queue is empty" << endl;
        return; 
    }

   
    NodePtr t = headPtr;
    int ord = t->get_ord();
    int qty = t->get_qty();
    
  
    int price = 0;
    string foodName = "";
    if(ord == 1) { 
        price = 100 * qty; 
        foodName = "Ramen"; 
    }
    else if(ord == 2) { 
        price = 20 * qty; 
        foodName = "Somtum"; 
    }
    else if(ord == 3) { 
        price = 50 * qty; 
        foodName = "Fried Chicken"; 
    }

   
    cout << "Customer no: " << customer_no << endl; 
    cout << foodName << endl;
    cout << "You have to pay " << price << endl;
    
   
    int cash = 0;
    cout << ":Cash:"; 
    cin >> cash;
    
    
    while(cash < price) {
        cout << "Cash:"; 
        int added_cash;
        cin >> added_cash;
        cash = added_cash; 
    }

    cout << "Thank you" << endl;
    
   
    if(cash > price){
        cout << "Change is:" << cash - price << endl;
    }

   
    customer_no++;
    headPtr = headPtr->get_next();
    if(headPtr == NULL) tailPtr = NULL; 
    
    size--;
    delete t;
}

Queue::~Queue(){
    
    while(headPtr != NULL){
        NodePtr t = headPtr;
        headPtr = headPtr->get_next();
        delete t;
    }
}

#endif