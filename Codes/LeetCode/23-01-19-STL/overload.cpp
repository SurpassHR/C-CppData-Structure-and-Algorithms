#include <iostream>

using namespace std;

int sum(int a) {
    cout << "调用了int sum(int a)" << endl;
    return a;
}

double sum(double a) {
    cout << "调用了double sum(double a)" << endl;
    return a;
}

int sum(int a, int b) {
    cout << "调用了int sum(int a, int b)" << endl;
    return a + b;
}

int main() {
    int a = 1;
    int b = 1;
    double c = 1;

    cout << sum(a) << endl;
    cout << sum(c) << endl;
    cout << sum(a, b) << endl;

    return 0;
}
