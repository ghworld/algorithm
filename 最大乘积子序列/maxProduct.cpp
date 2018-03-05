//
// Created by mi on 2/24/18.
//

#include <iostream>
#include <vector>

// 最大乘积子序列问题

using namespace std;

class Solution{
public:
    int maxProduct(vector<int> A){
        int maxPro=0 ;
        int minPro=0 ;

        for(int i=0; i<A.size();i++){
            maxPro=max(max(A[i],maxPro*A[i]),minPro*A[i]);
            minPro=min(min(A[i],maxPro*A[i]),minPro*A[i]);
            maxPro=max(maxPro,minPro);
        }

        return maxPro;
    }
};

/*

int main(){

    cout<<"max product !"<<endl;
    Solution* solution;

    vector<int> A={1,2,3,4};
    cout<<"max product is : "<<solution->maxProduct(A);


}*/
