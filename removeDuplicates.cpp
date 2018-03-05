//
// Created by mi on 7/6/17.
//




#include <vector>
#include <iostream>

using std::vector;

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() == 0) return 0;
        int dup = nums[0];
        int end = 1;
        for (int i = 1; i < nums.size(); i++) {

            if (nums[i] != dup) { //与上个不重复时；
                nums[end] = nums[i];
                dup = nums[i];
                end++;
            }
        }

        return end;
    }


    int removeDuplicates_II(vector<int> &nums) {
        if (nums.size() == 0) return 0;
        int dup1 = nums[0];
        int dup2 = nums[1];
        int end = 2;
        for (int i = 2; i < nums.size(); i++) {

            if (nums[i] != dup1) { //与上个不重复时；
                nums[end] = nums[i];
                dup1 = dup2;
                dup2 = nums[i];
                end++;
            }
        }

        return end;
    }


    void print_array(vector<int> nums) {
        for (int i = 0; i < nums.size(); i++) {
            std::cout << nums[i] << "\t";
        }
    }

};


/*
int main() {
//    vector<int> nums = {1, 1, 2, 2, 3, 4};

    Solution solution;
//    int result = solution.removeDuplicates(nums);

//    std::cout << result << std::endl;

    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int result2 = solution.removeDuplicates_II(nums);
    std::cout << result2 << std::endl;
    solution.print_array(nums);

}*/
