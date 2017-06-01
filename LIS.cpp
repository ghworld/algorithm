//
// Created by mi on 5/25/17.
//

#include "Utils.h"



//longest inscrease sequence


int max_vector(vector<int> v1){
    int max=-1;
    for(int  i =0; i <v1.size();i++){

        if(v1[i]>max){
            max=v1[i];
        }
    }

    return max;
}

int LIS(vector<int> nums){
    if(nums.empty())
        return 0;
    int len=nums.size();
    vector<int> lis(len,1);

for(int i=1;i<len;++i){
    for(int j =0;j<i;++j){
        if(nums[i]>nums[j] && (lis[i]<lis[j]+1)){
            lis[i]=lis[j]+1;
        }
    }
}
    return max_vector(lis);


}

//
//int main(){
//
//
//
//    vector<int> nums={1,2,3,0,1,4,2,3,4,5};
//
//    int len=LIS(nums);
//    cout<<len<<endl;
//
////    cout<<max_vector(nums);
//}