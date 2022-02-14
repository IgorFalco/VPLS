#ifndef RETANGULO_H
#define RETANGULO_H

#include<iostream>
#include<math.h>
#include "Ponto.hpp"

struct Retangulo
{
    float perimetro();
    float area();
    bool quadrado();
    Ponto p[4];
};

#endif