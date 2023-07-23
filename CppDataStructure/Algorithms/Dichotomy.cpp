#include <bits/stdc++.h>
using namespace std;

class Dichotomy {
public:
    int dichotomy(vector<int> nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};

int main() {
    vector<int> arr = { 5,2,11,9,7,17,21,6,3,11 };
    sort(arr.begin(), arr.end());
    int target = 0;
    cout << "Input num to find: ";
    cin >> target;
    int ret = Dichotomy().dichotomy(arr, target);
    cout << ret << endl;
    return 0;

}
