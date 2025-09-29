#include <iostream>
using namespace std;

int main() {
    int arr[10] ;
    
    for (int i = 0; i < 10; i++) {
        cout << "Masukkan value index ke- " << i << ": " ;
        cin >> arr[i];
    }
    int j=0;
    while (j<10) {
        cout << "isi index ke- " << j << ": " << arr[j] << endl;
        j++;
    }
    return 0;
}