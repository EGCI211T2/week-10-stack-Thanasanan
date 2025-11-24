#include<iostream>
using namespace std;
#include "stack.h"

int main(int argc, char **argv){
    Stack s;
    
    
    s.push('5'); 
    s.push('1');
    s.push('7');
    
   
    cout << "Popped: " << s.pop() << endl; 
    
    s.push('6');
    
    cout << "Popped: " << s.pop() << endl; 
    cout << "Popped: " << s.pop() << endl; 
    cout << "Popped: " << s.pop() << endl; 
    cout << "Popped: " << s.pop() << endl; 

    return 0;
}