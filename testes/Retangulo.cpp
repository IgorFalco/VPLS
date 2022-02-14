#include"Retangulo.hpp"

float Retangulo::perimetro(){
    float lado1;
    float lado2;
    float lado3; 
    float lado4;

    lado1 = this->p[0].distancia(p[1]);
    lado2 = this->p[1].distancia(p[2]);
    lado3 = this->p[2].distancia(p[3]);
    lado4 = this->p[3].distancia(p[0]);

    int conta = 0;
    if(lado2 != lado4){
        conta++;
    }
    if(lado1 != lado3){
        conta++;
    }
    if(conta != 0){
        std::cout <<"Não é um retângulo" << std::endl;
        return 0;
    }

    return (lado1 + lado2 + lado3 + lado4);
          
}

float Retangulo::area(){
    float lado1;
    float lado2;
    float lado3; 
    float lado4;

    lado1 = this->p[0].distancia(p[1]);
    lado2 = this->p[1].distancia(p[2]);
    lado3 = this->p[2].distancia(p[3]);
    lado4 = this->p[3].distancia(p[0]);

    int conta = 0;
    if(lado2 != lado4){
        conta++;
    }
    if(lado1 != lado3){
        conta++;
    }
    if(conta != 0){
        std::cout <<"Não é um retângulo" << std::endl;
        return 0;
    }
        
    
    return (lado1*lado2);

}

bool Retangulo::quadrado(){
    float lado1;
    float lado2;
    float lado3; 
    float lado4;

    lado1 = this->p[0].distancia(p[1]);
    lado2 = this->p[1].distancia(p[2]);
    lado3 = this->p[2].distancia(p[3]);
    lado4 = this->p[3].distancia(p[0]);

    int conta = 0;
    if(lado2 != lado4){
        conta++;
    }
    if(lado1 != lado3){
        conta++;
    }
    if(conta != 0){
        std::cout <<"Não é um retângulo" << std::endl;
        return 0;
    }

    if(lado1 == lado2 && lado3 == lado4){
        return true;
    }
        
    else{
        return false; 
    }  
       
}