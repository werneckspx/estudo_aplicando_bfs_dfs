#include "fifo.hpp"
#include <iostream>

Fifo::Fifo() : front(nullptr), end(nullptr), memoriaUsada(0), picoMemoriaUsada(0) { }

bool Fifo::Empty() const {
    return front == nullptr;
}

void Fifo::Push(int value) {
    FifoNode *newNode = new FifoNode(value);
    memoriaUsada += sizeof(FifoNode);

    if (memoriaUsada > picoMemoriaUsada) {
        picoMemoriaUsada = memoriaUsada;
    }

    if (end) {
        end->setNext(newNode);
    }
    end = newNode;

    if (!front) {
        front = end;
    }
}

void Fifo::Pop() {
    if (Empty()) {
        return;
    }

    FifoNode *temp = front;
    front = front->getNext();

    if (!front) {
        end = nullptr;
    }

    delete temp;
    memoriaUsada -= sizeof(FifoNode);
}

FifoNode *Fifo::Front() {
    return front;
}
