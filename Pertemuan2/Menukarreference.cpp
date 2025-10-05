#include <iostream>
using namespace std;

void TukarTigaReference(int &x, int &y, int &z) {
    int temp = x;
    x = y;
    y = z;
    z = temp;
}

int main() {
    int p = 100, q = 200, r = 300;

    cout << "--- Sebelum ditukar (Reference) ---" << endl;
    cout << "Nilai p: " << p << endl;
    cout << "Nilai q: " << q << endl;
    cout << "Nilai r: " << r << endl;

    TukarTigaReference(p, q, r);

    cout << "\n--- Setelah ditukar (Reference) ---" << endl;
    cout << "Nilai p: " << p << endl;
    cout << "Nilai q: " << q << endl;
    cout << "Nilai r: " << r << endl;

    return 0;
}