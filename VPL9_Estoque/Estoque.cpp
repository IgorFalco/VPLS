#include <string>
#include<iostream>

#include "Estoque.hpp"

void Estoque::add_mercadoria(const std::string& mercadoria, unsigned int qtd) {
  
  std::map<std::string,unsigned int>::iterator it;
  
  it = lista_produtos.find(mercadoria);

  if(it == lista_produtos.end()){
      
      this->lista_produtos.insert(std::pair<std::string, unsigned int>(mercadoria, qtd));

  } else{

      it->second += qtd;
  }
  
}

void Estoque::sub_mercadoria(const std::string& mercadoria, unsigned int qtd) {

  std::map<std::string,unsigned int>::iterator it;
  
  it = lista_produtos.find(mercadoria);

  if(it == lista_produtos.end()){

      std::cout << mercadoria << " inexistente" << std::endl;

  } else{
      
      if(it->second < qtd){
          std::cout << mercadoria << " insuficiente"<< std::endl;
      }else{
          
          it->second -= qtd; 
      }
      
  }
}

unsigned int Estoque::get_qtd(const std::string& mercadoria) const {

    std::map<std::string,unsigned int>::const_iterator it;

    it = lista_produtos.find(mercadoria);

    if(it == lista_produtos.end())
        return 0;
        else{
            return it->second;
        }
}

void Estoque::imprime_estoque() const {

    std::map<std::string,unsigned int>::const_iterator it;

    for(it = lista_produtos.begin(); it != lista_produtos.end();it++){

        std::cout << it->first << ", "<< it->second << std::endl;
    }
}

Estoque& Estoque::operator += (const Estoque& rhs) {
  
  std::map<std::string,unsigned int>::iterator it;
  std::map<std::string,unsigned int>::const_iterator c_it;
  std::map<std::string,unsigned int>::const_iterator c_it2;

  for(it = this->lista_produtos.begin(); it != this->lista_produtos.end(); it++)
    for(c_it = rhs.lista_produtos.begin(); c_it != rhs.lista_produtos.end(); c_it++)
    {
        if(it->first == c_it->first)
        {
            it->second += c_it->second; 
        }else
            continue;
    }

  for(c_it = rhs.lista_produtos.begin(); c_it != rhs.lista_produtos.end(); c_it++)
    for(it = this->lista_produtos.begin(); it != this->lista_produtos.end(); it++) 
    {
        c_it2 = this->lista_produtos.find(c_it->first);

        if(c_it2 == this->lista_produtos.end())
        {
            this->lista_produtos.insert(std::pair<std::string, unsigned int>(c_it->first, c_it->second));
        }
    }

    if(this->lista_produtos.begin() == this->lista_produtos.end())
    {
        for(c_it = rhs.lista_produtos.begin(); c_it != rhs.lista_produtos.end(); c_it++)
        {
            this->lista_produtos.insert(std::pair<std::string, unsigned int>(c_it->first, c_it->second));
        }
    }
  
    

  return *this;
}

Estoque& Estoque::operator -= (const Estoque& rhs) {

  std::map<std::string,unsigned int>::iterator it;
  std::map<std::string,unsigned int>::const_iterator c_it;

  for(it = this->lista_produtos.begin(); it != this->lista_produtos.end(); it++)
    for(c_it = rhs.lista_produtos.begin(); c_it != rhs.lista_produtos.end(); c_it++)
    {
        if(it->first == c_it->first)
        {
            it->second -= c_it->second; 
        }
    }
  return *this;
}

bool operator < (Estoque& lhs, Estoque& rhs) {

  std::map<std::string,unsigned int>::iterator it_lhs;
  std::map<std::string,unsigned int>::iterator it_rhs;
  int confere = 0;

      for(it_lhs = lhs.lista_produtos.begin(); it_lhs != lhs.lista_produtos.end(); it_lhs++)
        {
            it_rhs = rhs.lista_produtos.find(it_lhs->first);

                if(it_rhs == rhs.lista_produtos.end())
                    return false;
                else
                    continue;
        };

  for(it_lhs = lhs.lista_produtos.begin(); it_lhs != lhs.lista_produtos.end(); it_lhs++)
  {
      for(it_rhs = rhs.lista_produtos.begin(); it_rhs != rhs.lista_produtos.end(); it_rhs++)
        {
            if(it_lhs->first == it_rhs->first && it_lhs->second >= it_rhs->second)
            {
                    confere++;    
            }
        }
  };

  if(confere != 0)
        return false;
    else
        return true;
}

bool operator > (Estoque& lhs, Estoque& rhs) {

  std::map<std::string,unsigned int>::iterator it_lhs;
  std::map<std::string,unsigned int>::iterator it_rhs;
  int confere = 0;

      for(it_rhs = rhs.lista_produtos.begin(); it_rhs != rhs.lista_produtos.end(); it_rhs++)
        {
            it_lhs = lhs.lista_produtos.find(it_rhs->first);

                if(it_lhs == lhs.lista_produtos.end())
                    return false;
                else
                    continue;
        };

  for(it_lhs = lhs.lista_produtos.begin(); it_lhs != lhs.lista_produtos.end(); it_lhs++)
  {
      for(it_rhs = rhs.lista_produtos.begin(); it_rhs != rhs.lista_produtos.end(); it_rhs++)
        {
            if(it_lhs->first == it_rhs->first && it_lhs->second <= it_rhs->second)
            {
                    confere++;    
            }
        }
  };

  if(confere != 0)
        return false;
    else
        return true;
}
