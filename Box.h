//
// Created by mi on 4/13/17.
//

#ifndef FIRSTDEMO_BOX_H
#define FIRSTDEMO_BOX_H


#include <cmath>

class Box {
public:
    double length;
    double width;
    double  height;

    Box(double lengthVal,double widthVal,double heightVal);

    double volume();

};


#endif //FIRSTDEMO_BOX_H
