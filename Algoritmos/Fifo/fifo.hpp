#ifndef FIFO_H
#define FIFO_H

#include "Fifo/fifoNode.hpp"

class Fifo {
public:
    Fifo();

    ~Fifo() {
        while (!Empty()) {
            Pop();
        }
    }

    FifoNode *Front();

    void Push(int value);

    void Pop();

    bool Empty() const;
private:
    FifoNode *front;
    FifoNode *end;
};

#endif
