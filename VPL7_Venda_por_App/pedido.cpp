#include "pedido.hpp"


Pedido::~Pedido() {

 while(!m_produtos.empty()) delete m_produtos.front(), m_produtos.pop_front();
}

void Pedido::setEndereco(const std::string& endereco) {
  this->m_endereco = endereco;
}

float Pedido::calculaTotal() const {
float total = 0;
 
  for (auto const& it : m_produtos) {

      total = total + (it->getQtd() * it->getValor());
  }
  
  return total;
}

void Pedido::adicionaProduto(Produto* p) {

  this->m_produtos.push_back(p);
}

std::string Pedido::resumo() const {
  
  std::string str;
  for (auto const& it : m_produtos) {

      str += it->descricao() + "\n";
  }

  str += "Endereco: "+m_endereco;

  
  return str;
}

