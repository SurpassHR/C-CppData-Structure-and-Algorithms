#include <iostream>
#include <algorithm>

// 1. 仿函数 std::greater<T>()

// 2. 自定义仿函数
struct Cmp {
    bool operator()(int a, int b) const
    {
        return a > b;
    }
};

// 3. 成员函数重载 -- ClassType::operator(ClassType rhs)
class CType {
public:
    CType() {}
    ~CType() {}
    operator () (CType rhs) {}
};
// 若有 CType a; CType b; CType c = a + b; 则等价于 CType c = a.operator()(b);

// 4. 非成员函数重载 -- operator(ClassType lhs, ClassType rhs)
operator () (CType lhs, CType rhs) {}
// 若有 CType a; CType b; CType c = a + b; 则等价于 CType c = operator()(a, b);

int main()
{
    return 0;
}