#include "fifoNode.hpp"

std::size_t totalMemoryAllocated = 0;
std::size_t totalMemoryDeallocated = 0;

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
void *FifoNode::operator new(std::size_t size) {
    totalMemoryAllocated += size;
    // std::cout << "[new] Allocating " << size << " bytes.\n";
    // std::cout << "Total " << totalMemoryAllocated << " bytes.\n";
    void *ptr = std::malloc(size);
    if (!ptr) {
        throw std::bad_alloc();
    }
    return ptr;
}

void FifoNode::operator delete(void *ptr) noexcept {
    std::free(ptr);
}

void FifoNode::printTotalMemoryAllocated() {
    std::cout << totalMemoryAllocated << std::endl;
}
