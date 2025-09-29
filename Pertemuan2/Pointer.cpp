#include <iostream>
using namespace std;

void Tukar(int *x, int *y) {
    int temp = *x;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 20,b = 30;
    int *ptr;
    ptr = &a;
    
    
    cout << "Value of a: " << a << endl;
    cout << "Address of a: " << &a << endl;
    cout << "Value stored int ptr (address of a): " << ptr << endl;
    cout << "Value pointed to by ptr : " << *ptr << endl;

    Tukar(&a, &b);
    cout << "After Swaping, Value of a= " << a << " and b=" << b << endl;
    return 0;
}