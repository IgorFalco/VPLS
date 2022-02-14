#include "Processo.hpp"
#include "ListaProcessos.hpp"
#include<iostream>

Node* ListaProcessos::criar_node(Node* anterior,Processo* proc,Node* seguinte)
{
    if(head == nullptr)
    {
        Node* aux = new Node;
        aux -> data = proc;
        aux -> next = nullptr;
        aux -> previous = nullptr;

        return aux;
    }
    else
    {
        Node* aux = new Node;
        aux -> data = proc;
        aux -> next = seguinte;
        aux -> previous = anterior;

        anterior -> next = aux;
        seguinte->previous = aux;

        return aux;
    };
    
};
Node* ListaProcessos::criar_node_dir(Node* proc,Processo* p)
{
    Node* aux = new Node;
    aux -> data = p;
    aux -> next = nullptr;
    aux -> previous = proc;

    proc->next = aux;

    

    return aux;
};
Node* ListaProcessos::criar_node_esq(Node* proc,Processo* p)
{
    Node* aux = new Node;
    aux -> data = p;
    aux -> next = proc;
    aux -> previous = nullptr;

    proc -> previous = aux;

    return aux;
};

void ListaProcessos::ordenar_processo(Node* proc, Processo* p)
{
    if(p ->_prioridade <= tail->data->_prioridade)
    {
            tail = criar_node_dir(proc,p);
                return;
    }   
        else if(p ->_prioridade > head->data->_prioridade)
            {
                head = criar_node_esq(proc,p);
                return;
            };
    if(p->_prioridade <= head->data->_prioridade)
    {
        Node *current = head;
        Node *previous = nullptr;

        while (current != nullptr) //Percorre tudo
        {
            if(previous != nullptr)
            {
                if(previous->data->_prioridade >= p->_prioridade && p->_prioridade > current->data->_prioridade)
                {
                    criar_node(previous,p,current);
                    return;
                }
            }
            
        previous = current; //Penultimo 
        current = current->next; //Que estamos vendo
	    }
    }       
            
};

void ListaProcessos::adicionar_processo(Processo* proc)
{
    if(head != nullptr)
    {
        ordenar_processo(head , proc);
    }
    else
    {
        head = criar_node(nullptr,proc,nullptr);
        tail = head;
    }
};

Processo* ListaProcessos::remover_processo_maior_prioridade()
{
    Node* current = head;
    Node* previous = nullptr;

    if (current -> data == head -> data) //Caso seja o que queremos elminar
	{
		if (previous == nullptr) // HEAD
			{ 
				head = current -> next; //Head é o segundo termo agora
			} 
				
		
	}
	 return current -> data;
};

Processo* ListaProcessos::remover_processo_menor_prioridade()
{
    Node *current = head;
	Node *anterior = nullptr;

	while (current != nullptr) //Percorre tudo
	{
		 if (current->next == nullptr) //TAIL
						{ 
							anterior -> next = nullptr;   //Penultimo agora é TAIL
                            anterior -> previous = anterior;
							tail = anterior;
						} 
	
	
	anterior = current; //Penultimo 
	current = current->next; //Que estamos vendo
	}
    return anterior -> data;
};

Processo* ListaProcessos::remover_processo_por_id(int id)
{
    Node *current = head;
	Node *previous = nullptr;

	while (current != nullptr) //Percorre tudo
	{
		if (current->data->_id == id) //Caso seja o que queremos elminar
		{
			if (previous == nullptr) // HEAD
				{ 
					head = current->next;
                    current -> next -> previous = nullptr;  //He`ad é o segundo termo agora
				} 
					else if (current->next == nullptr) //TAIL
						{ 
							previous->next = nullptr;
                            previous-> previous = previous; //Penultimo agora é TAIL
							tail = previous;
						} 
			else 
				{
					previous->next = current->next;
                    current -> next = current -> previous; //um nó aponta para o seu segundo sucessor.
				}
		
		}
	
	previous = current; //Penultimo 
	current = current->next; //Que estamos vendo
	}
	return previous-> data ;
};

void ListaProcessos::imprimir_lista()
{
    Node* current = head;
	Node* previous = nullptr;
	while (current != nullptr) 
	{
        if(previous == nullptr)
            current -> data -> imprimir_dados();
        else
            current -> data -> imprimir_dados();

        previous = current; 
        current = current->next; 
	}
    
	
	
};