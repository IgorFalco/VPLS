#include "fila.h"
#include<stdlib.h>

struct No {
  int chave;
  No* proximo;
};

Fila::Fila() {
  primeiro_ = new No;
  ultimo_ = new No;
  primeiro_ = nullptr;
  ultimo_ = nullptr;
}

void Fila::Inserir(int k) {
    
    No* aux = new No; 
	aux->chave = k; 
	aux->proximo = nullptr; 

		if (primeiro_ == nullptr)
	  {
			primeiro_ = aux; 
			ultimo_ = aux; 
		} 
			else 
				{
					ultimo_->proximo = aux; 
					ultimo_ = aux;       
				}  
  
}

void Fila::RemoverPrimeiro() {
  ExcecaoFilaVazia vazio;
  if(primeiro_ == nullptr) throw vazio;
    else{
        primeiro_ = primeiro_->proximo;
    }


}

int Fila::primeiro() const {
    ExcecaoFilaVazia vazio;
    if(primeiro_ == nullptr) throw vazio;
        else return primeiro_->chave;
}

int Fila::ultimo() const {
    ExcecaoFilaVazia vazio;
    if(primeiro_ == nullptr) throw vazio;
        else return ultimo_->chave;
}

int Fila::tamanho() const {
    int contagem = 0;
	No *aux = primeiro_;

	while (aux != nullptr) 
	{
        contagem++;
		aux = aux->proximo;
	}

  return contagem;
}