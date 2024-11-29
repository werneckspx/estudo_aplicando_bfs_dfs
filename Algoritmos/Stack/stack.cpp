#include "stack.hpp"
#include <iostream>

Stack::Stack() : top(nullptr) { }

bool Stack::Empty() {
    return top == nullptr;
}

void Stack::Push(int d) {
    StackNode *aux = new StackNode(d, top);
    memoriaUsada += sizeof(StackNode);

    if (memoriaUsada > picoMemoriaUsada) {
        picoMemoriaUsada = memoriaUsada;
    }

    top = aux;
    size++;
}

void Stack::Pop() {
    if (Empty()) {
        return;
    }

    StackNode *aux = top;
    top = aux->getAnt();

    delete aux;
    memoriaUsada -= sizeof(StackNode);
    size--;
}

StackNode *Stack::Top() {
    return top;
}

int Stack::Size() const {
    return size;
}

