#include <iostream>
using namespace std;

struct student {
    int scoreA, scoreB;
    student(): scoreA(0), scoreB(0) { }
    student(int _scoreA, int _scoreB): scoreA(_scoreA), scoreB(_scoreB) { }
    bool operator < (const student stuB) {
        cout << "<操作符重载" << endl;
        if (this->scoreA < stuB.scoreA) return this->scoreA < stuB.scoreA;
        return this->scoreB < stuB.scoreB;
    }
    bool operator == (const student stuB) {
        cout << "==操作符重载" << endl;
        if (this->scoreA == stuB.scoreA) return this->scoreA == stuB.scoreA;
        return this->scoreB == stuB.scoreB;
    }
    bool operator > (const student stuB) {
        cout << ">操作符重载" << endl;
        if (this->scoreA > stuB.scoreA) return this->scoreA > stuB.scoreA;
        return this->scoreB > stuB.scoreB;
    }
};

int main() {
    student A = student(95, 97);
    student B = student(98, 94);
    cout << (A < B) << endl;
    cout << (A == B) << endl;
    cout << (A > B) << endl;

    return 0;
}
