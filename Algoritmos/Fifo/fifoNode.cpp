#include "fifoNode.hpp"

int FifoNode::getValue() const {
    return value;
}

FifoNode *FifoNode::getNext() {
    return next;
}

void FifoNode::setNext(
    FifoNode *node
) {
    next = node;
}