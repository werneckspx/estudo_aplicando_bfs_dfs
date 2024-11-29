#ifndef STACKNODE_H
#define STACKNODE_H

#include <iostream>

class StackNode {
public:
    StackNode(int v, StackNode *a = nullptr) : value(v), ant(a) { }

    int getValue() const;
    StackNode *getAnt();
private:
    int value;
    StackNode *ant;
};

#endif