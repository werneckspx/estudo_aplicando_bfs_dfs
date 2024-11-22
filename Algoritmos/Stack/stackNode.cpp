#include "stackNode.hpp"

int StackNode::getValue() const {
    return value;
}

StackNode *StackNode::getAnt() {
    return ant;
}