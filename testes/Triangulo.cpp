#include "Triangulo.hpp"

float Triangulo::perimetro(){
    float lado1;
    float lado2;
    float lado3;

    lado1 = this->p[0].distancia(this->p[1]);
    lado2 = this->p[1].distancia(this->p[2]);
    lado3 = this->p[2].distancia(this->p[0]);

    return lado1 + lado2 + lado3;
}

float Triangulo::area(){

    float p = perimetro()/2;

    float lado1;
    float lado2;
    float lado3;

    lado1 = this->p[0].distancia(this->p[1]);
    lado2 = this->p[1].distancia(this->p[2]);
    lado3 = this->p[2].distancia(this->p[0]);

    float area = 0;

    area = sqrt(p*(p-lado1)*(p - lado2)*(p-lado3));
    return area;
}

bool Triangulo::equilatero(){
    float lado1;
    float lado2;
    float lado3;

    lado1 = this->p[0].distancia(this->p[1]);
    lado2 = this->p[1].distancia(this->p[2]);
    lado3 = this->p[2].distancia(this->p[0]);

    if(lado1 == lado2 && lado2 == lado3)
        return true;
    else
        return false;
}

bool Triangulo::semelhante(Triangulo& t){
    float lado1_t;
    float lado2_t;
    float lado3_t;

    float lado1;
    float lado2;
    float lado3;

    lado1_t = t.p[0].distancia(t.p[1]);
    lado2_t = t.p[1].distancia(t.p[2]);
    lado3_t = t.p[2].distancia(t.p[0]);

    lado1 = this->p[0].distancia(this->p[1]);
    lado2 = this->p[1].distancia(this->p[2]);
    lado3 = this->p[2].distancia(this->p[0]);

    float a = 0;
    float b = 0;
    float c = 0;

    a = lado1 / lado1_t;
    b = lado2 / lado2_t;
    c = lado3 / lado3_t;

    if(a == b && b == c)
        return true;
    else    
        return false;

}