//
// Created by mi on 7/13/18.
//


#include <cstdio>
#include <iostream>


using namespace std;
class Solution {
public:
    int solution(char *line) {
        int a;
        int b;
        sscanf(line, "%d%d", &a, &b);
        printf("%d\n", a + b);

    }
};
//
//
//int main() {
//    Solution *slt = new Solution();
//    std::cout<<"begin"<<endl;
//    char line[10];
//    sscanf("aa","%s",line);
//    printf("%s",line);
//    return 0;
//}