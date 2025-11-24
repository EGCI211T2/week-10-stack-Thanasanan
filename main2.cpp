#include <iostream>
#include <cstring>
using namespace std;

#include "stack.h"

int main(int argc, char **argv){
    int i, j; 
    
   
    for(i = 1; i < argc; i++){
        
        bool valid = true;
        Stack s; 
        
        
        for(j = 0; j < strlen(argv[i]); j++){
            char c = argv[i][j];

            
            if(c == '[' || c == '{'){
                s.push(c);
            }
          
            else if(c == ']' || c == '}'){
                
                
                char x = s.pop();
                

                if(x == 0){
                    valid = false; 
                    cout << "Too many closing brackets" << endl;
                    break; 
                }

               
                if(c == ']' && x != '['){
                    valid = false;
                    cout << "Mismatch detected: expected ] but found " << x << endl;
                    break;
                }
                if(c == '}' && x != '{'){
                    valid = false;
                    cout << "Mismatch detected: expected } but found " << x << endl;
                    break;
                }
            }
        } 

        if(valid == true && s.pop() != 0){
            valid = false;
            cout << "Too many opening brackets" << endl;
        }

       
        if(valid){
            cout << "argv " << i << ": Correct" << endl;
        } else {
            cout << "argv " << i << ": Incorrect" << endl;
        }
        
        cout << "-----------------------" << endl;
    }

    return 0;
}