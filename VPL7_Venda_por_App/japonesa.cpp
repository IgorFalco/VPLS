#include "japonesa.hpp"

std::string Japonesa::descricao() const {
  
  std::string str;

  std::string quantidade_string(std::to_string(this->getQtd()));
  std::string sushis_string(std::to_string(sushis));
  std::string temakis_string(std::to_string(temakis));
  std::string hots_string(std::to_string(hots));

  str = quantidade_string + "X " + "Comida japonesa - " + combinado +  ", " + sushis_string + " sushis, " +  temakis_string + " temakis e " + hots_string + " hots.";
   
  return str;
}

Japonesa::Japonesa(const std::string& combinado,
                   int sushis,
                   int temakis,
                   int hots,
                   int qtd,
                   float valor_unitario) {

  this->combinado = combinado;
  this->sushis = sushis;
  this->temakis = temakis;
  this->hots = hots;
  this->m_qtd = qtd;
  this->m_valor_unitario = valor_unitario;
}