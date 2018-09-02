//
// Created by mi on 18-8-12.
//


#include <iostream>
#include <vector>

using namespace std;


//#define __tmain main


class Solution {


public:
//    大顶堆
    void maxHeapify(vector<int> &arr, int k, int length) {

        while (k < length) {
            int l = 2 * k + 1;
            int r = 2 * k + 2;
            int max_index = k;

            if (l < length && arr[l] > arr[max_index]) {
                max_index = l;
            }
            if (r < length && arr[r] > arr[max_index]) {
                max_index = r;
            }

            if (k == max_index) {
                break;
            }
            int tmp = arr[k];
            arr[k] = arr[max_index];
            arr[max_index] = tmp;
            k = max_index;
        }
    }

    void buildMaxHeap(vector<int> &arr, int length) {
        for (int i = length / 2 - 1; i >= 0; i--) {
            maxHeapify(arr, i, length);
        }
    }

//从小到大排序
    void heapSort(vector<int> &arr) {
        int length = arr.size();
        buildMaxHeap(arr, length);
        for (int i = length - 1; i >= 0; i--) {
            int tmp = arr[i];
            arr[i] = arr[0];
            arr[0] = tmp;
            buildMaxHeap(arr, i);
        }

    }

    void printHeap(vector<int> arr) {
        for (int i = 0; i < arr.size(); i++) {
            cout << arr.at(i) << "\t";
        }
        cout << endl;
    }
};
//
//
//int __tmain() {
//    vector<int> nums = {7, 6, 5, 4, 3, 2, 1};
//    Solution *solu = new Solution();
//    solu->heapSort(nums);
//    solu->printHeap(nums);
//    return 0;
//}
//
//

