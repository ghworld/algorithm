//
// Created by mi on 7/5/17.
//
#include <vector>
#include <iostream>
using std::vector;


class solution{
public:
    int search(vector<int> & nums,int target){
        int len=nums.size();
        if(len==0) return -1;
        int left=0;
        int right=len-1;
        while (left<=right){
            int mid=(left+right)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid] >target ){
             left=mid+1;
            } else if(nums[mid] <target ){
                right=mid-1;
            }
        }
        return  -1;
    }
};

/*


int main(){
    vector<int> A={1,2,3,4,5,6};
    solution *solution1=new solution();
    std::cout<<solution1->search(A,13);

}
*/
