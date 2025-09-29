    #include <iostream>
    using namespace std;

    int cariMax(int arr[], int ukuran) {
        int max = arr[0];
        for (int i = 1; i < ukuran; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        return max;
    }

    void OperasiAritmatika(int arr[],int ukuran){
        int totaljumlah = 0;
        for(int i = 0; i < ukuran; i++){
            totaljumlah += arr[i];
        }
        cout << "Total perjumlah: " << totaljumlah << endl;

        int totalKali = 1;
        for(int i = 0; i < ukuran; i++){
            totalKali *= arr[i];
        }
        cout << "Total perkalian: " << totalKali << endl;
    }
        int main() {
            const int ukuran = 5;
            int arr[ukuran];
            for (int i = 0; i < ukuran; i++) {
            cout << "Masukkan Nilai Array ke-" << i << ": ";
            cin >> arr[i];    
            }
            cout << endl;
            cout << "Nilai Maksimum: " << cariMax(arr, ukuran) << endl;
        
            OperasiAritmatika(arr, ukuran);
            return 0;
        }