#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx; // 定义互斥锁

int counter = 0; // 共享变量

void incrementCounter(int id) {
    for (int i = 0; i < 20000; ++i) {
        mtx.lock(); // 加锁
        counter++;
        mtx.unlock(); // 解锁
    }
    std::cout << "Thread " << id << " finished." << std::endl;
}

int main() {
    std::thread t1(incrementCounter, 1);
    std::thread t2(incrementCounter, 2);

    t1.join();
    t2.join();

    std::cout << "Counter value: " << counter << std::endl;

    return 0;
}
