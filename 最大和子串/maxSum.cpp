//
// Created by mi on 2/28/18.
//


//参考 http://blog.csdn.net/lecholin/article/details/71566557

#include <iostream>
using namespace std;
class Solution {
public:
    void maxSum(int array[],int length){ //联机算法,复杂度为O(n)
        int maxSum=0;
        int nowSum=0;
        bool negative=true;
        int maxStart=0;
        int maxEnd=0;
        int nowStart=0;
        int nowEnd=0;

        for (int i=0;i<length;i++){
            if(array[i]>0) negative= false;
        }

        if(negative) return ; //如果全负则退出

        for(int i=0;i<length;i++){

            nowSum+=array[i];
            if(nowSum>maxSum){
                maxSum=nowSum;
                nowEnd=i;
                maxEnd=nowEnd;
                maxStart=nowStart;
            }
            else if(nowSum<0){ //重新开始
                nowSum=maxSum=0;
                nowStart=nowEnd=i+1;
            }
        }

        cout << maxStart <<"\t"<<maxEnd<< "\t"<< maxSum<<endl;

    }
};


//
//int main(){
//
////    int a[10]={1,2,3,4,5,6};
//    int a[10]={1,2,-5,3,4,5,6};
//    int length=sizeof(a)/sizeof(int);
//    Solution solution;
//    solution.maxSum(a,length);
//
//
//}