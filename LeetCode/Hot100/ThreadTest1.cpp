#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx; // 定义一个互斥量

void print_message(const std::string& message) {
    // mtx.lock(); // 对共享资源加锁
    std::cout << message << std::endl;
    // mtx.unlock(); // 对共享资源解锁
}

int main() {
    std::thread t1(print_message, "Hello");
    std::thread t2(print_message, "World");
    // 加锁输出输出就是 Hello\n World\n
    // 不加锁可能会出现 World\n Hello\n
    t1.join();
    t2.join();
    return 0;
}
