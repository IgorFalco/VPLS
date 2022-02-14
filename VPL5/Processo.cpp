#include "Processo.hpp"

void Processo::imprimir_dados()
{
    std::cout << this -> _id << " " << this -> _nome << " " << this -> _prioridade << std::endl;
}