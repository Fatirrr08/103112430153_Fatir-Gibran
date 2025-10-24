#include <iostream>
using namespace std;

struct Node {
    float data;
    Node* next;
};

// Buat list dari awal
void createList(Node* &head) {
    head = NULL;
}

// Insert di akhir (untuk setup list awal)
void insertLast(Node* &head, float X) {
    Node* newNode = new Node;
    newNode->data = X;
    newNode->next = NULL;

    if (head == NULL) head = newNode;
    else {
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }
}

// Menampilkan isi list
void printList(Node* head) {
    Node* temp = head;
    cout << "Isi List: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Fungsi mencari nilai X
bool search(Node* head, float X) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == X) return true;
        temp = temp->next;
    }
    return false;
}

// Prosedur hapus elemen sesuai kondisi
void deleteCondition(Node* &head, float X) {
    if (head == NULL) {
        cout << "List kosong" << endl;
        return;
    }

    Node* temp = head;
    Node* prev = NULL;

    // cari elemen bernilai X
    while (temp != NULL && temp->data != X) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Tidak ada elemen bernilai " << X << endl;
        return;
    }

    // jika X di awal
    if (temp == head) {
        cout << "Elemen X = " << X << " di awal list, dihapus." << endl;
        head = head->next;
        delete temp;
    }
    // jika X di akhir
    else if (temp->next == NULL) {
        cout << "Elemen X = " << X << " di akhir list, dihapus." << endl;
        prev->next = NULL;
        delete temp;
    }
    // jika X di tengah
    else {
        Node* target = temp->next;
        cout << "Elemen X = " << X << " di tengah list, hapus elemen setelahnya (" 
             << target->data << ")" << endl;
        temp->next = target->next;
        delete target;
    }
}

int main() {
    Node* head;
    createList(head);

    // Buat list awal
    insertLast(head, 10.5);
    insertLast(head, 12.0);
    insertLast(head, 20.9);
    insertLast(head, 25.1);

    cout << "=== LIST AWAL ===" << endl;
    printList(head);

    // Cari elemen
    float cari = 12.0;
    cout << "\nCari elemen " << cari << ": ";
    if (search(head, cari)) cout << "Ditemukan" << endl;
    else cout << "Tidak ditemukan" << endl;

    // Proses hapus
    cout << "\n=== PROSES HAPUS ===" << endl;
    deleteCondition(head, 12.0); // hapus setelah X
    printList(head);

    deleteCondition(head, 10.5); // hapus X di awal
    printList(head);

    deleteCondition(head, 25.1); // hapus X di akhir
    printList(head);

    deleteCondition(head, 99.9); // X tidak ada
    printList(head);

    return 0;
}
