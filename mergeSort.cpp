//
// Created by mi on 7/6/17.
//


#include <vector>
#include <iostream>

using std::vector;

class MergeSort {

public:
    void merge_array(vector<int> &nums, int left, int mid, int right) {

        vector<int> sorted_array;
        int l = left;
        int r = mid + 1;


        while (l < mid + 1 && r < right + 1) {
            if (nums[l] < nums[r]) {
                sorted_array.push_back(nums[l]);
                l++;
            } else {
                sorted_array.push_back(nums[r]);
                r++;
            }
        }

        while (l < mid + 1) {
            sorted_array.push_back(nums[l]);
            l++;
        }

        while (r < right + 1) {
            sorted_array.push_back(nums[r]);
            r++;
        }


        for (int i = 0; i < right - left + 1; i++) {
            nums[i + left] = sorted_array[i];
        }


        print_vector(sorted_array);


    }


public:
    void merge_sort(vector<int> &nums, int left, int right) {

        int mid = (left + right) / 2;
        if (left < right) {
            merge_sort(nums, left, mid);
            merge_sort(nums, mid + 1, right);
            merge_array(nums, left, mid, right);

        }

    }

    void print_vector(vector<int> &nums) {
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            std::cout << nums[i] << ", ";
        }
        std::cout << std::endl;
    }


};

/*

int main() {

    vector<int> nums = {9, 4, 2, 3};
//
    MergeSort mergeSort;
    int left = 0;
    int right = nums.size() - 1;
    mergeSort.merge_sort(nums, left, right);


}*/
