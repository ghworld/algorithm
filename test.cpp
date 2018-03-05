
// Created by mi on 4/13/17.
//

#include <stdio.h>
#include <stdlib.h>
#include <iostream>


struct person {
    int data;
    struct person *m;

};


struct SIMPLE
{
    int a;
    char b;
};

//声明结构体变量s1和指向结构体变量的指针s2
struct SIMPLE s1, *s2;

//给变量s1和s2的成员赋值,注意s1.a和s2->a并不是同一成员


#define __tmain main

#ifdef __tmain

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain




//
//int __tmain() {
//
//    person p;
//    p.data = 1;
//
//    std::cout << p.data;
//
//
//    struct person *p1;
////    p1->data=20;
//    p.m=p1;
////###################
//
// s1.a = 5;
//s1.b = 6;
////s2->a = 3;
////s2->b = 4;
//
//
//
//}
