#include <iostream>
#include <cmath>
using namespace std;

// 乘法
/**
 * @param p: 被乘数
 * @param q: 乘数
 * @return: 乘积
*/
string multi(string p, string q) {
    string sum = "";
    for (int i = 0; i < p.size(); i++) {
        int carry = 0;
        string multi = "";
        for (int j = 0; j < q.size(); j++) {
            int val = (p[i] - '0') * (q[i] - '0');
            carry = val / 10;
            val %= 10;
            multi.insert(multi.begin(), val + '0');
        }
        if (carry) {
            multi.insert(multi.begin(), carry + '0');
        }

        if (sum.size() == 0) {
            sum = multi;
        } else {
            carry = 0;
            int len = max(sum.size(), multi.size());
            for (int k = len - 1; k >= 0; k--) {
                int val = sum[k - (len - sum.size())] + multi[k - (len - multi.size())];
                carry = val / 10;
                val %= 10;
                sum[k - (len - sum.size())] = val + '0';
            }
            if (carry) {
                sum.insert(sum.begin(), carry + '0');
            }
            sum.push_back('0');
        }
    }

    return sum;
}

int main() {
    string p = "";
    string q = "";
    cin >> p >> q;
    string sum = multi(p, q);
    cout << sum << endl;
    return 0;
}