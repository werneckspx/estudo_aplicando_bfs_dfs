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

    size_t getMemoriaUsada() const { return memoriaUsada; }
    size_t getPicoMemoriaUsada() const { return picoMemoriaUsada; }
private:
    FifoNode *front;
    FifoNode *end;

    size_t memoriaUsada = 0;
    size_t picoMemoriaUsada = 0;
};

#endif
