#include "queue.h"

void createQueue(Queue &Q) {
    Q.head = -1;
    Q.tail = -1;
}

bool isEmptyQueue(Queue Q) {
    return (Q.tail == -1);
}

bool isFullQueue(Queue Q) {
    return ((Q.tail + 1) % MAX_SIZE == Q.head);
}

void enqueue(Queue &Q, infotype x) {
    if (isFullQueue(Q)) {
        std::cout << "Antrean Penuh" << std::endl;
    } else {
        if (isEmptyQueue(Q)) {
            Q.head = 0;
        }
        Q.tail = (Q.tail + 1) % MAX_SIZE;
        Q.info[Q.tail] = x;
    }
}

infotype dequeue(Queue &Q) {
    if (isEmptyQueue(Q)) {
        std::cout << "Antrean Kosong" << std::endl;
        return -1;
    } else {
        infotype x = Q.info[Q.head];

        if (Q.head == Q.tail) {
            createQueue(Q);
        } else {
            Q.head = (Q.head + 1) % MAX_SIZE;
        }
        return x;
    }
}

void printInfo(Queue Q) {
    std::cout << "H:" << Q.head << " T:" << Q.tail << " | Queue: ";
    if (isEmptyQueue(Q)) {
        std::cout << "empty queue" << std::endl;
    } else {
        int i = Q.head;
        while (i != Q.tail) {
            std::cout << Q.info[i] << " ";
            i = (i + 1) % MAX_SIZE;
        }
        std::cout << Q.info[Q.tail] << std::endl;
    }
}