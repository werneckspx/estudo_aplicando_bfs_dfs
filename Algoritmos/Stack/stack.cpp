#include "stack.hpp"

Stack::Stack() : top(nullptr) { }

bool Stack::Empty() {
    return top == nullptr;
}

void Stack::Push(int d) {
    StackNode *aux = new StackNode(d, top);
    top = aux;
}

void Stack::Pop() {
    if (Empty()) {
        return;
    }

    StackNode *aux = top;
    top = aux->getAnt();
    delete(aux);
}

StackNode *Stack::Top() {
    return top;
}