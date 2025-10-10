#include<iostream>
using namespace std;

struct mahasiswa{
        string nama;
        float nilai1, nilai2;
};

void input(mahasiswa &mhs){
        cout<<"Masukkan Nama : ";
        cin>>mhs.nama;
        cout<<"Masukkan Nilai 1 : "; 
        cin>>mhs.nilai1;
        cout<<"Masukkan Nilai 2 : "; 
        cin>>mhs.nilai2;
}

float rata2(mahasiswa mhs){
        return (mhs.nilai1 + mhs.nilai2)/2;
}
int main(){
        mahasiswa mhs;
        input(mhs);
        cout<<"Rata-rata Nilai : "<<rata2(mhs)<<endl;
        return 0;
}