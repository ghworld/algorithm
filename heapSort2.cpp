//
// Created by mi on 7/6/17.
//


#include <vector>
#include <iostream>

#include <set>

using namespace std;
using std::vector;


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

//        while (k < len) {
        int l = left(k);
        int r = right(k);
        int max_index = k;

        if (l < len && nums[max_index] < nums[l]) {
            max_index = l;
        }
        if (r < len && nums[max_index] < nums[r]) {
            max_index = r;
        }
        if (max_index == k) {
//                break;
            return;
        }

        int tmp = nums[k];
        nums[k] = nums[max_index];
        nums[max_index] = tmp;
        k = max_index;
//        }

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

    void print_heap(vector<int> nums, int heap_size) {

        for (int i = 0; i < heap_size; i++) {
            cout << nums[i] << ", ";
        }
        cout << endl;

    }


};


//2017.11.01重写一遍
class Solution {
public:
    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    void max_heapify(vector<int> &num, int k, int len) {
        int l = left(k);
        int r = right(k);
        int max_index = k;
        if (l < len && num[l] > num[max_index]) {
            max_index = l;
        }
        if (r < len && num[r] > num[max_index]) {
            max_index = r;
        }
        if (max_index == k) {
            return;
        }
//        交换值
        int tmp = num[k];
        num[k] = num[max_index];
        num[max_index] = tmp;
        k = max_index;

    }

    void print_heap(vector<int> &num, int heap_size) {
        for (int i = 0; i <heap_size; i++) {
            cout << num[i] << "\t";
        }
        cout << endl;
    }

    void build_max_heapify(vector<int> &num, int heap_size) {
        for (int i = heap_size / 2 - 1; i >= 0; i--) {
            max_heapify(num, i,heap_size);
        }
        print_heap(num, heap_size);
    }

    void heap_sort(vector<int> &num) {

        int len = num.size();
        build_max_heapify(num, len);
        for (int i = len - 1; i >= 0; i--) {
//            每次与0值进行交换,然后重新构建堆
            int tmp = num[0];
            num[0] = num[i];
            num[i] = tmp;
            build_max_heapify(num, i);
        }

        print_heap(num,len);
    };

};


/*int main() {

    vector<int> nums = {1, 2, 10, 3, 4, 5, 6};

 *//*   HeapSort *heapSort = new HeapSort();
    cout << "************************" << endl;
    heapSort->heap_sort(nums);*//*


    Solution *solution=new Solution();
    cout<<"***********************"<<endl;
    solution->heap_sort(nums);

}*/
