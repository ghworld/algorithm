//
// Created by mi on 6/15/17.
//


#include "Utils.h"


double get_sqrt(double x) {
    double g = x;
    double delta = 0.00000001;
    while (fabs(g * g - x) > delta) {
        g = (g + x / g) / 2;
    }
    return g;
}

//int main() {
//
//    cout << get_sqrt(0.04);
//
//}
