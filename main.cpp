#include <stdio.h>
#include <stdlib.h>
#include <iostream>
//#include "LinkedList.h"
#include "Box.h"


using namespace std;


struct User {
    int age;
    string name;

    User(int ageVal) : age(ageVal) {};

    User(int ageVal, string name) : age(ageVal), name(name) {};

};

/*
int main() {
    User *user1 = new User(1);
    std::cout << user1->age << endl;
    std::cout << user1->name<<endl;
//    User user2 = User(2,"guohao");
//
//    std::cout<<user2.age<<endl;
//    std::cout<<user2.name;

}*/


//int main(void) {







//    Box *box = new Box(1, 2, 3);
//
//    cout << box->width << endl;


//    LinkList* list = LinkList_Create();
//
//    int i = 0;
//
//    Value v1, v2, v3, v4, v5;
//
//    v1.v=1, v2.v=2, v3.v=3, v4.v=4, v5.v=5;
//
//    LinkList_Insert(list, (LinkListNode*)&v1, 0);
//    LinkList_Insert(list, (LinkListNode*)&v2, 0);
//    LinkList_Insert(list, (LinkListNode*)&v3, 0);
//    LinkList_Insert(list, (LinkListNode*)&v4, 0);
//    LinkList_Insert(list, (LinkListNode*)&v5, 0);
//
//    Value* pV = NULL;
//
//    for(i=0; i<LinkList_Length(list); i++)
//    {
//        pV = (Value*)LinkList_Get(list, i);
//
//        printf("%d\n", pV->v);
//    }
//
//    while(LinkList_Length(list) > 0)
//    {
//        pV = (Value*)LinkList_Delete(list, LinkList_Length(list)-1);
//
//        printf("%d\n", pV->v);
//    }
//
//    LinkList_Destroy(list);

//    return 0;
//}