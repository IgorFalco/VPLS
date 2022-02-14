#include "pizza.hpp"

std::string Pizza::descricao() const {

  std::string str;
  
  std::string quantidade_string(std::to_string(this->getQtd()));
  std::string pedacos_string(std::to_string(pedacos));
  
  if(borda_recheada == true) 
    str = quantidade_string + "X Pizza "+ sabor + ", " + pedacos_string + " pedacos e borda recheada.";
    
  if(borda_recheada == false) 
    str = quantidade_string + "X Pizza "+ sabor + ", " + pedacos_string + " pedacos e sem borda recheada.";

  return str;

}

Pizza::Pizza(const std::string& sabor,
             int pedacos,
             bool borda_recheada,
             int qtd,
             float valor_unitario) {
  
  this->sabor = sabor;
  this->pedacos = pedacos;
  this->borda_recheada = borda_recheada;
  this->m_qtd = qtd;
  this->m_valor_unitario = valor_unitario;
}