//
// Created by mi on 2/26/18.
//

#include <queue>
#include <iostream>
#include <stack>


using namespace std;

// c++ 的接中方法和其他的太不一样,这个用起来不方便
// 应该熟悉STL


class Solution{
    queue<int> q1;
    queue<int> q2;

public:
    int pop(){

        if (q1.empty() && q2.empty()){
            cout<<"two stack is empty";
            exit(-1);
        }
        if (q1.empty()){
            while (q2.size()>1){
                q1.push(q2.front());
                q2.pop();
            }
            int top=q2.front();
            q2.pop();
            return top;
        }
        else if(q2.empty()){
            while (q1.size()>1){
                q2.push(q1.front());
                q1.pop();
            }
            int top=q1.front();
            q1.pop();
            return top;
        }

    }

    void push(int element){
        if (q1.empty()){
            q2.push(element);
        } else if(q2.empty()){
            q1.push(element);
        }
    }
};

//
//int main(){
//
//    Solution solution;
//    solution.push(1);
//    cout<< solution.pop();
//}