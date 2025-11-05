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
    Stack Temp; 
    CreateStack(Temp);

    while (!IsEmpty(S)) {
        Push(Temp, Pop(S));
    }

    while (!IsEmpty(Temp)) {
        Push(S, Pop(Temp));
    }
}