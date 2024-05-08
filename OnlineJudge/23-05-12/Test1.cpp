
/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2019. All rights reserved.
 * Description: 上机编程认证
 * Note: 缺省代码仅供参考，可自行决定使用、修改或删除
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    // 待实现函数，在此函数中填入答题代码
    vector<int> SortArray(const vector<int>& numbers)
    {
        vector<int> odd = {};
        vector<int> even = {};
        vector<bool> split = {};
        vector<int> ret = {};
        for (int i = 0; i < numbers.size(); i++) {
            // 为偶数
            if (numbers[i] % 2 == 0) {
                even.push_back(numbers[i]);
                split.push_back(0);
                // 为奇数
            } else {
                odd.push_back(numbers[i]);
                split.push_back(1);
            }
        }

        sort(odd.begin(), odd.end());
        sort(even.begin(), even.end(), greater<int>());

        for (int i = 0, j = 0; i + j < numbers.size();) {
            if (split[i + j] == 0) {
                ret.push_back(even[i]);
                i++;
            } else {
                ret.push_back(odd[j]);
                j++;
            }
        }

        return ret;
    }
};

// 以下为考题输入输出框架，此部分代码不建议改动
inline int ReadInt()
{
    int number;
    std::cin >> number;
    return number;
}

template<typename T>
inline std::vector<T> ReadVector(int size)
{
    std::vector<T> objects(size);
    for (int i = 0; i < size; ++i) {
        std::cin >> objects[i];
    }
    return objects;
}

template<typename T>
inline void WriteVector(const std::vector<T>& objects, char delimeter = ' ')
{
    auto it = objects.begin();
    if (it == objects.end()) {
        return;
    }
    std::cout << *it;
    for (++it; it != objects.end(); ++it) {
        std::cout << delimeter << *it;
    }
    std::cout << std::endl;
}

int main()
{
    auto num = ReadInt();
    auto numbers = ReadVector<int>(num);
    Solution solution;
    WriteVector(solution.SortArray(numbers));
    return 0;
}
