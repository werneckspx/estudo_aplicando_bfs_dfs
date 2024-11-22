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
private:
    StackNode *top;
};

#endif