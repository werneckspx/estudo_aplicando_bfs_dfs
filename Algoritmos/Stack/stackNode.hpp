#ifndef STACKNODE_H
#define STACKNODE_H

#include <iostream>

class StackNode {
public:
    StackNode(int v, StackNode *a = nullptr) : value(v), ant(a) { }

    int getValue() const;
    StackNode *getAnt();

    void printTotalMemoryAllocated();

    void *operator new(std::size_t size);
    void operator delete(void *ptr) noexcept;
private:
    int value;
    StackNode *ant;
};

#endif