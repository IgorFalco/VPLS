#ifndef PONTO2D_H
#define PONTO2D_H


#include<cmath>

struct Ponto2D
{
    double x;
    double y;

    Ponto2D(double x, double y)
    {
        this -> x = x;
        this -> y = y;    
    };
    Ponto2D(){};

    double calcular_distancia(Ponto2D* ponto);
};


#endif