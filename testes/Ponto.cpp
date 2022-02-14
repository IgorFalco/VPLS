#include "Ponto.hpp"
#include<iostream>


float Ponto::distancia(Ponto &p){

	float distancia_x;
	float distancia_y;

	distancia_x = (p.x - this->x)*(p.x - this->x);
	distancia_y = (p.y - this->y)*(p.y - this->y);
	
	return sqrt(distancia_x + distancia_y);
}

void Ponto::atribuir(float a, float b){

	this->x = a;
	this->y = b;
}