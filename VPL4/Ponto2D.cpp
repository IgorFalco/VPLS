#include "Ponto2D.hpp"

double Ponto2D::calcular_distancia(Ponto2D* ponto)
{
    double dx = ponto -> x - this -> x;
    double dy = ponto -> y - this -> y;
    return sqrt(dx*dx - dy*dy);
}
