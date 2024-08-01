#ifndef TEST_OVERRIDE_NEW_H
#undef  TEST_OVERRIDE_NEW_H

#include <cstddef>
#include <new>

// 标准 operator new，用于正常内存分配
void* operator new(std::size_t size, const char* file, int line);
void* operator new[](std::size_t size, const char* file, int line);
void operator delete(void* ptr) noexcept;

#define NEW new(__FILE__, __LINE__)
#define DELETE delete

#endif