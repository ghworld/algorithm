//
// Created by mi on 3/2/18.
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
// http://blog.csdn.net/so_geili/article/details/53737001

class Solution{


public:
    void LCS(vector<string> A,vector<string> B){
        vector<vector<int>> matrix=vector<vector<int>>(A.size()+1,vector<int>(B.size()+1));
        cout<<endl<<"scan matrix"<<endl;
        printVector(matrix);
        // 生成标示矩阵
        for(int i=1;i<A.size()+1;i++){
            for(int j=1;j<B.size()+1;j++){
                if(A[i-1]==B[j-1]){  // 因为i=1,j=1开始遍历的
                matrix[i][j]=matrix[i-1][j-1]+1;
                } else{
                    matrix[i][j]=max(matrix[i][j-1],matrix[i-1][j]);
                }
            }
        }
        cout<<endl<<"scan matrix"<<endl;
        printVector(matrix);

        // 根据矩阵提取LCS
        cout<<endl<<"scan LCS"<<endl;
        printLCS(matrix,A,B);
    }

    void printLCS(vector<vector<int>> matrix,vector<string> A,vector<string> B){
        int i=A.size();
        int j=B.size();
        int k=matrix[i][j];
        string s[k];
        cout<<"s.length():\t"<<s->length()<<endl;
        while (k>0){

            cout<<matrix[i][j]<<matrix[i][j-1]<<matrix[i-1][j]<<endl;
            if(matrix[i][j] == matrix[i][j-1]){
                j--;
                cout<<"1"<<endl;
            }
            else if(matrix[i][j] == matrix[i-1][j]) {
                i--;
                cout << "2" << endl;
            }
            else {
                s[k-1]=A[i-1];
                cout<<"k-1:\t"<<k-1<<"\t"<<A[i-1]<<endl;
                cout<<"3"<<endl;
                i--;
                j--;
            }
            k=k-1;
        }
        cout<< "序列：\t"<<endl;
        for (int p=0;p< sizeof(s)/sizeof(s[0]);p++){
            cout<<s[p]<<"\t";
        }
    }
    void printVector(vector<vector<int>> matrix){
        int m=matrix[0].size();
        int n=matrix.size();
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                cout<<matrix[i][j]<<"\t";
            }
            cout<<endl;
        }
    }
};
//
//
//int main(){
//
//    Solution solution;
//    vector<string> A={"A","B","C","D","E"};
//    vector<string> B={"A","B","C","D","E"};
//    solution.LCS(A,B);
//
////    int a[3]={0};
////    vector<int> v=vector<int>(3);
////    cout<<endl<<a[0]<<endl;
////    cout<<v[0]<<endl;
//
//}
