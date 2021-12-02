#include<iostream>

#include"Shapes.h"

int main()
{
    Circle crcl("Circle", 5.0);
    Square sqr("Square", 2.0);
    Rectangle rctangl("Rectangle", 2.5, 4.0);
    Triangle trn("Triangle", 3., 4., 5.);

    Cube cbe("Cube", 6.);
    Sphere sph("Sphere", 5.);

    crcl.show_info();
    sqr.show_info();
    rctangl.show_info();
    trn.show_info();
    cbe.show_info();
    sph.show_info();

    return 0;
}
