#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    CreateStack(S);

    PushAscending(S, 3);
    PushAscending(S, 4);
    PushAscending(S, 8);
    PushAscending(S, 2);
    PushAscending(S, 3);
    PushAscending(S, 9);
    
    PrintInfo(S); 

    cout << "balik stack" << endl;
    BalikStack(S);
    
    PrintInfo(S); 
    
    return 0;
}