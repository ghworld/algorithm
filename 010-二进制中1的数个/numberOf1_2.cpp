//
// Created by mi on 18-8-12.
//
#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

class Solution{
public:
    int numberOf1(int n){
        int count=0;
        unsigned long flag=1;

        while (flag <=INT_MAX){
            if((n & flag) != 0 ){
                count++;
            }
            flag <<=1;
        }

        if((n & flag) !=0){
            count++;
        }

        return count;
    }
};

//
//
//int main(){
//
//    Solution *solu=new Solution;
//    int num=solu->numberOf1(2);
//
//    cout <<  num;
//}