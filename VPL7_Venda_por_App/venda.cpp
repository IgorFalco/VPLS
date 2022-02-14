#include "venda.hpp"

#include <iomanip>

Venda::~Venda() {
  while(!m_pedidos.empty()) delete m_pedidos.front(), m_pedidos.pop_front();
}

void Venda::adicionaPedido(Pedido* p) {
  this->m_pedidos.push_back(p);
}

void Venda::imprimeRelatorio() const {

  float total = 0;
  int a = 0;

  for (auto const& it : m_pedidos) {
      
      std::cout << "Pedido " << (a+1) << std::endl;

      std::cout << it->resumo() << std::endl;

      a++;

      total = total + it->calculaTotal();
  }
  std::cout << "Relatorio de Vendas" << std::endl;
  std::cout << "Total de vendas: R$ " ;
  printf("%0.2f\n",total);
  std::cout << "Total de pedidos: " << a << std::endl;

}