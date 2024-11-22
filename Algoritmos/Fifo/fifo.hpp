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

    void PrintMemoryUsage();

    size_t getMemoriaUsada() const { return memoriaUsada; }
    size_t getPicoMemoriaUsada() const { return picoMemoriaUsada; }
    size_t getMemoriaTotal() const { return memoriaTotal*sizeof(FifoNode); }
private:
    FifoNode *front;
    FifoNode *end;

    size_t memoriaTotal = 0;
    size_t memoriaUsada = 0;
    size_t picoMemoriaUsada = 0;
    size_t size = 0;
};

#endif
