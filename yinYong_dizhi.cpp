//
// Created by mi on 5/25/17.
//

#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using  std::vector;



using namespace std;



int add_one(int a){
   cout<<"传值"<<endl;
    a+=1;
    return a;
}


int add_one_yiyong(int &a){
    cout<<"传引用"<<endl;
    a+=2;
    return a;
}

int add_one_dizhi(int *a){
    cout<<"传地址"<<endl;
    *a+=2;
    return *a;
}
/*

int main() {

    char a[6]="niho";

    int b=1;
    add_one(b);
    cout<<b<<endl;
//    add_one_yiyong(b);
//    cout<<b<<endl;
    add_one_dizhi(&b);
    cout<<b<<endl;

    cout<<b<<endl;

    cout<<*(&b);

}
*/



void test_vector(vector<int> A){
    A[0]=100;
}

void test_array(int A[]){
    A[0]=100;
}
/*

int main(){

    vector<int> A={1,2,3};
    test_vector(A);
    std::cout<<A[0]<<'\t';
    */
/*********************************//*


    int B[]={1,2,3};
    test_array(B);
    std::cout<<B[0]<<'\t';


}*/
