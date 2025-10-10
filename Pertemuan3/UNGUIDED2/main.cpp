#include <iostream>
#include "pelajaran.h"
using namespace std;

int main(){
    string namapel = "stuktur data";
    string kodepel = "STD";

    pelajaran pel = create_pelajaran(namapel, kodepel);
    tampilan_pelajaran(pel);
    return 0;
}