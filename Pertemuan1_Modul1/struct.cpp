#include <iostream>
using namespace std;
#define MAX 5
int main() {
    int i;
    struct data {
        char nama[40];
        int nilai;
    };
    data siswa [MAX];
    for ( i = 0; i< MAX; i++){
        cout<< "Masukkan data ke-"<<(i+1)<<endl;
        cout<< "Nama : "; cin>>siswa[i].nama;
        cout<< "Nilai : "; cin>>siswa[i].nilai;
    }
    cout<<"\ndata siswa\n";
    cout<< "=======" ;
    for ( i = 0; i< MAX; i++){
        cout<< "\ndata ke- : "<<i+1<<endl;
        cout<< "\n\nnama : "<<siswa[i].nama<<endl;
        cout<< "nilai : "<<siswa[i].nilai<<endl;
    }
    return 0;
}