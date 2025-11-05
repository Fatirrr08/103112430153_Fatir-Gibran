#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Stack S;
    
    CreateStack(S);
    GetInputStream(S);
    PrintInfo(S); 
    cout << "balik stack" << endl;
    BalikStack(S);
    PrintInfo(S); 
    
    return 0;
}