//
// Created by mi on 5/25/17.
//

#include "Utils.h"



// 最长递增子序列
// 参考  http://blog.csdn.net/u013178472/article/details/54926531


int max_vector(vector<int> v1) {
    int max = -1;
    for (int i = 0; i < v1.size(); i++) {

        if (v1[i] > max) {
            max = v1[i];
        }
    }

    return max;
}

int LIS(vector<int> nums) {
    if (nums.empty())
        return 0;
    int len = nums.size();
    vector<int> lis(len, 1);

    for (int i = 1; i < len; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j] && (lis[i] < lis[j] + 1)) {
                lis[i] = lis[j] + 1;
            }
        }
    }
    return max_vector(lis);

}




//第二种方式

using namespace std;
#define len(a) (sizeof(a) / sizeof(a[0])) //数组长度

class Solution2 {
public:
    int lis(int arr[], int len) {
        int longest[len];
        for (int i = 0; i < len; i++)
            longest[i] = 1;

        for (int j = 1; j < len; j++) {
            for (int i = 0; i < j; i++) {
                if (arr[j] > arr[i] && longest[j] < longest[i] + 1) { //注意longest[j]<longest[i]+1这个条件，不能省略。
                    longest[j] = longest[i] + 1; //计算以arr[j]结尾的序列的最长递增子序列长度
                }
            }
        }

        int max = 0;
        for (int j = 0; j < len; j++) {
            cout << "longest[" << j << "]=" << longest[j] << endl;
            if (longest[j] > max) max = longest[j];  //从longest[j]中找出最大值
        }
        return max;
    }
};


//第三种方式  N*logN
class Solution3 {
public:
    int lis(vector<int> v1) {
        int len = v1.size();
        vector<int> arr(len, 1);  //这种初始化可以简单些;
        int max_pos = 1;
        int pos = 0;

        for (int i = 0; i < v1.size(); i++) {
            if (arr[max_pos-1] < v1[i]) {
                arr[max_pos] = v1[i];
                max_pos++;
            } else {
                pos = biSearch(arr, max_pos, v1[i]);
                arr[pos] = v1[i];
            }

        }
        return max_pos;

    }

    int biSearch(vector<int> arr, int len, int w) {
        int left = 0;
        int right = len - 1;
        int mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            if (arr[mid] < w) {
                left = mid + 1;
            } else if (arr[mid] > w) {
                right = mid - 1;
            } else {
                return mid; //找到了.
            }
        }
        return left;
    }


};

/*

int main() {
*/
/*
    vector<int> nums = {1, 2, 3, 0, 1, 4, 2, 3, 4, 5};
// Solution1

    int len=LIS(nums);
    cout<<len<<endl;*//*
*/
/*

*//*


//    Solution2
    int arr[] = {1, 4, 5, 6, 2, 3, 8}; //测试数组
    Solution2 *solution2 = new Solution2();
    int ret = solution2->lis(arr, len(arr));
    cout << "max increment substring len=" << ret << endl;
    return 0;


*/
/*
  //Solution3
    int a[] = {1, 2};
    Solution3 solution3;
    cout<<solution3.lis(nums);
*//*


}
*/

