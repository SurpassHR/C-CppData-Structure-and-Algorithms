#include <iostream>
#include <stack>
#include <map>

using namespace std;

#define MAX 10000

// 栈：操作符，操作数
stack<int> oprd;
stack<char> oprt;
// 符号优先级映射
map<int, int> mapOprtPrior;

int calc(char oprt, int a, int b) {
    if (oprt == '+') {
        cout << a << " + " << b << endl;
        return a + b;
    } else if (oprt == '-') {
        cout << a << " - " << b << endl;
        return a - b;
    } else if (oprt == 'x') {
        cout << a << " * " << b << endl;
        return a * b;
    } else if (oprt == '/') {
        cout << a << " / " << b << endl;
        return a / b;
    }

    cout << "oprt = " << oprt << endl;

    return INT32_MAX;
}

int main() {
    mapOprtPrior.emplace('+', 0);
    mapOprtPrior.emplace('-', 0);
    mapOprtPrior.emplace('x', 1);
    mapOprtPrior.emplace('/', 1);
    // 操作数，第一个数字，读入字符，临时变量，答案
    int num, fst, t, ans = 0;
    // 操作符
    char op;
    // 读入第一个数字
    cin >> fst;
    oprd.push(fst);
    // op为操作符，num为操作数
    while (cin >> op >> num) {
        // 若操作符栈为空则入栈
        if (oprt.empty()) {
            oprt.push(op);
        } else {
            // 若操作符优先级低于或等于栈顶操作符优先级，则栈顶操作符出栈运算
            if (mapOprtPrior[op] <= mapOprtPrior[oprt.top()]) {
                int x, y;
                x = oprd.top();
                oprd.pop();
                y = oprd.top();
                oprd.pop();
                oprd.push(calc(oprt.top(), y, x));
                oprt.pop();
                oprt.push(op);
            } else {
                oprt.push(op);
            }
        }
        // 操作数入栈
        oprd.push(num);
    }

    while (!oprd.empty() && !oprt.empty()) {
        int x, y;
        x = oprd.top();
        oprd.pop();
        y = oprd.top();
        oprd.pop();
        oprd.push(calc(oprt.top(), y, x));
        oprt.pop();
    }

    cout << oprd.top() << endl;

    return 0;
}
