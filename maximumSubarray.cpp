//
// Created by mi on 6/1/17.
//

//Maximum Subarray


#include "Utils.h"

#include <math.h>

int maximumSubarray(vector<int> &V) {


    int begin = -1;
    int end = -1;

    int size = V.size();
    vector<int> local(size);
    vector<int> global(size);

    local[0] = V[0];
    global[0] = V[0];


    for (int i = 1; i < size; i++) {
        local[i] = max(V[i], local[i - 1] + V[i]);
        global[i] = max(global[i - 1], local[i]);
    }

    return global[size - 1];
}

/*

int main() {

    vector<int> vector1 = {10, -1, 1, 2, 3};


    cout << "*****************" << endl;
//    cout<<vector1[0]<<endl;
    int sum = maximumSubarray(vector1);
    cout << sum << endl;

    return 0;
}*/
