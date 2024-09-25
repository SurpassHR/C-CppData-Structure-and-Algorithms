//
// Created by h30045134 on 2024/9/24.
//

#include <memory>
#include <iostream>

class CTest {
public:
    CTest()
    {
        std::cout << "CTest()" << std::endl;
    }
    ~CTest()
    {
        std::cout << "~CTest()" << std::endl;
    }
};

void Case1()
{
    std::cout << "-----------------------" << "\n";
    std::cout << "case1: " << "\n";
    // 申请裸指针但是不释放
    auto *ctBarePtr = new CTest; // 无法自动释放
}

void Case2()
{
    std::cout << "-----------------------" << "\n";
    std::cout << "case2: " << "\n";
    // 申请shared_ptr但是不释放
    std::shared_ptr<CTest> ctSharedPtr = std::make_shared<CTest>(); // 自动释放
    std::shared_ptr<CTest> ctSharedPtr1 = ctSharedPtr; // 在同一时间可以有多个指针持有该资源
}

void Case3()
{
    std::cout << "-----------------------" << "\n";
    std::cout << "case3: " << "\n";
    // 申请unique_ptr但是不释放
    std::unique_ptr<CTest> ctUniquePtr = std::make_unique<CTest>(); // 自动释放
    // std::unique_ptr<CTest> ctUniquePtr1 = ctUniquePtr; // Call to deleted constructor of 'std::unique_ptr<CTest>' 'unique_ptr' has been explicitly marked deleted here
    std::unique_ptr<CTest> ctUniquePtr1 = std::move(ctUniquePtr); // 在同一时间不能有多个指针持有该资源
}

void Case4()
{
    std::cout << "-----------------------" << "\n";
    std::cout << "case4: " << "\n";
    // 申请auto_ptr但是不释放
    std::auto_ptr ctAutoPtr(new CTest); // 自动释放
}

int main()
{
    Case1();
    Case2();
    Case3();
    Case4();

    return 0;
}