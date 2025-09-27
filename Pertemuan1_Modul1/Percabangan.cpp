#include <iostream>
using namespace std;

int main() {
    double tot_pembelian, diskon;
    cout << "Total pembelian: Rp";
    cin >> tot_pembelian;
    diskon = (tot_pembelian > 100000) ? 0.05 * tot_pembelian : 0;
    cout << "Diskon: Rp" << diskon << endl;
    return 0;
}