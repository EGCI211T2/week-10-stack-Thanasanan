#include <iostream>
#include <vector>
#include <string>
#include "queue.h"
using namespace std;

int main(int argc, char **argv){
    Queue q;
    int i = 1;
    
    while(i < argc){
        string arg = argv[i];
        
        if(arg == "x"){
            q.dequeue(); 
            i++; 
        }
        else {
            int ord = atoi(argv[i]);
            
            
            if(ord >= 1 && ord <= 3){
                if(i + 1 < argc){
                    int qty = atoi(argv[i+1]);
                    q.enqueue(ord, qty); 
                    i += 2; 
                } else {
                    i++; 
                }
            } else {
               
                i++; 
            }
        }
    }
    
    cout << "========================================" << endl;
   
    cout << "There are " << q.get_size() << " ppl left in the queue" << endl;
    
    return 0;
}