//
// Created by mi on 5/24/17.
//

#include <iostream>


int trailingZeroes(int n) {

    int result=0;
    if (n < 5) {
        result = 0;
    } else {

        int k = n / 5;
        while (k > 0) {
            result += k;
            k = k / 5;
        }

    }

    return result;

}
/*

int main() {


    int n = 5;
    std::cout << trailingZeroes(n) << std::endl;

}*/
