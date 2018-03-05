//
// Created by mi on 5/24/17.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int adjustArray(int s[], int l, int r) {
    int i = l;
    int j = r;
    int BASED = s[i];

    while (i < j) {
        //
        while (i < j & s[j] > BASED) {
            j--;
        }
        if (i < j) {
            s[i] = s[j];
            i++;
        }
        while (i < j & s[i] < BASED) {
            i++;
        }
        if (i < j) {
            s[j] = s[i];
            j--;
        }
    }

    s[i] = BASED;

    return i;

}


void quickSort(int arr[], int l, int r) {
    if (l < r) {
        int i = adjustArray(arr, l, r);
        quickSort(arr, 0, i - 1);
        quickSort(arr, i + 1, r);
    }

}


/*

int main() {

    int arr[5] = {2, 3, 4, 1, 5};

//    adjustArray(s, 0, 4);

    quickSort(arr, 0, 4);
    cout << "======================" << endl;
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << "\t";
    }

}

 */
