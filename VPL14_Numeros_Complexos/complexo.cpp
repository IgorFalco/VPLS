// Copyright 2018 Universidade Federal de Minas Gerais (UFMG)

#include "complexo.h"

#include <cmath>

struct pontos
{
    double a;
    double b;
};


Complexo::Complexo() : Complexo(0, 0) {
}

Complexo::Complexo(double a) : Complexo(a, 0) {
}

Complexo::Complexo(double a, double b) {
    numero = new pontos;
    numero->a = a;
    numero->b = b;
}

double Complexo::real() const {
    return numero->a;
}

double Complexo::imag() const {
   return numero->b;
}

bool Complexo::operator==(Complexo x) const {
    if(x.numero->a == this->numero->a && x.numero->b == this->numero->b)
        return true;
    else
        return false;
}

void Complexo::operator=(Complexo x) {
   this->numero->a = x.numero->a;
   this->numero->b = x.numero->b;
  
} 

double Complexo::modulo() const {
    double modulo;

    modulo = sqrt((this->numero->a*this->numero->a)+(this->numero->b*this->numero->b));
    return modulo;
}

Complexo Complexo::conjugado() const {

    Complexo aux;
    aux.numero->a = this->numero->a;
    aux.numero->b = this->numero->b*(-1);
    return aux;
}

Complexo Complexo::operator-() const {
    Complexo aux;
    aux.numero->a = this->numero->a*(-1);
    aux.numero->b = this->numero->b*(-1);
    return aux;
}

Complexo Complexo::inverso() const {
    Complexo aux;
    if(this->numero->a == 0)
        aux.numero->a = 0;
    else
        aux.numero->a = 1/this->numero->a;

    if(this->numero->b == 0)
        aux.numero->b = 0;
    else
        aux.numero->b = 1/this->numero->b;

    return aux;
}

Complexo Complexo::operator+(Complexo y) const {
    Complexo soma;
    soma.numero->a = this->numero->a + y.numero->a;
    soma.numero->b = this->numero->b + y.numero->b;
    return soma;
}

Complexo Complexo::operator-(Complexo y) const {
    Complexo soma;
    soma.numero->a = this->numero->a - y.numero->a;
    soma.numero->b = this->numero->b - y.numero->b;
    return soma;
}

Complexo Complexo::operator*(Complexo y) const {
    Complexo mult;
    mult.numero->a = this->numero->a*y.numero->a - this->numero->b*y.numero->b ;
    mult.numero->b = this->numero->a*y.numero->b + this->numero->b*y.numero->a;
    return mult;
}

Complexo Complexo::operator/(Complexo y) const {
    Complexo div;
    if(this->numero->a*this->numero->a + this->numero->b*this->numero->b == 0)
    {
        div.numero->a = 0;
        div.numero->b = 0;
    }else{
        div.numero->a = (this->numero->a*y.numero->a + this->numero->b*y.numero->b)/(this->numero->a*this->numero->a + this->numero->b*this->numero->b);
        div.numero->b = (y.numero->a*this->numero->b - this->numero->a*y.numero->b)/(this->numero->a*this->numero->a + this->numero->b*this->numero->b);
    }
       
    

    return div;
}
