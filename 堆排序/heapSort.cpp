//
// Created by mi on 6/1/17.
//
#include "../Utils.h"


class HeapSort {
    int parent(int i) {
        return (i - 1) / 2;
    }
    int left(int i) {
        return 2 * i + 1;
    }
    int right(int i) {
        return 2 * i + 2;
    }
    void max_heapify(vector<int> &nums, int k, int len) {
        while (k < len) {
            int max_index = k;
            int l = left(k);
            int r = right(k);
            if (l < len && nums[l] > nums[max_index]) {
                max_index = l;
            }
            if (r < len && nums[r] > nums[max_index]) {
                max_index = r;
            }
            if (k == max_index) {
                break;
            }
            int tmp = nums[k];
            nums[k] = nums[max_index];
            nums[max_index] = tmp;
            k = max_index;
        }
    }
    void build_max_heapify(vector<int> &nums, int heap_size) {
        for (int i = heap_size / 2 - 1; i >= 0; i--) {
            max_heapify(nums, i, heap_size);
        }
        print_heap(nums, heap_size);
    }

public:
    void heap_sort(vector<int> &nums) {
        int len = nums.size();
        build_max_heapify(nums, len);
        for (int i = len - 1; i >= 0; i--) {
            int tmp = nums[0];
            nums[0] = nums[i];
            nums[i] = tmp;
            build_max_heapify(nums, i);
        }
        print_heap(nums, len);
    }

public:
    void print_heap(vector<int> nums, int heap_size) {
        for (int i = 0; i < heap_size; i++) {
            cout << nums[i] << ", ";
        }
        cout << endl;
    }
};


/*int main(){
    int A[]={1,10,2,3,4,7,5,6};
    vector<int> nums;
    for(int i =0;i<sizeof(A)/sizeof(A[0]);i++)
        nums.push_back(A[i]);

    HeapSort sort;
    sort.print_heap(nums,nums.size());
    cout<<"*****************"<<endl;
    sort.heap_sort(nums);
}*/

