//
// Created by mi on 5/25/17.
//
#include <string>
#include <vector>
#include <math.h>
#include <iostream>

using std::string;
using std::vector;
using std::max;
using std::cout;
using std::endl;


void print_LCS(vector<vector<int>> LCS, string A, string B,int i ,int  j ) {

    int len_A = A.size();
    int len_B = B.size();
//    for (int i = len_A; i > 0; i--) {
//        for (int j = len_B; j > 0; j--) {
            if (A[i - 1] == B[j - 1]) {
                cout << A[i] << endl;
                i--;
                j--;
            } else {
                if (LCS[i][j - 1] > LCS[j - 1][i]) {
                    j--;
                } else {
                    i--;
                }
            }

    print_LCS(LCS,A,B,i,j);
//        }
//    }


}


void scan_ventor(vector<vector<int>> A) {
    int m = A.size();
    int n = A[0].size();


    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
}

int LCS(string A, string B) {
    if (A.empty()) return 0;
    if (B.empty()) return 0;

    int len_A = A.size();
    int len_B = B.size();


    vector<vector<int>> LCS = vector<vector<int>>(1 + len_A, vector<int>(1 + len_B));

    for (int i = 1; i < 1 + len_A; i++) {
        for (int j = 1; j < 1 + len_B; j++) {

            if (A[i - 1] == B[j - 1]) {
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            } else {
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
            }


        }
    }

//scan vector
    scan_ventor(LCS);
    cout << "===================" << endl;
//print longest common subsequence
    print_LCS(LCS, A, B,1+len_A,1+len_B);

    return LCS[len_A][len_B];

}
/*


int main() {

    string A = "guahaoc";
    string B = "guohao";

    int lcs_length = LCS(A, B);
    cout << lcs_length << std::endl;


}*/
