#ifndef LISTAPROCESSOS_HPP
#define LISTAPROCESSOS_HPP

#include "Processo.hpp"

struct Node
{
    Processo *data;
    Node *next = nullptr;
    Node *previous = nullptr;
};

struct ListaProcessos
{

    Node* head = nullptr;
    Node* tail = nullptr;

    Node* criar_node_dir(Node* p,Processo* proc);
    Node* criar_node_esq(Node* p,Processo* proc);
    Node* criar_node(Node* p,Processo* proc,Node* proce);
    void adicionar_processo(Processo* proc);
    Processo* remover_processo_maior_prioridade();
    Processo* remover_processo_menor_prioridade();
    Processo* remover_processo_por_id(int id);
    void ordenar_processo(Node* proc, Processo* p);
    void imprimir_lista();
};
#endif