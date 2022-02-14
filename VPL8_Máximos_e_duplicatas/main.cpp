#include <vector>
#include <iostream>

#include "Algoritmos.hpp"

template <class T> void read_input(std::vector<T>& vec) {
  T val;
  while (std::cin >> val) {
    vec.push_back(val);
  }
}

template <class T> void print_input(std::vector<T>& vec) {

  for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec.at(i);
        if(i != vec.size() - 1)
            std::cout << ", ";
    }
    std::cout << std::endl;
}

template <class T> T get_max(std::vector<T>& vec) {
  
  T maior = vec[0];
  if (vec.empty()) {
    std::cout << "Erro: vetor vazio.\n";
  }
  for(size_t i = 0; i < vec.size(); i++)
  {
      if (maior > vec[i])
      {
          maior = maior;   
      }else{
          maior = vec[i];
      }
      
  }
  return maior;
}

template <class T> unsigned int count_duplicates(std::vector<T>& vec) {

  int k = 0;
  int contador = 0;
  int resultado[vec.size()];
  int aux = 0;

  std::vector<T> lista;
  
  lista = vec;

  for(int i = 0; i < vec.size(); i++)
  {
      for(int j = 0; j < lista.size(); j++)
        {
            if(vec[i] == lista[j])
            {
                k++;
                lista[j] = -1;
            } 
        }
        if(k == 0)
            resultado[i] = k;
        else
            resultado[i] = k - 1;
            
        k=0;
  }

  for(int i = 0; i < vec.size(); i++)
  {
      aux += resultado[i];
  }

  return aux;
}

template <class T> void test_print_input() {
  std::vector<T> vec;
  read_input(vec);
  print_input(vec);
}

template <class T> void test_get_max() {
  std::vector<T> vec;
  read_input(vec);
  std::cout << get_max(vec) << std::endl;
}

template <class T> void test_count_dups() {
  std::vector<T> vec;
  read_input(vec);
  std::cout << count_duplicates(vec) << std::endl;
}

int main() {
  int tipo_teste;
  std::cin >> tipo_teste;
  switch (tipo_teste) {
    case 0:
      test_print_input<std::string>();
      break;
    case 1:
      test_print_input<int>();
      break;
    case 2:
      test_get_max<double>();
      break;
    case 3:
      test_get_max<char>();
      break;
    case 4:
      test_count_dups<int>();
      break;
    case 5:
      test_count_dups<std::string>();
      break;
    default:
      std::cout << "Erro: teste invalido: " << tipo_teste << std::endl;
  }
  return 0;
}