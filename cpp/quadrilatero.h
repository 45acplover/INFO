#ifndef QUADRILATERO_H
#define QUADRILATERO_H
#include <iostream>
#include <cmath>

class QUADRILATERO
{
    private:
    double lato1;
    double lato2;
    double lato3;
    double lato4;

    public:
    void setlato1(double a);
    void setlato2(double b);
    void setlato3(double c);
    void setlato4(double d);
    void getlato1();
    void getlato2();
    void getlato3();
    void getlato4();

};



#endif