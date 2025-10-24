#include <iostream>
using namespace std;

// Deklarasi Node
struct Node {
    float data;
    Node* next;
};

// Prosedur membuat list kosong
void createList(Node* &head) {
    head = NULL;
}

// Prosedur membuat elemen baru
Node* createElement(float X) {
    Node* elm = new Node;
    elm->data = X;
    elm->next = NULL;
    return elm;
}

// Prosedur insertAscending
void insertAscending(Node* &head, Node* newNode) {
    if (head == NULL || newNode->data < head->data) {
        newNode->next = head;
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL && temp->next->data < newNode->data) {
            temp = temp->next;
        }
        newNode->next = temp->next;
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

int main() {
    Node* head;
    createList(head);

    // Tambah elemen secara ascending
    insertAscending(head, createElement(10.5));
    insertAscending(head, createElement(12.0));
    insertAscending(head, createElement(20.9));
    insertAscending(head, createElement(25.1));

    cout << "=== LIST ASCENDING ===" << endl;
    printList(head);

    // Tambah elemen baru
    cout << "\nTambahkan elemen baru bernilai 15.0:" << endl;
    insertAscending(head, createElement(15.0));
    printList(head);

    return 0;
}
