//
// Created by mi on 7/4/17.
//


#include <stack>
#include <iostream>

typedef int ElementType;

using std::stack;

class Solution {
private:
    stack<ElementType> s1;
    stack<ElementType> s2;
public:
    ElementType push(ElementType data) {
        s1.push(data);
    }

    ElementType pop() {
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if (!s2.empty()) {
            ElementType result = s2.top();
            s2.pop();
            return result;
        } else {
            return 0;
        }
    };

};

/*

int main() {

    */
/*Solution mq;
    mq.push(1);
    mq.push(2);
    ElementType p1 = mq.pop();
    ElementType p2 = mq.pop();
    std::cout << p1 << "\t" << p2 << std::endl;*//*

*/
/********************************************************//*

    Solution *mq2=new Solution();
    mq2->push(1);
    mq2->push(2);
    ElementType p3 = mq2->pop();
    ElementType p4 = mq2->pop();
    std::cout<<p3<<'\t'<<p4<<std::endl;



}*/
