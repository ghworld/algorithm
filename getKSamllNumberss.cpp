//
// Created by mi on 6/1/17.
//

//最小k个数


#include "Utils.h"


int partition(vector<int> nums, int start, int end) {
    int tmp = nums[start];
    while (start < end) {
        while (start < end & nums[end] >= tmp) {
            end--;
        }
        nums[start] = nums[end];
        while (start < end & nums[start] <= tmp) {
            start++;
        }
        nums[end] = nums[start];
    }
    nums[start] = tmp;

    return start;
}


vector<int> kSmallNums(vector<int> &nums, int k) {
    vector<int> kNums;

    int start = 0;
    int end = nums.size() - 1;
    int index = partition(nums, start, end);

    while (index != k - 1) {
        if (index > k - 1) {
            end = index - 1;
        } else {
            start = index + 1;
        }
        index = partition(nums, start, end);
    }
    for (int i = 0; i < k; i++) {
        kNums.push_back(nums[i]);
    }
    return kNums;
}


vector<int> kSmallNums_multiset(vector<int> nums, int k) {
    multiset<int, greater<int>> s;
    for (int i = 0; i < nums.size() && i < k; i++) {
        s.insert(nums[i]);
    }
    for (int i = k; i < nums.size(); i++) {
        int num = nums[i];
        if (num < *s.begin()) {
            s.erase(s.begin());
            s.insert(num);
        }
    }
    vector<int> res;
    while (!s.empty()) {
        res.push_back(*s.begin());
        s.erase(s.begin());
    }
    return res;
}

//int main() {
//    vector<int> v = {1, 2, 34, 5, 4};
////    vector<int> result = kSmallNums(v, 2);
//    vector<int> result = kSmallNums(v, 2);
//
//
//    for (int i = 0; i < result.size(); i++) {
//        std::cout << result[i] << endl;
//    }
//
//    return 0;
//
//}