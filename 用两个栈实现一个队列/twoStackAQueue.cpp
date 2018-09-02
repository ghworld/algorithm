//
// Created by mi on 1/9/18.
//


#include <stack>
#include <iostream>

using namespace std;


//这只是个最普通的方法;
class Solution{

    stack<int> s1;
    stack<int> s2;

    int enqueue(int num){
        s1.push(num);
    }

    int dequeue(){
        if (s2.empty()){
            while (!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int top=s2.top();
        s2.pop();
        return top;
    }
};
//
//int main(){
//
//    Solution solution;
//    solution.enqueue(1);
//    solution.enqueue(2);
//    solution.enqueue(3);
//
//    cout<<solution.dequeue()<<endl;
//    cout<<solution.dequeue()<<endl;
//    cout<<solution.dequeue()<<endl;
//
//}