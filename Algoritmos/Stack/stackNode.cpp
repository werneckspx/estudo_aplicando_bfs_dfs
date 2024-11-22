#include "stackNode.hpp"

std::size_t totalMemoryAllocatedS = 0;

int StackNode::getValue() const {
    return value;
}

StackNode *StackNode::getAnt() {
    return ant;
}

void *StackNode::operator new(std::size_t size) {
    totalMemoryAllocatedS += size;
    // std::cout << "[new] Allocating " << size << " bytes.\n";
    // std::cout << "Total " << totalMemoryAllocatedS << " bytes.\n";
    void *ptr = std::malloc(size);
    if (!ptr) {
        throw std::bad_alloc();
    }
    return ptr;
}

void StackNode::operator delete(void *ptr) noexcept {
    std::free(ptr);
}

void StackNode::printTotalMemoryAllocated() {
    std::cout << totalMemoryAllocatedS << std::endl;
}