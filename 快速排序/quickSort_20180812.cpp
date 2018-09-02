//
// Created by mi on 18-8-12.
//

#include <iostream>
#include <vector>
using namespace std;

//#define __tmain main

class Solution {
    int  adJust(vector<int> &arr, int start, int end) {

        int i=start;
        int j =end;
        int BASED= arr[i];

        while (i < j){
            while (i <j && arr.at(j) > BASED ){
                j--;
            }
            if(i<j){
                arr[i]=arr[j];
                i++;
            }
            while(i<j && arr.at(i) < BASED){
                i++;
            }
            if(i<j){
                arr[j]=arr[i];
                j--;
            }
        }
        arr[i]=BASED;
        return  i;
    }

public:
    void quickSort(vector<int> &arr,int start,int end) {
        if(start < end){
           int k= adJust(arr, start, end);
            quickSort(arr,start,k-1);
            quickSort(arr,k+1,end);
        }
    }

    void printArr(vector<int> arr){
        for(int i=0;i<arr.size();i++){
            cout <<"\t"<< arr.at(i);
        }
        cout<<endl;
    }

};
//
//
//int  __tmain() {
//
//    vector<int> nums={7,6,5,4,3,2,1};
//    Solution *solu = new Solution;
//
//    int length =nums.size()-1;
//    solu->quickSort(nums,0,length);
//    solu->printArr(nums);
//
//    return 0;
//}
