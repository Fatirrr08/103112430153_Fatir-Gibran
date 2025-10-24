#include <iostream>
#include <string>

using namespace std;

const int KAPASITAS_RAK = 12;

struct Buku {
    string judul;
    string penulis;
};

struct RakBuku {
    Buku T[KAPASITAS_RAK]; 
    int TOP;               
};

void createStack(RakBuku &S) {
    S.TOP = -1; 
}

void push(RakBuku &S, string inJudul, string inPenulis) {
    if (S.TOP < KAPASITAS_RAK - 1) {
        S.TOP++;
        S.T[S.TOP].judul = inJudul;
        S.T[S.TOP].penulis = inPenulis;
        cout << "Info: Buku '" << inJudul << "' berhasil ditambahkan." << endl;
    } else {
        cout << "Error: Rak buku sudah penuh!" << endl;
    }
}

void pop(RakBuku &S, string &outJudul, string &outPenulis) {
    if (S.TOP > -1) {
        outJudul = S.T[S.TOP].judul;
        outPenulis = S.T[S.TOP].penulis;
        S.TOP--;
    } else {
        cout << "Error: Rak buku sudah kosong!" << endl;
        outJudul = "";
        outPenulis = "";
    }
}

void get(RakBuku &S, string inJudulCari, string &outPenulis) {
    string tempJudul, tempPenulis;
    bool found = false;
    outPenulis = ""; 

    while (S.TOP > -1 && !found) {
        pop(S, tempJudul, tempPenulis);
        cout << "Info: Mengambil buku '" << tempJudul << "' dari rak." << endl;

        if (tempJudul == inJudulCari) {
            found = true;
            outPenulis = tempPenulis;
        }
    }

    if (!found) {
        cout << "Info: Buku dengan judul '" << inJudulCari << "' tidak ditemukan." << endl;
    }
}

const int MAX_QUEUE = 10; 

struct Queue {
    int T[MAX_QUEUE];
    int HEAD;
    int TAIL;
};

void createQueue(Queue &Q) {
    Q.HEAD = -1;
    Q.TAIL = -1;
}

bool isEmpty(Queue Q) {
    return (Q.HEAD == -1 && Q.TAIL == -1);
}

bool isFull(Queue Q) {
    return ((Q.TAIL + 1) % MAX_QUEUE == Q.HEAD);
}

void enqueue(Queue &Q, int data) {
    if (isFull(Q)) {
        cout << "Error: Queue penuh!" << endl;
    } else {
        if (isEmpty(Q)) {
            Q.HEAD = 0; 
        }
        Q.TAIL = (Q.TAIL + 1) % MAX_QUEUE;
        Q.T[Q.TAIL] = data;
        cout << "Info: Angka " << data << " masuk ke antrian." << endl;
    }
}

void dequeue(Queue &Q, int &data) {
    if (isEmpty(Q)) {
        cout << "Error: Queue kosong!" << endl;
        data = -1;
    } else {
        data = Q.T[Q.HEAD];
        cout << "Info: Angka " << data << " keluar dari antrian." << endl;
        
        if (Q.HEAD == Q.TAIL) {
            createQueue(Q);
        } else {
            Q.HEAD = (Q.HEAD + 1) % MAX_QUEUE;
        }
    }
}
int main() {
    cout << "--- DEMO STACK RAK BUKU ---" << endl;
    RakBuku rak;
    createStack(rak);

    push(rak, "Laskar Pelangi", "Andrea Hirata");
    push(rak, "Bumi Manusia", "Pramoedya Ananta Toer");
    push(rak, "Cantik Itu Luka", "Eka Kurniawan");

    cout << "\nKondisi rak saat ini (TOP index): " << rak.TOP << endl;
    
    cout << "\nMencari buku 'Bumi Manusia'..." << endl;
    string penulisDitemukan;
    get(rak, "Bumi Manusia", penulisDitemukan);

    if (!penulisDitemukan.empty()) {
        cout << "Hasil: Penulis buku 'Bumi Manusia' adalah " << penulisDitemukan << endl;
    }
    cout << "Kondisi rak sekarang (TOP index): " << rak.TOP << endl << endl;

    cout << "\n--- DEMO QUEUE ANTRIAN ---" << endl;
    Queue antrian;
    createQueue(antrian);
    int dataKeluar;

    enqueue(antrian, 10);
    enqueue(antrian, 20);
    enqueue(antrian, 30);
    
    dequeue(antrian, dataKeluar);
    
    enqueue(antrian, 40);

    cout << "\nMengosongkan antrian..." << endl;
    while (!isEmpty(antrian)) {
        dequeue(antrian, dataKeluar);
    }
    
    dequeue(antrian, dataKeluar);

    return 0;
}
