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

    int Size() const;

    size_t GetMemoriaTotalUsada() const { return picoMemoriaUsada; }
private:
    FifoNode *front;
    FifoNode *end;

    size_t picoMemoriaUsada = 0;
    size_t memoriaUsada = 0;
    size_t size = 0;
};

#endif
