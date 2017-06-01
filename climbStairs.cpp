//
// Created by mi on 5/24/17.
//


#include <iostream>


int climbStairs(int n) {

    int result[n];


    result[0] = 1;

    if (n >= 2) {
        result[1] = 2;
    }
    for (int i = 2; i < n; i++) {
        result[i] = result[i - 1] + result[i - 2];
    }

    return result[n-1];

}/*


int main() {

    int n = 3;
    std::cout << climbStairs(n) << std::endl;
}
*/