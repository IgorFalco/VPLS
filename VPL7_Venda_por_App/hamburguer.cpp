#include "hamburguer.hpp"

std::string Hamburguer::descricao() const {
  
  std::string str;

  std::string quantidade_string(std::to_string(this->getQtd()));

  if(artesanal == true)
    str = quantidade_string +"X "+ "Hamburguer "  + tipo + " artesanal";
  else  
    str = quantidade_string + "X "+ "Hamburguer "  + tipo + " simples";

  return str;
}

Hamburguer::Hamburguer(const std::string& tipo,
                       bool artesanal,
                       int qtd,
                       float valor_unitario) {
  
  this->m_qtd = qtd;
  this->m_valor_unitario = valor_unitario;
  this->tipo = tipo;
  this->artesanal = artesanal;
}