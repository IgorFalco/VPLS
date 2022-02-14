// NÃO ALTERE ESSA LINHA
#include "avaliacao_basica_escalonador.hpp"
#include "ListaProcessos.hpp"
#include "Processo.hpp"
#include<string.h>

using namespace std;

int main() {

    ListaProcessos lista;

    int _id;
    int _prioridade;
    char escolha;
    string _nome; //oi

    while(cin >> escolha)
    {
        switch (escolha)
        {
        case 'a':
            cin >> _id >> _nome >> _prioridade;
            lista.adicionar_processo(new Processo(_id, _nome, _prioridade));
            break;
        case 'p':
            lista.imprimir_lista();
            break;

        case 'm':
            lista.remover_processo_maior_prioridade();
            break;
        
        case 'n':
            lista.remover_processo_menor_prioridade();
            break;
        
        case 'b':
            avaliacao_basica();
            break;
        case 'r':
            cin >> _id;
            lista.remover_processo_por_id(_id);
            break;

        }
    }


    return 0;
}