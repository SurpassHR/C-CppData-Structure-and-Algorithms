#include "TestOverrideNew.h"
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <iostream>

void* operator new(std::size_t size, const char* file, int line) {
    std::cout << "[" << file << ":" << line << "] " << "Allocating " << size << " bytes in file " << file << " at line " << line << std::endl;
    return std::malloc(size);
}

void* operator new[](std::size_t size, const char* file, int line) {
    std::cout << "Allocating " << size << " bytes in file " << file << " at line " << line << std::endl;
    return std::malloc(size);
}

// 重载的 operator delete，用于释放内存
void operator delete(void* ptr) noexcept {
    std::free(ptr);
}