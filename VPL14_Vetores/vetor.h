#pragma once

#include <cassert>
#include <vector>

// Define um vetor de qualquer Tipo cujos índices variam em
// qualquer intervalo, inclusive negativos.
template <class Tipo> 
class Vetor {
  public:
    // Cria um vetor cujos índices variam de 'inicio' até 'fim'.
    // PRECONDIÇÃO: fim >= inicio.
    Vetor(int inicio, int fim);

    // Altera o valor do índice i.
    // PRECONDIÇÃO: i está dentro do intervalo de índices do vetor.
    void atribuir(int i, Tipo valor);

    // Retorna o valor do índice i.
    // PRECONDIÇÕES: 
    // (1) i está dentro do intervalo de índices do vetor.
    // (2) i foi inicializando anteriormente.
    Tipo valor(int i) const; 
  
  private:
    int inicio_;  // Primeiro índice válido do vetor.
    int fim_;  // Último índice válido do vetor.
    std::vector<Tipo> elementos_;  // Elementos do vetor.
    std::vector<bool> elementos_verificadores;
};

// DEFINIÇÃO DAS CLASSES DE EXCEÇÃO.

// Lançada quando o intervalo [inicio, fim] não contém nenhum índice.
struct ExcecaoIntervaloVazio {
  int inicio;  // Índice de início do arranjo que lançou a excecao.
  int fim;  // Índice de fim do arranjo que lançou a excecao.
};

//Lançada quando 'indice' não pertence a [inicio, fim].
struct ExcecaoIndiceInvalido {
  int inicio;  // Índice de início do arranjo que lançou a excecao.
  int fim;  // Índice de fim do arranjo que lançou a excecao.
  int indice;  // Índice inválido. 
};

// Lançada quando o valor de 'indice' é solicitado e o mesmo não foi previamente
// inicializado.
struct ExcecaoIndiceNaoInicializado {
  int indice;  // Índice do arranjo que não foi inicializado. 
};


// IMPLEMENTAÇÃO DOS MÉTODOS DA CLASSE.

template <class Tipo> 
Vetor<Tipo>::Vetor(int inicio, int fim) : 
    inicio_(inicio), 
    fim_(fim) {
    ExcecaoIntervaloVazio e{inicio_,fim_};
    if(fim_ < inicio_) throw e;
  elementos_.resize(fim - inicio + 1);
  elementos_verificadores.resize(fim - inicio + 1);
  
  for(int i = 0; i < elementos_verificadores.size(); i++){
    elementos_verificadores[i] = false;
  }
}

template <class Tipo> 
void Vetor<Tipo>::atribuir(int i, Tipo valor) {
    ExcecaoIndiceInvalido e{inicio_,fim_,i}; 
  if(i < inicio_ || i > fim_) throw e;
  int j = i - inicio_;
  elementos_[j] = valor;
  elementos_verificadores[j] = true;
}

template <class Tipo> 
Tipo Vetor<Tipo>::valor(int i) const { 
  ExcecaoIndiceInvalido e{inicio_,fim_,i};
  ExcecaoIndiceNaoInicializado k{i};

  if(i < inicio_ || i > fim_) throw e;
  int indice = i - inicio_;
  if(elementos_verificadores[indice] == false) throw k;


  int j = i - inicio_;     
  return elementos_[j];
}