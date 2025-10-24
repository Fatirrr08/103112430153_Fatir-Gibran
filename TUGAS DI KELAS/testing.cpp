#include <iostream>
using namespace std;

int main() {
    int ThreadA, ThreadB;
    int temp;

// THREAD A
ThreadA = 0;
temp = ThreadA;
ThreadA = temp + 1;
// THREAD B
ThreadB = 0;
temp = ThreadB;
ThreadB = temp + 1;

cout << ThreadA << endl;
cout << ThreadB << endl;
    return 0;
}
