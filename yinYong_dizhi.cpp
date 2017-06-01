//
// Created by mi on 5/25/17.
//

#include <iostream>
#include <stdio.h>
#include <string>



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

//    char a[6]="niho";

    int b=1;
    add_one(b);
    cout<<b<<endl;
    add_one_yiyong(b);
    cout<<b<<endl;
    add_one_dizhi(&b);
    cout<<b<<endl;

    cout<<b<<end;

    cout<<*(&b);

}*/
