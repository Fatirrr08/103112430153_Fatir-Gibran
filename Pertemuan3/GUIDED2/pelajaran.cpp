#include "pelajaran.h"

pelajaran create_pelajaran(string namaMapel, string kodepel){
    pelajaran p;
    p.namaMapel = namaMapel;
    p.kodeMapel = kodepel;
    return p;
}

void tampilan_pelajaran(pelajaran pel){
    cout<<"Nama Mata Pelajaran : "<<pel.namaMapel<<endl;
    cout<<"Kode Mata Pelajaran : "<<pel.kodeMapel<<endl;
}