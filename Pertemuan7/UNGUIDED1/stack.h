#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef int infotype; 
#define MaxEl 20 

struct Stack {
    infotype info[MaxEl + 1]; 
    int top;                  
};

void CreateStack(Stack &S);

int IsEmpty(Stack S);

void Push(Stack &S, infotype X);

infotype Pop(Stack &S);

void PrintInfo(Stack S);

void BalikStack(Stack &S);

#endif