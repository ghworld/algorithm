//
// Created by mi on 6/2/17.
//


#include "Utils.h"

//Rotate String


class Solution {
public:
    string rotateString(string &A, int offset) {
        if (A.empty() || A.size() == 0) {
            return A;
        }
        int len = A.size();
        offset %= len;
        reverse(A, 0, len - offset - 1);
        reverse(A, len - offset, len - 1);
        reverse(A, 0, len - 1);
        return A;
    }


private:
    void reverse(string &str, int start, int end) {
        while (start < end) {
            char temp = str[start];
            str[start] = str[end];
            str[end] = temp;
            start++;
            end--;
        }
    }


};


void rotateString(string A, int offset) {
//    这个方法的空间复杂度为O(n),最好可以到达O(1);如上所示方法,原地交换；

    int len = A.length();
    string after;
    string before;

    for (int i = len - offset; i < len; i++) {
        after += A[i];
    }

    for (int i = 0; i < len - offset; i++) {
        before += A[i];
    }

    cout << after << endl;
    cout << before << endl;
    cout << after + before << endl;

}

/*

int main() {

    Solution *solution = new Solution;
    string s1 = "abcdefg";
    int offset = 3;

    solution->rotateString(s1, offset);

    cout << s1 << endl;


    cout << "**********" << endl;
    string s2 = "abcdefg";
    rotateString(s2, offset);


}*/
