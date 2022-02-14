#ifndef TRIANGULO_H
#define TRIANGULO_H

#include<iostream>
#include<math.h>
#include "Ponto.hpp"

struct Triangulo{ 
    
    float perimetro();
    float area();
    bool equilatero();
    bool semelhante(Triangulo &t);

    Ponto p[3];

};



#endif