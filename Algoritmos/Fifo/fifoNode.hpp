#ifndef FIFONODE_H
#define FIFONODE_H

#include <iostream>

class FifoNode {
public:
    FifoNode(int v, FifoNode *n = nullptr) : value(v), next(n) { }

    int getValue() const;
    FifoNode *getNext();
    void setNext(FifoNode *node);

    void printTotalMemoryAllocated();

    void *operator new(std::size_t size);
    void operator delete(void *ptr) noexcept;
private:
    int value;
    FifoNode *next;
};

#endif