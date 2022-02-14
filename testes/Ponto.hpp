#ifndef PONTO_H
#define PONTO_H
#include<iostream>
#include<math.h>

struct Ponto
{
	float x;
	float y;

	float distancia(Ponto &p);

	void atribuir(float a, float b);
};

#endif