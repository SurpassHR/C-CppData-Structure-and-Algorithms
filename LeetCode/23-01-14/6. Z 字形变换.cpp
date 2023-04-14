#include "../LeetCode.h"

class Solution {
public:
    string convert(string s, int numRows) {
        // Z字的一竖有numRows个元素
        // Z字中间有numRows - 2个元素

        // 一个周期有numRows + numRows - 2个元素
        int i, j;
        string ret, last, obliq, vert;
        ret.resize(s.size());
        // 一个完整周期元素个数
        int cycleNum = 2 * numRows - 2;
        // 斜线上的元素个数
        int obliqNum = numRows - 2;
        // 则竖线上的元素个数
        int vertNum = cycleNum - obliqNum;
        // 最后一个周期的元素个数
        int lastCycle;
        if (cycleNum == 0) {
            lastCycle = s.size();
        } else {
            lastCycle = s.size() % cycleNum;
        }
        // 完整周期数
        int cycles;
        if (cycleNum == 0) {
            cycles = 0;
        } else {
            cycles = s.size() / cycleNum;
        }
        // 取出最后一个周期元素
        last = s.substr(cycleNum * cycles, lastCycle);
        // 最后一个周期是否有斜线元素
        int lastObliqNum = last.size() % numRows == last.size() ? 0 : last.size() % numRows;
        string lastObliq;
        // 取出最后一个周期斜线元素
        if (lastObliqNum) {
            lastObliq = last.substr(numRows, lastObliqNum);
            reverse(lastObliq.begin(), lastObliq.end());
        }

        // 取出各个竖线元素
        for (i = 0; i < vertNum; i++) {
            for (j = i; j < cycleNum * cycles; j += cycleNum) {
                vert.append(1, s[j]);
            }
        }

        // 取出各个斜线元素
        for (i = cycleNum - 1; i >= vertNum; i--) {
            for (j = i; j < cycleNum * cycles; j += cycleNum) {
                obliq.append(1, s[j]);
            }
        }

        //         // 排列顺序
        //         for (i = 0; i < s.size(); i++) {
        //             // 界定范围
        //             // 1.位于竖线上
        //             // 条件: i % cycleNum < 4
        //             int vertIndex = (i / cycleNum) * vertNum + i % cycleNum;
        //             int obliqIndex = (i / cycleNum) * obliqNum + i % cycleNum - vertNum;
        //             int lastIndex = i % cycleNum;
        //
        //             if (i % cycleNum < numRows && vertIndex < vert.size()) {
        //                 cout << "i = " << i << endl;
        //                 ret.append(1, vert[vertIndex]);
        //             }
        //
        //             // 2.位于斜线上
        //             // 条件: 4 =< i % cycleNum < cycleNum
        //             else if (i % cycleNum >= numRows && i % cycleNum < cycleNum && obliqIndex < obliq.size()) {
        //                 cout << "i = " << i << endl;
        //                 ret.append(1, obliq[obliqIndex]);
        //             }
        //
        //             // 3.位于最后一个周期
        //             // 条件: i >= cycleNum * cycles && i % cycleNum < last.size()
        //             else if (i >= cycleNum * cycles && i % cycleNum < last.size()) {
        //                 cout << "i = " << i << endl;
        //                 ret.append(1, last[lastIndex]);
        //             }
        //         }

        for (i = 0; i < numRows; i++) {
            // 边界划分
            // 上边界
            // if (i >= 0 && i < 1) {
            if (i == 0) {
                for (j = i; j < s.size(); j += cycleNum) {
                    // 位于最后一个周期
                    if (j >= cycleNum * cycles) {
                        ret.append(1, last[i]);
                    } else {
                        ret.append(1, vert[i * cycles + (j / cycleNum)]);
                    }
                }
            }
            // 中间
            if (i >= 1 && i < numRows - 1) {
                for (j = i; j < s.size();) {
                    // 位于最后一个周期
                    if (j >= cycleNum * cycles) {
                        ret.append(1, last[i]);
                        // 如果最后一个周期存在斜线
                        if (lastObliqNum) {
                            j += 2 * i;
                            ret.append(1, lastObliq[i]);
                        }
                        j += cycleNum;
                    } else {
                        // 竖线
                        ret.append(1, vert[i * cycles + j / cycleNum]);
                        j += cycleNum - 2 * i;
                        // 斜线
                        ret.append(1, obliq[(i - 1) * cycles + j / cycleNum]);
                        j += 2 * i;
                    }
                }
            }
            // 下边界
            // if (i >= numRows - 1 && i < numRows) {
            if (i == numRows - 1) {
                for (j = i; j < s.size(); j += cycleNum) {
                    // 位于最后一个周期
                    if (j >= cycleNum * cycles) {
                        ret.append(1, last[i]);
                    } else {
                        ret.append(1, vert[i * cycles + (j / cycleNum)]);
                    }
                }
            }

        }

        return ret;
    }
};

class Solution1 {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> stringArr;
        stringArr.resize(numRows);
        string ret;
        int period = 2 * numRows - 2;
        int i;
        for (i = 0; i < s.size(); i++) {
            int mod = i % period;
            if (mod < numRows) {
                stringArr[mod] += s[i];
            } else {
                stringArr[period - mod] += s[i];
            }
        }

        for (auto substr : stringArr) {
            ret += substr;
        }

        return ret;
    }
};

int main(void) {
    Solution sl;
    string s = "PAYPALISHIRING";
    int numRows = 3;
    // sl.convert(s, numRows);

    Solution1 sl1;
    cout << sl1.convert(s, numRows) << endl;

    return 0;
}
