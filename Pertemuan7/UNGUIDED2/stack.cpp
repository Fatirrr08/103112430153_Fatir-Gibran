#include "stack.h"
#include <iostream>

using namespace std;

void CreateStack(Stack &S) {
    S.top = 0; 
}

int IsEmpty(Stack S) {
    return S.top == 0;
}

void Push(Stack &S, infotype X) {
    if (S.top < MaxEl) { 
        S.top++; 
        S.info[S.top] = X; 
    } else {
        cout << "Stack Penuh, Push gagal!" << endl;
    }
}

infotype Pop(Stack &S) {
    infotype X = 0; 
    if (!IsEmpty(S)) {
        X = S.info[S.top]; 
        S.top--;           
    } 
    return X; 
}

void PrintInfo(Stack S) {
    if (!IsEmpty(S)) {
        cout << "[TOP] ";
        for (int i = S.top; i >= 1; i--) { 
            cout << S.info[i] << " ";
        }
        cout << endl;
    } else {
        cout << "Stack Kosong" << endl;
    }
}

void BalikStack(Stack &S) {
    Stack Temp1; 
    Stack Temp2; 
    CreateStack(Temp1);
    CreateStack(Temp2);

    while (!IsEmpty(S)) {
        Push(Temp1, Pop(S));
    }
    
    while (!IsEmpty(Temp1)) {
        Push(Temp2, Pop(Temp1));
    }
    
    while (!IsEmpty(Temp2)) {
        Push(S, Pop(Temp2));
    }
}

void PushAscending(Stack &S, infotype X) {
    Stack Temp;
    CreateStack(Temp);

    while (!IsEmpty(S) && S.info[S.top] > X) {
        Push(Temp, Pop(S));
    }

    Push(S, X);

    while (!IsEmpty(Temp)) {
        Push(S, Pop(Temp));
    }
}