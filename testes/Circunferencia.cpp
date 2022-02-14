#include"Circunferencia.hpp"
#define PI 3.14

float Circunferencia::perimetro(){
    
    float raio;
    raio = this->p[0].distancia(p[1]);

    return (2 * PI * raio);
}

float Circunferencia::area(){
    float raio;
    raio = this->p[0].distancia(p[1]);

    return (PI * raio * raio);
}

bool Circunferencia::contem(Ponto& ponto){

    float raio;
    float distancia_raio_a_ponto;

    raio = this->p[0].distancia(p[1]);
    distancia_raio_a_ponto = this->p[0].distancia(ponto);

    if(distancia_raio_a_ponto > raio)
        return false;
    else
        return true;
}

bool Circunferencia::contem(Triangulo& t){

    int contagem = 0;

    if(contem(t.p[0]) == false)
        contagem++;
    if(contem(t.p[1]) == false)
        contagem++;
    if(contem(t.p[2]) == false)
        contagem++;

    if(contagem != 0)
        return false;
    else
        return true;
}

bool Circunferencia::contem(Retangulo& r){
    int contagem = 0;

    if(contem(r.p[0]) == false)
        contagem++;
    if(contem(r.p[1]) == false)
        contagem++;
    if(contem(r.p[2]) == false)
        contagem++;
    if(contem(r.p[3]) == false)
        contagem++;

    if(contagem != 0)
        return false;
    else
        return true;
}

bool Circunferencia::pertence(Ponto &ponto){
    float raio;
    float distancia_raio_a_ponto;

    raio = this->p[0].distancia(p[1]);
    distancia_raio_a_ponto = this->p[0].distancia(ponto);
    

    if(distancia_raio_a_ponto == raio || distancia_raio_a_ponto == 0)
        return false;
    else
        return true;
}

bool Circunferencia::circunscrita(Triangulo& t){
    int contagem = 0;

    if(pertence(t.p[0]) == false)
        contagem++;
    if(pertence(t.p[1]) == false)
        contagem++;
    if(pertence(t.p[2]) == false)
        contagem++;

    if(contagem != 0)
        return false;
    else
        return true;
    
}

bool Circunferencia::circunscrita(Retangulo& r){
    int contagem = 0;

    if(pertence(r.p[0]) == false)
        contagem++;
    if(pertence(r.p[1]) == false)
        contagem++;
    if(pertence(r.p[2]) == false)
        contagem++;
    if(pertence(r.p[3]) == false)
        contagem++;

    if(contagem != 0)
        return false;
    else
        return true;
}