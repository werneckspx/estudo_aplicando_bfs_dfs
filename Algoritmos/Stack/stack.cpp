#include "stack.hpp"
#include <iostream>

Stack::Stack() : top(nullptr), memoriaUsada(0), picoMemoriaUsada(0) { }

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
}

void Stack::Pop() {
    if (Empty()) {
        return;
    }

    StackNode *aux = top;
    top = aux->getAnt();

    delete aux;
    memoriaUsada -= sizeof(StackNode);
}

StackNode *Stack::Top() {
    return top;
}
