#include "fifo.hpp"

Fifo::Fifo() : front(nullptr), end(nullptr) { }

bool Fifo::Empty() const {
    return front == nullptr;
}

void Fifo::Push(int value) {
    FifoNode *newNode = new FifoNode(value);
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
}

FifoNode *Fifo::Front() {
    return front;
}