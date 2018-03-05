//
// Created by mi on 7/5/17.
//

#include <iostream>
#include <vector>

using std::cout;
using std::vector;

/*
 * Search in Rotated Sorted Array
 * leetcode:  https://leetcode.com/problems/search-in-rotated-sorted-array/#/description
 * csdn:      http://www.cnblogs.com/grandyang/p/4325648.html
 *
 * */


class Solution {
public:
    int search(vector<int> &nums, int target) {
        int n = nums.size();

        if (n == 0) return -1;
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < nums[right]) {
                if (nums[mid] <= target && nums[right] >= target)
                    left = mid + 1;
                else
                    right = mid - 1;
            } else {
                if (nums[mid] >= target && nums[left] <= target)
                    right = mid - 1;
                else
                    left = mid + 1;

            }
        }

        return -1;


    }
};


/*
 * Search in Rotated Sorted Array II
 * http://www.cnblogs.com/grandyang/p/4325840.html
 * leetcode:  https://leetcode.com/problems/search-in-rotated-sorted-array-ii/#/description
 * */


class Solution2 {
public:
    bool search(vector<int> &nums, int target) {
        int len = nums.size();
        int left = 0;
        int right = len - 1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target)
                return true;
            else if (nums[mid] < nums[right]) {
                if (nums[mid] < target && nums[right] >= target)
                    left = mid + 1;
                else
                    right = mid - 1;

            } else if (nums[mid] > nums[right]) {
                if (nums[left] <= target &&  nums[mid] > target )
                    right = mid - 1;
                else
                    left = mid + 1;
            } else
                --right;

        }

        return false;

    }
};
/*

int main() {

    Solution *solution = new Solution();
    vector<int> A = {1, 2, 3, 4, 5, 6,6};
    cout << solution->search(A, 3)<<'\n';
    */
/******************************************//*

    Solution2 *solution2 = new Solution2();
    vector<int> B={3,5,1};
    cout<<solution2->search(B,3);
    cout<<'\n'<<true;


}*/
