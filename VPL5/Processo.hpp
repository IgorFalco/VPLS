#ifndef PROCESSO_HPP
#define PROCESSO_HPP

#include<iostream>

struct Processo
{
    int _id;
    int _prioridade;
    std::string _nome;

    Processo(int _id, std::string _nome, int _prioridade)
    {
        this -> _id = _id;
        this -> _nome = _nome;
        this -> _prioridade = _prioridade;
    };
    Processo(){};

    void imprimir_dados();
};

#endif
