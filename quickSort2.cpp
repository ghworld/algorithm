//
// Created by mi on 7/6/17.
//

#include <iostream>


int addjustArray(int s[], int l, int r) {
    int i = l;
    int j = r;
    int BASED = s[i];
    while (i < j) {
        while (i < j && s[j] > BASED) {
            j--;
        }
        if (i < j) {
            s[i] = s[j];
            i++;
        }
        while (i < j && s[i] < BASED) {
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


int quickSort2(int s[], int l, int r) {

    if (l < r) {
        int i = addjustArray(s, l, r);
        quickSort2(s, 0, i - 1);
        quickSort2(s, i + 1, r);
    }

}
/*

int main() {

    int array[] = {2, 1,4, 3};
    quickSort2(array, 0, 3);


    for (int i = 0; i < 4; i++) {
        std::cout << array[i] << '\n';
    }

}*/
