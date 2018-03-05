//
// Created by mi on 7/3/17.
//


#include <iostream>

int sum,ans[8];
int solve(int n, long long mark, int *ans){
    for (int i=n>8?++sum&0:0; n>8&&i<8; i!=7?std::cout << ans[i++] << " " : std::cout << ans[i++] << std::endl);
    for (int i=0; i<8; !(mark>>i&1)&&!(mark>>(n+i+7)&1)&&!(mark>>(n-i+30)&1)?solve(n+(ans[n-1]=i+1)-i, mark|1ll<<i|1ll<<(n+i+7)|1ll<<(n-i+30), ans):0,i++);
    return sum;
}
//int main(){
//    std::cout << solve(1, 0, ans) << std::endl;
//}

using namespace std;

int c[20], n=8, cnt=0;
void print(){
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            if(j == c[i]) cout<<"1 ";
            else cout<<"0 ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void search(int r){
    if(r == n){
        print();
        ++cnt;
        return;
    }
    for(int i=0; i<n; ++i){
        c[r] = i;
        int ok = 1;
        for(int j=0; j<r; ++j)
            if(c[r]==c[j] || r-j==c[r]-c[j] || r-j==c[j]-c[r]){
                ok = 0;
                break;
            }
        if(ok) search(r+1);
    }
}

//int main(){
//    search(0);
//    cout<<cnt<<endl;
//    return 0;
//}