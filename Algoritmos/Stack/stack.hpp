#ifndef STACK_H
#define STACK_H

#include "Stack/stackNode.hpp"

class Stack {
public:
    Stack();

    ~Stack() {
        while (!Empty()) {
            Pop();
        }
    }

    bool Empty();

    void Push(int d);

    void Pop();

    StackNode *Top();

    size_t getMemoriaUsada() const { return memoriaUsada; }
    size_t getPicoMemoriaUsada() const { return picoMemoriaUsada; }
private:
    StackNode *top;

    size_t memoriaUsada = 0;
    size_t picoMemoriaUsada = 0;
};

#endif