#include "fifo.hpp"
#include <iostream>

Fifo::Fifo() : front(nullptr), end(nullptr) { }

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

    size++;
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
    size--;
}

FifoNode *Fifo::Front() {
    return front;
}

int Fifo::Size() const {
    return size;
}

