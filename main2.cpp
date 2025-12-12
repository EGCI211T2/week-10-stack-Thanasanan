#include <iostream>
#include <cstring>
#include "stack.h"
using namespace std;

int main(int argc, char **argv){
    
    
    for(int i = 1; i < argc; i++){
        Stack s;
        bool match = true;
        bool tooManyClosed = false;
        
        
        for(int j = 0; j < strlen(argv[i]); j++){
            char c = argv[i][j];
            
            
            if(c == '{' || c == '['){
                s.push(c);
            }
            
            else if(c == '}' || c == ']'){
                if(s.getSize() == 0){
                    tooManyClosed = true;
                    match = false;
                    break;
                }
                char open = s.pop();
                if( (c == '}' && open != '{') || (c == ']' && open != '[') ){
                    match = false;
                    break; 
                }
            }
        }
        
        // --- PRINT RESULT ---
        if(match == false){
            if(tooManyClosed) 
                 cout << "argv " << i << ": Incorrect: too many closed parenthesis" << endl;
            else 
                 cout << "argv " << i << ": Incorrect: mismatch" << endl;
        }
        else if(s.getSize() > 0){
             cout << "argv " << i << ": Incorrect: too many open parenthesis" << endl;
        }
        else{
             cout << "argv " << i << ": Correct" << endl;
        }
    }
    return 0;
}