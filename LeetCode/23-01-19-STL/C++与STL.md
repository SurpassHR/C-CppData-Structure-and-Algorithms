# C++与STL

## 1.通过`Hello World!`分析C++基本语法

```c++
// 头文件
#include <iostream>

// 标准命名空间，解决不同工程间变量函数命名冲突的问题，std是C++标准库所在的命名空间
using namespace std;

int main() {
    cout << "Hello World!" << endl;

    return 0;
}
```

### 在C++中使用C语言的库函数

```c
/* C */
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
```
```C++
/* C++ */
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
```

## 2.基本数据类型

```C++
int number = 1;
char character = 'a';
bool boolean = true; // false
char* cString = "Hello";
string cppString = "World";
```
### C++结构体类型

```C
struct node {
    int number;
    node* next;
};
struct node* head; // 需要加struct
```

```C++
/* C++ */
struct node {
    int number;
    node* next;
};
node* head; // 不需要加struct
```

### C++结构体构造函数[struct.cpp](./struct.cpp)

```C++
struct st {
    int a, b;
    /* 构造函数与结构体同名 */
    st() : a(0), b(0) {}
    st(int _a, int _b) : a(_a), b(_b) {}
};

int main() {
    st newSt1 = st();
    st newSt2 = st(1, 2);
    cout << newSt1.a << newSt1.b << endl;
    cout << newSt2.a << newSt2.b << endl;

    return 0;
}
```

```bash
# Output
00
12
```

当重写了构造函数后，默认的无参构造函数消失，再次创建结构体时就必须使用含参的构造函数；但是C++支持函数重载，通过重载不同参数个数的构造函数也可以支持不同的创建结构体。

## 3.输入输出

```C++
/* 流输入cin */
cin >> number; // scanf("%d", &number);
cin >> character; // scanf("%c", &character);
cin >> cString; // scanf("%s", cString);
```

```C++
/* 流输出cout */
cout << number << endl; // 1
cout << character << endl; // a
cout << boolean << endl; // 1
cout ‹< cString << endl; // Hello
cout << cppString << endl; // World
```

## 4.动态内存分配[memory_allocate.cpp](./memory_allocate.cpp)

```C++
/* 区别于C中的动态分配内存 */
node* head = (node*)malloc(sizeof(node));
node* head1 = new node(); // new开辟空间并返回指针
```

## 5.引用类型[reference.cpp](./reference.cpp)

```bash
# Output
a = 1, b = 2
a = 2, b = 1
```

## 6.函数重载[overload.cpp](./overload.cpp)

```bash
# Output
调用了int sum(int a)
1
调用了double sum(double a)
1
调用了int sum(int a, int b)
2
```

**合法的重载方式:**
1. 函数名不同。
2. 形参类型不同。
3. 形参个数不同。
4. 有缺省值不引起调用时歧义。

### 函数的缺省值

```C++
int sum(int a, int b = 0) {
    cout << "调用的是int sum(int a, int b = 0)" << endl;
    return a + b;
}

int main() {
    int a = 1;
    cout << sum(a) << endl;

    return 0;
}
```

```bash
# Output
调用的是int sum(int a, int b = 0)
1
```

## 7.运算符重载[oprator_overload.cpp](./operator_overload.cpp)

```bash
# Output
<操作符重载
1
==操作符重载
0
>操作符重载
0
```
