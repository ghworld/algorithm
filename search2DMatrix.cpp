//
// Created by mi on 7/5/17.
//

/*
 *leetcode:
 *
 * 74. Search a 2D Matrix
 * https://leetcode.com/problems/search-a-2d-matrix/#/description
 *
 * */
#include <vector>
#include <iostream>

using std::vector;
using std::cout;

class solution {
public:
    bool searchMatrix(vector<vector<int>> &nums, int target) {


        if ( nums.size() == 0 || nums[0].size()== 0)
            return false;
        int n = nums.size();


        int left = 0;
        int right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid][0] == target) return true;
            else if (nums[mid][0] > target) {
                right = mid - 1;
            } else if (nums[mid][0] < target) {
                left = mid + 1;
            }
        }

        int row = right;
        if(row<0)
            return false;
        int low = 0;
        int m = nums[0].size();

        int high = m - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[row][mid] == target) return true;
            else {
                if (nums[row][mid] < target) {
                    low = mid + 1;

                } else if (nums[row][mid] > target) {
                    high = mid - 1;
                }
            }


        }

        return false;

    }
};
/*


int main() {
//    vector<vector<int>> A={{1,2,3},{4,5,6}};
    vector<vector<int>> A = {};
    solution *solution1 = new solution();
    cout << solution1->searchMatrix(A, 0);

}
*/
