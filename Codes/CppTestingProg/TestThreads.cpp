//
// Created by h30045134 on 2024/9/24.
//

#include <thread>
#include <iostream>
#include <atomic>
#include <mutex>

std::atomic<int> g_a = 0;
int g_b = 0;
int g_c = 0;
std::mutex g_mutex;

void IncreaseA()
{
    for (int i = 0; i < 30000; ++i) {
        g_a++;
    }
}

void IncreaseB()
{
    for (int i = 0; i < 30000; ++i) {
        g_b++;
    }
}

void IncreaseC()
{
    for (int i = 0; i < 30000; ++i) {
        g_mutex.lock();
        g_c++;
        g_mutex.unlock();
    }
}

int main()
{
    std::thread t1(IncreaseA);
    std::thread t2(IncreaseA);
    std::thread t3(IncreaseA);

    t1.join();
    t2.join();
    t3.join();

    std::cout << g_a << std::endl; // 未锁，但原子操作，90000

    std::thread t4(IncreaseB);
    std::thread t5(IncreaseB);
    std::thread t6(IncreaseB);

    t4.join();
    t5.join();
    t6.join();

    std::cout << g_b << std::endl; // 未锁，且非原子操作，不一定

    std::thread t7(IncreaseC);
    std::thread t8(IncreaseC);
    std::thread t9(IncreaseC);

    t7.join();
    t8.join();
    t9.join();

    std::cout << g_c << std::endl; // 上锁，但非原子操作，90000

    return 0;
}