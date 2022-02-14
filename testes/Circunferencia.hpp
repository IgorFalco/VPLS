#ifndef CIRCUNFERENCIA_H
#define CIRCUNFERENCIA_H

#include"Ponto.hpp"
#include"Triangulo.hpp"
#include"Retangulo.hpp"

struct Circunferencia
{
    float perimetro();
    float area();
    bool contem(Ponto&p);
    bool contem(Triangulo& p);
    bool contem(Retangulo& p);
    bool pertence(Ponto& p);
    bool circunscrita(Triangulo& t);
    bool circunscrita(Retangulo& r);

    Ponto p[2];

};







#endif